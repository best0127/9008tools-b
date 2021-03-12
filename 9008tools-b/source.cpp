#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

#define PATH "E:\\workplace\\program\\gpt.img"
using namespace std;

void scanFile()
{
	unsigned char buf[512 * 14];	//存放读取的数据
	string partition[64];

	ifstream fin;
	fin.open(PATH, ios::binary | ios::in);
	fin.read((char*)buf, 512 * 14);

	//解析分区名
	for (int i = 0; i < 40; i++)
	{
		for (int j = 56 + (128 * i); j <= 79 + (128 * i); j++)
		{
			string partName(1, buf[j]);
			partition[i] = partition[i] + partName;
		}
		cout <<setw(4)<< i << ": " << partition[i] << endl;
	}

	//计算分区大小
	//int b = buf[34]<<16;
	int b = buf[42]<<16;
	cout << b << endl;
	system("pause");


}

void print()
{
		cout << "**********高通9008为您服务**********" << endl;
		cout << "-->1 进入9008模式" << endl;
		cout << "-->2 刷入引导文件" << endl;
		cout << "-->3 选择芯片格式(默认UFS)" << endl;
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
	default:
		break;
	}
}


int main()
{
	//scanFile();
	print();
	chooseFun();
	system("pause");
}