#!/bin/bash
#SBATCH --job-name=julexe
#SBATCH --output=result.txt
#SBATCH --partition=nu
#SBATCH --ntasks=1
#SBATCH --time=00:07:00
#SBATCH --mail-user=ei.duranvargas@gmail.com
#SBATCH --mail-type=END,FAIL

module load gcc/7.2.0

srun ./julexe