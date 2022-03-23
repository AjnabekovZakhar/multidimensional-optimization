#pragma once
#include"Expr.h"
#include"opt_fun1_expr.h"
#include"opt_fun2_expr.h"
#include"opt_fun3_expr.h"
#include"opt_fun4_expr.h"
#include<string>
/// \brief Абстрактный класс для оптимизируюмых функций
class Opt_fun:public Expr
{
	protected:
		vector<Expr*> grad;
		vector<vector<Expr*>> Hess;
	public:
		/// \brief Вычисление значения градиента в точке
		virtual vector<double> calc_grad(const vector<double>&);
		/// \brief Вычисление значения Гессиана в точке
		virtual vector<vector<double>> calc_Hess(const vector<double>&);
		
		virtual string info()=0;
};

/// \brief Класс для оптимизируюмой функции f(x,y)=x^2+y^2
class Opt_fun1 :public Opt_fun
{
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun1();
	virtual string info() override;
};
/// \brief Класс для оптимизируюмой функции f(x,y)=(1-x)^2+100(y-x^2)^2
class Opt_fun2 :public Opt_fun
{
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun2();
	virtual string info() override;
};
/// \brief Класс для оптимизируюмой функции f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3 :public Opt_fun
{
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3();
	virtual string info() override;
};
/// \brief Класс для оптимизируюмой функции f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4 :public Opt_fun
{
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4();
	virtual string info() override;
};