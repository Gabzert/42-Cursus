import numpy as np

def get_data(filename):
	all_data = np.genfromtxt(filename, delimiter=",", dtype=str, encoding=None)
	main_data = np.genfromtxt(filename, delimiter=",", skip_header=1, dtype=str, encoding=None)
	header = np.genfromtxt(filename, delimiter=",", dtype=str, max_rows=1)
	header = header[5:]
	main_data = main_data[:, 1:]  # Exclude Index and Hogwarts House
	main_data[main_data == ''] = np.nan
	desc_data = main_data[:, 5:].astype(np.double)
	# print(f"DESC Data: {desc_data}")
	return all_data, desc_data, header


def calculate_percentile(data, percentile):
	sorted_data = sorted(data)
	rank = percentile / 100.0 * (len(data) + 1)
	if rank.is_integer():
		return sorted_data[int(rank) - 1]
	else:
		k = int(rank)
		d = rank - k
		if ( not np.isnan(sorted_data[k - 1]) and  not np.isnan(sorted_data[k])):
			return (1 - d) * sorted_data[k - 1] + d * sorted_data[k]
		else:
			if np.isnan(sorted_data[k - 1]):
				return (1 - d) * sorted_data[k - 2] + d * sorted_data[k]
			elif np.isnan(sorted_data[k]):
				return (1 - d) * sorted_data[k - 1] + d * sorted_data[k + 1]
	print("Error: calculate_percentile")

def describe(data: np.ndarray):
	# Get the number of columns
	num_columns = data.shape[1]

	# Get the number of rows
	num_rows = data.shape[0]

	means = []
	std_devs = []
	mins = []
	maxs = []
	p25 = []
	p50 = []
	p75 = []
	for col in range(num_columns):
		col_data = [data[row][col] for row in range(num_rows)]
		col_sum = np.nansum(col_data)
		col_mean = col_sum / num_rows
		means.append(col_mean)
		squared_diffs = [(data[row][col] - col_mean) ** 2 for row in range(num_rows)]
		# Calculate the variance for the column
		col_variance = np.nansum(squared_diffs) / num_rows
		# Calculate the standard deviation for the column
		col_std_dev = col_variance ** 0.5
		std_devs.append(col_std_dev)
		col_min = col_data[0]
		col_max = col_data[0]
		for row in col_data:
			col_min = row if row < col_min else col_min
			col_max = row if row > col_max else col_max
		mins.append(col_min)
		maxs.append(col_max)
		p25.append(calculate_percentile(col_data, 25))
		p50.append(calculate_percentile(col_data, 50))
		p75.append(calculate_percentile(col_data, 75))

	return num_columns, num_rows, means, std_devs, mins, maxs, p25, p50, p75

# Example usage
if __name__ == '__main__':
	filename = "./datasets/dataset_train.csv"
	all_data, desc_data, header = get_data(filename)
	num_columns, num_rows, means, std_devs, mins, maxs, p25, p50, p75 = describe(desc_data)
	header[0] = ' '
	output = []
	output.append('\t'.join(header))
	column_widths = [max(len(header[i]), len(f"{num_rows:.6f}"), len(f"{means[i]:.6f}"), len(f"{std_devs[i]:.6f}"),
					len(f"{mins[i]:.6f}"), len(f"{p25[i]:.6f}"),
					len(f"{p50[i]:.6f}"), len(f"{p75[i]:.6f}"),
					len(f"{maxs[i]:.6f}")) for i in range(num_columns)]
	count_str = "Count\t" + '\t'.join([f'{num_rows:.6f}' for _ in range(num_columns)])
	output.append(count_str)
	mean_str = "Mean\t" + '\t'.join([f'{means[i]:.6f}' for i in range(num_columns)])
	output.append(mean_str)
	std_dev_str = "Std\t" + '\t'.join([f'{std_devs[i]:.6f}' for i in range(num_columns)])
	output.append(std_dev_str)
	min_str = "Min\t" + '\t'.join([f'{mins[i]:.6f}' for i in range(num_columns)])
	output.append(min_str)
	p25_str = "25%\t" + '\t'.join([f'{p25[i]:.6f}' for i in range(num_columns)])
	output.append(p25_str)
	p50_str = "50%\t" + '\t'.join([f'{p50[i]:.6f}' for i in range(num_columns)])
	output.append(p50_str)
	p75_str = "75%\t" + '\t'.join([f'{p75[i]:.6f}' for i in range(num_columns)])
	output.append(p75_str)
	max_str = "Max\t" + '\t'.join([f'{maxs[i]:.6f}' for i in range(num_columns)])
	output.append(max_str)
	for i in range(len(output)):
		output[i] = '\t'.join([output[i].split('\t')[j].ljust(column_widths[j] + 1) for j in range(num_columns)])

	print('\n'.join(output))

  
