#include "opt_fun3_expr.h"

double Opt_fun3_grad1::calc(const vector<double>& v)
{
	return 2 * v[0] * exp(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

Opt_fun3_grad1::Opt_fun3_grad1()
{
	dim = 3;
}

double Opt_fun3_grad2::calc(const vector<double>& v)
{
	return 2 * v[1] * exp(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

Opt_fun3_grad2::Opt_fun3_grad2()
{
	dim = 3;
}

double Opt_fun3_grad3::calc(const vector<double>& v)
{
	return 2 * v[2] * exp(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

Opt_fun3_grad3::Opt_fun3_grad3()
{
	dim = 3;
}

double Opt_fun3_Hess11::calc(const vector<double>& v)
{
	return (4*v[0]*v[0]+2)* exp(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

double Opt_fun3_Hess22::calc(const vector<double>& v)
{
	return (4 * v[1] * v[1] + 2) * exp(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

double Opt_fun3_Hess33::calc(const vector<double>& v)
{
	return (4 * v[2] * v[2] + 2) * exp(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

double Opt_fun3_Hess12::calc(const vector<double>& v)
{
	return 4*v[0] * v[1]  * exp(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

double Opt_fun3_Hess13::calc(const vector<double>& v)
{
	return 4 * v[0] * v[2] * exp(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

double Opt_fun3_Hess23::calc(const vector<double>& v)
{
	return 4 * v[1] * v[2] * exp(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}
Opt_fun3_Hess11::Opt_fun3_Hess11()
{
	dim = 3;
}

Opt_fun3_Hess22::Opt_fun3_Hess22()
{
	dim = 3;
}

Opt_fun3_Hess33::Opt_fun3_Hess33()
{
	dim = 3;
}

Opt_fun3_Hess12::Opt_fun3_Hess12()
{
	dim = 3;
}

Opt_fun3_Hess13::Opt_fun3_Hess13()
{
	dim = 3;
}

Opt_fun3_Hess23::Opt_fun3_Hess23()
{
	dim = 3;
}
