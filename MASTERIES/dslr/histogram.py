import sys
import matplotlib.pyplot as plot
from describe import get_data


def plot_histogram(courses, data):
	course_index = None
	for course in courses:
		for i, column_name in enumerate(data[0]):
			if column_name == course:
				course_index = i
				break
		if course_index is None:
			print("Course column not found in data.")
			return
		Gfilter = data[:, 0] == 'Gryffindor'
		Hfilter = data[:, 0] == 'Hufflepuff'
		Rfilter = data[:, 0] == 'Ravenclaw'
		Sfilter = data[:, 0] == 'Slytherin'

		Gryffindor = data[Gfilter, course_index]
		Hufflepuff = data[Hfilter, course_index]
		Ravenclaw = data[Rfilter, course_index]
		Slytherin = data[Sfilter, course_index]
		plot.figure(figsize=(10, 8))
		plot.hist(Gryffindor, alpha=0.5, label='Gryffindor')
		plot.hist(Hufflepuff, alpha=0.5, label='Hufflepuff')
		plot.hist(Ravenclaw, alpha=0.5, label='Ravenclaw')
		plot.hist(Slytherin, alpha=0.5, label='Slytherin')
		plot.legend(loc='upper right')
		plot.title(f'Score distribution for {course}')
		plot.xlabel('Score')
		plot.ylabel('Frequency')
		plot.show()

if __name__ == '__main__':


	filename = "./datasets/dataset_train.csv"
	all_data, desc_data, header = get_data(filename)
	header = header[1:]
	all_data = all_data[:, 1:]
	plot_histogram(header, all_data)
	# plot_histogram(sys.argv[1], all_data)

