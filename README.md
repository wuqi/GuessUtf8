# GuessUtf8
 Guess code is UTF8 or GBK

 猜汉字字符编码是否为UTF8,实用有效

 抽取自libchardet,一般中文编码只需要猜是 GBK还是 UTF8编码,所以仅提取此部分的代码。

## 原理

GBK是固定的双字节编码,UTF8是变长的,先判断字符是否为常用字，选取前三千七百左右，然后判断字符是否在高频字里(现为前1024个),如果没有则继续,如果都不在则判断为UTF8

字频表根据高德地理信息poi数据[^1]进行的优化,不一定适合所有情况,如果需要可以自行修改字频表,修改方式:

1.  根据资料排出字频,最常用设置为0,依次往后排列

2.  根据gbk编码顺序,将字符的字频序号填入数组中即可,gbk中的字符序号计算方式如下:
   ``` cpp
   int order = 94 * (current - (unsigned char)0xb0) + (next - (unsigned char)0xa1);
   ```


[^1] 国家信息中心, 2017, "高德地图兴趣点POI（Point of Interest）数据", https://doi.org/10.18170/DVN/WSXCNM, 北京大学开放研究数据平台, V2 :  [链接](https://opendata.pku.edu.cn/dataset.xhtml?persistentId=doi:10.18170/DVN/WSXCNM&version=2.5)
