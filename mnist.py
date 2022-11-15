
import torch
import torchvision
import numpy as np
from PIL import Image
from matplotlib import pyplot as plt
from torchvision import datasets, transforms
from torch.utils.data import DataLoader, Dataset

train_data = datasets.MNIST(
            root="./data/",
            train=True,
            transform=transforms.ToTensor(),
            download=True)

test_data = datasets.MNIST(
            root="./data/",
            train=False,
            transform=transforms.ToTensor(),
            download=True)

train_data_loader = torch.utils.data.DataLoader(
        dataset=train_data,
        batch_size=64,
        shuffle=True,
        drop_last=True)

test_data_loader = torch.utils.data.DataLoader(
        dataset=test_data,
        batch_size=100,
        shuffle=False,
        drop_last=False)

images, labels = next(iter(train_data_loader))	# images：Tensor(100,1,28,28)、labels：Tensor(64,)

img = torchvision.utils.make_grid(images)	# 把64张图片拼接为1张图片

# pytorch网络输入图像的格式为（C, H, W)，而numpy中的图像的shape为（H,W,C）。故需要变换通道才能有效输出
img = img.numpy().transpose(1, 2, 0)
std = [0.5, 0.5, 0.5]
mean = [0.5, 0.5, 0.5]
img = img * std + mean
print(labels)
plt.imshow(img)
plt.show()

def mnist_net(input_shape):
    model = keras.Sequential()
    model.add(keras.layers.Flatten(input_shape=input_shape))
    model.add(keras.layers.Dense(units=120,activation=tf.nn.relu))
    model.add(keras.layers.Dense(units=10,activation=tf.nn.softmax))
    return model