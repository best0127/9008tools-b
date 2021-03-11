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
	int b = buf[34]<<16;
	cout << b;
	system("pause");


}

int main()
{
	scanFile();
	system("pause");
}