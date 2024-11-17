import cv2
import numpy as np

def to_grayscale(image):
    height, width, _ = image.shape
    grayscale_image = [[0] * width for _ in range(height)]
    for i in range(height):
        for j in range(width):
            b, g, r = image[i, j]
            grayscale_value = (int(r) + int(g) + int(b)) // 3  # Prevent overflow
            grayscale_image[i][j] = grayscale_value
    return grayscale_image

def to_binary(grayscale_image, threshold=128):
    height = len(grayscale_image)
    width = len(grayscale_image[0])
    binary_image = [[0] * width for _ in range(height)]
    for i in range(height):
        for j in range(width):
            binary_image[i][j] = 255 if grayscale_image[i][j] >= threshold else 0
    return binary_image

# Load the image
image = cv2.imread('C:/Users/ishwo/Desktop/it-is-it/practical/multimedia/lenna.jpg')
if image is None:
    print("Error: Image not found.")
    exit()

# Convert to grayscale and binary
grayscale_image = to_grayscale(image)
binary_image = to_binary(grayscale_image)

# Convert lists to NumPy arrays
grayscale_image_np = np.array(grayscale_image, dtype=np.uint8)
binary_image_np = np.array(binary_image, dtype=np.uint8)

# Save the results as files
cv2.imwrite("grayscale_image.jpg", grayscale_image_np)
cv2.imwrite("binary_image.jpg", binary_image_np)
print("Images saved as 'grayscale_image.jpg' and 'binary_image.jpg'")
