#!/bin/bash
#SBATCH --job-name=test_job      # Job name
#SBATCH --output=output.txt      # Standard output and error log
#SBATCH --error=error.txt        # Error log
#SBATCH --time=00:01:00          # Wall time limit in HH:MM:SS
#SBATCH --ntasks=2               # Number of tasks (processes)
#SBATCH --cpus-per-task=1        # Number of CPU cores per task
#SBATCH --mem=1GB                # Memory per node

# Print a message
echo "Starting the script"

build.sh