---
## Example

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
