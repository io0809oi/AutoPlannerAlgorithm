#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main();

//
//x:���ΰ��� �ð� ����,y=���� ���νð�
//

int x[10000] = { 0 };
int y[10000] = { 0 };
//ry:���� ���νð� �������� ������
int ry[10000] = { 0 };

//ycount:���� ���νð� �� �Ǿ����� üũ
int ycount[10000] = { 0 };

//���
int calculate(int xtime, int ytime)
{
	//2���� �迭�� �� �� ����
	for (int i = 0; i < xtime; i++)
	{
		for (int j = 0; j < ytime; j++)
		{
			if (ycount[j] == 0)
			{
				if (x[i] >= ry[j])
				{
					printf(" %d�� ¥�� ������ x�� %d��°\n", ry[j], i + 1);
					x[i] -= ry[j];
					ycount[j]++;
				}
				else {
					continue;
				}
			}
			else {
				continue;
			}

		}
	}

	return 0;
}

int input()
{

	//���� ���� �ð� ���� ��,���� ��
	int xtime, ytime = 0;
	//���� ���� �ð��� ���� �� �ð��� ����
	int xsum = 0, ysum = 0;
	int Max_y = 0;
	int Max_x = 0;
	printf("���� ���� �ð��� ���� ���� ���� ���� �Է����ּ���\n");
	scanf("%d %d", &xtime, &ytime);
	printf("\n���� ���� �ð��� ���ʴ�� �Է����ּ���\n");

	for (int i = 0; i < xtime; i++)
	{
		scanf("%d", &x[i]);
		xsum += x[i];
		if (Max_x < x[i])
		{
			Max_x = x[i];
		}

	}
	printf("���� ���� �ð��� �Է����ּ���\n");
	for (int i = 0; i < ytime; i++)
	{
		scanf("%d", &y[i]);
		ysum += y[i];
		if (Max_y < y[i])
		{
			Max_y = y[i];
		}
		printf("���� ����:%d\n", ysum);
	}
	printf("\n");

	if (ysum > xsum)
	{
		printf("ERROR:���� �ð��� ���� ���� �ð����� �����ϴ�\n");
		main();

	}
	else {
		if (Max_x < Max_y)
		{
			printf("ERROR:���� ���� �ð��� ���� ���ɽð����� ���� ���� �����մϴ�\n");
			return main();
		}
		else {
			int a = 0;
			for (int i = 0; i < ytime; i++)
			{
				a = rand() % ytime;
				if (ry[a] != NULL)
				{
					i--;
					continue;
				}
				else
				{
					ry[a] = y[i];
				}
			}
			sort(x,x+xtime);
			calculate(xtime, ytime);

		}
	}
	return 0;
}

int main()
{

	input();


	return 0;
}