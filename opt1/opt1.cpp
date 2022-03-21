#include <iostream>
#include<vector>
using namespace std;

#include"opt_method.h"

mt19937 SingletonGenerator::mersennetwister;

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

            cout << "Choose a function to optimize"<<endl;
            cout<<"\"r\" - Rosenbrock function" << endl;
            cout << "another char - x^2+y^2" << endl;
            cin >> input;
            if (input == 'r')
                opt_fun = new Opt_fun2();
            else
                opt_fun = new Opt_fun1();

            cout << endl;

            cout << "Choose a domain" << endl;
            cout << "\"a\" - all space" << endl;
            cout << "another char - limited" << endl;
            cin >> input;
            if (input == 'a')
                area = new All_space(2);
            else {
                cout << "Choose borders (2 left, 2 right)" << endl;
                cin >> left[0] >> left[1] >> right[0] >> right[1];
                area = new Dom(2, left, right);
            }

            cout << endl;

            cout << "Choose an optimization method" << endl;
            cout << "\"n\" - Newton's method" << endl;
            cout << "another char - random search" << endl;
            cin >> input;

            cout << endl;

            if (input == 'n') {
                cout << "Choose a stop criterion" << endl;
                cout << "\"i\" - ||x_n-x_{n-1}||<eps" << endl;
                cout << "\"g\" - |grad(f(x_n))|<eps" << endl;
                cout << "\"f\" - |(f(x_n)-f(x_{n-1}))/f(x_n)|" << endl;
                cout << "another char - number of iterations" << endl;
                cin >> input;

                cout << "Choose a number of iterations" << endl;
                cin >> max;
                cout << "Choose epsilon" << endl;
                cin >> epsilon;

                switch (input) {
                case 'i':
                    stop_crit = new Stop_crit_Newton_dif(max, epsilon);
                    break;
                case 'g':
                    stop_crit = new Stop_crit_Newton_grad(max, epsilon);
                    break;
                case 'f':
                    stop_crit = new Stop_crit_Newton3(max, epsilon);
                    break;
                default:
                    stop_crit = new Stop_crit_count(max);
                    break;
                }

                opt_method = new Newton(area,opt_fun,stop_crit);
            
            }
            else {
                cout << "Choose stop criterion" << endl;
                cout << "\"i\" - ||x_n-x_{n-1}||<eps (for x_n!=x_{n-1})" << endl;
                cout << "\"c\" - number of iterations since the last change" << endl;
                cout << "another char - number of iterations" << endl;
                cin >> input;
                cout << "Choose a number of iterations" << endl;
                cin >> max;
                cout << "Choose a delta" << endl;
                cin >> delta;
                cout << "Choose a probability" << endl;
                cin >>p;
                switch (input) {
                case 'i':
                    cout << "Choose epsilon" << endl;
                    cin >> epsilon;

                    stop_crit = new Stop_crit_random_search_dif(max, epsilon);
                    break;
                case 'c':
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

            cout << endl;

            cout << "Choose x_0" << endl;
            cin >> v[0] >> v[1];
            opt_method->optim(v);
            cout << endl;
            output = opt_method->info();
            for (auto str : output)
                cout << str << endl;
        }
        catch (exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
        cout << endl;
        cout << "Press q to quit, another char continue" <<endl;
        cin >> input;
        cout << endl << endl;
    }

    return 0;
}