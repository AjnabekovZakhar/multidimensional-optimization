#pragma once
#include"Expr.h"


/// \brief Класс для 1ой координаты градиента для f(x,y)=(1-x)^2+100(y-x^2)^2
class Opt_fun2_grad1 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun2_grad1();
};
/// \brief Класс для 2ой координаты градиента для f(x,y)=(1-x)^2+100(y-x^2)^2
class Opt_fun2_grad2 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun2_grad2();
};
/// \brief Класс для элемента (1,1) Гессиана для f(x,y)=(1-x)^2+100(y-x^2)^2
class Opt_fun2_Hess11 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun2_Hess11();
};
/// \brief Класс для элементов (1,2) и (2,1) Гессиана для f(x,y)=(1-x)^2+100(y-x^2)^2
class Opt_fun2_Hess12 :public Expr {//тоже что и 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun2_Hess12();
};
/// \brief Класс для элемента (2,2) Гессиана для f(x,y)=(1-x)^2+100(y-x^2)^2
class Opt_fun2_Hess22 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun2_Hess22();
};