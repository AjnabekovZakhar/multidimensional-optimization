#pragma once
#include"Expr.h"


/// \brief Класс для 1ой координаты градиента для f(x,y)=x^2+y^2
class Opt_fun1_grad1:public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun1_grad1();
};
/// \brief Класс для 2ой координаты градиента для f(x,y)=x^2+y^2
class Opt_fun1_grad2 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun1_grad2();
};
/// \brief Класс для элементов (1,1) и (2,2) Гессиана для f(x,y)=x^2+y^2
class Opt_fun1_Hess11 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun1_Hess11();
};
/// \brief Класс для элементов (1,2) и (2,1) Гессиана для f(x,y)=x^2+y^2
class Opt_fun1_Hess12 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun1_Hess12();
};
