#pragma once
#include"dom.h"
#include"opt_fun.h"
#include"Stop_crit.h"
#include"Something.h"

class Opt_method
{
protected:
	vector<vector<double>> x_n;

	Area* area=nullptr;
	Opt_fun* opt_fun=nullptr;
	Stop_crit* stop_crit=nullptr;
public:
	virtual vector<vector<double>> optim(vector<double>) = 0;
	void set_area(Area*);
	void set_opt_fun(Opt_fun*);
	void set_stop_crit(Stop_crit*);
	~Opt_method();
};

class Newton :public Opt_method {
protected:
	vector<double> p_n;
public:
	virtual vector<vector<double>> optim(vector<double>) override;
	Newton(Area*, Opt_fun*, Stop_crit*);
};

class Random_search :public Opt_method {
protected:
	double delta;
	double p;
public:
	virtual vector<vector<double>> optim(vector<double>) override;
	Random_search(Area*, Opt_fun*,Stop_crit*,double, double);
};