# Brainfuck

A simple, recursive, brainfuck interpreter.

Coded in C, it uses recursivity to process loops.

## Brainfuck ..?

An esoteric programming language, created in 1993 by Urban Müller.

It uses only a pointer, and the 8 operations you can perform on it. Brainfuck code looks like this :

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b4/Hello_World_Brainfuck.png/420px-Hello_World_Brainfuck.png" width="50%" />
</p>

This program reads it and executes it.

### How to use it

Using ``make`` will create the ``brainfuck`` executable.

Run it with :

```
./brainfuck <file>
```

The file argument is the path to the brainfuck code. For example, you can try ``./brainfuck samples/helloworld.bfk``.
