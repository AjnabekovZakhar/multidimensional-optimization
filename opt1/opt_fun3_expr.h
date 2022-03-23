#pragma once
#include"Expr.h"
/// \brief ����� ��� 1�� ���������� ��������� ��� f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_grad1 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_grad1();
};
/// \brief ����� ��� 2�� ���������� ��������� ��� f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_grad2 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_grad2();
};
/// \brief ����� ��� 3�� ���������� ��������� ��� f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_grad3 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_grad3();
};

/// \brief ����� ��� �������� (1,1) �������� ��� f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess11 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess11();
};
/// \brief ����� ��� �������� (2,2) �������� ��� f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess22 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_Hess22();
};
/// \brief ����� ��� �������� (3,3) �������� ��� f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess33 :public Expr {//���� ��� � 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun3_Hess33();
};
/// \brief ����� ��� ��������� (1,2) � (2,1) �������� ��� f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess12 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess12();
};
/// \brief ����� ��� ��������� (1,3) � (3,1) �������� ��� f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess13 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess13();
};
/// \brief ����� ��� ��������� (2,3) � (3,2) �������� ��� f(x,y,z)=exp(x^2+y^2+z^2)
class Opt_fun3_Hess23 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun3_Hess23();
};