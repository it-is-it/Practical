import cv2
import numpy as np


def morph_images(image1, image2, t):
    if image1.shape != image2.shape:
        image2 = cv2.resize(image2, (image1.shape[1], image1.shape[0]))
    morphed_image = cv2.addWeighted(image1, 1 - t, image2, t, 0)
    return morphed_image


image_trump = cv2.imread('trump.jpg')
image_lion = cv2.imread('lion.jpg')

morphed_image = morph_images(image_trump, image_lion, t=0.5)

cv2.imwrite('morphed_image.png', morphed_image)

cv2.imshow("Morphed Image", morphed_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
