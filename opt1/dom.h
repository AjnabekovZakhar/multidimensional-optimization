#pragma once
#include<vector>
#include<string>
#include"Something.h"
using namespace std;
/// \brief Абстрактный класс для области оптимизации
class Area
{
protected:
	unsigned dim;
public:
	/// \brief Проверка точки на принадлежность области
	virtual bool inside(vector<double>) = 0;
	/// \brief Корректировка для прямой пересекающей границу
	virtual vector<double> correct_point(vector<double>, vector<double>)=0;
	const unsigned get_dim();
	virtual string info()=0;
};
/// \brief Класс для неограниченной области оптимизации
class All_space:public Area {
public:
	All_space(unsigned);
	virtual bool inside(vector<double>) override;
	virtual vector<double> correct_point(vector<double>, vector<double>) override;
	virtual string info() override;
};
/// \brief Класс для ограниченной области оптимизации
class Dom :public Area {
protected:
	vector<double> left;
	vector<double> right;
public:
	Dom(unsigned, vector<double>, vector<double>);
	virtual bool inside(vector<double>) override;
	/// \brief Генерация случайной точки из ограниченной области
	vector<double> get_random_point();
	virtual vector<double> correct_point(vector<double>, vector<double>) override;
	/// \brief Пересечение области с квадратом, заданным центром и половиной длины стороны
	Dom cross_dom(vector<double>, double);
	virtual string info() override;
};