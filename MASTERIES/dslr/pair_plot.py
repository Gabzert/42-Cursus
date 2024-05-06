import matplotlib.pyplot as plot
from describe import get_data
import seaborn as sns
import pandas as pd


def plot_pair(data):
	# plot.figure(figsize=(10, 8))
	data_df = pd.DataFrame(data, columns=data[0])
	data_df = data_df.drop(0)
	data_df = data_df.set_index(data_df.columns[0])

	if data_df.empty:
		print("DataFrame is empty. Nothing to plot.")
		return
	data_df = data_df.drop(['First Name', 'Last Name', 'Birthday', 'Best Hand'], axis=1)
	if data_df.shape[1] == 0:
		print("No columns remaining after dropping unnecessary columns. Cannot plot.")
		return
	numeric_cols = ['Arithmancy', 'Astronomy', 'Herbology', 'Defense Against the Dark Arts', 
					'Divination', 'Muggle Studies', 'Ancient Runes', 'History of Magic', 
					'Transfiguration', 'Potions', 'Care of Magical Creatures', 'Charms', 'Flying']
	for col in numeric_cols:
		data_df[col] = pd.to_numeric(data_df[col], errors='coerce')

	data_df['Hogwarts House'] = pd.Categorical(data_df['Hogwarts House'])
	sns.pairplot(data_df, hue='Hogwarts House', markers = ".", height=1)
	plot.title('Pair Plot')
	plot.legend(loc='upper right')
	plot.show()

if __name__ == '__main__':
	filename = "./datasets/dataset_train.csv"
	all_data = get_data(filename)[0]
	plot_pair(all_data)
