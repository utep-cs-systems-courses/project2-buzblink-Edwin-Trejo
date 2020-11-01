# makefile configuration
COMMON_OBJECTS	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: toy.elf

toy.elf: ${COMMON_OBJECTS} toyMain.o switches.o interrupt_handler.o leds.o libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $a $^


load: toy.elf
	msp430loader.sh toy.elf


clean:
	rm -f *.o *.elf

wdInterruptHandler.o: stateMachines.h
