#include "pch.h"
#include <iostream>
#include <cstring>
#include "Customer.h"
#include "CustomerHandler.h"
#include "CusCommonDecl.h"
using namespace std;

int main(void)
{
	CustomerHandler manager;
	int choice;

	while (1)
	{
		//타이틀 출력
		cout << "----고객관리----" << endl;
		manager.ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case PRODUCT:
			manager.ShowProduct();
			break;
		case REGISTER:
			manager.CusRegister();
			break;
		case BUY_1:
			manager.Buy_PointWithdraw();
			break;
		case BUY_2:
			manager.Buy_PointDeposit();
			break;
		case SHOW:
			manager.ShowCusInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
}