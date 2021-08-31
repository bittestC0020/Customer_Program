#include "pch.h"
#include "Product.h"
#include "Customer.h"
#include "NewCustomer.h"
#include "NormalCustomer.h"
#include "VipCustomer.h"
#include "CustomerHandler.h"
#include "String.h"
#include "CusCommonDecl.h"

//��ǰ ����
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
	cout << "0. ��ǰ����" << endl;
	cout << "1. �����" << endl;
	cout << "2. ����(����Ʈ ����)" << endl;
	cout << "3. ����(����Ʈ ����)" << endl;
	cout << "4. ������ ��ȸ" << endl;
	cout << "5. ���α׷� ����" << endl;
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
	cout << "�� ���� ����" << endl;
	cout << "1. �ű԰����" << endl;
	cout << "2. �Ϲݰ����" << endl;
	cout << "3. ��������" << endl;
	cout << "����: ";
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
	cout << "[����]" << endl;
	cout << "��ID: ";	cin >> id;
	while (true) {
		cout << "������ ��ǰ(��ȣ�� �Է�): "; cin >> product;
		if (product < 0 || product>5) {
			cout << "��ǰ�� ���Է��ϼ���." << endl;
			continue;
		}
		cout << "��ǰ ����: "; cin >> count;
		if (count < 0) {
			cout << "��ǰ�� ������ �ٽ� �Է��ϼ���" << endl;
			continue;
		}
		money = count * (p[product - 1].GetProMoney());

		cout << "��ǰ " << p[product - 1].GetProname() << "�� " << count << "�� �����ϼ̽��ϴ�." << endl;
		cout << "�� �����ݾ��� " << money << "�Դϴ�." << endl;
		break;
	}


	while (true) {
		try {
			for (int i = 0; i < cusNum; i++) {
				if (cusArr[i]->GetCusID() == id) {
					cout << "����Ʈ �ܾ�: " << cusArr[i]->GetPoint() << endl;
					if (cusArr[i]->GetPoint() == 0) {
						cout << "���� �����ִ� ����Ʈ�� �����ϴ�." << endl;
						cusArr[i]->DepositAmount(money);
						cusArr[i]->DepositPoint(money);
						cout << "�����Ϸ�" << endl << endl;
						cout << "������ ����Ʈ: " << cusArr[i]->GetPoint() << endl << endl;
						return;
					}
					cout << "����� ����Ʈ: "; cin >> pp;
					cusArr[i]->Withdraw(pp);
					cout << "����Ʈ ��� �Ϸ�" << endl;
					money = money - pp;
					cout << "�����ݾ�: " << money << endl;
					cusArr[i]->DepositAmount(money);
					cusArr[i]->DepositPoint(money);
					cout << "�����Ϸ�" << endl << endl;
					cout << "������ ����Ʈ: " << cusArr[i]->GetPoint() << endl << endl;
					return;
				}
			}
			cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
			return;
		}
		catch(MinusException& expt){
			expt.ShowExceptionInfo();
			cout << "����� ����Ʈ�� ���Է��ϼ���." << endl;
		}
		catch (InsuffException& expt) {
			expt.ShowExceptionInfo();
			cout << "����� ����Ʈ�� ���Է��ϼ���." << endl;
		}
	}


}

void CustomerHandler::Buy_PointDeposit(void)
{
	int money=0;
	int id;
	int product;
	int count;
	cout << "[����]" << endl;
	cout << "��ID: ";	cin >> id;
	while (true) {
			cout << "������ ��ǰ(��ȣ�� �Է�): "; cin >> product;
			if (product < 0 || product>5) {
				cout << "��ǰ�� ���Է��ϼ���." << endl;
				continue;
			}
			cout << "��ǰ ����: "; cin >> count;
			if (count < 0) {
				cout << "��ǰ�� ������ �ٽ� �Է��ϼ���" << endl;
				continue;
			}
			money = count * (p[product - 1].GetProMoney());

			cout << "��ǰ " << p[product - 1].GetProname() << "�� " << count << "�� �����ϼ̽��ϴ�." << endl;
			cout << "�� �����ݾ��� " << money << "�Դϴ�." << endl;
			break;
	}
	for (int i = 0; i < cusNum; i++)
	{
		if (cusArr[i]->GetCusID() == id)
		{
			cusArr[i]->DepositAmount(money);
			cusArr[i]->DepositPoint(money);
			cout << "�����Ϸ�" << endl << endl;
			cout << "������ ����Ʈ: " << cusArr[i]->GetPoint() << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
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

	cout << "[�����]" << endl;
	cout << "��ID: ";	cin >> id;
	cout << "��  ��: ";	cin >> name;
	cout << "����Ʈ: "; cin >> pp;
	cout << endl;

	cusArr[cusNum++] = new NewCustomer(id, name,pp);
}

void CustomerHandler::MakeNormalCustomer()
{
	int id;
	String name;
	int rate;
	double p_rate=0;
	cout << "[�����]" << endl;
	cout << "��ID: ";	cin >> id;
	cout << "��  ��: ";	cin >> name;
	cout << "�߰�����Ʈ����([1]:0.01, [2]:0.02, [3]:0.03): "; cin >> rate;
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

	cout << "[�����]" << endl;
	cout << "��ID: ";	cin >> id;
	cout << "��  ��: ";	cin >> name;
	cout << "�߰�����Ʈ����([1]:0.01, [2]:0.02, [3]:0.03): "; cin >> p;
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

	cout << "�߰�������([1]:0.01, [2]:0.03, [3]:0.05):"; cin >> v;
	
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