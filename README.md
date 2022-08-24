# GuessUtf8
 Guess code is Utf8 or GBK

 猜字符编码,实用有效

 ##原理

 抽取自libchardet,但是一般中文编码只需要猜是gbk还是utf8,所以简化了一下:gbk是固定的双字节编码,utf8是变长的,判断字符是否在gbk的常用字符里(现为前1024个),如果没有则继续,如果都不在常用字频里则判断为utf8

字频表根据地理信息poi点进行的优化,不一定适合所有情况,如果需要可以自行修改字频表,修改方式:

1. 根据资料排出字频,最常用设置为0,依次往后排列

2. 根据gbk编码顺序,将字符的字频序号填入数组中即可,gbk中的字符序号计算方式如下:
   ``` cpp
   int order = 94 * (current - (unsigned char)0xb0) + (next - (unsigned char)0xa1);
   ```

   
