#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

#define PATH "E:\\workplace\\program\\gpt.img"
using namespace std;

void scanFile()
{
	unsigned char buf[512 * 14];	//��Ŷ�ȡ������
	string partition[64];

	ifstream fin;
	fin.open(PATH, ios::binary | ios::in);
	fin.read((char*)buf, 512 * 14);

	//����������
	for (int i = 0; i < 40; i++)
	{
		for (int j = 56 + (128 * i); j <= 79 + (128 * i); j++)
		{
			string partName(1, buf[j]);
			partition[i] = partition[i] + partName;
		}
		cout <<setw(4)<< i << ": " << partition[i] << endl;
	}

	//���������С
	//int b = buf[34]<<16;
	int b = buf[42]<<16;
	cout << b << endl;
	system("pause");


}

void print()
{
		cout << "**********��ͨ9008Ϊ������**********" << endl;
		cout << "-->1 ����9008ģʽ" << endl;
		cout << "-->2 ˢ�������ļ�" << endl;
		cout << "-->3 ѡ��оƬ��ʽ(Ĭ��UFS)" << endl;
		cout << "-->4 �ض�GPT����" << endl;
		cout << "-->5 ѡ��ض�����������ʼ�ض�" << endl;
		cout << "-->6 ѡ��д�����������ʼд��" << endl;
		//cout << "7 ����9008ģʽ" << endl;
		//cout << "8 ����9008ģʽ" << endl;
		cout << "-->0 �˳�" << endl;

}

void chooseFun()
{
	int ch;
	cout << "-->";
	cin >> ch;
	switch (ch)
	{
	case 1:
		cout << "�ȴ����룬�ֻ�����9008ģʽ����"<<endl;
		//---����CMD���������� adb reboot edl
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