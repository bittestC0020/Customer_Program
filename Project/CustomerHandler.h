#ifndef __CUSTOMERHANDLER_H__
#define __CUSTOMERHANDLER_H__
#include "CustomerArray.h"
#include "Customer.h"
using namespace std;

class CustomerHandler {
	//Customer * cusArr[100];   // 고객 저장을 위한 배열
	BoundCheckCusArray<Customer *> cusArr;
	int cusNum = 0;        // 저장된 고객 수
public:
	CustomerHandler();

	~CustomerHandler();
	void ShowProduct(void);		//상품보기
	void ShowMenu(void);       // 메뉴출력
	void CusRegister(void);    // 고객등록
	void Buy_PointWithdraw(void); //결제방식_포인트차감
	void Buy_PointDeposit(void);//결제방식_포인트적립
	void ShowCusInfo(void);     // 고객정보조회

protected:
	void MakeNewCustomer();//신규고객
	void MakeNormalCustomer();//일반고객
	void MakeVipCustomer();//우수고객
};
#endif