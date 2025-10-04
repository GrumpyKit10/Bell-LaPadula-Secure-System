///////////////////  
/   Project 1     /  
/ Matthew Wilson  /  
/ mlw0420@unt.edu /  
/    11369458     /  
/  CSCE 3550.001  /  
/     3-3-22      /  
///////////////////

# Bell-LaPadula Secure System
**CSCE 3550: Foundations of Cybersecurity – Spring 2022**  
**Project 1 – Bell-LaPadula Security Model Implementation**

---

## Project Summary
This project implements a secure system using the Bell-LaPadula (BLP) model with simple security, the *-property, and strong tranquility. Subjects and objects store names and values, while a Reference Monitor manages security levels and enforces access rules. Commands from an input file are parsed, validated, and executed if allowed; invalid commands are reported as Bad Instructions.

---

## Using the Makefile
The executable is named `secureblp`.

1. `make` — invokes the Makefile to compile `.cpp` files into `secureblp` and object files.  
2. `./secureblp` — runs the program with the specified instruction file.  
3. `make clean` — removes all object files and the `secureblp` executable.
