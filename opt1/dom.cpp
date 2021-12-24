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

vector<double> All_space::correct_point(vector<double> inside, vector<double> outside)
{
    return outside;
}

string All_space::info()
{
    return "Domain: R^"+ to_string(dim);
}

Dom::Dom(int dim_, vector<double> left_, vector<double> right_)
{
    dim = dim_;
    if (dim != left_.size() || dim != right_.size())
        throw domain_error("dim != left_.size() || dim != right_.size()");
    for (int i = 0; i < left_.size(); ++i)
        if (left_[i] >= right_[i])
            throw domain_error("left_["+to_string(i)+"] >= right_[" + to_string(i) + "]");
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

vector<double> Dom::correct_point(vector<double>inside , vector<double>outside)
{
    if (!(this->inside(inside)))
        throw invalid_argument("inside point not inside");
    if ((inside.size() != outside.size())||(inside.size() != dim))
        throw length_error("dimension error");
    if (this->inside(outside))
        return outside;

    vector<double> new_left = left - inside, new_right = right - inside,new_outside=outside-inside,res;
    
    for (int i = 0; i < dim; ++i) {
        if (new_outside[i] < new_left[i]) {
            res = ((new_left[i] / new_outside[i]) * new_outside)+inside;
            if (this->inside(res))
                return res;
        }
        if (new_outside[i] > new_right[i]) {
            res = ((new_right[i] / new_outside[i]) * new_outside) + inside;
            if (this->inside(res))
                return res;
        }
    }
    return outside;
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

string Dom::info()
{
    string res="Domain: ";
    for (int i = 0; i < left.size(); ++i)
        res += ("[" + to_string(left[i])+", "+ to_string(right[i])+"]x");
    res.pop_back();
    return res;
}

const int Area::get_dim()
{
    return dim;
}
