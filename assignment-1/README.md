
# CPSC 8700 - Assignment 1

This is a c++ project which rotates .ppm and .pgm image files in P2 and P3 ASCII format and P5 and P6 binary formats.

The following skills are used:
* Use of classes and classes containing objects as members.
* Use of a Creational Design Pattern Singleton.
* Use of command line arguments and file I/O streams.
* Use of zip/compression utilities and makefiles

```
In samples folder:
 file name ends with A: ASCII file
 file name ends with B: Binary (Raw) file
```

## Run Locally

Clone the project

```bash
  git clone https://github.com/aditeyaS/8700-assignments
```

Go to the project directory

```bash
  cd 8700-assignments/assignment-1
```

Compile files

```bash
  make
```

Rotate file

```bash
  ./rotator <input.ppm> <output.ppm> -<mode> <angle>
  
  mode:
    -l: rotate left
    -r: rotate right

  angle:
    angle = { 90x | x ∈ W }
    i.e. 0, 90, 180, 270, 360, ...
```


## Usage/Examples

```bash
    ./rotator samples/rgbA.ppm rgbA_r90.ppm -r 90
```

