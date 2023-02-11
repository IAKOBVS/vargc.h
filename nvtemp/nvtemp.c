#include <stdio.h>
#include "nvidia/gdk/nvml.h"
#include <time.h>
#include "/home/james/c/vargc.h"

#define NANO_MULTIPLIER 1000000
#define LOOP_INTERVAL 200 * NANO_MULTIPLIER
#define COUNT_ARR(...) PP_NARG(__VA_ARGS__)

int main()
{
	int arrSize = COUNT_ARR(36, 37, 38, 39, 40, 42, 44, 46, 48, 50, 54, 56, 57, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 87, 88, 89, 90, 91, 92, 93, 94, 96, 98, 100);
	unsigned int speedAndTemp[2][COUNT_ARR(36, 37, 38, 39, 40, 42, 44, 46, 48, 50, 54, 56, 57, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 87, 88, 89, 90, 91, 92, 93, 94, 96, 98, 100)] = {
		{36, 37, 38, 39, 40, 42, 44, 46, 48, 50, 54, 56, 57, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 87, 88, 89, 90, 91, 92, 93, 94, 96, 98, 100},
		{45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83}
	};
	nvmlDevice_t device;
	if (nvmlInit() != NVML_SUCCESS)
		goto ERROR;
	if (nvmlDeviceGetHandleByIndex(0, &device) != NVML_SUCCESS)
		goto ERROR_SHUTDOWN;
	unsigned int temp;
	unsigned int tmp = 0;
	unsigned int speed;
	unsigned int i;
	struct timespec interval;
	interval.tv_nsec = LOOP_INTERVAL;
	for (;;) {
		if ((temp = nvmlDeviceGetTemperature(device, NVML_TEMPERATURE_GPU, &temp) != NVML_SUCCESS))
			goto ERROR_SHUTDOWN;
		if (temp != tmp) {
			for (int i = 0; i < arrSize; ++i)
				;
		}
		tmp = temp;
		nanosleep(&interval, NULL);
	}
	if (nvmlShutdown() != NVML_SUCCESS)
		goto ERROR;
	return 0;
ERROR_SHUTDOWN:
	nvmlShutdown();
ERROR:
	perror("");
	return 1;
}
