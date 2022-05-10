# makefile configuration
COMMON_OBJECTS		= wdt_handler.o p2_interrupt_handler.o draw_shapes.o switches.o wdt_c_handler.o buzzer.o
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:demo-c.elf demo-s.elf

#additional rules for files
demo-c.elf: ${COMMON_OBJECTS} demo.o color_diamond-c.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load-c: demo-c.elf
	msp430loader.sh $^

demo-s.elf: ${COMMON_OBJECTS} demo.o color_diamond-s.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load-s: demo-s.elf
	msp430loader.sh $^


clean:
	rm -f *.o *.elf *~ *#
