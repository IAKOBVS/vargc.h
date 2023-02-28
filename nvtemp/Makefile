ARCH   := $(shell getconf LONG_BIT)

ifeq (${ARCH},$(filter ${ARCH},32 64))
   NVML_LIB := /opt/cuda/lib64/
else
   $(error Unknown architecture!)
endif

CFLAGS  := -I /usr/include -I /opt/cuda/include
LDFLAGS := -lnvidia-ml -L $(NVML_LIB)

nvtemp: nvtemp.o
	$(CC) $< $(LDFLAGS) -o $@ -O2 -flto

clean:
	-@rm -f nvtemp.o
	-@rm -f nvtemp
