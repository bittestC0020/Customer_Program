#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__
#include "String.h"
class Customer
{
private:
	int cusID;      // ��ID
	int amount;	// �����ݾ�
	int point;      // �� �� Ʈ
	//char * cusName; // ���̸�
	String cusName;//���̸�
public:
	Customer(int ID, String name);//������
	//Customer(const Customer &ref);//���������
	//Customer& operator=(const Customer& ref);//������ �����ε�

	int GetCusID() const;//��ID

	int GetPoint();//��Point

	void AddPoint(int pp);//����Ʈ�� �Ű������� �Ͽ� ����Ʈ�� ����

	virtual void DepositAmount(int money);//�����ݾ� ����

	virtual void DepositPoint(int money);//�����ݾ��� �Ű������� �Ͽ� �����ݾ׿� ���� ����Ʈ ����

	int Withdraw(int p); //����Ʈ ����

	virtual void ShowCusInfo();//��ü ��ȸ

	//~Customer();//����
};

#endif