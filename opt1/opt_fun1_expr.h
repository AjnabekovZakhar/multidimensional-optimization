#pragma once
#include"Expr.h"


/// \brief ����� ��� 1�� ���������� ��������� ��� f(x,y)=x^2+y^2
class Opt_fun1_grad1:public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun1_grad1();
};
/// \brief ����� ��� 2�� ���������� ��������� ��� f(x,y)=x^2+y^2
class Opt_fun1_grad2 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun1_grad2();
};
/// \brief ����� ��� ��������� (1,1) � (2,2) �������� ��� f(x,y)=x^2+y^2
class Opt_fun1_Hess11 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun1_Hess11();
};
/// \brief ����� ��� ��������� (1,2) � (2,1) �������� ��� f(x,y)=x^2+y^2
class Opt_fun1_Hess12 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun1_Hess12();
};
