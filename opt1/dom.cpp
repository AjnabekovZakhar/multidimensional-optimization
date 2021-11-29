#include "dom.h"

All_space::All_space(int dim_)
{
    dim = dim_;
}

bool All_space::inside(vector<double> v)
{
    if (dim != v.size())
        throw("dim != v.size()");
    return true;
}

Dom::Dom(int dim_, vector<double> left_, vector<double> right_)
{
    dim = dim_;
    if (dim != left_.size() || dim != right_.size())
        throw("dim != left_.size() || dim != right_.size()");
    left = left_;
    right = right_;
}

bool Dom::inside(vector<double>v)
{
    if (dim != v.size())
        throw("dim != v.size()");
    for (int i = 0; i < dim; ++i) {
        if (v[i]<left[i]) {
            /*vector<double> new_left = left - v + p;// границы относительно предыдущей точки(если перенести начало коорд. в неё)
            v = v - p;
            p = (new_left[i] / p[i]) * p;
            v = v + p;*/
            return false;
        }
        if (v[i] > right[i]) {
            /*vector<double> new_right = right - v + p;// границы относительно предыдущей точки(если перенести начало коорд. в неё)
            v = v - p;
            p = (new_right[i] / p[i]) * p;
            v = v + p;*/
            return false;
        }
    }
    return true;
}

vector<double> Dom::get_random_point()
{
    vector<double> point;
    for (int i = 0; i < dim; ++i)
        point.push_back(((right[i]-left[i])*getu01_sing())+left[i]);
    return point;
}

Dom Dom::cross_dom(vector<double>v, double delta)
{
    vector<double> left_, right_;
    for (int i = 0; i < v.size(); ++i) {
        left_.push_back(max(left[i], v[i] - delta));
        right_.push_back(min(right[i],v[i]+delta));
    }
    return Dom(v.size(),left_,right_);
}

const int Area::get_dim()
{
    return dim;
}
