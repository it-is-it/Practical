import numpy as np
import cv2

random_array = np.random.randint(0, 256, (400, 400), dtype=np.uint8)
cv2.imwrite('random_image.png', random_array)
print("Random image saved as 'random_image.png'")
