#ifndef __PRODUCT_H__
#define __PRODUCT_H__
#include "String.h"
class Product {
private:
	int proID;
	int money;
	String proname;
public:
	Product(int ID, int money, String name);//��ǰ����

	int GetProID() const;//��ǰID
	int GetProMoney() const;//��ǰ �ݾ�
	String GetProname() const;//��ǰ �̸�

};

#endif
