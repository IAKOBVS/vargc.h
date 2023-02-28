#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nvtemp.h"
#include </opt/cuda/include/nvml.h>

#if (defined(__GNUC__) && (__GNUC__ >= 3)) || (defined(__clang__) && __has_builtin(__builtin_expect))
  #define likely(x) __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else
  #define likely(x) (x)
  #define unlikely(x) (x)
#endif

#define NANO_TO_MILI 1000000
#define LOOP_INTERVAL 200 * NANO_TO_MILI

int main(void)
{
	struct timespec interval;
	interval.tv_nsec = LOOP_INTERVAL;
	nvmlDevice_t device;
	if (unlikely(nvmlInit() != NVML_SUCCESS))
		goto ERROR;
	if (unlikely(nvmlDeviceGetHandleByIndex(0, &device) != NVML_SUCCESS))
		goto ERROR_SHUTDOWN;
	unsigned int speed = 33;
	int tmp = 0;
	unsigned int temp;
	for (;;) {
		if (unlikely(nvmlDeviceGetTemperature(device, NVML_TEMPERATURE_GPU, &temp) != NVML_SUCCESS))
			goto ERROR_SHUTDOWN;
		if (abs(tmp - (int)temp) > 2) {
			switch (temp) { TEMP_THEN_SPEED(speed); }
			if (unlikely(nvmlDeviceSetFanSpeed_v2(device, 0, speed)))
				goto ERROR_SHUTDOWN;
			tmp = temp;
		}
		nanosleep(&interval, NULL);
	}
	if (unlikely(nvmlShutdown() != NVML_SUCCESS))
		goto ERROR_SHUTDOWN;
	return 0;

ERROR_SHUTDOWN:
	nvmlShutdown();
ERROR:
	perror("");
	return 1;
}
