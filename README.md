# MiniMat Vector Calculator

A simple C program for working with 3D vectors. It can create and store vectors, perform calculations, and load or save vectors using CSV files.

## Build

```bash
gcc vector.c mainLab7.c storage.c -o miniMat7
```

## Run

```bash
./miniMat7
./miniMat7 -h
```

The `-h` option shows the help message.

## Commands

- `a = 1 2 3` or `a = 1,2,3` — create or update a vector.
- `a + b`, `a - b`, `a * 2`, `2 * a` — perform calculations.
- `c = a + b` — save a calculated vector.
- `a` — display a vector.
- `list` — show stored vectors.
- `clear` — delete all stored vectors.
- `load filename` — load vectors from a CSV file.
- `save filename` — save vectors to a CSV file.
- `quit` — exit.

## Example

Enter `a = 1 2 3`, then use `list` to display the stored vector.

CSV rows use the format `name,x,y,z`. Filenames can include relative or absolute paths and do not need a `.csv` extension. Use spaces around operators; vector names are limited to 7 characters.

## Dynamic Memory

Vectors are stored in a dynamically allocated array. The program uses `realloc()` to increase capacity when needed, and `free()` to release memory when vectors are cleared or the program exits.
