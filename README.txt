McCall-BGnet README

See Traub/README or nrntraub/README for a Traub model roadmap.

Some important information so far:
traub_cells: A list containing 356 cells objects with corresponding GIDs 0-355.
pnm.nclist: A list containing every single NetCon between the Traub cells.

To make the BGnet model compatible with the above items, do two things:
1) In BGnet, rename the cells list. Call it hahn_cells. Create some kind of GID
   offset for these cells, perhaps starting at 400. Or 4000, since the full
   Traub model contains 3560 cells.
2) Find out whether the BGnet model uses pnm.nclist at all, to access NetCons
   or for some other reason. If it does, figure out a workaround for this. At
   the moment, I believe the McCall-BGnet model is set up to use a generic
   nclist instead of pnm.nclist, because I used ParallelContext instead of
   ParallelNetManager. Don't forget that in Traub, pc is actually pnm.pc!

---
June 30th
init.hoc file creates Traub cells and connections, and BGnet cells and connections.
Correct stimuli are applied to Traub cells and connections, and spikes are
recorded to file out%d.dat. BGnet model doesn't seem to run, doesn't print out
a spike file. Try running BGnet first to see if model runs, with Traub running
second.

---
July 3rd
If all of the Traub model code is commented out in init.hoc, the BGnet code
produces the correct results. So it looks like the Traub code is somehow
affecting the spike rates for the BGnet model. There might be some fudged
connection in the BGnet code, or it might have something to do with the netcons.

---
July 5th
Looks like both the Traub model and BGnet were using nclist to store NetCons,
which could've been causing some problems with cell connections and setting
weights. I've changed the name of nclist in the Traub model to traub_nclist.

---
July 6th
I was wrong. There wasn't any connection between the Traub cells and the Hahn
cells. Rather, the Traub model file manage_setup.hoc was calling a proc named
methods(), which was using pc.spike_compress(). This pc.spike_compress() is what
was changing the spike output. It looks like the only use for this methods()
proc is to speed up the model run time, but I'd rather leave it commented out.
Apparently the models were both spiking correctly, it's just that this methods()
proc changed the data that was written to the spikevec and idvec. With this proc
commented out, both models run just fine and give the correct spike rates.

---
July 7th
Don't use pun(), the proc defined in Traub code. Use stdinit() as usual, as in
the BGnet code, and the init.hoc file will produce both spike files with correct
spike rates. Models are running concurrently with no problems.
