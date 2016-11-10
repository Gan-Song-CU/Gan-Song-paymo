#ifndef READER_H
#define READER_H

#include<fstream>
#include<string>
#include<vector>

using namespace std;

class reader{
private:
	vector<size_t> position;
public:
	const char* path;
	string T;
	ifstream input;
	bool ifend;

	reader(const char* path_) : path(path_) { ifend = false; };


	void load() { input.open(path); }

	void getoff_hearder(){ getline(input, T); }

	string& readline(){ getline(input, T); return T; }
	
	void read_id(int& x, int & y, double &z);


};



void reader::read_id( int& x, int & y , double& z){
	if (T.size() == 0){
		ifend = true;
		return;
	}
	position.push_back ( T.find(", "));
	position.push_back(  T.find(", ", position.back() + 1, 2) );
	position.push_back(  T.find(", ", position.back() + 1, 2) );
	position.push_back(  T.find(", ", position.back() + 1, 2) );

	x = stoi(T.substr(position[0] + 2, position[1] - position[0] - 2));
	y = stoi(T.substr(position[1] + 2, position[2] - position[1] - 2));
	z = stod(T.substr(position[2] + 2, position[3] - position[2] - 2));

	position.clear();

}
















#endif