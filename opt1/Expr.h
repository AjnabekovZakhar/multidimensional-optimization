#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

class Expr
{
	protected:
		int dim;
	public:
		virtual double calc(const vector<double>&) = 0;
		double operator()(const vector<double>&);
};


