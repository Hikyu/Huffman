#ifndef SORT_H
#define SORT_H
#include "TreeNode.h"
#include <list>
#include <algorithm>
using namespace std;
class Sort
{
	list<TreeNode*> ilist;
public:
	void insert(TreeNode *p)
	{
		ilist.push_back(p);
		stable_sort(ilist.begin(), ilist.end(),isshort);
	}
	static bool isshort(TreeNode *x, TreeNode *y);
	TreeNode* pop()
	{
		TreeNode *q = ilist.front();
		ilist.pop_front();
		return q;
	}
};
bool Sort::isshort(TreeNode *x, TreeNode *y)
{
	return x->info < y->info;
}
#endif