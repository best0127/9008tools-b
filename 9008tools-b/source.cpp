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
		fseek(fp, 0, SEEK_END);//SEEK_END ��end of file
		size = ftell(fp);
		fclose(fp);
		return size;
	}
}

void scanFile()
{
	unsigned char buf[512 * 16];	//��Ŷ�ȡ������
	string partition[60];	//��ŷ�����

	ifstream fin;
	fin.open("meizufqb.img", ios::binary | ios::in);
	fin.read((char*)buf, 512 * 16);

	//����������
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
	system("color 3e"); //����������ɫΪ����
	cout << "**********��ͨ9008Ϊ������**********" << endl;
	cout << "-->1 ����9008ģʽ" << endl;
	cout << "-->2 ˢ�������ļ�" << endl;
	cout << "-->3 ѡ��оƬ��ʽ(Ĭ��emmc)" << endl;
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
	case 2:
		cout << "��ʼˢ�������ļ�����" << endl;
		system("QSaharaServer.exe -s 13:prog_emmc_firehose_8936.mbn -p \\.\com21");
		print();
		chooseFun();
		break;
	case 4:
		cout << "��ʼ�ض���������" << endl;
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