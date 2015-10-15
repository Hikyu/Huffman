#ifndef TREENODE_H
#define TREENODE_H
#include<iostream>
class TreeNode
{
public:
	int info;
	char data;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int m=0,char n=' ',TreeNode* a=NULL ,TreeNode* b=NULL,TreeNode* c=NULL)
	{
		info = m;
		data - n;
		left = a;
		right = b;
		parent=c;
	}
};
#endif