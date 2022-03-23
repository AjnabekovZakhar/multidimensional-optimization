#pragma once
#include"Expr.h"

class Opt_fun3_grad1 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_grad1();
};
class Opt_fun3_grad2 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_grad2();
};
class Opt_fun3_grad3 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_grad3();
};


class Opt_fun3_Hess11 :public Expr {//тоже что и 22
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess11();
};

class Opt_fun3_Hess22 :public Expr {//тоже что и 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_Hess22();
};

class Opt_fun3_Hess33 :public Expr {//тоже что и 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_Hess33();
};

class Opt_fun3_Hess12 :public Expr {//тоже что и 22
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess12();
};

class Opt_fun3_Hess13 :public Expr {//тоже что и 22
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess13();
};

class Opt_fun3_Hess23 :public Expr {//тоже что и 22
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess23();
};