#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
/// \brief Абстрактный класс для функций
class Expr
{
	protected:
		unsigned dim;
	public:
		/// \brief Вычисление значения функции в точке
		virtual double calc(const vector<double>&) = 0;
		double operator()(const vector<double>&);
		const int get_dim();
};


