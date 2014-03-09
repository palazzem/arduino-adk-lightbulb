=====================
Arduino ADK lightbulb
=====================

Simple project to turn on/off a LED connected with your ADK compatible device.

Structure
---------

Arduino waits for a command from ADK serial port. If you want to create new
features, just edit these functions:

* ``parseResponse()``: simply change buffer parsing to get one or more commands with parameters
* ``commandInterpreter(uint8_t command)``: use this switch case to run arbitrary Arduino tasks

Accessory descriptor
--------------------

Remember to change these descriptors even in your Android app manifest:

.. code-block:: c

		// Accessory descriptor. It's how Arduino identifies itself in Android.
		char accessoryName[] = "LED actuator";
		char manufacturer[] = "Example, Inc.";
		char model[] = "ADK-Led";

		char versionNumber[] = "0.1.0";
		char serialNumber[] = "1";
		char url[] = "http://www.example.com";

Android ADK application
-----------------------

* `UDOO ADK lightbulb`_

.. _UDOO ADK lightbulb: https://github.com/palazzem/udoo-adk-lightbulb

License
-------

FreeBSD (see ``LICENSE`` file)
