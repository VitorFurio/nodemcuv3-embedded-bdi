## Description

This folder contains various implementations of the vacuum example from the [Getting Started](https://jason.sourceforge.net/mini-tutorial/getting-started/) documentation of the [Jason interpreter](http://jason.sourceforge.net/wp/).

* v1: vacuum moves and cleans dirty spaces.
* v2: vacuum starts on "start" press and cleans dirty spaces.
* v3: vacuum starts on "start" press, blinks when dirty deposit is full, and cleans dirty spaces.

For reference, the circuit with the ESP8266 should look as follows:

* *INSERT IMAGE HERE*

Where the analog interface is used to detect various buttons. The values read from the analog interface correspond to different button presses, represented in the table below:

| Start  |  Dirt  | Full_Deposit |  Value |
| :---: | :---: | :---: | :---: | 
| 0 | 0 | 0 | 10 |
| 0 | 0 | 1 | 116 |
| 0 | 1 | 0 | 368 |
| 0 | 1 | 1 | 423 |
| 1 | 0 | 0 | 589 |
| 1 | 0 | 1 | 615 |
| 1 | 1 | 0 | 693 |
| 1 | 1 | 1 | 715 |