#pragma once
#include"Expr.h"
#include"Something.h"
#include"opt_fun.h"

class sup_stop
{
	virtual void set_x_n(vector<double>)=0;
};

class sup_stop_Newton:public sup_stop{
	protected:
		vector<double> x_n;
		vector<double> x_n_old;
		Opt_fun*  func;
	public:
		sup_stop_Newton(Opt_fun*,vector<double>);
		virtual void set_x_n(vector<double>) override;
		~sup_stop_Newton();
		const vector<double> get_x_n();
		const vector<double> get_x_n_old();

};
