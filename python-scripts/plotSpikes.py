from matplotlib import pyplot
from pylab import *
import numpy as np

marker_size = 0.5
ncell = 50

def plotSpikes(*files):
	"Takes a spikes.txt file as input, then processes and plots the data"
	global_gidoffset = input("Value of global_gidoffset (probs either 0 or 4000): ")
	global_gidoffset = float(global_gidoffset)
	fig, axarr = pyplot.subplots(len(files))
	fig.set_tight_layout(True)
	for f in files:
		data = loadtxt(f, unpack=True)
		data = data.T

		stn = np.array([row for row in data if 0 <= (row[1]-global_gidoffset) < (ncell/5)])
		gpe = np.array([row for row in data if ncell/5 <= (row[1]-global_gidoffset) < (ncell/5 * 4)])
		gpi = np.array([row for row in data if (ncell/5 * 4) <= (row[1]-global_gidoffset) < ncell])
		stria = np.array([row for row in data if ncell <= (row[1]-global_gidoffset) < ncell+10])

		if len(stn) > 0:
			axarr[files.index(f)].plot(stn[:, 0], stn[:, 1], 'r.', markersize=marker_size)

		if len(gpe) > 0:
			axarr[files.index(f)].plot(gpe[:, 0], gpe[:, 1], 'g.', markersize=marker_size)

		if len(gpi) > 0:
			axarr[files.index(f)].plot(gpi[:, 0], gpi[:, 1], 'b.', markersize=marker_size)

		if len(stria) > 0:
			axarr[files.index(f)].plot(stria[:, 0], stria[:, 1], 'y.', markersize=marker_size)

		axarr[files.index(f)].set_title(f)
		axarr[files.index(f)].tick_params(labelsize=4)

	savefig('spike-raster.png', dpi=500)

plotSpikes("normal-spikes.txt", "mptp-spikes.txt")
