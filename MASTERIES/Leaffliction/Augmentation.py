import os
import sys
from PIL import Image, ImageOps, ImageEnhance
import numpy as np

def augment_image(image_path):
	try:
		image = Image.open(image_path)
	except Exception as e:
		print(f"Error opening image: {e}")
		return
	
	base_name, ext = os.path.splitext(image_path)
	
	augmentations = {
		'flip': ImageOps.mirror(image),
		'rotate': image.rotate(90),
		'skew': image.transform(image.size, Image.AFFINE, (1, 0.5, 0, 0.5, 1, 0)),
		'contrast': ImageEnhance.Contrast(image).enhance(2),  # Increased contrast
		'illumination': ImageEnhance.Brightness(image).enhance(1.5),  # Increased brightness
		'scale': image.resize((int(image.size[0] * 1.8), int(image.size[1] * 1.8)))  # Scale to 180% of original size
	}
	
	for aug_type, aug_image in augmentations.items():
		new_file_name = f"{base_name}_{aug_type}{ext}"
		aug_image.save(new_file_name)
		print(f"Saved augmented image: {new_file_name}")

if __name__ == "__main__":
	if len(sys.argv) != 2:
		print("Usage: Augmentation.py <image_path>")
		sys.exit(1)

	image_path = sys.argv[1]
	if not os.path.isfile(image_path):
		print("Provided path is not a file.")
		sys.exit(1)

	augment_image(image_path)
