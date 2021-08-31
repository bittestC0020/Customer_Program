#ifndef __PRODUCT_H__
#define __PRODUCT_H__
#include "String.h"
class Product {
private:
	int proID;
	int money;
	String proname;
public:
	Product(int ID, int money, String name);//상품생성

	int GetProID() const;//상품ID
	int GetProMoney() const;//상품 금액
	String GetProname() const;//상품 이름

};

#endif
