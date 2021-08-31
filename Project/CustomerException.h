#ifndef __CUS_EXCEPTION_H__
#define __CUS_EXCEPTION_H__
#include "CusCommonDecl.h"

class MinusException
{
private:
	int exval;    // 예외의 원인이 되는 금액

public:
	MinusException(int val) : exval(val)
	{  }

	void ShowExceptionInfo(void) const
	{
		cout <<  exval << "은 0보다 작아 유효하지 않습니다!" << endl;
	}
};

class InsuffException
{
private:
	int point;     // 현재 잔액
	int pp;      // 출금 요구액
public:
	InsuffException(int val, int val2)
		: point(val), pp(val2)
	{  }

	void ShowExceptionInfo() const
	{
		cout << "포인트 " << pp - point << "가(이) 부족합니다!" << endl;
	}
};

#endif
