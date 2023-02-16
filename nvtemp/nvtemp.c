#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nvtemp.h"

#include <nvidia/gdk/nvml.h>

#define NANO_TO_MILI 1000000
#define LOOP_INTERVAL 200 * NANO_TO_MILI

int main()
{
	nvmlDevice_t device;
	if (nvmlInit() == NVML_SUCCESS); else goto ERROR;
	if (nvmlDeviceGetHandleByIndex(0, &device) == NVML_SUCCESS); else goto ERROR_SHUTDOWN;
	int temp;
	int tmp = 0;
	unsigned int speed = 36;
	struct timespec interval;
	interval.tv_nsec = LOOP_INTERVAL;
	if (system("sudo nvidia-settings -a \"[gpu:0]/GPUFanControlState=1\"")) goto ERROR_SHUTDOWN;
	for (char buf[57];;) {
		if (nvmlDeviceGetTemperature(device, NVML_TEMPERATURE_GPU, (unsigned int *)&temp) == NVML_SUCCESS); else goto ERROR_SHUTDOWN_RESET_FAN;
		if (abs(tmp - temp) > 2) {
			switch (temp) {
				TEMP_THEN_SPEED(speed);
			}
			tmp = temp;
			sprintf(buf, "sudo nvidia-settings -a \"[fan:0]/GPUTargetFanSpeed=%d\"", speed);
			system(buf);
		}
		nanosleep(&interval, NULL);
	}
	if (nvmlShutdown() == NVML_SUCCESS); else goto ERROR_SHUTDOWN_RESET_FAN;
	system("sudo nvidia-settings -a \"[gpu:0]/GPUFanControlState=0\"");
	return 0;

ERROR_SHUTDOWN_RESET_FAN:
	system("sudo nvidia-settings -a \"[gpu:0]/GPUFanControlState=0\"");
ERROR_SHUTDOWN:
	nvmlShutdown();
ERROR:
	perror("");
	return 1;
}
