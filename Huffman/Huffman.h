#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "TreeNode.h"
#include <map>
#include <utility>
#include<sstream>
#include<stack>
#include "Sort.h"
using namespace std;
class Huffman
{
	TreeNode *root;
	map<char, TreeNode*> leaf;//存放叶子节点的rongqi
	void MergeTree(TreeNode* l,TreeNode* r,TreeNode* p)
	{
		p->left = l;
		p->right = r;
		p->data = ' ';
		p->info = l->info + r->info;
		l->parent = p;
		r->parent = p;
	}
public:
	Huffman(map<char,int> a)
	{
		//////////////////////建树
		Sort m;
		int n = a.size();
		TreeNode* p, *l, *r;
		TreeNode* list = new TreeNode[n];
		map<char, int>::iterator it = a.begin();
		for (int i = 0; i != n; ++i)
		{
			list[i].data = it->first;
			list[i].info = it->second;
			list[i].parent=list[i].left = list[i].right = NULL;
			m.insert(list+i);
			pair<char, TreeNode*> k(it->first,list+i);
			leaf.insert(k);//将叶子节点指针存入map，方便编码译码
			++it;
		}
		for (int i = 0; i < n - 1; ++i)
		{
			p = new TreeNode;
			l = m.pop();
			r = m.pop();
			MergeTree(l, r, p);
			m.insert(p);
			root = p;
		}
	}
	void encode(string file,string file1)//编码
	{
		map<char, TreeNode*>::iterator it;
		ifstream in(file.c_str(), ifstream::in);
		ofstream out(file1.c_str(), ifstream::out);
		string word;
		while (getline(in, word))//读入行
		{
			istringstream line(word);
			string character;
			while (line >> character)//读入单词
			{
				for (int i = 0; i != character.size(); ++i)//读入字母
				{
					it = leaf.find(character[i]);
					findfather(it->second, out);
				}
				out << " ";
			}
			out << endl;
		}
	}
	void findfather(TreeNode *p,ofstream& out)//从叶子节点向上追溯，进行字母编码
	{
		TreeNode* q = p;
		stack<int> astack;
		while (q->parent != NULL)
		{
			q = q->parent;
			if (q->left == p)
				astack.push(0);
			else
				astack.push(1);
			p = p->parent;
		}
		while (!astack.empty())
		{
			out << astack.top();
			astack.pop();
		}
	}
	void decode(string file, string file1)//译码
	{
		ifstream in(file.c_str(), ifstream::in);
		ofstream out(file1.c_str(), ifstream::out);
		string word;
		while (getline(in,word))//读入行
		{
			istringstream line(word);
			string character;
			while (line >> character)//读入单词
			{
				TreeNode* p = root;
				for (int i = 0; i != character.size(); ++i)//读入数字
				{
					if (character[i] == '0')
						p = p->left;
					else
						p = p->right;
					if (p->data!= ' ')
					{
						out << p->data;
						p = root;
					}
				}
				out << " ";
			}
			out << endl;
		}
	}
};
#endif