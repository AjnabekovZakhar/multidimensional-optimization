#pragma once
#include<vector>
#include<string>
#include"Something.h"
using namespace std;
/// \brief ����������� ����� ��� ������� �����������
class Area
{
protected:
	unsigned dim;
public:
	/// \brief �������� ����� �� �������������� �������
	virtual bool inside(vector<double>) = 0;
	/// \brief ������������� ��� ������ ������������ �������
	virtual vector<double> correct_point(vector<double>, vector<double>)=0;
	const unsigned get_dim();
	virtual string info()=0;
};
/// \brief ����� ��� �������������� ������� �����������
class All_space:public Area {
public:
	All_space(unsigned);
	virtual bool inside(vector<double>) override;
	virtual vector<double> correct_point(vector<double>, vector<double>) override;
	virtual string info() override;
};
/// \brief ����� ��� ������������ ������� �����������
class Dom :public Area {
protected:
	vector<double> left;
	vector<double> right;
public:
	Dom(unsigned, vector<double>, vector<double>);
	virtual bool inside(vector<double>) override;
	/// \brief ��������� ��������� ����� �� ������������ �������
	vector<double> get_random_point();
	virtual vector<double> correct_point(vector<double>, vector<double>) override;
	/// \brief ����������� ������� � ���������, �������� ������� � ��������� ����� �������
	Dom cross_dom(vector<double>, double);
	virtual string info() override;
};