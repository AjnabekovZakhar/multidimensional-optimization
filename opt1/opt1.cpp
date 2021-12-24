#include <iostream>
#include<vector>
using namespace std;

#include"opt_method.h"


std::mt19937 SingletonGenerator::mersennetwister;

/*
int main()
{
    
    setlocale(LC_ALL, "Russian");
   
    Area* area = new Dom(2, {1,1}, {10,10});
    Opt_fun* opt_fun= new Opt_fun1();
    Stop_crit* stop_crit = new Stop_crit_Newton_dif(100,1e-5);
    Newton*Nwtn =new Newton(area, opt_fun, stop_crit);
    vector<double> v = {3,3};
    vector<vector<double>> res;
    res = Nwtn->optim(v);
   
    cout << "Метод Ньютона" << endl;
    cout << "Область: [1, 10]^2" << endl;
    cout << "Функция: x^2+y^2" << endl;
    cout << "Критерий остановки: по числу итераций(100) и по разнице точек(<1e-5)" << endl;

    for (int i = 0; i < res.size(); ++i)
        cout << "x_" << i << ": " << res[i][0] << ' ' << res[i][1] << " f: " << opt_fun->calc(res[i])<<endl;

    cout << "Число итераций: " << dynamic_cast<Stop_crit_Newton_dif*>(stop_crit)->get_count()<<endl;

    cout << endl;

    dynamic_cast<Stop_crit_Newton_dif*>(stop_crit)->reset_count();

    opt_fun = new Opt_fun2;
    Nwtn = new Newton(area, opt_fun, new Stop_crit_Newton_grad(100,1e-5));
    res = Nwtn->optim(v);

    cout << "Метод Ньютона" << endl;
    cout << "Область: [1, 10]^2" << endl;
    cout << "Функция: (1-x)^2+100(y-x^2)^2" << endl;
    cout << "Критерий остановки: по числу итераций(100) и норме градиента(<1e-5)" << endl;

    for (int i = 0; i < res.size(); ++i)
        cout << "x_" << i << ": " << res[i][0] << ' ' << res[i][1] << " f: " << opt_fun->calc(res[i])<<endl;

    cout << endl;

    Nwtn = new Newton(area, opt_fun, new Stop_crit_Newton3(100, 1e-5));
    res = Nwtn->optim(v);

    cout << "Метод Ньютона" << endl;
    cout << "Область: [1, 10]^2" << endl;
    cout << "Функция: (1-x)^2+100(y-x^2)^2" << endl;
    cout << "Критерий остановки: по числу итераций(100) и третий способ(<1e-5)" << endl;

    for (int i = 0; i < res.size(); ++i)
        cout << "x_" << i << ": " << res[i][0] << ' ' << res[i][1] << " f: " << opt_fun->calc(res[i]) << endl;

    cout << endl;

    stop_crit = new Stop_crit_random_search_dif(100,1e-5);

    Random_search rand_serch(new Dom(2, { 1,1 }, { 10,10 }), new Opt_fun1(),stop_crit,1,0.5);
    
    res = rand_serch.optim(v);

    cout << "Метод случайного поиска" << endl;
    cout << "Область: [-10, 10]^2" << endl;
    cout << "Функция: (1-x)^2+100(y-x^2)^2" << endl;
    cout << "Критерий остановки: по числу итераций(100) и по разнице значений точек(<1e-5)" << endl;
    for (int i = 0; i < res.size(); ++i)
        cout << "x_" << i << ": " << res[i][0] << ' ' << res[i][1] << " f: " << opt_fun->calc(res[i]) << endl;

    cout << endl;

    stop_crit = new Stop_crit_random_search_last_change(100, 100);

    Random_search rand_serch2(new Dom(2, { 1,1 }, { 10,10 }), new Opt_fun1(), stop_crit, 1, 0.5);

    res = rand_serch2.optim(v);

    cout << "Метод случайного поиска" << endl;
    cout << "Область: [-10, 10]^2" << endl;
    cout << "Функция: (1-x)^2+100(y-x^2)^2" << endl;
    cout << "Критерий остановки: по числу итераций(100) и по количеству точек без изменений(10)" << endl;
    for (int i = 0; i < res.size(); ++i)
        cout << "x_" << i << ": " << res[i][0] << ' ' << res[i][1] << " f: " << opt_fun->calc(res[i]) << endl;

    cout << endl;

    return 0;
}
*/
int main() {
    SingletonGenerator::get_mt().seed(42);



    Area* area;
    Opt_fun* opt_fun;
    Stop_crit* stop_crit;
    Opt_method* opt_method;
    vector<double> v = { 0,0 }, left = { -10,-10 }, right = {10,10};
    vector<vector<double>> res;
    int max, max_lc;
    double epsilon,delta,p;

    vector<string> output;

    char input='f';
    while (input != 'q') {
        try {
            cout << "Choose a function to optimize(r - Rosenbrock function, another char - x^2+y^2)" << endl;
            cin >> input;
            if (input == 'r')
                opt_fun = new Opt_fun2();
            else
                opt_fun = new Opt_fun1();
            cout << "Choose a domain(r - all space, another char - limited)" << endl;
            cin >> input;
            if (input == 'r')
                area = new All_space(2);
            else {
                cout << "Choose borders (2 left, 2 right)" << endl;
                cin >> left[0] >> left[1] >> right[0] >> right[1];
                area = new Dom(2, left, right);
            }
            cout << "Choose an optimization method(r - Newton's method, another char - random search)" << endl;
            cin >> input;
            if (input == 'r') {
                cout << "Choose stop criterion(r - ||x_n-x_{n-1}||, g - grad ,f - |(f(x_n)-f(x_{n-1}))/f(x_n)|, another char - number of iterations)" << endl;
                cin >> input;
                cout << "Choose a number of iterations" << endl;
                cin >> max;
                switch (input) {
                case 'r':
                    cout << "Choose epsilon" << endl;
                    cin >> epsilon;
                    stop_crit = new Stop_crit_Newton_dif(max, epsilon);
                    break;
                case 'g':
                    cout << "Choose epsilon" << endl;
                    cin >> epsilon;
                    stop_crit = new Stop_crit_Newton_grad(max, epsilon);
                    break;
                case 'f':
                    cout << "Choose epsilon" << endl;
                    cin >> epsilon;
                    stop_crit = new Stop_crit_Newton3(max, epsilon);
                    break;
                default:
                    stop_crit = new Stop_crit_count(max);
                    break;
                }
                opt_method = new Newton(area,opt_fun,stop_crit);
            }
            else {
                cout << "Choose stop criterion(r - ||x_n-x_{n-1}|| (x_n!=x_{n-1}), g - number of iterations since the last change, another char - number of iterations)" << endl;
                cin >> input;
                cout << "Choose a number of iterations, delta and probability" << endl;
                cin >> max>>delta>>p;
                switch (input) {
                case 'r':
                    cout << "Choose epsilon" << endl;
                    cin >> epsilon;

                    stop_crit = new Stop_crit_random_search_dif(max, epsilon);
                    break;
                case 'g':
                    cout << "Choose maximum number of iterations since the last change" << endl;
                    cin >> max_lc;
                    stop_crit = new Stop_crit_random_search_last_change(max,max_lc);
                    break;
                default:
                    stop_crit = new Stop_crit_count(max);
                    break;
                }
                opt_method = new Random_search(area, opt_fun, stop_crit,delta,p);
            }
            cout << "Choose x_0" << endl;
            cin >> v[0] >> v[1];
            opt_method->optim(v);
            cout << endl;
            output = opt_method->info();
            for (auto str : output)
                cout << str << endl;
            cout << endl;
            cout << "Press q to quit, another char continue" << endl << endl;
            cin >> input;
        }
        catch (domain_error& e) {
            cout << "Exception: " << e.what() << endl;
        }
    }

    


    return 0;
}