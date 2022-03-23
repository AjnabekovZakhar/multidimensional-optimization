#pragma once
#include"Expr.h"
/// \brief Класс для 1ой координаты градиента для f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_grad1 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_grad1();
};
/// \brief Класс для 2ой координаты градиента для f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_grad2 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_grad2();
};
/// \brief Класс для 3ей координаты градиента для f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_grad3 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_grad3();
};

/// \brief Класс для элемента (1,1) Гессиана для f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess11 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess11();
};
/// \brief Класс для элемента (2,2) Гессиана для f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess22 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_Hess22();
};
/// \brief Класс для элемента (3,3) Гессиана для f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess33 :public Expr {//тоже что и 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_Hess33();
};
/// \brief Класс для элементов (1,2) и (2,1) Гессиана для f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess12 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess12();
};
/// \brief Класс для элементов (1,3) и (3,1) Гессиана для f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess13 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess13();
};
/// \brief Класс для элементов (2,3) и (3,2) Гессиана для f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess23 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess23();
};