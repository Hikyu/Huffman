#include"scan.h"
#include"Huffman.h"
using namespace std;
int main()
{
	string ifile("g:\\yu.txt");
	string ofile("g:\\kai.txt");
	scan a;
	a.run(ifile);//扫描文件，统计字母频率
	Huffman b(a.tmp);//建立霍夫曼树
	b.encode(ifile,ofile);//编码
	b.decode(ofile,"g:\\yukai.txt");
	system("pause");
	return 0;
}