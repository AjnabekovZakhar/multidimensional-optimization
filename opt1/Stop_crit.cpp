#include "Stop_crit.h"

bool Stop_crit_count::check(sup_stop * =nullptr)
{

    if (count >= max) {
        return false;

    }
    ++count;
    return true;
}

Stop_crit_count::Stop_crit_count(int max_)
{
    if (max_ < 1)
        throw("max < 1");
    max = max_;
}

void Stop_crit_count::set_max(int max_)
{
    max = max_;
}

const int Stop_crit_count::get_count()
{
    return count;
}

void Stop_crit_count::reset_count()
{
    count = 0;
}

bool Stop_crit_Newton_dif::check(sup_stop*sup)
{
    sup_stop_Newton*sup_N = dynamic_cast<sup_stop_Newton*>(sup);

    if (count >= max) {
        return false;

    }
    if (!(sup_N->get_x_n_old().empty())&&(abs((sup_N->get_x_n())-(sup_N->get_x_n_old())) < epsi)) {
        return false;

    }
    ++count;
    return true;
}

Stop_crit_Newton_dif::Stop_crit_Newton_dif(int max_, double epsi_):Stop_crit_count(max_)
{

    if (epsi_ < 0)
        throw("epsilon < 0");
    epsi = epsi_;

    
}

bool Stop_crit_Newton_grad::check(sup_stop*sup)
{
    sup_stop_Newton* sup_N = dynamic_cast<sup_stop_Newton*>(sup);

    if (count >= max) {
        return false;

    }
    if (abs(sup_N-> get_grad_x_n()) < epsi) {
        return false;

    }
    ++count;
    return true;
}

Stop_crit_Newton_grad::Stop_crit_Newton_grad(int max_, double epsi_) :Stop_crit_count(max_)
{

    if (epsi_ < 0)
        throw("epsilon < 0");
    epsi = epsi_;
}

bool Stop_crit_Newton3::check(sup_stop* sup)
{
    sup_stop_Newton* sup_N = dynamic_cast<sup_stop_Newton*>(sup);

    if (count >= max) {
        return false;

    }
    if (!(sup_N->get_x_n_old().empty()) && (abs((sup_N->get_fun_x_n()-sup_N->get_fun_x_n_old())/ sup_N->get_fun_x_n()) < epsi)) {
        return false;
    }
    ++count;
    return true;
}

Stop_crit_Newton3::Stop_crit_Newton3(int max_, double epsi_) :Stop_crit_count(max_)
{

    if (epsi_ < 0)
        throw("epsilon < 0");
    epsi = epsi_;
}

bool Stop_crit_random_search_dif::check(sup_stop* sup)
{
    sup_stop_random_search* sup_rs = dynamic_cast<sup_stop_random_search*>(sup);

    if (count >= max) {
        return false;

    }
    if (!(sup_rs->get_x_n_old().empty()) && (abs((sup_rs->get_fun_x_n()) - (sup_rs->get_fun_x_n_old())) < epsi)) {
        return false;

    }
    ++count;
    return true;
}

Stop_crit_random_search_dif::Stop_crit_random_search_dif(int max_, double epsi_) :Stop_crit_count(max_)
{

    if (epsi_ < 0)
        throw("epsilon < 0");
    epsi = epsi_;
}

bool Stop_crit_random_search_last_change::check(sup_stop* sup)
{
    sup_stop_random_search* sup_rs = dynamic_cast<sup_stop_random_search*>(sup);

    if (count >= max) {
        return false;

    }
    if (sup_rs->get_last_change_count()>=max_lc) {
        return false;

    }
    ++count;
    return true;
}

Stop_crit_random_search_last_change::Stop_crit_random_search_last_change(int max_, int max_lc_) :Stop_crit_count(max_),max_lc(max_lc_)
{
}
