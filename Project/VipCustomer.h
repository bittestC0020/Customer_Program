#ifndef __VIPCUSTOMER_H__
#define __VIPCUSTOMER_H__
#include "NormalCustomer.h"
#include "String.h"

class VipCustomer : public NormalCustomer {
private:
	double VipRate;
public:
	VipCustomer(int id, String name, double p_rate, double v_rate)
		:NormalCustomer(id, name, p_rate), VipRate(v_rate)
	{}

	virtual void DepositAmount(int money) {
		if (money < 0) {
			throw MinusException(money);
		}
		NormalCustomer::DepositAmount(money*(1 - VipRate));
	};
	virtual void DepositPoint(int money) {
		if (money < 0) {
			throw MinusException(money);
		}
		NormalCustomer::DepositPoint(money*(1 - VipRate));
	};
	virtual void ShowCusInfo()
	{
		cout << "--¿ì¼ö°í°´--" << endl;
		Customer::ShowCusInfo();
	}
};
#endif
