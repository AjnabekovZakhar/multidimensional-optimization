#pragma once
#include<vector>
#include"Something.h"
using namespace std;
class Area
{
protected:
	int dim;
public:
	virtual bool inside(vector<double>) = 0;
	const int get_dim();
};

class All_space:public Area {
public:
	All_space(int);
	virtual bool inside(vector<double>) override;
};

class Dom :public Area {
protected:
	vector<double> left;
	vector<double> right;
public:
	Dom(int, vector<double>, vector<double>);
	virtual bool inside(vector<double>) override;
	vector<double> get_random_point();
	Dom cross_dom(vector<double>, double);
};