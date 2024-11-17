import cv2
import os
image = cv2.imread('lenna.jpg')
cv2.imwrite('lenna.png', image)
cv2.imwrite('lenna.tif', image)

def get_uncompressed_size(image):
    height, width, channels = image.shape
    return (height * width * channels) / 1024

def get_compressed_size(file_path):
    return os.path.getsize(file_path) / 1024

uncompressed_jpg_size = get_uncompressed_size(image)
compressed_jpg_size = get_compressed_size('lenna.jpg')
compressed_png_size = get_compressed_size('lenna.png')
compressed_tif_size = get_compressed_size('lenna.tif')

print(f"Uncompressed JPG size: {uncompressed_jpg_size:.2f} KB")
print(f"Compressed JPG size: {compressed_jpg_size:.2f} KB")
print(f"Compressed PNG size: {compressed_png_size:.2f} KB")
print(f"Compressed TIFF size: {compressed_tif_size:.2f} KB")