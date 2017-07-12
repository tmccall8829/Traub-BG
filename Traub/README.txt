NEURON version of Traub et al J Neurophysiol. 2005 Apr;93(4):1829-30.
Single-column thalamocortical network model exhibiting gamma oscillations
sleep spindles, and epileptogenic bursts.

See: http://senselab.med.yale.edu/senselab/modeldb/ShowModel.asp?model=45539

Prepare for running with
nrnivmodl mod

See the comparison of each cell type with the fortran output with
nrngui onecell.hoc

=== Begin Roadmap ===

Model Guide File

This file is meant to be a guide to the complexities of the nrntraub model.
In it I will describe, in as little or as much detail as necessary, each line
of the init.hoc file. This isn't meant to be an exhaustive guide. It is only
meant to serve as a roadmap to use when connecting nrntraub to BGnet. The most
important information is the different descriptions of each load_file or
localloadfile command and what that loaded file contains.

Note that the defalt run state for this model, at the moment, is with
all of the default variables and with -mpi passed to nrniv. So the model
will run in parallel with use_load_balance = 0 and the other default
variables.
---

File: Init.hoc
xopen hoc/defvar.hoc
    - contains default_var.hoc, lines 16-38 in init.hoc
    - localloadfile manage_setup.hoc
        - load nrngui (loads some necessary libraries, even if we don't use the
        gui)
        - localloadfile fortmap.hoc
            - Creates vectors type_vinit and vgaba. These vectors contain the
            vinit values for each cell type and the vgaba values for each cell
            type, respectively.
        - localloadfile hoc/parlib.hoc
            - load neuron hoc files (netparmpi, binfo, loadbal)
            - localloadfile lbcreate.hoc (for load balancing)
                - load_balanced_create proc: create cells and set gids based on
                load balancing config, but ONLY IF LOAD_BALANCE_PHASE > 0.
                - By default, load_balance_phase = 0 so no load balancing. I'll
                leave this for now, since it'll be easier to connect the cells
                without the load balance cell configuration.
            - localloadfile mscreate.hoc
            - Again, only important for load balancing. From now on I'm not
            going to go in-depth on these files.
            - Create new instance of the ParallelNetManager class, which
            they name pnm and then set to pc = pnm.pc (as a shortcut)
            - base_gid() and thishost_gid() return gids
            - If load_balance_phase = 0, which it currently does, most of
            this stuff isn't used. They just use gid_distribute() which uses
            pnm.round_robin()
            - This entire file is essentially proc definitions. I'll talk about
            what these do if/when they're called.
        - localloadfile finit this helps to manage the setup and
        initialization of the different cell voltages
        - localloadfile hoc/traubcon.hoc
            - This is code to use if use_traubexact = 1. By default,
            use_traubexact = 0 so this code isn't called, only loaded.
        - localloadfile cell_templates loads the cell templates in the
        cells folder.
        - localloadfile net/network_specification_interface
            - Most importantly, the cells list is created here.
            - Also important are the cell_append and nc_append functions
            defined here, which append cells to certain positions in the
            cells list and append netcons to nclist, respectively.
            - Note that these are only defined here and called elsewhere,
            but they'll likely be useful when connecting BGnet to nrntraub.
            - This file also contains functions that are used to set up
            connections between the cells and to insert constant current
            injections.
        - serial=0, so (!serial)=1 and therefore hoc/parlib2.hoc is loaded.
        - localloadfile hoc/parlib2.hoc
            - Load balance functions targetcomp_exists and target_exists
            - par_netstim_create() creates a list of 14 PulseSyn objects
            - Also contains functions to create more netcons and current
            injections, so I believe that this file redefines the functions
            nc_append etc. from network_specification_interface.hoc when the
            model is run in parallel.
        - localloadfile serial_or_par_wrapper.hoc
            - All this file does is define two functions, both of which just
            return pc.gid_exists($1) or pc.gid2cell($1), respectively, unless
            the model is run in serial. Which it isn't.
        - localloadfile groucho.hoc. This is the big daddy. ~11,000 lines in
        this file.
            - Line 2681 is where the important cell creation stuff starts. When
            the model is run, this code starts printing out "creating x abc cells",
            etc.
            - Much of this file is variable definitions and huge chunks of
            commented code. Seriously, like thousands and thousands of lines of
            comments and variable definitions.
            - It also constructs the synaptic compartment maps, i.e. maps of
            the connections between the compartments of the various cells. The
            file then creates these synaptic connections and then creates
            netstims for the various cell types.
            - All of this is super complicated, and will need to be revisited
            when I start attempting to connect these cells to the BGnet cells.
        - Finally, get the spikes, create a histogram, and finish setup. Print
        the setup time.
    - Define some global variables like tstop, dt, etc.
    - Call prun(), which is defined in parlib.hoc and runs pnm.psolve(tstop)
    - Compute the endtime, write the spikes to a file (ending in .dat), print
    the histogram, print the spike stats info, and finally print the endtime.
