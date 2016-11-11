//header guard at start of header file
#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>

using namespace std;

class tree
{
public:
	node* inroot;
	string insert_type;

	tree(node* _inroot) : inroot(_inroot), insert_type("not define") {};
	void insert(const int, const int, const double, string );
	set<int>* search_fri(int) ;
	double search_max_trans(int);
	void output_balance(ofstream* );



	~tree() { delete inroot; }

private:
	void insert_take(const int, const int, const double, node* &);
	set<int>* search_fri_take(int, node*);
	double search_max_trans_take(int, node*);
	


	int bsheight(node*&);
	node* srl(node* &);
	node* drl(node* &);
	node* srr(node* &);
	node* drr(node* &);
	

};



#endif