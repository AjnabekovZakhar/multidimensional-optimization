#pragma once
#include"Expr.h"


/// \brief ����� ��� 1�� ���������� ��������� ��� f(x,y)=(1-x)^2+100(y-x^2)^2
class Opt_fun2_grad1 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun2_grad1();
};
/// \brief ����� ��� 2�� ���������� ��������� ��� f(x,y)=(1-x)^2+100(y-x^2)^2
class Opt_fun2_grad2 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun2_grad2();
};
/// \brief ����� ��� �������� (1,1) �������� ��� f(x,y)=(1-x)^2+100(y-x^2)^2
class Opt_fun2_Hess11 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun2_Hess11();
};
/// \brief ����� ��� ��������� (1,2) � (2,1) �������� ��� f(x,y)=(1-x)^2+100(y-x^2)^2
class Opt_fun2_Hess12 :public Expr {//���� ��� � 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun2_Hess12();
};
/// \brief ����� ��� �������� (2,2) �������� ��� f(x,y)=(1-x)^2+100(y-x^2)^2
class Opt_fun2_Hess22 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun2_Hess22();
};