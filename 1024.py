import matplotlib.pylab as plt
from skimage.color import rgb2gray
from skimage.io import imread
import numpy as np
import tensorflow as tf
import cv2
image = imread("D:/桌面/testIMG.jpg")
print(type(image))
plt.imshow(image)
plt.show()

# tf.nn.conv2d(image,[1,1,1,1],[1,1,1,1],"SAME")
# width,height = image.shape

def conv(image,keral_conv):
    n,m = image . shape
    output_image = np . zeros((n,m))
    for i in range(n-3):
        for j in range(m-3):
            temp = 0
            for q in range(3):
                for p in range(3):
                    temp += image[i+q][j+p] * keral_conv[q][p]
            output_image[i][j] = temp
    return output_image

try:
    image = imread(" D:/桌面:/testIMG.jpg ")
    print ( image . shape )
    print ( type ( image ))
    plt.imshow("test",image)
    # plt.waitKey(0)
    # plt.destroyAl1Windows()
    keral_conv =[[1,0,-1][1,0,-1][1,0,-1]]
    output_image = conv ( image , keral_conv)
    plt.imshow(" output ", output_image)
    # plt.waitKey(0)
    # plt.destroyAl1Windows()
    # plt.destroywindow ("output")
except Exception as ex:
    print (ex)
    ex.with_traceback()
