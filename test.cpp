// test1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "guess.h"

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream afile;
	afile.open("1.txt", std::ios::out | std::ios::in);
	char data[50000];
	while (!afile.eof()) {
		afile >> data;
		bool a = isUTF8(data);
		if (a) {
			std::cout << data << std::endl;
		}
	}
}