#!/bin/bash

# Define the number of MPI processes
NUM_PROCESSES=2

# Define the output files for stdout and stderr
STDOUT_FILE="output.txt"
STDERR_FILE="error.txt"

# Define the path to the Singularity Image File
SIF_FILE="myimage.sif"

# Run the application within the Singularity container using MPI
singularity exec "$SIF_FILE" mpirun -np $NUM_PROCESSES main > "$STDOUT_FILE" 2> "$STDERR_FILE"