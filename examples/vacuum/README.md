## Description

This folder contains various implementations of the vacuum example from the [Getting Started](https://jason.sourceforge.net/mini-tutorial/getting-started/) documentation of the [Jason interpreter](http://jason.sourceforge.net/wp/).

For more information, see [the example description](https://embedded-bdi.github.io/application.html).

----

## How to run the examples

To run each example, place the files from each subfolder on its corresponding locations and run `make agent`. The executable will be compiled and uploaded to the nodeMCUv3.

|      File      |            Location            |
|:--------------:|:------------------------------:|
|  agent.config  |      nodemcuv3-embedded-bdi/     |
| CMakeLists.txt |   nodemcuv3-embedded-bdi/main/   |
| agent_loop.cpp |  nodemcuv3-embedded-bdi/main/src/ |
|  agent_loop.c  |  nodemcuv3-embedded-bdi/main/src/ |
|   functions.h  | nodemcuv3-embedded-bdi/main/data/ |
|  functions.cpp | nodemcuv3-embedded-bdi/main/data/ |
| agentspeak.asl | nodemcuv3-embedded-bdi/main/data/ |

* Alternatively, `make` targets are available to copy the files, compile the agent, flash, and monitor the program in the NodeMCUv3 board. Note that the Makefile is available the root of the repository and the make command should be run inside the `nodemcuv3-embedded-bdi` folder:
  * `v1-traditional`
  * `v1-reactive`
  * `v1-proactive`
  * `v2-traditional`
  * `v2-reactive`
  * `v2-proactive`
  * `v3-traditional`
  * `v3-reactive`
  * `v3-proactive`