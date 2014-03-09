#include <adk.h>

#define BUFFSIZE 128
#define LED 13

// Accessory descriptor. It's how Arduino identifies itself in Android.
char accessoryName[] = "LED actuator";
char manufacturer[] = "Example, Inc.";
char model[] = "ADK-Led";

char versionNumber[] = "0.1.0";
char serialNumber[] = "1";
char url[] = "http://www.example.com";

// ADK configuration
USBHost Usb;
ADK adk(&Usb, manufacturer, model, accessoryName, versionNumber, url, serialNumber);
uint8_t buffer[BUFFSIZE];
uint32_t bytesRead = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  delay(1000);
  Serial.println("Ready for commands...");
}

void loop()
{
  readingFromADK();
}

void readingFromADK()
{
  Usb.Task();

  // Starting listening when ADK is available
  if (adk.isReady()) {
      adk.read(&bytesRead, BUFFSIZE, buffer);
    if (bytesRead > 0) {
      commandInterpreter(parseResponse());
    }
  }
}

uint8_t parseResponse()
{
  return buffer[0];
}

void commandInterpreter(uint8_t command)
{
  switch(command) {
    case 0:
      Serial.println("Received command: 0 -> turn off");
      digitalWrite(LED, LOW);
      break;
    case 1:
      Serial.println("Received command: 1 -> turn on");
      digitalWrite(LED, HIGH);
      break;
    default:
      Serial.println("Command not available");
      break;
  }
}
