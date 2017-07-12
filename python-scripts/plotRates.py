from pylab import *
import numpy as np
from matplotlib import pyplot

width = 0.35
fig, ax = pyplot.subplots()

global_gidoffset = 4000
graph_title = input("What title should I place at the top of the plot? ")
file_title = input("What should I name the file (omit extension)? ")
sim_time = input("Enter sim time (1=1000msec, etc.): ")
sim_time = float(sim_time)

def plotMPTPSpikeRates(mptp_file):
    """Takes mptp spikes file as input, processes data, and plots spike rates"""

    # Process mptp_file data first and plot
    data = loadtxt(mptp_file, unpack=True)
    data = data.T

    # Change these numbers to modify the number of cells processed.
    # They change based on the values of numSTN etc. in pPARrun.txt
    stn = np.array([row for row in data if 0 <= (row[1]-global_gidoffset) < 10])
    gpe = np.array([row for row in data if 10 <= (row[1]-global_gidoffset) < 40])
    gpi = np.array([row for row in data if 40 <= (row[1]-global_gidoffset) < 50])
    striatum = np.array([row for row in data if 50 <= (row[1]-global_gidoffset) < 60])

    stn_spike_rate = float(len(stn))/10/sim_time
    gpe_spike_rate = float(len(gpe))/30/sim_time
    gpi_spike_rate = float(len(gpi))/10/sim_time
    striatum_spike_rate = float(len(striatum))/10/sim_time

    stn_bar = ax.bar(1, stn_spike_rate, width, color='white', edgecolor='black')
    gpe_bar = ax.bar(3, gpe_spike_rate, width, color='white', edgecolor='black')
    gpi_bar = ax.bar(5, gpi_spike_rate, width, color='white', edgecolor='black')
    str_bar = ax.bar(7, striatum_spike_rate, width, color='white', edgecolor='black')

def plotSTNDBSSpikeRates(stn_dbs_file):
    "Takes stn_dbs spikes file as input, processes data, and plots spike rates"

    # plotMPTPSpikeRates('mptp-spikes.txt')

    data = loadtxt(stn_dbs_file, unpack=True)
    data = data.T

    stn = np.array([row for row in data if 0 <= row[1] < 100])
    gpe = np.array([row for row in data if 100 <= row[1] < 400])
    gpi = np.array([row for row in data if 400 <= row[1] < 500])

    stn_with_dbs = np.array([row for row in stn if 2500 <= row[0] <= 5000])
    gpe_with_dbs = np.array([row for row in gpe if 2500 <= row[0] <= 5000])
    gpi_with_dbs = np.array([row for row in gpi if 2500 <= row[0] <= 5000])

    stn_spike_rate = float(len(stn_with_dbs))/100/2.5
    gpe_spike_rate = float(len(gpe_with_dbs))/300/2.5
    gpi_spike_rate = float(len(gpi_with_dbs))/100/2.5

    stn_bar = ax.bar(1 + width, stn_spike_rate, width, color='gray', edgecolor='black')
    gpe_bar = ax.bar(3 + width, gpe_spike_rate, width, color='gray', edgecolor='black')
    gpi_bar = ax.bar(5 + width, gpi_spike_rate, width, color='gray', edgecolor='black')
    ax.set_xticks([1 + width, 3 + width, 5 + width])
    ax.set_xticklabels(('STN', 'GPe', 'GPi'))
    ax.set_ylabel('Spike rate (Hz)')
    ax.set_title('Spike Rates')
    pyplot.show()


def plotNormalSpikeRates(normal_file):
    "Takes normal_spikes file as input, processes data, and plots spike rates"

    plotMPTPSpikeRates('mptp-spikes.txt')

    data = loadtxt(normal_file, unpack=True)
    data = data.T

    stn = np.array([row for row in data if 0 <= (row[1]-global_gidoffset) < 10])
    gpe = np.array([row for row in data if 10 <= (row[1]-global_gidoffset) < 40])
    gpi = np.array([row for row in data if 40 <= (row[1]-global_gidoffset) < 50])
    striatum = np.array([row for row in data if 50 <= (row[1]-global_gidoffset) < 60])

    stn_spike_rate = float(len(stn))/10/sim_time
    gpe_spike_rate = float(len(gpe))/30/sim_time
    gpi_spike_rate = float(len(gpi))/10/sim_time
    striatum_spike_rate = float(len(striatum))/10/sim_time

    stn_bar = ax.bar(1 + width, stn_spike_rate, width, color='gray', edgecolor='black')
    gpe_bar = ax.bar(3 + width, gpe_spike_rate, width, color='gray', edgecolor='black')
    gpi_bar = ax.bar(5 + width, gpi_spike_rate, width, color='gray', edgecolor='black')
    str_bar = ax.bar(7 + width, striatum_spike_rate, width, color='gray', edgecolor='black')
    ax.set_xticks([1 + width/2, 3 + width/2, 5 + width/2, 7 + width/2])
    ax.set_xticklabels(('STN', 'GPe', 'GPi', 'Str'))
    ax.set_ylabel('Spike rate (Hz)')
    ax.set_title(graph_title)
    savefig(file_title + '.png', dpi=700)


plotNormalSpikeRates('normal-spikes.txt')
