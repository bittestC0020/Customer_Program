#include "pch.h"
#include "Product.h"
#include "Customer.h"
#include "NewCustomer.h"
#include "NormalCustomer.h"
#include "VipCustomer.h"
#include "CustomerHandler.h"
#include "String.h"
#include "CusCommonDecl.h"

//상품 종류
Product p[5] = {
	Product(1, 50000, "OUTER"),
	Product(2, 10000, "SKIRTS"),
	Product(3, 30000, "DRESS"),
	Product(4, 5000, "HAT"),
	Product(5, 20000, "SHOES")
};

CustomerHandler::CustomerHandler()
	: cusNum(0)
{
}

CustomerHandler::~CustomerHandler()
{
	for (int i = 0; i < cusNum; i++) {
		delete cusArr[i];
	}
}

void CustomerHandler::ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "0. 상품보기" << endl;
	cout << "1. 고객등록" << endl;
	cout << "2. 결제(포인트 차감)" << endl;
	cout << "3. 결제(포인트 적립)" << endl;
	cout << "4. 고객정보 조회" << endl;
	cout << "5. 프로그램 종료" << endl;
}
void CustomerHandler::ShowProduct(void)
{
	cout << "-----Product------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << p[i].GetProID() << ": " << p[i].GetProname() << endl;
	}
	cout << endl;

}
void CustomerHandler::CusRegister(void)
{
	int type;
	cout << "고객 종류 선택" << endl;
	cout << "1. 신규고객등록" << endl;
	cout << "2. 일반고객등록" << endl;
	cout << "3. 우수고객등록" << endl;
	cout << "선택: ";
	cin >> type;
	if (type == NEW) {
		MakeNewCustomer();
	}
	else if (type==NORMAL){
		MakeNormalCustomer();
	}
	else {
		MakeVipCustomer();
	}
}

void CustomerHandler::Buy_PointWithdraw(void)
{
	int money;
	int id;
	int pp;
	int product, count;
	cout << "[결제]" << endl;
	cout << "고객ID: ";	cin >> id;
	while (true) {
		cout << "구매할 상품(번호로 입력): "; cin >> product;
		if (product < 0 || product>5) {
			cout << "상품을 재입력하세요." << endl;
			continue;
		}
		cout << "상품 개수: "; cin >> count;
		if (count < 0) {
			cout << "상품의 개수를 다시 입력하세요" << endl;
			continue;
		}
		money = count * (p[product - 1].GetProMoney());

		cout << "상품 " << p[product - 1].GetProname() << "을 " << count << "개 구매하셨습니다." << endl;
		cout << "총 결제금액은 " << money << "입니다." << endl;
		break;
	}


	while (true) {
		try {
			for (int i = 0; i < cusNum; i++) {
				if (cusArr[i]->GetCusID() == id) {
					cout << "포인트 잔액: " << cusArr[i]->GetPoint() << endl;
					if (cusArr[i]->GetPoint() == 0) {
						cout << "현재 남아있는 포인트가 없습니다." << endl;
						cusArr[i]->DepositAmount(money);
						cusArr[i]->DepositPoint(money);
						cout << "결제완료" << endl << endl;
						cout << "적립된 포인트: " << cusArr[i]->GetPoint() << endl << endl;
						return;
					}
					cout << "사용할 포인트: "; cin >> pp;
					cusArr[i]->Withdraw(pp);
					cout << "포인트 사용 완료" << endl;
					money = money - pp;
					cout << "결제금액: " << money << endl;
					cusArr[i]->DepositAmount(money);
					cusArr[i]->DepositPoint(money);
					cout << "결제완료" << endl << endl;
					cout << "적립된 포인트: " << cusArr[i]->GetPoint() << endl << endl;
					return;
				}
			}
			cout << "유효하지 않은 ID 입니다." << endl << endl;
			return;
		}
		catch(MinusException& expt){
			expt.ShowExceptionInfo();
			cout << "사용할 포인트를 재입력하세요." << endl;
		}
		catch (InsuffException& expt) {
			expt.ShowExceptionInfo();
			cout << "사용할 포인트를 재입력하세요." << endl;
		}
	}


}

void CustomerHandler::Buy_PointDeposit(void)
{
	int money=0;
	int id;
	int product;
	int count;
	cout << "[결제]" << endl;
	cout << "고객ID: ";	cin >> id;
	while (true) {
			cout << "구매할 상품(번호로 입력): "; cin >> product;
			if (product < 0 || product>5) {
				cout << "상품을 재입력하세요." << endl;
				continue;
			}
			cout << "상품 개수: "; cin >> count;
			if (count < 0) {
				cout << "상품의 개수를 다시 입력하세요" << endl;
				continue;
			}
			money = count * (p[product - 1].GetProMoney());

			cout << "상품 " << p[product - 1].GetProname() << "을 " << count << "개 구매하셨습니다." << endl;
			cout << "총 결제금액은 " << money << "입니다." << endl;
			break;
	}
	for (int i = 0; i < cusNum; i++)
	{
		if (cusArr[i]->GetCusID() == id)
		{
			cusArr[i]->DepositAmount(money);
			cusArr[i]->DepositPoint(money);
			cout << "결제완료" << endl << endl;
			cout << "적립된 포인트: " << cusArr[i]->GetPoint() << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void CustomerHandler::ShowCusInfo(void)
{

	for (int i = 0; i < cusNum; i++)
	{
		cusArr[i]->ShowCusInfo();
		cout << endl;
	}
}

void CustomerHandler::MakeNewCustomer()
{
	int id;
	String name;
	int pp;

	cout << "[고객등록]" << endl;
	cout << "고객ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "포인트: "; cin >> pp;
	cout << endl;

	cusArr[cusNum++] = new NewCustomer(id, name,pp);
}

void CustomerHandler::MakeNormalCustomer()
{
	int id;
	String name;
	int rate;
	double p_rate=0;
	cout << "[고객등록]" << endl;
	cout << "고객ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "추가포인트비율([1]:0.01, [2]:0.02, [3]:0.03): "; cin >> rate;
	switch (rate)
	{
	case A:
		p_rate = 0.01;
		break;
	case B:
		p_rate = 0.02;
		break;
	case C:
		p_rate = 0.03;
		break;
	default:
		cout << "Illegal selection.." << endl;
	}
	cout << endl;

	cusArr[cusNum++] = new NormalCustomer(id, name, p_rate);
}

void CustomerHandler::MakeVipCustomer()
{
	int id;
	String name;
	int p,v;

	double p_rate=0;
	double v_rate=0;

	cout << "[고객등록]" << endl;
	cout << "고객ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "추가포인트비율([1]:0.01, [2]:0.02, [3]:0.03): "; cin >> p;
	switch (p)
	{
	case A:
		p_rate = 0.01;
		break;
	case B:
		p_rate = 0.02;
		break;
	case C:
		p_rate = 0.03;
		break;
	default:
		cout << "Illegal selection.." << endl;
	}

	cout << "추가할인율([1]:0.01, [2]:0.03, [3]:0.05):"; cin >> v;
	
	switch (v)
	{
	case A:
		v_rate = 0.01;
		break;
	case B:
		v_rate = 0.03;
		break;
	case C:
		v_rate = 0.05;
		break;
	default:
		cout << "Illegal selection.." << endl;
	}

	cout << endl;

	cusArr[cusNum++] = new VipCustomer(id, name, p_rate, v_rate);
}