#include"opt_fun4_expr.h"

double Opt_fun4_grad1::calc(const vector<double>&v )
{
	return 2*v[0];
}

double Opt_fun4_grad2::calc(const vector<double>& v)
{
	return 4 * v[1] * v[1] * v[1];
}

double Opt_fun4_grad3::calc(const vector<double>& v)
{
	return cos(v[2]);
}

double Opt_fun4_grad4::calc(const vector<double>& v)
{
	return -sin(v[3]);
}

Opt_fun4_grad1::Opt_fun4_grad1()
{
	dim = 4;
}
Opt_fun4_grad2::Opt_fun4_grad2()
{
	dim = 4;
}
Opt_fun4_grad3::Opt_fun4_grad3()
{
	dim = 4;
}
Opt_fun4_grad4::Opt_fun4_grad4()
{
	dim = 4;
}

double Opt_fun4_Hess11::calc(const vector<double>&v)
{
	return 2;
}

double Opt_fun4_Hess22::calc(const vector<double>&v)
{
	return 12*v[1]*v[1];
}

double Opt_fun4_Hess33::calc(const vector<double>&v)
{
	return -sin(v[2]);
}

double Opt_fun4_Hess44::calc(const vector<double>&v)
{
	return -cos(v[3]);
}

Opt_fun4_Hess11::Opt_fun4_Hess11()
{
	dim = 4;
}

Opt_fun4_Hess22::Opt_fun4_Hess22()
{
	dim = 4;
}
Opt_fun4_Hess33::Opt_fun4_Hess33()
{
	dim = 4;
}
Opt_fun4_Hess44::Opt_fun4_Hess44()
{
	dim = 4;
}
double Opt_fun4_Hess12::calc(const vector<double>&)
{
	return 0.0;
}
Opt_fun4_Hess12::Opt_fun4_Hess12()
{
	dim = 4;
}
