//header guard at start of header file
#ifndef NODE_H
#define NODE_H

#include <set>


using namespace std;

class node
{
public:
	int id;
	int height;
	set<int>*  friends = new set<int>;
	double max_trans = 0;
	double balance = 0;

	node* left;
	node* right;

	node(int a) : id(a), left(nullptr), right(nullptr) {};
	node() : left(nullptr), right(nullptr) { };
	~node(){ delete left; delete right; delete friends; };
};

#endif

