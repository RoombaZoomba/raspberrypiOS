# raspberrypiOS

Final Project - Building a Raspberry Pi on OS - By Ben, Carl, Fernando, Nathan

The set up:
    We thought of simply translating gheith's code(from X86-32 to Arm 32). However we realized just translating gheith's code isn't enough. In the process of looking at arm 64 and gheith's code, we realized that gheith's code was too 86 specific. Because of this, we could not simply translate his base code to start up to simply start up the OS. We needed a starting plate and OS dev was able to provide alot of the mbr, linker, and essential parts such as the UART. This required us to study and understand what the mbr, the linker, and essential parts do.  We were able to gather the code, put it together, and expand on the OS using parts of gheith's code. 
    We had alot of trouble setting up the environment at the beginning. For we example wanted to use DAS U-Boot but that proved too difficult to implement. Now originally, we were going to use a Raspiberry Pi. We acquired a Raspiberry Pi 4 from Chatterjee. However, we needed QEMU to emulate and debug/test our code. When we got QEMU, QEMU only supported Raspiberry Pi's up to 2b and because of some substantial differences between 4 and 2b, we decided to stick to 2b and QEMU due to the sake of time and effort. We also had to use a cross compiler since the code we were running on was X86 and we were compiling for arm. Setting all of these proved to be challenging task.
    After we were able to get into kernel main, we were able to implement several things from OS and gheith's code. For one, we developed the atomic class, spinlock, heap/malloc, and implemented stdio, stdlib, and uart together using from gheith's code, OS dev, and geeks for geeks.
    
    



If you have added anything to your project since your presentation, please describe what it was and point out the additions in your codebase.
We were able to finish up and furnish spinlock, develop heap/malloc, and finish parts of stdio, stdlib, and uart.





Resources compiled and used:
https://wiki.osdev.org/Raspberry_Pi_Bare_Bones

