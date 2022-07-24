#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main();

//
//x:공부가능 시간 총합,y=과목별 공부시간
//

int x[10000] = { 0 };
int y[10000] = { 0 };
//ry:과목별 공부시간 랜덤으로 돌린거
int ry[10000] = { 0 };

//ycount:과목별 공부시간 다 되었는지 체크
int ycount[10000] = { 0 };

//계산
int calculate(int xtime, int ytime)
{
	//2차원 배열로 비교 및 대입
	for (int i = 0; i < xtime; i++)
	{
		for (int j = 0; j < ytime; j++)
		{
			if (ycount[j] == 0)
			{
				if (x[i] >= ry[j])
				{
					printf(" %d분 짜리 과목은 x의 %d번째\n", ry[j], i + 1);
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

	//공부 가능 시간 묶음 수,과목 수
	int xtime, ytime = 0;
	//공부 가능 시간과 과목 별 시간의 총합
	int xsum = 0, ysum = 0;
	int Max_y = 0;
	int Max_x = 0;
	printf("공부 가능 시간의 묶음 수와 과목 수를 입력해주세요\n");
	scanf("%d %d", &xtime, &ytime);
	printf("\n공부 가능 시간을 차례대로 입력해주세요\n");

	for (int i = 0; i < xtime; i++)
	{
		scanf("%d", &x[i]);
		xsum += x[i];
		if (Max_x < x[i])
		{
			Max_x = x[i];
		}

	}
	printf("과목별 공부 시간을 입력해주세요\n");
	for (int i = 0; i < ytime; i++)
	{
		scanf("%d", &y[i]);
		ysum += y[i];
		if (Max_y < y[i])
		{
			Max_y = y[i];
		}
		printf("현재 총합:%d\n", ysum);
	}
	printf("\n");

	if (ysum > xsum)
	{
		printf("ERROR:공부 시간이 공부 가능 시간보다 많습니다\n");
		main();

	}
	else {
		if (Max_x < Max_y)
		{
			printf("ERROR:과목별 공부 시간중 공부 가능시간보다 많은 값이 존재합니다\n");
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