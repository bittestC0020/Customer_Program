#ifndef __NEW_H__
#define __NEW_H__
#include "Customer.h"
#include "pch.h"
#include "String.h"
//신규고객
class NewCustomer : public Customer {
private:
	int Point;//추가적립포인트
public:
	NewCustomer(int id, String name, int Point)
		:Customer(id, name)
	{
		AddPoint(Point);
	}
	virtual void ShowCusInfo()
	{
		cout << "--신규고객--" << endl;
		Customer::ShowCusInfo();
	}
};
#endif