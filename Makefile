SRC = 	main.c\
		application/application.c\
		MCAL/DIO_Driver/dio.c\
		ECUAL/LED_Driver/led.c\
		ECUAL/Button_Driver/button.c

OBJ = $(subst .c,.o, $(SRC))

MCU = atmega32

CFLAGS = -Os -Wall -mmcu=$(MCU)

INCLUDE = -I./utils
INCLUDE += -I./MCAL
INCLUDE += -I./ECUAL

default:
	@echo $(filter %led,$(SRC))
	
compile:$(OBJ)
	
	@avr-gcc $(CFLAGS) $(INCLUDE) $(OBJ) -o ./bin/main.elf
%.o:%.c
	@echo "compiling $^"
	@avr-gcc $(CFLAGS) $(INCLUDE) $^ -c -o $@

build:
	@echo " building Hex file ... "

	@avr-objcopy -j .text -j .data -O ihex ./bin/main.elf ./bin/main.hex


clean:
	$(foreach file,$(OBJ),$(shell rm $(file)))