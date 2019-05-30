# RoboSumo
RoboSumo made in C, with the CCS C compiler and microcontroller PIC16F877A.

## Circuit
For creating a PCB suited for our application we started by making a list of the materials that we need just for the PCB.
##### Digital Parts
-[PIC16F877A](https://www.arrow.com/en/products/pic16f877a-ip/microchip-technology)

-[4Mhz Quarz Crystal](https://www.arrow.com/en/products/hc49us-ff5f18-4.0000/ilsi-america)

-[2x(22pF Capacitor)](https://www.arrow.com/en/products/de11xra220kn4ap01f/murata-manufacturing)

-[QTR-1RC Reflectance Sensor](https://www.pololu.com/product/2459)

-[Bluetooth Module HC-05](https://www.arrow.com/en/products/hc-05/libelium-comunicaciones-distribuidas-sl)

The crystal and the capacitors are for the oscillator needed for the microcontroller so it can work for itself, the bluetooth se we can control it with a phone  and the sensors are for help us when the sumo reachs the edge so it won't fall off the ring.

##### 
So for the first step of designing your own PCB you have to be very careful because if you mess up any connection the whole PCB won't work and all the money you spent on it will be lost. The circuit was made using [Proteus Design Suite](https://www.labcenter.com/), we make sure to keep things very small but because we are using 40-pin PDIP the PCB get a little bit big because of that, neither the motor driver or the boost converter are big so most of the space is the microcontroller
## Programming
For the programming the university gave us this really neat [MPLAB PICkit 4 In-Circuit Debugger](https://www.microchip.com/developmenttools/ProductDetails/PG164140) but to make things easier we bought this [Chinese Programmer]()
## Assembly
