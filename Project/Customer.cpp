#include "pch.h"
#include <iostream>
#include <cstring>
#include "Customer.h"
#include "CustomerException.h"
using namespace std;

Customer::Customer(int ID, String name)
	: cusID(ID), point(0)
{
	//cusName = new char[strlen(name) + 1];
	//strcpy(cusName, name);
	cusName = name;
}
/*
Customer::Customer(const Customer & ref)
	: cusID(ref.cusID), amount(ref.amount), point(ref.point)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

Customer & Customer::operator=(const Customer & ref)
{
	cusID = ref.cusID;
	amount = ref.amount;
	point = ref.point;
	delete[] cusName;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
	return *this;
}
*/
int Customer::GetCusID() const { return cusID; }


int Customer::GetPoint() { return point; }

void Customer::AddPoint(int pp)
{
	point += pp;
}


void Customer::DepositAmount(int money)
{
	if (money < 0) {
		throw MinusException(money);
	}
	amount += money;
}

void Customer::DepositPoint(int money)
{
	if (money < 0) {
		throw MinusException(money);
	}
	point += money * 0.1;
}
int Customer::Withdraw(int p) 
{
	if (point < p) {
		throw InsuffException(point,p);
	}
	if (p < 0) {
		throw MinusException(p);
	}

	point -= p;
	return p;
}

void Customer::ShowCusInfo()
{
	cout << "°èÁÂID: " << cusID << endl;
	cout << "ÀÌ  ¸§: " << cusName << endl;
	cout << "ÃÑ°áÁ¦±Ý¾×: " << amount << endl;
	cout << "ÃÑÆ÷ÀÎÆ®: " << point << endl;
}
/*
Customer::~Customer()
{
	delete[]cusName;
}
*/