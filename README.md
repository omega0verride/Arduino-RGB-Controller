# Arduino-RGB-Controller
Simple RGB Controller - Version 1.0

This is the first version of a RGB Controller Software using Arduino.

![](/demo_files/run.PNG=250x250) ![](/demo_files/demo.gif=250x250)

There are 2 types of RGB LEDs, choose your version. 
![](/rgb_diagram.png)

**Make sure to set the correct serial port.**

```
 # ------------------------------------------arduino adjustable variables------------------------------------------- 
    PORT = "COM5"
    global interval, lasttime
    interval = 0.03 
    lasttime = time.time() 
    global arduinoBoardSerial 
    arduinoBoardSerial = serial.Serial('%s' % PORT, 115200, timeout=0.5) 
   
    time.sleep(2)  # add a 2 second delay because arduino takes some time to initialize
 # ------------------------------------------------------------------------------------------------------------------
 ``` 

**Changing baud rate might affect communication speed by a lot, try what fits best for your use or do not change it.**

interval = 0.03 -> sets the delay between each communication with arduino, because arduino needs time to process each serial communication. 
