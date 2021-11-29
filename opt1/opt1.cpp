#include <iostream>
#include<vector>
using namespace std;

#include"opt_method.h"


std::mt19937 SingletonGenerator::mersennetwister;
//test


int main()
{
    SingletonGenerator::get_mt().seed(42);
    setlocale(LC_ALL, "Russian");
   
    Area* area = new Dom(2, {-10,-10}, {10,10});
    Opt_fun* opt_fun= new Opt_fun1();
    Stop_crit* stop_crit = new Stop_crit_Newton_dif(100,1e-5);
    Newton*Nwtn =new Newton(area, opt_fun, stop_crit);
    vector<double> v = {3,3};
    vector<vector<double>> res;
    res = Nwtn->optim(v);
   
    cout << "Метод Ньютона" << endl;
    cout << "Область: [-10, 10]^2" << endl;
    cout << "Функция: x^2+y^2" << endl;
    cout << "Критерий остановки: по числу итераций(100) и норме градиента(<1e-5)" << endl;
    /*cout << "x_0: ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
    cout << "x_n: ";
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ' ';
    cout << endl;
    cout << "f(x_n): " << opt_fun->calc(res) << endl;*/
    for (int i = 0; i < res.size(); ++i)
        cout << "x_" << i << ": " << res[i][0] << ' ' << res[i][1] << " f: " << opt_fun->calc(res[i])<<endl;

    cout << "Число итераций: " << dynamic_cast<Stop_crit_Newton_dif*>(stop_crit)->get_count();
    cout << endl;

    dynamic_cast<Stop_crit_Newton_dif*>(stop_crit)->reset_count();

    opt_fun = new Opt_fun2;
    Nwtn = new Newton(area, opt_fun, stop_crit);
    res = Nwtn->optim(v);

    cout << "Метод Ньютона" << endl;
    cout << "Область: [-10, 10]^2" << endl;
    cout << "Функция: (1-x)^2+100(y-x^2)^2" << endl;
    cout << "Критерий остановки: по числу итераций(100) и норме градиента(<1e-5)" << endl;
    /*cout << "x_0: ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
    cout << "x_n: ";
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ' ';
    cout << endl;
    cout << "f(x_n): " << opt_fun->calc(res) << endl;*/
    for (int i = 0; i < res.size(); ++i)
        cout << "x_" << i << ": " << res[i][0] << ' ' << res[i][1] << " f: " << opt_fun->calc(res[i])<<endl;
    cout << "Число итераций: " << dynamic_cast<Stop_crit_Newton_dif*>(stop_crit)->get_count();
    cout << endl;
    stop_crit = new Stop_crit_count(10000);

    Random_search rand_serch(area,opt_fun,stop_crit,1,0.5);
    
    res = rand_serch.optim(v);

    cout << "Метод случайного поиска" << endl;
    cout << "Область: [-10, 10]^2" << endl;
    cout << "Функция: (1-x)^2+100(y-x^2)^2" << endl;
    cout << "Критерий остановки: по числу итераций(10000)" << endl;
    cout << "x_0: ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
    cout << "x_n: ";
    for (int i = 0; i < res.back().size(); ++i)
        cout << res.back()[i] << ' ';
    cout << endl;
    cout << "f(x_n): " << opt_fun->calc(res.back()) << endl;
    /*for (int i = 0; i < res.size(); ++i)
        cout << "x_" << i << ": " << res[i][0] << ' ' << res[i][1] << " f: " << opt_fun->calc(res[i])<<endl;*/
    return 0;
}

