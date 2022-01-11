#include <iostream>

using namespace std;

struct Branch
{
	struct Branch *right;
	struct Branch *left;
	int type;
	int data;
};

struct TreeStruct
{
	Branch branches[100];
};

int main()
{
	TreeStruct tree;
	tree.branches[0].left = &tree.branches[1];
	tree.branches[1].data = 111;
	cout << (*tree.branches[0].left).data << endl;
	return 0;
}
