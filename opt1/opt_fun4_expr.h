#pragma once
#include"Expr.h"

class Opt_fun4_grad1 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_grad1();
};
class Opt_fun4_grad2 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_grad2();
};
class Opt_fun4_grad3 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_grad3();
};
class Opt_fun4_grad4 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_grad4();
};

class Opt_fun4_Hess11 :public Expr {//тоже что и 22
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_Hess11();
};

class Opt_fun4_Hess22 :public Expr {//тоже что и 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_Hess22();
};

class Opt_fun4_Hess33 :public Expr {//тоже что и 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_Hess33();
};

class Opt_fun4_Hess44 :public Expr {//тоже что и 22
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_Hess44();
};

class Opt_fun4_Hess12 :public Expr {//тоже что и 22
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_Hess12();
};
