# FolderSize, written in C

A small single-file project, aimed at reaching the lowest possible folder size evaluation time possible.

Whilst the **FolderSizeCPP** repo is a derivation of a bigger project, where the code is utilized in a NodeJS module, a non-C++ variant is useless to me, however I still wanted to see how fast we can get by using even faster language than C++. Turns out `not much`

## Usage

To get the size of your desired folder, simply use `FolderSize [Path]`

## Building

### Note

As of release **1.1** all later released builds will be compiled in **GCC (MinGW64)** with `-Ofast -ffast-math` parameters.

### Building yourself

You are free to take any approach of building this project, it is dependency-free and has no real requirements.
