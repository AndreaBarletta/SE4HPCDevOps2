#!/bin/bash
#SBATCH --job-name=matrix_multiplication
#SBATCH --output=matrix_multiplication_output.txt
#SBATCH --error=matrix_multiplication_error.txt
#SBATCH --ntasks=2  # Adjust the number of tasks based on your MPI configuration
#SBATCH --time=01:00:00  # Adjust the time limit as needed
#SBATCH --partition=your_partition  # Replace with the appropriate partition for your job


# add job