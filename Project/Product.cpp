#include "pch.h"
#include <iostream>
#include "Product.h"

Product::Product(int ID, int money, String name)
	:proID(ID), money(money)
{
	proname = name;
}

int Product::GetProID() const
{
	return proID;
}

int Product::GetProMoney() const
{
	return money;
}

String Product::GetProname() const
{
	return proname;
}
