#ifndef __NEW_H__
#define __NEW_H__
#include "Customer.h"
#include "pch.h"
#include "String.h"
//�ű԰�
class NewCustomer : public Customer {
private:
	int Point;//�߰���������Ʈ
public:
	NewCustomer(int id, String name, int Point)
		:Customer(id, name)
	{
		AddPoint(Point);
	}
	virtual void ShowCusInfo()
	{
		cout << "--�ű԰�--" << endl;
		Customer::ShowCusInfo();
	}
};
#endif