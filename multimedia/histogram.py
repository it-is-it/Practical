import cv2
import matplotlib.pyplot as plt

image = cv2.imread('lenna.jpg')
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Increase the figure size to make room for all elements
plt.figure(figsize=(10, 6))
plt.hist(gray_image.ravel(), bins=256, range=(0, 256), color='gray', alpha=0.7)
plt.title('Histogram of lenna.jpg')
plt.xlabel('Pixel Intensity')
plt.ylabel('Frequency')

# Adjust the margins to ensure everything fits
plt.subplots_adjust(left=0.1, right=0.9, top=0.9, bottom=0.1)

plt.savefig('lenna_histogram.png')
plt.close()
