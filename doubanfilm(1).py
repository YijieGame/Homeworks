# 拿到页面源代码
# 编写正则，提取页面数据
# 保存数据

import requests
import re

# csv文件：数据与数据间用逗号隔开，方便进行数据处理
fp = open("top250.text", mode="w", encoding='utf-8')

# url = "https://movie.douban.com/top250"
for num in range(0, 250, 25):
    url = "https://movie.douban.com/top250?start=num&filter="
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
    obj = re.compile(r'<div class="item">.*?<span class="title">(?P<filename>.*?)</span>'
                     r'.*?<p class="">.*?导演: (?P<director>.*?)&nbsp;.*?<br>'
                     r'(?P<year>.*?)&nbsp;.*?&nbsp;(?P<country>.*?)&nbsp;'
                     r'.*?<span class="rating_num" property="v:average">'
                     r'(?P<score>.*?)</span>.*?<span>(?P<number>.*?)人评价</span>', re.S)

    # 进行正则匹配
    result = obj.finditer(pageSource)
    for item in result:
        filename = item.group("filename")
        director = item.group("director")
        year = item.group("year").strip()  # 去除字符串左右两端的空白
        country = item.group("country")
        score = item.group("score")
        number = item.group("number")
        print("电影名称:" + filename)
        print("导演：" + director)
        print("年代：" + year)
        print("地区：" + country)
        print("豆瓣评分：" + score)
        print("共有" + number + "人为该电影评分\n")
        fp.write(f"{filename},{director},{year},{country},{score},{number}\n")

fp.close()

