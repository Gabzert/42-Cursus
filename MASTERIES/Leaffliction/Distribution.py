import os
import sys
import glob
from collections import Counter
import matplotlib.pyplot as plt
plt.rc('xtick', labelsize=8) 
from PIL import Image

def fetch_images(directory):
	# Fetch all images in the directory and its subdirectories
	image_extensions = ('*.JPG', '*.jpeg', '*.png', '*.bmp', '*.gif')
	images = []
	for ext in image_extensions:
		images.extend(glob.glob(os.path.join(directory, '**', ext), recursive=True))
	return images


def analyze_images(images):
	# Analyze the dataset by counting images in each subdirectory
	plant_types = [os.path.basename(os.path.dirname(image)) for image in images]
	return Counter(plant_types)


def create_charts(data, directory_name):
	# Create pie chart
	plt.figure(figsize=(10, 5))

	plt.subplot(1, 2, 1)
	plt.pie(data.values(), labels=data.keys(), autopct='%1.1f%%', startangle=140)
	plt.title(f'Pie Chart of Plant Types in {directory_name}')

	# Create bar chart
	plt.subplot(1, 2, 2)
	bars = plt.bar(data.keys(), data.values(), width=0.5)
	colors = ['skyblue', 'orange', 'green', 'red', 'purple', 'brown', 'pink', 'gray', 'olive', 'cyan']
	for bar in bars:
		bar.set_color(colors.pop(0))
	plt.xlabel('Plant Types')
	plt.ylabel('Number of Images')
	plt.title(f'Bar Chart of Plant Types in {directory_name}')

	plt.tight_layout()
	plt.show()


#takes as arguments a directory and fetches images in its subdirectories
if __name__ == "__main__":
	if len(sys.argv) != 2:
		print("Usage: python Distribution.py <directory>")
		sys.exit(1)
	directory = sys.argv[1]
	#check if the directory exists
	if not os.path.exists(directory):
		print("The directory does not exist")
		sys.exit(1)
	#check if the directory is a directory
	if not os.path.isdir(directory):
		print("The directory is not a directory")
		sys.exit(1)

	images = fetch_images(directory)
	data = analyze_images(images)
	create_charts(data, directory)
