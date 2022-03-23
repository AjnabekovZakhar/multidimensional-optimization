#pragma once
#include"Expr.h"
#include"opt_fun1_expr.h"
#include"opt_fun2_expr.h"
#include"opt_fun3_expr.h"
#include"opt_fun4_expr.h"
#include<string>
class Opt_fun:public Expr
{
	protected:
		vector<Expr*> grad;
		vector<vector<Expr*>> Hess;
	public:
		virtual vector<double> calc_grad(const vector<double>&);
		virtual vector<vector<double>> calc_Hess(const vector<double>&);
		
		virtual string info()=0;
};


class Opt_fun1 :public Opt_fun//x^2+y^2
{
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun1();
	virtual string info() override;
};

class Opt_fun2 :public Opt_fun//(1-x)^2+100(y-x^2)^2
{
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun2();
	virtual string info() override;
};

class Opt_fun3 :public Opt_fun//exp(x^2+y^2+z^2)
{
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3();
	virtual string info() override;
};

class Opt_fun4 :public Opt_fun//x^2+y^4+sin(z)+cos(w)
{
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4();
	virtual string info() override;
};