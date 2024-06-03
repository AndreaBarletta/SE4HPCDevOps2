#!/bin/bash
#SBATCH --job-name=test_job      # Job name
#SBATCH --output=output.txt      # Standard output and error log
#SBATCH --error=error.txt        # Error log
#SBATCH --time=00:01:00          # Wall time limit in HH:MM:SS
#SBATCH --ntasks=2               # Number of tasks (processes)
#SBATCH --cpus-per-task=1        # Number of CPU cores per task
#SBATCH --mem=1GB                # Memory per node

# Define the number of MPI processes
NUM_PROCESSES=2

# Define the path to the Singularity Image File
SIF_FILE="container.sif"

# Bind-mount the current directory to /mnt inside the container
BIND_PATH=$(pwd)

# Define main file path within the container
MAIN_PATH="/usr/local/SE4HPCDevOps2/build"

# Run
singularity exec --bind /scratch_local:/scratch_local $SIF_FILE mpirun -np $NUM_PROCESSES -wdir $MAIN_PATH main > ~/output.txt 2> ~/error.txt



