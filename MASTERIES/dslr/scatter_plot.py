import sys
import matplotlib.pyplot as plot
from describe import describe, get_data
import numpy as np


def plot_scatter(data):
	feature1_greater = data[data[:,4] > data[:,2]]
	feature2_greater = data[data[:,4] <= data[:,2]]
	plot.figure(figsize=(10, 8))
	plot.scatter(feature1_greater[:,4], feature1_greater[:,2], c='red', label='Astronomy')
	plot.scatter(feature2_greater[:,4], feature2_greater[:,2], c='blue', label='Defense Against the Dark Arts')
	plot.xlabel('Astronomy')
	plot.ylabel('Defense Against the Dark Arts')
	plot.title('Scatter Plot')
	plot.legend(loc='upper right')
	plot.show()

if __name__ == '__main__':
	filename = "./datasets/dataset_train.csv"
	all_data, desc_data, header = get_data(filename)
	header = header[1:]
	num_columns, num_rows, means, std_devs, mins, maxs, p25, p50, p75 = describe(desc_data)
	plot_scatter(desc_data)
