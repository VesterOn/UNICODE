#define _CRT_SECURE_NO_WARNINGS
//#define _UNICODE
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <io.h>//setmode
#include <fcntl.h>//_O_U16TEXT
#include <stdio.h>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <locale>
#include <codecvt>
#include <vector>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	wofstream wfout("text.txt");
	if (wfout.is_open())
	{
		wfout << L"This is c++ not java\n";
		wfout << L"There is my house\n";
	}
	wfout.close();
	int choose;
	cin >> choose;
	switch (choose)
	{
	case 1:
	{
		char plaintxt[] = "This is c++ not java";
		int t = MultiByteToWideChar(CP_ACP, 0, plaintxt, -1, NULL, 0);
		wchar_t* unicodetxt = new wchar_t[t];
		MultiByteToWideChar(CP_ACP, 0, plaintxt, -1, unicodetxt, t);
		wcout << unicodetxt << endl;

	}
		break;
	case 2:
	{
		wchar_t plaintxt[] = L"This is c++ not java";
		int t= WideCharToMultiByte(CP_ACP, 0, plaintxt, -1, NULL, 0,0,0);
		char* unicodetxt = new char[t];
		WideCharToMultiByte(CP_ACP, 0, plaintxt, -1, unicodetxt, t, 0, 0);
		wcout << unicodetxt << endl;

	}
	break;
	case 3:
	{
		wifstream wfin("text.txt");
		wstring wstr;
		if(wfin.is_open())
			while (getline(wfin, wstr))
			wcout << wstr << endl;
		wfin.close();
	}
	case 4:
	{
		vector<wstring> vec;
		wifstream wfin("text.txt");
		wstring wstr;
		if (wfin.is_open())
		{
			while (getline(wfin, wstr))
				vec.push_back(wstr);
		}
		wfin.close();
		if(vec.size()>0)
		{
			size_t size = vec[0].length();
			int max = 0;
			size_t* sizes = new size_t[vec.size()];
			for (int i = 0; i < vec.size(); i++) {
				if (size < vec[i].length()) {
					max = i;
					size = vec[i].length();
				}
				sizes[i] = vec[i].length();
			}
			wcout << "Самая большая сторка: " << vec[max] << endl;
			size_t middle = 0;
			for (int i = 0; i < vec.size(); i++)
				middle += sizes[i];
			cout << "Средняя длина: " << middle / vec.size();
		}
	}
	break;
	}
	return 0;
}

