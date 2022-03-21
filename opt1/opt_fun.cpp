#include "opt_fun.h"

vector<double> Opt_fun::calc_grad(const vector<double>&v)
{
    if (dim != v.size())
        throw domain_error("dim!=v.size()");
    vector<double> res(dim);
    for (unsigned i = 0; i < dim; ++i)
        res[i]=grad[i]->calc(v);
    return res;
}

vector<vector<double>> Opt_fun::calc_Hess(const vector<double>& v)
{
    if (dim != v.size())
        throw domain_error("dim!=v.size()");
    vector<vector<double>> res(dim);
    vector<double> res2(dim);

    for (unsigned i = 0; i < dim; ++i) {
        for (unsigned j = 0; j < dim; ++j)
            res2[j] = Hess[i][j]->calc(v);
        res[i] = res2;
    }
    return res;
}
const int Opt_fun::get_dim()
{
    return dim;
}
double Opt_fun1::calc(const vector<double>& v)
{
    return (v[0] * v[0]) + (v[1] * v[1]);
}

Opt_fun1::Opt_fun1()
{
    dim = 2;
    grad = { new Opt_fun1_grad1,new Opt_fun1_grad2 };
    Hess = { {new Opt_fun1_Hess11,new Opt_fun1_Hess12},
        {new Opt_fun1_Hess12,new Opt_fun1_Hess11} };
}

string Opt_fun1::info()
{
    return "f(x,y)=x^2+y^2";
}

double Opt_fun2::calc(const vector<double>& v)
{
    return (1-v[0])*(1-v[0])+100*(v[1]-v[0]*v[0])* (v[1] - v[0] * v[0]);
}

Opt_fun2::Opt_fun2()
{
    dim = 2;
    grad = { new Opt_fun2_grad1,new Opt_fun2_grad2 };
    Hess = { {new Opt_fun2_Hess11,new Opt_fun2_Hess12},
        {new Opt_fun2_Hess12,new Opt_fun2_Hess22} };
}

string Opt_fun2::info()
{
    return "f(x,y)=(1-x)^2+100(y-x^2)^2";
}
