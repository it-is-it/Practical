import cv2
import numpy as np

threshold_matrix = np.array([
    [0, 128],
    [192, 64]
])


def to_grayscale(image):
    height, width, _ = image.shape
    grayscale_image = [[0] * width for _ in range(height)]
    for i in range(height):
        for j in range(width):
            r, g, b = int(image[i, j][0]), int(
                image[i, j][1]), int(image[i, j][2])
            grayscale_value = (r + g + b) // 3
            grayscale_image[i][j] = grayscale_value
    return grayscale_image


def apply_dithering(grayscale_image, threshold_matrix):
    height = len(grayscale_image)
    width = len(grayscale_image[0])
    matrix_size = threshold_matrix.shape[0]
    dithered_image = np.zeros((height, width), dtype=np.uint8)
    for i in range(height):
        for j in range(width):
            threshold = threshold_matrix[i % matrix_size, j % matrix_size]
            dithered_image[i,
                           j] = 255 if grayscale_image[i][j] > threshold else 0
    return dithered_image


image = cv2.imread('lenna.jpg')

if image is None:
    print("Error: Image not loaded correctly.")
    exit()

grayscale_image = to_grayscale(image)

dithered_image = apply_dithering(grayscale_image, threshold_matrix)

cv2.imshow("Dithered Image", dithered_image)

cv2.imwrite('dithered_lenna.jpg', dithered_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
