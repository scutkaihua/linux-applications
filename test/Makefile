
CROSS_COMPILE :=arm-linux-gnueabihf-
CC		:=$(CROSS_COMPILE)gcc
LD		:=$(CROSS_COMPILE)ld
OBJCOPY :=$(CROSS_COMPILE)objcopy
OBJDUMP :=$(CROSS_COMPILE)objdump

OBJS	:= main.o

$(NAME).bin :$(OBJS)
	S(LD) -g -o $(NAME)

%.o : %.c
	$(CC) -Wall -g -nostdlib -c -O0 -o $@ $<

%.o : %.S
	$(CC) -Wall -g -nostdlib -c -O0 -o $@ $<

clean:
	rm -rf *.o *.bin
