#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<vector>

#define PATH "gpt.img"
using namespace std;

int getFileSize()
{
	FILE * fp;
	int size = 0;
	if (fp = fopen(PATH, "r"))
	{
		fseek(fp, 0, SEEK_END);//SEEK_END ：end of file
		size = ftell(fp);
		fclose(fp);
		return size;
	}
}

void scanFile()
{
	unsigned char buf[512 * 16];	//存放读取的数据
	string partition[60];	//存放分区名

	ifstream fin;
	fin.open("meizufqb.img", ios::binary | ios::in);
	fin.read((char*)buf, 512 * 16);

	//解析分区名
	for (int i = 0; i < 60; i++)
	{
		for (int j = 56 + (128 * i); j <= 79 + (128 * i); j++)
		{
			string partName(1, buf[j]);
			partition[i] = partition[i] + partName;

		}
			cout << setw(3) << i << ": " << partition[i] << endl;
	}



}

void print()
{
	system("color 3e"); //调整界面配色为蓝黄
	cout << "**********高通9008为您服务**********" << endl;
	cout << "-->1 进入9008模式" << endl;
	cout << "-->2 刷入引导文件" << endl;
	cout << "-->3 选择芯片格式(默认emmc)" << endl;
	cout << "-->4 回读GPT分区" << endl;
	cout << "-->5 选择回读分区名并开始回读" << endl;
	cout << "-->6 选择写入分区名并开始写入" << endl;
	//cout << "7 进入9008模式" << endl;
	//cout << "8 进入9008模式" << endl;
	cout << "-->0 退出" << endl;

}

void chooseFun()
{
	int ch;
	cout << "-->";
	cin >> ch;
	switch (ch)
	{
	case 1:
		cout << "等待三秒，手机进入9008模式……"<<endl;
		//---进入CMD，运行命令 adb reboot edl
		system("adb devices");
		system("adb reboot edl");
		//-----------------------------------
		print();
		chooseFun();
		break;
	case 2:
		cout << "开始刷入引导文件……" << endl;
		system("QSaharaServer.exe -s 13:prog_emmc_firehose_8936.mbn -p \\.\com21");
		print();
		chooseFun();
		break;
	case 4:
		cout << "开始回读分区……" << endl;
		scanFile();
		print();
		chooseFun();
		break;
	case 0:
		exit(0);
		break;
	default:
		break;
	}
}


int main()
{
	print();
	chooseFun();
	system("pause");
}