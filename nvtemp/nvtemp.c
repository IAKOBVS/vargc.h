#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nvtemp.h"
#include <assert.h>

#include </opt/cuda/include/nvml.h>

#define NANO_TO_MILI 1000000
#define LOOP_INTERVAL 200 * NANO_TO_MILI

int main()
{
	nvmlDevice_t device;
	if (nvmlInit() == NVML_SUCCESS);
	else goto ERROR;
	if (nvmlDeviceGetHandleByIndex(0, &device) == NVML_SUCCESS);
	else goto ERROR_SHUTDOWN;
	unsigned int minSpeed;
	unsigned int maxSpeed;
	nvmlDeviceGetMinMaxFanSpeed(device, &minSpeed, &maxSpeed);
	printf("min: %d, max: %d", minSpeed, maxSpeed);
	/* assert(2==3); */
	/* int temp; */
	/* int tmp = 0; */
	/* unsigned int speed = 36; */
	/* struct timespec interval; */
	/* interval.tv_nsec = LOOP_INTERVAL; */
	/* for (char buf[57];;) { */
	/* 	if (nvmlDeviceGetTemperature(device, NVML_TEMPERATURE_GPU, (unsigned int *)&temp) == NVML_SUCCESS); */
	/* 	else goto ERROR_SHUTDOWN; */
	/* 	if (abs(tmp - temp) > 2) { */
	/* 		switch (temp) { */
	/* 			TEMP_THEN_SPEED(speed); */
	/* 		} */
	/* 		tmp = temp; */
	/* 		printf("%d\n", temp); */
	/* 	} */
	/* 	nanosleep(&interval, NULL); */
	/* } */
	if (nvmlShutdown() == NVML_SUCCESS);
	else goto ERROR_SHUTDOWN;
	return 0;

ERROR_SHUTDOWN:
	nvmlShutdown();
ERROR:
	perror("");
	return 1;
}
