Jacob Cole
Zac Adams

Type "make clean" into the terminal to ensure old files are deleted before every "make" command. After, type "make" into the terminal and hit Enter. 
This should create the 'compiler' executable file. You can then test it with various files by running './compiler < fileName' where ‘fileName’ is any file to be compiled.

The compiler will send the CMachine code to stdout. 

NOTE: Because this was fixed last minute, I used r500 as the register to be reserved for 0 so I didn’t have to rewrite a bunch of other stuff.