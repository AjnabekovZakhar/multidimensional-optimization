#pragma once
#include<vector>
#include"sup_stop.h"
#include<string>
using namespace std;
/// \brief ����������� ����� ��� ��������� ��������� ������� �����������
class Stop_crit
{

public:
/// \brief ����� ��� �������� ������� ���������
	virtual bool check(sup_stop*) = 0;
	virtual string info() = 0;
};
/// \brief ����� ��� �������� ��������� �� ����� ��������
class Stop_crit_count:public Stop_crit
{
protected:
	int count = 0;
	int max=100;
public:
	virtual bool check(sup_stop*) override;
	Stop_crit_count(int);
	void set_max(int);
	const int get_count();
	virtual void reset();
	virtual string info() override;
};
/// \brief ����� ��� �������� ��������� ||x_n-x_{n-1}||<eps ��� ������ �������
class Stop_crit_Newton_dif :public Stop_crit_count {
protected:
	double epsi;
	public:
		virtual bool check(sup_stop*) override;
		Stop_crit_Newton_dif(int,double);
		virtual string info() override;
};
/// \brief ����� ��� �������� ��������� |grad(f(x_n))|<eps ��� ������ �������
class Stop_crit_Newton_grad :public Stop_crit_count {
protected:
	double epsi;
public:
	virtual bool check(sup_stop*) override;
	Stop_crit_Newton_grad(int, double);
	virtual string info() override;
};
/// \brief ����� ��� �������� ��������� |(f(x_n)-f(x_{n-1}))/f(x_n)|<eps ��� ������ �������
class Stop_crit_Newton3 :public Stop_crit_count { 
protected:
	double epsi;
public:
	virtual bool check(sup_stop*) override;
	Stop_crit_Newton3(int, double);
	virtual string info() override;
};
/// \brief ����� ��� �������� ��������� ||x_n-x_{n-1}||<eps ��� ���������� ������
class Stop_crit_random_search_dif :public Stop_crit_count {
protected:
	double epsi;
public:
	virtual bool check(sup_stop*) override;
	Stop_crit_random_search_dif(int, double);
	virtual string info() override;
};
/// \brief ����� ��� �������� ��������� �� ����� �������� � ���������� ��������� ��� ���������� ������
class Stop_crit_random_search_last_change :public Stop_crit_count {
protected:
	int max_lc;
public:
	virtual bool check(sup_stop*) override;
	Stop_crit_random_search_last_change(int, int);
	virtual string info() override;
};