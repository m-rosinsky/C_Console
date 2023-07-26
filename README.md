# C_Console
A generic expandable console application written in C

Written by Michael Rosinsky

## About

This project is designed for use in applications that require a
console (CLI) style interface.

The developer should be able to configure their specific
commands for the console's parser to handle, and the functionality
of each command.

This console application will take care of all the terminal configurations,
command history, tab completion (planned), etc.

## Usage

Add all commands to the ```command.c``` file, and all command
functionality to the ```commands``` directory.

The main function will instantiate a new console and run it.
