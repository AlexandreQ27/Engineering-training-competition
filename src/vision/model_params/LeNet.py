import paddle
import paddle.nn.functional as F


class LeNet(paddle.nn.Layer):
    def __init__(self):
        # 继承自LeNet类
        super(LeNet, self).__init__()
        # 二维卷积层，输入为单通道的 28*28 灰度图像，输出为6通道的 28*28 图像， 说明这个地方有6个卷积核进行了操作
        self.conv1 = paddle.nn.Conv2D(in_channels=1, out_channels=6, kernel_size=5, stride=1, padding=2)
        # 最大值池化，池化核为2， 6*28*28 变为 6*14*14
        self.max_pool1 = paddle.nn.MaxPool2D(kernel_size=2, stride=2)
        # 二维卷积层， 输入6通道， 输出16通道， 有16个 6*5*5 的卷积核， 输出尺寸 10*10
        self.conv2 = paddle.nn.Conv2D(in_channels=6, out_channels=16, kernel_size=5, stride=1)
        # 最大值池化， 16*10*10 变为 16*5*5
        self.max_pool2 = paddle.nn.MaxPool2D(kernel_size=2, stride=2)
        # 三个全连接层， 变为向量进行操作
        self.linear1 = paddle.nn.Linear(in_features=16 * 5 * 5, out_features=120)
        self.linear2 = paddle.nn.Linear(in_features=120, out_features=84)
        self.linear3 = paddle.nn.Linear(in_features=84, out_features=10)

    def forward(self, x):
        x = self.conv1(x)
        x = F.relu(x)
        x = self.max_pool1(x)
        x = self.conv2(x)
        x = F.relu(x)
        x = self.max_pool2(x)
        x = paddle.flatten(x, start_axis=1, stop_axis=-1)
        x = self.linear1(x)
        x = F.relu(x)
        x = self.linear2(x)
        x = F.relu(x)
        x = self.linear3(x)
        return x
