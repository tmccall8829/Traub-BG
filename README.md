# Traub-BG README

(See Traub/README or nrntraub/README for a Traub model roadmap.)

## Compiling
This directory, Traub-BG, contains all of the files necessary to run the model. The 
github repo is currently configured (7/15/2017) not to include the directory of 
compiled mod files, x86_64 (or something else, depending on your machine architecture).
So to run the model, you must first compile the mod files. 

To compile the model, ensure that your working directory is Traub-BG and then type:
```
nrnivmodl mod
```

at the command-line prompt. That will compile the mod files -- no other special 
configuration is necessary.


## Running the model

First of all, you will notice that there are files named "mptp.hoc" and "normal.hoc".
These .hoc files are identical, except for the fact that one of them runs the model in
the MPTP state and the other runs the model in the normal state.

You may run the model either in serial mode or in parallel mode. Just note that running
in serial mode will take a very long time, so parallel runs are probably preferred.

To run the model, you have two options: you can either use the shell script named 
"doit.sh" in the scripts directory by typing
```
scripts/doit.sh
```
or you can run the mptp.hoc file and the normal.hoc file separately by typing
```
mpirun -np <x> nrniv -mpi mptp.hoc (or normal.hoc)
```

where x is the number of processes. I have the shell script configured to use 16, but
you can use any number that is appropriate for your machine.

Once you begin running the model, you will get a lot of output describing the setup 
steps. After that you will see a bunch of lines (t=1, t=2, ...t=tstop) showing you the
current t value. When t gets to tstop (set to 1000 in the .hoc files), the model is
done. It will print out the runtime and then exit.


## Analyzing results

The scripts directory contains some python scripts for analyzing the model:
1. plotRates.py (for generating a plot of the spike rates)
2. plotSpikes.py (for generating a raster plot for mptp-spikes & normal-spikes files)
3. modelNotify.py (for sending you a text when the model is done (optional))
4. raster.py (for generating an individual raster plot for the Traub model data)

The scripts are relatively straight-forward. Just keep in mind that they are hard 
coded to use set file names, and if you change the default file names you will also
have to change the scripts. They are currently written to use python 3.6, so if you 
use a different python version (which you likely do, probably 2.7 or something) you 
will need to change the input() calls to raw_input(). 

If you run the model using the doit.sh script, these python scripts will run 
automatically. They'll ask you for the global_gidoffset (which is 4000 here), and the
sim_time (type 1 for 1 second -- that's the default). If you run the mptp.hoc and
normal.hoc files individually, you'll need to run
```
python scripts/<script-name.py>
```

to generate the figures. 

NOTE: Always make sure to run these scripts from the Traub-BG directory. Do not cd 
into these directories, because then the python scripts will not be able to find the
data files (spike files) to analyze.


## Notes on the model layout

The model uses the Traub model (files are located in the Traub directory) as the 
cortical input for the BGnet model (files are distributed throughout the Traub-BG
directory). The Traub cells and connections are created first. The model is currently
set to create 356 Traub cells, which is 1/10th the number of cells used in the Traub
paper. You may use 3560 cells if you like, but the model will take a very long time to
run. Also, I haven't tested the model with 3560 cells yet, so you may get errors. I'd
recommend sticking to using 356 cells. To change to 3560 cells, there is a variable
called "one_tenth_ncell" which is currently set to 1 which sets up 356 cells. Change 
it to 0 to use 3560 cells. Note that the GIDs for the Traub cells will be 0-(ncell-1).
So by default, the Traub cells will have GIDs 0 through 355. With 3560 cells, they 
would be 0 through 3559. The global_gidoffset value is set to 4000 to ensure that the
BGnet cells are created without interfering with the Traub GIDs.

After the Traub cells and connections are created, the BGnet cells and connections are
set up. These cells have GIDs 4000 through 4059. The model currently only creates 60
cells, which is 1/10th (roughly) of the cells used in the Hahn and McIntyre paper (just
like the Traub model). All of the code is set up to use 60 cells -- if you want to 
use 600 cells, you're going to find yourself re-writing a lot of if statements. The
original BGnet model only contained STN, GPe, and GPi cells, so there were 500 (or 50)
cells. I created 10 Striatum cells, so there are now 60 (or 600 w/ full setup) cells.

Check out "parms.txt" to see the number of cells and number of connections
between cells. The tuftIB and tuftRS cells from the Traub model are connected to the
STN and to the Striatum (which is then connected to the GPe and GPi).

If you want to get a text file containing a map of the cell connections, change tstop
in mptp.hoc or normal,hoc to 1 and run "nrniv mptp.hoc" or "nrniv normal.hoc". That'll
generate a file named "model_data.txt" which contains all of the connections, and 
some data on the percentage of randomly selected connections created using ctxProb.

All of the relevant hoc files for the BGnet code are in hahn_hoc, and the Traub files,
as I said above, are in Traub. Don't change the directory structure unless you want to
also re-write the code. The BGnet files have names that are very descriptive of their
function, but if you can't figure out what one of them does just ask me.

That's about it. If you have any questions, don't hesitate to ask me! I am sure you'll
have a bunch of questions that I haven't yet anticipated.
