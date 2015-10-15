#ifndef SCAN_H
#define SCAN_H
#include <map>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;
class scan
{
public:
	map<char, int> tmp;
	void run(const string a)//扫描
	{
		ifstream in;
		open(a, in);
		string word;
		while (in>>word)
		{
			for (int i = 0; i != word.size(); ++i)
				++tmp[word[i]];
		}
	}
	ifstream& open(const string a,ifstream &in)//打开文件
	{
		in.close();
		in.clear();
		in.open(a.c_str());
		return in;
	}
	map<char, int> re()
	{
		return tmp;
	}
};
#endif