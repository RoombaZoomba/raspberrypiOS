
run:
	qemu-system-arm -m 1024 -M raspi2b -serial stdio -kernel myos.elf

build:
	./gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -c mbr.S -o mbr.o
	./gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c kernel.c -o kernel.o -O2 -Wall -Wextra
	./gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c ourstdio.c -o ourstdio.o -O2 -Wall -Wextra
	./gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c ourstdlib.c -o ourstdlib.o -O2 -Wall -Wextra
	./gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c ouruart.c -o ouruart.o -O2 -Wall -Wextra
	./gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc -T script.ld -o myos.elf -ffreestanding -O2 -nostdlib mbr.o kernel.o ourstdio.o ourstdlib.o ouruart.o
	./gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-objcopy myos.elf -O binary myos.bin

clean:
	rm *.o
	rm *.bin
	rm *.elf
