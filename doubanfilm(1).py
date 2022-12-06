# 拿到页面源代码
# 编写正则，提取页面数据
# 保存数据

import requests
import re

# csv文件：数据与数据间用逗号隔开，方便进行数据处理
fp = open("top250.text", mode="w", encoding='utf-8')

# url = "https://www.jjwxc.net/topten.php?orderstr=3&t=1"
for num in range(0, 250, 25):
    url = "https://www.jjwxc.net/topten.php?orderstr=3&t=1"
    # 进行反爬处理
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/101.0.4951.67 Safari/537.36"
    }
    resp = requests.get(url, headers=headers)

    # 解决乱码问题
    resp.encoding = "utf-8"
    pageSource = resp.text
    print(pageSource)

    # 编写正则表达式
    # re.S可以让正则中的.匹配换行符
    # 进行正则匹配
    for i in (0,10):
        obj = re.compile(r'target=\"_blank\"\nhref=\"(?P<filename>.*?)\"',
                         r'target=\"_blank\"\nhref=\"(?P<filename>.*?)\"',re.S)
        result = obj.finditer(pageSource)
        filename = result[0].group("filename")


        print("名称:" + filename)
        fp.write(f"{filename},\n")

fp.close()

