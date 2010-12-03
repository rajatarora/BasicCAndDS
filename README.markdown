#README#

This repository hosts some of the very basic programs in the C-Programming Language, and the implementations of a number of Data Structures in C. The purpose of this repo is *strictly* academic, that is, they are homework-style problems designed for the perusal of students who study C and Data Structures. 

However, students are **discouraged** to use these programs *as-is* in their homework problems. (As a matter of fact, they are not allowed to do so either. See the [license](https://github.com/rajatarora/BasicCAndDS/blob/master/LICENSE) file for more details.)

Just look at these programs, and try to implement them on their own. They are sufficiently documented with comments that will help you get started. 

Should you find any mistake in the code, or find a better way to do something and wish to tell me, or want any further explanations of the code, feel free to contact me at [rajat@rajatarora.info](mailto:rajat@rajatarora.info).

###Instructions for Compiling###
These programs have been coded and tested on a Linux system ([Ubuntu 10.10 Maverick Meerkat](http://ubuntu.com)). They should run on a Windows install too, if you use [GCC](http://gcc.gnu.org) to compile them (You can use [Code::Blocks](http://codeblocks.org), it uses GCC as its compiler.)

However, if you happen to have a Linux install, then just type:   
`gcc <filename>.c` to compile and `./a.out` to execute, in the terminal.

Also, note that for programs that are stored in their own directory (`HashTable` for example), you just have to compile `<DirectoryName>_tester.c`, and nothing else. It represents the tester program for the functions declared and defined in `<DirectoryName>.h` and `<DirectoryName>.c` files respectively.

Happy Coding!
