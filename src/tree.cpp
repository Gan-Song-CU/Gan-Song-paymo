#include"tree.h"

void tree::output_balance(ofstream* input){

	if (inroot == nullptr){
		return;
	}

	node* temp = inroot;
	stack< node*> contain;
	contain.push(temp);

	while (!contain.empty()){
		temp = contain.top();
		contain.pop();
		(*input) << "id is: " << temp->id << "  current balance:  " << temp->balance << endl;

		if (temp->left != nullptr){
			contain.push(temp->left);
		}

		if (temp->right != nullptr){
			contain.push(temp->right);
		}

	}

	
}



set<int>*  tree::search_fri(int x)
{
	return search_fri_take(x, inroot);
}

set<int>*  tree::search_fri_take(int x, node* root){

	while (root != nullptr){
		if (x == root->id)
		{
			return root->friends;

		}
		else if (x > root->id){
			root = root->right;
		}

		else {
			root = root->left;
		}
	}

	return new set<int>;

//	cout << "can not find the node";

}

double  tree::search_max_trans(int x)
{
	return search_max_trans_take(x, inroot);
}

double  tree::search_max_trans_take(int x, node* root){

	while (root != nullptr){
		if (x == root->id)
		{
			return root->max_trans;

		}
		else if (x > root->id){
			root = root->right;
		}

		else {
			root = root->left;
		}
	}

	return 0.0;

	//	cout << "can not find the node";

}

void tree::insert(const int x, const int y, const double z , string type){
	insert_type = type;
	insert_take(x, y, z, inroot);
}

void tree::insert_take(const int  x, const int y, const double z,  node* & root){

	if (root == nullptr)
	{
		root = new node(x);
		root->id = x;
		root->height = 0;
		root->friends->insert(y);
		root->max_trans = insert_type == "pay" ? max(root->max_trans, z) : root->max_trans;
		root->balance = insert_type == "pay" ? (root->balance - z) : (root->balance + z);


		if (root == nullptr)
		{

			cout << "Out of Space\n" << endl;
		}

		return;
	}

	else
	{
		if (x< root->id)
		{
			insert_take(x, y, z, root->left);

			if ((bsheight(root->left) - bsheight(root->right)) == 2)
			{
				if (x < root->left->id)
				{
					root = srl(root);
				}
				else
				{
					root = drl(root);
				}
			}
		}

		else if (x>root->id)
		{
			insert_take(x, y, z, root->right);
			if ((bsheight(root->right) - bsheight(root->left)) == 2)
			{
				if (x > root->right->id)
				{
					root = srr(root);
				}
				else
				{
					root = drr(root);
				}
			}
		}
		else
		{
			root->friends->insert(y);
			root->max_trans = insert_type == "pay" ? max(root->max_trans, z) : root->max_trans;
			root->balance = insert_type == "pay" ? (root->balance - z) : (root->balance + z);
		//	cout << "id Exists\n" << endl;
		}
	}
	int m, n, d;
	m = bsheight(root->left);
	n = bsheight(root->right);
	d = m> n ? m : n;
	root->height = d + 1;
}

int tree::bsheight(node* & p)
{
	int t;
	if (p == nullptr)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}

node* tree::srl(node* &p1)
{
	node* p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = max(bsheight(p2->left), p1->height) + 1;
	return p2;
}

node* tree::srr(node* &p1)
{
	node* p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = max(p1->height, bsheight(p2->right)) + 1;
	return p2;
}

node* tree::drl(node* &p1)
{
	p1->left = srr(p1->left);
	return srl(p1);
}
node* tree::drr(node* &p1)
{
	p1->right = srl(p1->right);
	return srr(p1);
}
