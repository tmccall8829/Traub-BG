from matplotlib import pyplot
from pylab import *
import numpy as np

marker_size = 0.5

def plotSpikes(in_file):
	data = loadtxt(in_file, unpack=True)
	data = data.T

	pyplot.plot(data[:, 0], data[:, 1], 'b.', markersize=marker_size)
	pyplot.ylim([156, 256])

	savefig(in_file[:len(in_file)-4] + '.png', dpi=500)
