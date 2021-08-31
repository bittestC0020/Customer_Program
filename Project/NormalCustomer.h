#ifndef __NORMAL_H__
#define __NORMAL_H__
#include "Customer.h"
#include "pch.h"
#include "String.h"
#include "CustomerException.h"
//�Ϲݰ�
class NormalCustomer : public Customer {
private:
	double PointRate;//�߰� ������
public:
	NormalCustomer(int id, String name,double p_rate)
		:Customer(id, name), PointRate(p_rate)
	{}
	virtual void DepositPoint(int money) {
		if (money < 0) {
			throw MinusException(money);
		}
		Customer::DepositPoint(money);
		Customer::DepositPoint(money * 10*PointRate);
	};
	virtual void ShowCusInfo()
	{
		cout << "--�Ϲݰ�--" << endl;
		Customer::ShowCusInfo();
	}
};
#endif