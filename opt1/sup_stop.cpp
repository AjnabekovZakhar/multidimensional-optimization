#include "sup_stop.h"

sup_stop_Newton::sup_stop_Newton(Opt_fun* func, vector<double>x_0):func(func),x_n(x_0)
{
}

void sup_stop_Newton::set_x_n(vector<double> x_n_)
{
	x_n_old = x_n;
	x_n = x_n_;
}

const vector<double> sup_stop_Newton::get_x_n()
{
	return x_n;
}

const vector<double> sup_stop_Newton::get_x_n_old()
{
	return x_n_old;
}
