Jacob Cole
Zac Adams

Type "make run" into the terminal and hit Enter. The program will then compile and run. The program consists of the requested functions insert, recordSearch, enter_new_scope, and leave_current_scope. The insert function works by pushing a new record into the symbol table data structure which in our case is similar to a single linked list. The recordSearch function loops through each entry in the symbol table list and then move to the next symbol table when reaching the last record entry and repeats this process. The enter_new_scope function also acts as a push function in that it creates a new symbol table and pushes it to the list (the symbol table stack also uses a structure similar to a single linked list). The leave_current_scope function acts as a pop function and deletes the last entry made in the symbol table stack.

The output from the program will print to the terminal what is expected from the function calls, and is followed by the actual output created by the functions inner workings.
