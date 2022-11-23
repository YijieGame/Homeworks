#author:卢一捷
#coding= utf-8
#@version:1.0
#@time:2022.10.20
#@dile:20080104卢一捷 .py
#@software:Pycharm

def one_hot(labels):
    onehot_labels = np.zeros(shape=[len(labels), 10])
    for i in range(len(labels)):
        index = labels[i]
        onehot_labels[i][index] = 1
    return onehot_labels