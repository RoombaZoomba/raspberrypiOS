# raspberrypiOS

Final Project - Building a Raspberry Pi on OS

The set up:
    We thought of simply translating gheith's code(from X86-32 to Arm 32). However we realized just translating gheith's code isn't enough. In the process of looking at arm 64 and gheith's code, we realized that gheith's code was too 86 specific. Because of this, we could not simply translate his base code to start up to simply start up the OS. We needed a starting plate and OS dev was able to provide alot of the mbr, linker, and essential parts such as the UART. We were able to gather the code, put it together, and expand on the OS using parts of gheith's code. 
    



If you have added anything to your project since your presentation, please describe what it was and point out the additions in your codebase.




Resources compiled and used:
https://wiki.osdev.org/Raspberry_Pi_Bare_Bones
mbr.S and script.ld is pretty much just taken from OSDev
