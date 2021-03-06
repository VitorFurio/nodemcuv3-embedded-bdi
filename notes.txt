Useful commands:

* `idf_start`: set toolchain environment variables.
* `idf.py size`: size of program file.
* `idf.py menuconfig`: config idf toolchain.
* `make translate`: translate agentspeak code.
* `make agent`: translate agentspeak code, build agent and flash code to board.

----

Useful links:

* https://docs.espressif.com/projects/esp-idf/en/latest/esp32/
* https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/
  * 8 pins for digital I/O: GPIO0, GPIO2 e GPIO15 (pay attention when using it!) shouldn't be used as input

* Heap size: 
  * https://esp32.com/viewtopic.php?t=3802
  * https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/api-reference/system/mem_alloc.html


```
I (241) log: Memory usage: 115188

-----

I (243) log: MALLOC_CAP_8BIT 85376
I (244) log: MALLOC_CAP_32BIT 114812

----

 DRAM .data size:     984 bytes
 DRAM .bss  size:    3928 bytes
Used static DRAM:    4912 bytes (  93392 available, 5.0% used)
Used static IRAM:   17955 bytes (  31197 available, 36.5% used)
      Flash code:   76362 bytes
    Flash rodata:   19724 bytes
Total image size:~ 115025 bytes (.bin may be padded larger)
```

```
#include "esp_log.h"
#include "esp_system.h"
#include "esp_heap_caps.h"

ESP_LOGI(TAG, "Memory usage: %d\n\n\n\n", esp_get_free_heap_size());
ESP_LOGI(TAG, "MALLOC_CAP_8BIT %d", heap_caps_get_free_size(MALLOC_CAP_8BIT));
ESP_LOGI(TAG, "MALLOC_CAP_32BIT %d", heap_caps_get_free_size(MALLOC_CAP_32BIT));
```