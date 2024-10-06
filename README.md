# Palindrome Checker
=====================

## Overview

This C program checks if a given string is a palindrome. It takes command-line arguments, concatenates them into a single string, removes numbers, converts uppercase letters to lowercase, and then checks if the resulting string is a palindrome.

## Usage

To compile and run the program, use the following command:

```bash
gcc -o palindrome main.c
./palindrome arg1 arg2 arg3 ...
```

Replace `arg1`, `arg2`, `arg3`, etc. with the desired command-line arguments. actually words of a phrase

## Example Use Cases

* `./palindrome Madam` outputs "PALAINDROME !"
* `./palindrome Hello` outputs "Error: non palindrome"
* `./palindrome A1b2c3` outputs "Error: non palindrome" (numbers are removed and the string is converted to lowercase)

## Code Explanation

The program uses dynamic memory allocation to concatenate the command-line arguments into a single string. It then iterates over the string, removing numbers and converting uppercase letters to lowercase. Finally, it checks if the resulting string is a palindrome by comparing characters from the start and end of the string, moving towards the center.

## Notes

* The program uses ANSI escape codes to print colored output.
* The program frees the dynamically allocated memory to prevent memory leaks.
