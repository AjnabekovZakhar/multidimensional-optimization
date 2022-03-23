#pragma once
#include"Expr.h"
/// \brief ����� ��� 1�� ���������� ��������� ��� f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_grad1 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_grad1();
};
/// \brief ����� ��� 2�� ���������� ��������� ��� f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_grad2 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_grad2();
};
/// \brief ����� ��� 3�� ���������� ��������� ��� f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_grad3 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_grad3();
};
/// \brief ����� ��� 4�� ���������� ��������� ��� f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_grad4 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_grad4();
};

/// \brief ����� ��� �������� (1,1) �������� ��� f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_Hess11 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_Hess11();
};
/// \brief ����� ��� �������� (2,2) �������� ��� f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_Hess22 :public Expr {//���� ��� � 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_Hess22();
};
/// \brief ����� ��� �������� (3,3) �������� ��� f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_Hess33 :public Expr {//���� ��� � 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun4_Hess33();
};
/// \brief ����� ��� �������� (4,4) �������� ��� f(x,y,z,w)=x^2+y^4+sin(z)+cos(w)
class Opt_fun4_Hess44 :public Expr {//���� ��� � 22
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_Hess44();
};
/// \brief ����� ��� ���������, �� ������� �� ���������, �������� ��� f(x,y)=x^2+y^2
class Opt_fun4_Hess12 :public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun4_Hess12();
};
