#include "set_compare.h"

bool set_compare::comp_1_ord(set<int>* p1, int num){

	if (p1->empty()){
		return false;
	}

	if (*(--p1->end()) < num){
		return false;
	}

	if (*p1->begin() > num){
		return false;
	}

	set<int>::iterator pp1 = p1->begin();
	set<int>::iterator pp11 = p1->end();


	while (pp1 != pp11){
		if (*pp1 == num){
			return true;
		}

		else if (*pp1 > num){
			return false;
		}
		else{
			pp1++;
		}
	}

	return false;


}

bool set_compare::comp_2_ord(set<int>* p1, set<int>* p2){

	if (p1->empty() || p2->empty()){
		return false;
	}

	if (*p1->rbegin()   < *p2->begin()){
		return false;
	}

	if (*p1->begin()   > * p2->rbegin()){
		return false;
	}

	set<int>::iterator pp1 = p1->begin();
	set<int>::iterator pp2 = p2->begin();
	set<int>::iterator pp11 = p1->end();
	set<int>::iterator pp22 = p2->end();

	while (pp1 != pp11 && pp2 != pp22){
		if (*pp1 == *pp2){
			return true;
		}

		else if (*pp1 > *pp2){
			pp2++;
		}
		else{
			pp1++;
		}
	}

	return false;

}



bool set_compare::comp_4_ord(set<int>* fri1, set<int>* fri2, tree& data)
{

	if (fri1->empty() || fri2->empty()){
		return false;
	}

	set<int>::iterator it;
	set<int>::iterator it1;
	set<int>::iterator it2;
	set<int>* fri1_fri;
	set<int>* fri2_fri;


	for (it = fri1->begin(); it != fri1->end(); it++){
		fri1_fri = data.search_fri(*it);

		if (comp_2_ord(fri1_fri, fri2)){
			return true;
		}

	}



	for (it1 = fri1->begin(); it1 != fri1->end(); it1++){
		fri1_fri = data.search_fri(*it1);

		for (it2 = fri2->begin(); it2 != fri2->end(); it2++){
			fri2_fri = data.search_fri(*it2);

			if (comp_2_ord(fri1_fri, fri2_fri)){

				return true;
			}

		}

	}


	if (it1 == fri1->end()){
		return false;
	}


	return false;

}
