#ifndef SET_COMPARE_H
#define SET_COMPARE_H
#include"tree.h"
#include<set>


using namespace std;

class set_compare
{
public:
	bool comp_1_ord(set<int>*, int) ; 
	bool comp_2_ord(set<int>*, set<int>*);
	bool comp_4_ord(set<int>*, set<int>*,  tree & );
};





#endif