#pragma once
#include<vector>
#include"sup_stop.h"
using namespace std;

class Stop_crit
{

public:
	virtual bool check(sup_stop*) = 0;
};

class Stop_crit_count:public Stop_crit
{
protected:
	int count = 0;
	int max=100;
public:
	virtual bool check(sup_stop*) override;
	Stop_crit_count(int);
	void set_max(int);
	const int get_count();
	void reset_count();
};

class Stop_crit_Newton_dif :public Stop_crit_count {
protected:
	double epsi;
	public:
		virtual bool check(sup_stop*) override;
		Stop_crit_Newton_dif(int,double);
};