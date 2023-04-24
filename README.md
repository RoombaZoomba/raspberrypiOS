# raspberrypiOS

Final Project - Booting a small OS to a Raspberry Pi - By Ben, Carl, Fernando, Nathan


    We originally believed we only needed to translate Dr. Gheith's assembly from x86-32 to Arm64. However, the process proved to be much more intricate and involved. By exploring Dr. Gheith's code and with some pointers from Esther, we realized much of the OS was x86 dependent - requiring us to do much more than simply translating assembly. Any attempt at adapting the existing OS to work on ARM architecture would basically result in a new OS (or not, Ship of Theseus paradox?), so instead we decided to start from the ground up and create a barebones operating system with the goal of booting and implementing some base functionality, such as multicore processing, atomic operations, spinlocks, and critical sections, with inspiration from Dr. Gheith's OS. We needed a starting plate and by referencing OSdev we were able to build the bootstrapper, linker, and other essentials like UART. We studied and researched the bootstrapping process, linker, ARM operations and architecture as well as essentials like creating our own Makefiles and using a cross compiler.
    
    We ran into many issues setting up the development environment. As we simply weren't just extending the functionality of an existing OS, it wasn't just writing some more C++ code like most other groups. 
    For example: 
    - Do we develop on our own machines or on the lab machines? Most of us have M1 Macs which run on ARM architecture, but we don't know how to setup QEMU          on MacOS. We don't have sudo permissions on lab machines, so how would we configure QEMU to emulate a Raspberry Pi?
    - How do we even configure QEMU to emulate a Raspberry Pi, and how do we "run" it?
    - Should we instead use a Linux VM on our personal machines and install QEMU from there? (This caused MANY issues we were unable to resolve)
    - Do we use a bootloader like DAS U-Boot or write a bootstrapping file ourselves? And how much of the process does DAS U-Boot take care of?
    
    We ended up developing on a Windows machine dual booting Linux and using QEMU to emulate the Raspberry Pi hardware. However, QEMU only supported up to 
Raspberry Pi 2b which used ARM32 architecture, meaning the environment we develop and test on (QEMU) and the environment we run on (Raspberry Pi 4) would be on different architectures, so for the sake of time and effort we stuck to the 2b and QEMU. We wanted to use DAS U-Boot, but again ran into a multitude of issues trying to download and configure it, costing us many braincells in the process. So with the help of OSDev we actually made the bootstrapping file.

    Once we got the OS to boot and enter kernelMain, we were able to get the Atomic class, spinlocks, stdio, stdlib and UART working with help from Dr. Gheith's code, OSdev, and geeksforgeeks. We also translated parts of machine.S into ARM64 and set up heap.
        


If you have added anything to your project since your presentation, please describe what it was and point out the additions in your codebase.
We were able to finish up and furnish spinlock, develop heap/malloc, and finish parts of stdio, stdlib, and uart.





Resources compiled and used:
    https://wiki.osdev.org/Raspberry_Pi_Bare_Bones  
    https://developer.arm.com/downloads/-/gnu-rm


