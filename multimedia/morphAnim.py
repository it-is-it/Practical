import cv2
import numpy as np
from PIL import Image


def morph_images(image1, image2, t):
    if image1.shape != image2.shape:
        image2 = cv2.resize(image2, (image1.shape[1], image1.shape[0]))
    morphed_image = cv2.addWeighted(image1, 1 - t, image2, t, 0)
    return morphed_image


image_trump = cv2.imread('trump.jpg')
image_lion = cv2.imread('lion.jpg')

steps = [0, 0.2, 0.4, 0.6, 0.8, 1]
morphed_images = []

for t in steps:
    morphed_image = morph_images(image_trump, image_lion, t)
    morphed_image_rgb = cv2.cvtColor(morphed_image, cv2.COLOR_BGR2RGB)
    pil_image = Image.fromarray(morphed_image_rgb)
    morphed_images.append(pil_image)

morphed_images[0].save('morphed_trump_lion.gif', save_all=True,
                       append_images=morphed_images[1:], optimize=True, duration=500, loop=0)
print("GIF has been saved as 'morphed_trump_lion.gif'")
