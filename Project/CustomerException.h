#ifndef __CUS_EXCEPTION_H__
#define __CUS_EXCEPTION_H__
#include "CusCommonDecl.h"

class MinusException
{
private:
	int exval;    // ������ ������ �Ǵ� �ݾ�

public:
	MinusException(int val) : exval(val)
	{  }

	void ShowExceptionInfo(void) const
	{
		cout <<  exval << "�� 0���� �۾� ��ȿ���� �ʽ��ϴ�!" << endl;
	}
};

class InsuffException
{
private:
	int point;     // ���� �ܾ�
	int pp;      // ��� �䱸��
public:
	InsuffException(int val, int val2)
		: point(val), pp(val2)
	{  }

	void ShowExceptionInfo() const
	{
		cout << "����Ʈ " << pp - point << "��(��) �����մϴ�!" << endl;
	}
};

#endif
