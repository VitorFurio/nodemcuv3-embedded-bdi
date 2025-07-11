---
## Example

This example illustrates an agent called `sensor1`, which collaborates with other agents on fire detection. Upon detecting a condition indicating the presence of fire in its area, the agent enters an alert state and exchanges information with other agents in the region to determine if the event is a fire or an isolated incident that could be mistaken for one (e.g., a temperature increase due to a heat source like a stove, heater, etc.). In this example, a fire is considered present when at least two sensors detect fire, at which point the agent triggers an emergency alarm.

### Docker-based execution (recommended)
If the ESP8266 board is connected to the /dev/ttyUSB0 serial port, type
```
sudo docker run --device=/dev/ttyUSB0 -it --rm maiquelb/embedded-bdi:latest /bin/bash -i -c "source /setup_esp8266.sh && cd /nodemcuv3-embedded-bdi && make fire_sensors"
```

If the ESP32 board is connected to a different serial port:
- Acess the container via shell (replace `[SERIAL PORT]` with the proper value):
  ```
  docker run --device=[SERIAL PORT] -it --rm maiquelb/embedded-bdi:latest bash
  ```
- Set the proper serial port in the line 7 of the `Makefile`
  ```
  nano /nodemcuv3-embedded-bdi/Makefile
  ```
- Run the example
  ```
  source /setup_esp8266.sh && cd /nodemcuv3-embedded-bdi && make fire_sensors
  ```
