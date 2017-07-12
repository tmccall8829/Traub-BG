#!/bin/bash
#SBATCH --job-name="Neuron_parallel"
#SBATCH --time=12:00:00
#SBATCH --nodes=1
#SBATCH -n 12
#SBATCH --mem=15gb
##SBATCH --output=test.o%j

module unload intel/13.0
module load intel/2015
module load neuron

cp ../nrntraub $PFSDIR

cd $PFSDIR/nrntraub
NPROCS=$SLURM_NPROCS
mpiexec -n $NPROCS `which nrniv` -mpi init.hoc

cp -ru * $SLURM_SUBMIT_DIR
