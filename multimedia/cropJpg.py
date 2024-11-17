import cv2
import numpy as np

# Load the image
image = cv2.imread('lenna.jpg')

# Check if the image is loaded correctly
if image is None:
    print("Error: Image not found. Ensure 'lenna.jpg' is in the working directory.")
    exit()

# Crop the image (100:600, 100:600)
cropped_image = image[100:600, 100:600]

# Display the cropped image
cv2.imshow("Cropped Image", cropped_image)

# Save the cropped image to a file
save_path = 'cropped_lenna.jpg'
if cv2.imwrite(save_path, cropped_image):
    print(f"Image saved successfully at {save_path}")
else:
    print("Error saving image.")

# Wait until a key is pressed and then close the window
cv2.waitKey(0)
cv2.destroyAllWindows()
