#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__
#include "String.h"
class Customer
{
private:
	int cusID;      // 고객ID
	int amount;	// 결제금액
	int point;      // 포 인 트
	//char * cusName; // 고객이름
	String cusName;//고객이름
public:
	Customer(int ID, String name);//고객생성
	//Customer(const Customer &ref);//복사생성자
	//Customer& operator=(const Customer& ref);//연산자 오버로딩

	int GetCusID() const;//고객ID

	int GetPoint();//고객Point

	void AddPoint(int pp);//포인트를 매개변수로 하여 포인트를 누적

	virtual void DepositAmount(int money);//결제금액 누적

	virtual void DepositPoint(int money);//결제금액을 매개변수로 하여 결제금액에 따라 포인트 적립

	int Withdraw(int p); //포인트 차감

	virtual void ShowCusInfo();//전체 조회

	//~Customer();//삭제
};

#endif