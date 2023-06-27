#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iomanip> 
#include <exception>
#include <typeinfo>
#include <string.h>
using namespace std;
template <typename T>
class MAT {
	T* const e;							//指向所有整型矩阵元素的指针
	const int r, c;							//矩阵的行r和列c大小
public:
	MAT(int r, int c);						//矩阵定义
	MAT(const MAT& a);				//深拷贝构造
	MAT(MAT&& a)noexcept;			//移动构造
	virtual ~MAT()noexcept;
	virtual T* const operator[ ](int r);//取矩阵r行的第一个元素地址，r越界抛异常
	virtual MAT operator+(const MAT& a)const;	//矩阵加法，不能加抛异常
	virtual MAT operator-(const MAT& a)const;	//矩阵减法，不能减抛异常
	virtual MAT operator*(const MAT& a)const;	//矩阵乘法，不能乘抛异常
	virtual MAT operator~()const;					//矩阵转置
	virtual MAT& operator=(const MAT& a);		//深拷贝赋值运算
	virtual MAT& operator=(MAT&& a)noexcept;	//移动赋值运算
	virtual MAT& operator+=(const MAT& a);		//“+=”运算
	virtual MAT& operator-=(const MAT& a);		//“-=”运算
	virtual MAT& operator*=(const MAT& a);		//“*=”运算
//print输出至s并返回s：列用空格隔开，行用回车结束
	virtual char* print(char* s)const noexcept;
};
template <class T>
MAT<T>::MAT(int r, int c) :r(r), c(c), e(new T[r * c]) {
}
template <class T>
MAT<T>::MAT(const MAT& a) : r(a.r), c(a.c), e(new T[a.r * a.c])
{

	for (int i = 0; i < r * c; i++) {
		e[i] = a.e[i];
	}
}
template <class T>
MAT<T>::MAT(MAT&& a)noexcept :r(a.r), c(a.c), e(a.e)
{
	*(int*)&a.r = 0;
	*(int*)&a.c = 0;
	*(T**)&a.e = NULL;
}
template <class T>
MAT<T>::~MAT()noexcept
{
	if (e != NULL)
		delete e;
	*(int**)&e = NULL;
	*(int*)&r = 0;
	*(int*)&c = 0;
}
template <class T>
T* const MAT<T>:: operator[ ](int r)
{
	if (r < 0 || r >= this->r)
	{
		throw("error!");

	}
	return e + r * c;
}
template <class T>
MAT<T> MAT<T>:: operator+(const MAT<T>& a)const
{
	if (r != a.r || c != a.c)
	{
		throw("Can not add two matrices!");

	}
	MAT<T> ans(r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			//ans[i][j] = ((MAT)(*this))[i][j] + ((MAT)a)[i][j];
			ans.e[i * c + j] = e[i * c + j] + a.e[i * c + j];
		}
	}
	return ans;
}
template <class T>
MAT<T> MAT<T>:: operator-(const MAT<T>& a)const
{
	if (r != a.r || c != a.c)
	{
		throw("Can not add two matrices!");
		return *this;
	}
	MAT<T> ans(r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			//ans[i][j] = ((MAT)(*this))[i][j] - ((MAT)a)[i][j];
			ans.e[i * c + j] = e[i * c + j] - a.e[i * c + j];
		}
	}
	return ans;
}
template <class T>
MAT<T> MAT<T>:: operator*(const MAT<T>& a)const
{
	{
		if (c != a.r)
		{
			throw("Can not multiply two matrices!");
			return *this;
		}
		MAT ans(this->r, a.c);
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < a.c; j++)
			{
				int sum = 0;
				for (int k = 0; k < c; k++)
				{
					sum += e[k + i * c] * a.e[j + k * a.c];
				}
				ans.e[i * r + j] = sum;
			}
		}
		return ans;
	}

}
template <class T>
MAT<T> MAT<T>:: operator~()const
{
	MAT<T> ans(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ans[j][i] = ((MAT)(*this))[i][j];
		}
	}
	return ans;
}
template <class T>
MAT<T>& MAT<T>::operator=(const MAT<T>& a)
{
	if (this == &a) {
		return *this;
	}
	if (e != NULL)
	{
		delete(e);
	}
	*(T**)&e = new T[a.r * a.c];


	for (int i = 0; i < a.r * a.c; i++)
	{
		e[i] = a.e[i];
	}
	*(int*)&r = a.r;
	*(int*)&c = a.c;
	return *this;
}
template <class T>
MAT<T>& MAT<T>::operator=(MAT<T>&& a)noexcept
{
	if (this == &a) {
		return *this;
	}
	if (e != NULL)
	{
		delete(e);
	}
	*(T**)&e = a.e;
	*(int*)&r = a.r;
	*(int*)&c = a.c;
	*(T**)&a.e = NULL;
	*(int*)&a.r = 0;
	*(int*)&a.c = 0;
	return*this;
}
template <class T>
MAT<T>& MAT<T>::operator+=(const MAT<T>& a)
{
	if (r != a.r || c != a.c)
	{
		throw("Can not add two matrices!");
	}
	return *this=*this+a;
}
template <class T>
MAT<T>& MAT<T>::operator-=(const MAT<T>& a)
{
	if (r != a.r || c != a.c)
	{
		throw("Can not add two matrices!");
		return *this;
	}
	return *this = *this - a;
}
template <class T>
MAT<T>& MAT<T>::operator*=(const MAT<T>& a)
{
	if (c!=a.r)
	{
		throw("Can not multiply two matrices!");
	}
	/*MAT ans(r, a.c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < a.c; j++)
		{
			int sum = 0;
			for (int k = 0; k < c; k++)
			{
				sum += e[k + i * c] * a.e[j + k * a.c];
			}
			ans.e[i * r + j] = sum;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			this->e[i * c + j] = ans.e[i * c + j];
		}
	}*/
	return *this=*this*a;
}

template <class T>
char* MAT<T>::print(char* s)const noexcept
{
	char temp[2000];
	if (typeid(e[0]) == typeid(int))
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (j == c - 1)
				{
					sprintf(temp, "%6d\n\0", (int)e[i * c + j]);
				}
				else
				{
					sprintf(temp, "%6d \0", (int)e[i * c + j]);
				}
				strcat(s, temp);
			}
		}
	}
	else if (typeid(e[0]) == typeid(long long))
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (j == c - 1)
				{
					sprintf(temp, "%6lld\n\0", (long long)(e[i * c + j]));
				}
				else
				{
					sprintf(temp, "%6lld \0", (long long)(*(e + i * c + j)));
				}
				strcat(s, temp);
			}
		}
	}
	return s;
}



template MAT<int>;			//用于实验四，必须放在模板定义文件的尾部，用于强制实例化
template MAT<long long>;		//用于实验四，必须放在模板定义文件的尾部，用于强制实例化


