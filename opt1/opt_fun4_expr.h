#pragma once
#include"Expr.h"
/// \brief Класс для 1ой координаты градиента для f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_grad1 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_grad1();
};
/// \brief Класс для 2ой координаты градиента для f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_grad2 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_grad2();
};
/// \brief Класс для 3ей координаты градиента для f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_grad3 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_grad3();
};
/// \brief Класс для 4ой координаты градиента для f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_grad4 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_grad4();
};

/// \brief Класс для элемента (1,1) Гессиана для f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_Hess11 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_Hess11();
};
/// \brief Класс для элемента (2,2) Гессиана для f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_Hess22 :public Expr {//тоже что и 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_Hess22();
};
/// \brief Класс для элемента (3,3) Гессиана для f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_Hess33 :public Expr {//тоже что и 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_Hess33();
};
/// \brief Класс для элемента (4,4) Гессиана для f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_Hess44 :public Expr {//тоже что и 22
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_Hess44();
};
/// \brief Класс для элементов, не лежащих на диагонали, Гессиана для f(x,y)=x^2+y^2
class Opt_fun4_Hess12 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_Hess12();
};
