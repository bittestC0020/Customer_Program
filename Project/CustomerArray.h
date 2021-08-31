#ifndef __CUS_ARRAY_H__
#define __CUS_ARRAY_H__
#include "Customer.h"
//typedef Customer * CUST_PTR;
template <typename T>
class BoundCheckCusArray
{
private:
	T * arr;
	int arrlen;

	BoundCheckCusArray(const BoundCheckCusArray& arr) { }
	BoundCheckCusArray& operator=(const BoundCheckCusArray& arr) { }

public:
	BoundCheckCusArray(int len = 100);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckCusArray();
};
template <typename T>
BoundCheckCusArray<T>::BoundCheckCusArray(int len) :arrlen(len)
{
	arr = new T[len];
}
template <typename T>
T& BoundCheckCusArray<T>::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}
template <typename T>
T BoundCheckCusArray<T>::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}
template <typename T>
int BoundCheckCusArray<T>::GetArrLen() const
{
	return arrlen;
}
template <typename T>
BoundCheckCusArray<T>::~BoundCheckCusArray()
{
	delete[]arr;
}
#endif
