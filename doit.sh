#!/bin/bash

# Run the model in MPTP state for 1 second (unless tstop is changed in file)
mpirun -np 16 nrniv -mpi mptp.hoc

sleep 1

# Run the model in normal state for 1 second (unless tstop changed)
mpirun -np 16 nrniv -mpi normal.hoc

sleep 1

python python-scripts/modelNotify.py

python python-scripts/plotSpikes.py

python python-scripts/plotRates.py
