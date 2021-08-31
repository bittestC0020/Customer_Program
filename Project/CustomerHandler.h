#ifndef __CUSTOMERHANDLER_H__
#define __CUSTOMERHANDLER_H__
#include "CustomerArray.h"
#include "Customer.h"
using namespace std;

class CustomerHandler {
	//Customer * cusArr[100];   // �� ������ ���� �迭
	BoundCheckCusArray<Customer *> cusArr;
	int cusNum = 0;        // ����� �� ��
public:
	CustomerHandler();

	~CustomerHandler();
	void ShowProduct(void);		//��ǰ����
	void ShowMenu(void);       // �޴����
	void CusRegister(void);    // �����
	void Buy_PointWithdraw(void); //�������_����Ʈ����
	void Buy_PointDeposit(void);//�������_����Ʈ����
	void ShowCusInfo(void);     // ��������ȸ

protected:
	void MakeNewCustomer();//�ű԰�
	void MakeNormalCustomer();//�Ϲݰ�
	void MakeVipCustomer();//�����
};
#endif