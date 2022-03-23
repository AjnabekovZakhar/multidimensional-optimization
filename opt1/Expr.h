#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
/// \brief ����������� ����� ��� �������
class Expr
{
	protected:
		unsigned dim;
	public:
		/// \brief ���������� �������� ������� � �����
		virtual double calc(const vector<double>&) = 0;
		double operator()(const vector<double>&);
		const int get_dim();
};


