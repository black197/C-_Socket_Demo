# C++ Socket Demo

开发软件：VS2017

## TCP版本
采用**流式套接字(SOCK_STREAM)**。

> SOCK_STREAM表示面向连接的数据传输方式。数据可以准确无误地到达另一台计算机，如果损坏或丢失，可以重新发送，但效率相对较慢。常用的HTTP协议就使用SOCK_STREAM传输数据，因为要确保数据的正确性，否则网页不能正常解析。

参考:[https://blog.csdn.net/xiaoquantouer/article/details/58001960](https://blog.csdn.net/xiaoquantouer/article/details/58001960 "windows环境下用c++实现socket编程")

## UDP版本
采用**数据报套接字(SOCK_DGRAM)**。

> SOCK_DGRAM表示无连接的数据传输方式。计算机只管传输数据，不作数据校验，如果数据在传输中损坏，或者没有到达另一台计算机，是没有办法补救的。也就是说，数据错了就错了，无法重传。因为SOCK_DGRAM所做的校验工作少，所以效率比SOCK_STREAM高。

参考:[https://www.cnblogs.com/findumars/p/5928712.html](https://www.cnblogs.com/findumars/p/5928712.html "C++ Socket UDP \"Hello World!\"")
