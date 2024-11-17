import cv2
import numpy as np

image = cv2.imread('lenna.jpg')
if image is None:
    print("Error: Image not found. Ensure 'lenna.jpg' is in the working directory.")
    exit()

cropped_image = image[100:600, 100:600]
cv2.imshow("Cropped Image", cropped_image)
cv2.waitKey(0)  # Wait until a key is pressed
cv2.destroyAllWindows()