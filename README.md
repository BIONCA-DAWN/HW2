HW2:

Files:

Coordinator.c starts 4 other smaller programs called child processes. It uses fork() to create them, exec() to run the Checker.c, and wait() to wait for each to finish before starting the next one.

Checker.c takes 2 numbers as an input. It checks if the second number can be divided evenly by the first one, and then prints the result.

Checker.h tells the compiler about the is_divisible function used in the Checker.

Makefile – A file already provided that builds and compiles everything for you.

To build:
$ make

To clean:
$ make clean

To run example:
$ ./coordinator 3 3 20 49 102
