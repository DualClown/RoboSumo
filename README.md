# RoboSumo
This guide will explain how to program and assemble a minisumo robot that can cover the categories of both autonomous and Radiocontrol. The Minisumo robot will be used in a fight between 2 RC robots or autonomous and the objective is take the opponent out of a ring.

## Circuit
For creating a PCB suited for our application we started by making a list of the materials that we need for the PCB. Remember that the parts linked in this list are for reference, so if you want to use diferent parts you are free to do it.
##### Important Parts
-[PIC16F877A](https://www.arrow.com/en/products/pic16f877a-ip/microchip-technology)

-[4Mhz Quartz Crystal](https://www.arrow.com/en/products/hc49us-ff5f18-4.0000/ilsi-america)

-[2x(22pF Capacitor)](https://www.arrow.com/en/products/de11xra220kn4ap01f/murata-manufacturing)

-[QTR-1RC Reflectance Sensor](https://www.pololu.com/product/2459)

-[Bluetooth Module HC-05](https://www.arrow.com/en/products/hc-05/libelium-comunicaciones-distribuidas-sl)

-[TB6612FNG Dual Motor Driver Carrier](https://www.pololu.com/product/713)

-[2xMotors](https://www.jsumo.com/core-dc-motor-6v-400-rpm)

-[Wheels](https://www.jsumo.com/slt20-aluminum-silicone-wheel-set-33mmx20mm-pair)

The crystal and the capacitors are for the oscillator needed for the microcontroller so it can work for itself, we can control the car via bluetooth it with a phone, and the sensors are for help us when the sumo reaches the edge so it won't fall off the ring. The TB6612FNG Motor Driver help us to rotate the motors in any direction very easily,we recommend you to use high torque motors so you can push the opponent out of the ring.

##### Power Source
-[7.4V Lipo Battery](https://www.jsumo.com/profuse-2s-74v-2800-mah-lipo-battery-jsumo)

-[Lipo Charger](https://www.jsumo.com/imax-b6-lipo-battery-charger)

-[Step Up Boost Regulator Board](https://www.jsumo.com/xl6009-step-up-boost-regulator-board-125v-35v-out)

-[5V Linear Voltage Regulator](https://www.arrow.com/en/products/2164/adafruit-industries)

-[1uF Capacitor](https://www.arrow.com/en/products/105ckr050m/illinois-capacitor)

-[0.1uF Capacitor](https://www.arrow.com/en/products/com-08375/sparkfun-electronics)

The power source is a very important part of this robot because if you don't supply the enough amount of current and voltage the sumo wont work properly. We need to boost the voltage of the batteries to 8V so we can use the voltage to drive the motors then step down the voltage with a linear regulator to supply the microcontroller, bluetooth and driver. The capacitor are for smoothing the input and output of the linear regulator, you can find more information about that configuration on its datasheet.

##### Miscellaneous
-[Resistors of different values](https://www.arrow.com/en/products/frn25j1r0/te-connectivity)

-[Headers](https://www.pololu.com/category/19/connectors)

-[Glue Gun](https://www.amazon.com/ccbetter-Upgraded-Removable-Anti-hot-Flexible/dp/B01178RVI2/ref=sr_1_1_sspa?keywords=glue+gun&qid=1559229987&s=gateway&sr=8-1-spons&psc=1)

-[Soldering iron](https://www.amazon.com/ANBES-Soldering-Iron-Kit-Electronics/dp/B06XZ31W3M/ref=sr_1_3?crid=1SRKZ91IKFQEH&keywords=soldering+iron&qid=1559230135&s=gateway&sprefix=solde%2Caps%2C231&sr=8-3)


So for the first step of designing your own PCB you have to be very careful because if you mess up any connection the whole PCB won't work and all the money you spent on it will be lost. The circuit was made using [Proteus Design Suite](https://www.labcenter.com/), we make sure to keep things very small but because we are using 40-pin PDIP the PCB get a little bit big because of that, neither the motor driver or the boost converter are big so most of the space taken by the microcontroller. Then we came up with this desing [PCB Robot](PCB.pdf) that incorporate everything that the robot needs, plus some headers for sensors and unused pin of the microcontroller so you can use it any way you want. And this is a [3D View](3DPCB.pdf) of the PCB so you can see how the things with fit inside the car.
## Programming
For the programming the university gave us this really neat [MPLAB PICkit 4 In-Circuit Debugger](https://www.microchip.com/developmenttools/ProductDetails/PG164140) but to make things easier we bought this [Chinese Programmer](https://www.amazon.com/BQLZR-Microcontroller-Automatic-Programming-Programmer/dp/B00EQ1Y4BU/ref=sr_1_1?crid=1ULJV4PH05T1N&keywords=pic+programmer+k150&qid=1559231113&s=gateway&sprefix=pic+prog%2Caps%2C311&sr=8-1).
To see and understand the source code please take a look a the [C code](source_code.c).
To create the app we used [MIT App Inventor](https://appinventor.mit.edu/explore/) and send characters to the microcontroller, then the microcontroller can make the motors do the movement we need. This is the [app](Sumo.apk) we created. The only problem with the app is that it only works for android for now, maybe in the future we will make an IOS app.
## Assembly
For the assembly we created a suited enclosure for the components of the car with [AutoCAD](https://www.autodesk.com/products/autocad/overview) so we can go to a place to cut it with laser in 5.5mm thick mdf, the finished [desing](Chassis_Sumo.dxf) you need AutoCAD to see it properly but [here](screenshot_chassis.PNG) is a picture of it. The red lines are indentations for the QTR sensor so we can hot glue them to the chassis. When you make all the conections and glue everything in place you have someting like the [pictures](Pictures.zip) we uploaded.
## Problems and Conclusions
-We had a big problem when making the car when we accidentaly rise too much the voltage of the boost converter and blow up the bluetooth module, so be carefull with those things, they are very fragile objects.

-Another problem was the very famous rush current of a motor when turned on so, we needed to connect in series a low value resistor to decrease the current.

-In the end the goal was met when the car perfectly worked, the next thing was to try it in a competition with the other cars from our class.

-The car is 100% improvable in any aspect, even the chassis or the desing of the PCB can be changed to improve its competitiveness.
