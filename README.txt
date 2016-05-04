Jacob Cole
Zac Adams

Type "make clean" into the terminal to ensure old files are deleted before every "make" command. After, type "make" into the terminal and hit Enter. 
This should create the 'compiler' executable file. You can then test it with various files by running './compiler < fileName' where ‘fileName’ is any file to be compiled.

The compiler will send the CMachine code to stdout. 

To compile the generated CMachine code through gcc, type in 'gcc fileName Assembly/accessories.c'. Then type './a.out' to run the file.

NOTE: Before the last '}' of main, the statement 'printf("");' was added in case a label
is the last thing. This is purely to get the generated C code to run with gcc. It is not
for any other purpose than that.