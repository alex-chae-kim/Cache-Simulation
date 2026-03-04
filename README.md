# Name
Alexander Kim (UFID: 71075724)

# Compilation

``` bash
make
```

# Testing and Running
All results are sent to output/out.
You might first need to make the scripts executable
``` bash
chmod +x run_data.sh check_example.sh
```

### Running the Example
``` bash
./check_example.sh
```
This script runs the cacheSim executable on the input from example.in and compares it to example.out.
The result will either be a message saying the files match, or the differences between the two.

### Running Other Inputs
``` bash
./run_data.sh <filename-in-/data>
```
This script runs the cacheSim executable on the input from the given file argument.
Note, this file must be in the /data directory.
The three files used in question 1 of the written component are available to test.

# Assumptipons
This project was developed on a mac and is intended to run in a Unix-like environment.

The project requires the following tools:
- g++ with C++17 support
- make
- bash

The cacheSim.cpp program also expects the text in the input files to match 
the format specified in the assignment.
