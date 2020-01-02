#include<stdio.h>
#include<stdlib.h>
#include<time.h>	
#include"mix.h"

void bubble(int *material);
void VS(int player, int computer);
void print_rule();
void roll(int*Dice);
//int check(int *dice1);
void swap(int *a, int *b);
void print_result(int *result, int K, int check_point);
int point_counter(int *result, int check_point);

int main(void)
{
	srand(time(NULL));
	int mode, check_point;
	int Dice1[4];
	int Dice2[4];
	int point1;
	int point2;
	while (1)
	{
		int Time = 0;
		printf("按(1)擲骰子，按(2)確認規則，按(3)退出遊戲");
		scanf_s("%d", &mode);
		switch (mode)
		{
		case 1:
			//玩家擲骰子
			do
			{
				roll(&Dice1[0]);					       	 //擲骰子
				bubble(&Dice1[0]);							 //美化數據
				check_point = finalproject(&Dice1[0]);				 //確認重複的兩顆骰子的位置
			} while (check_point == 1);						 //如果沒擲成功就繼續擲骰子
			print_result(&Dice1[0], Time, check_point);		 //印出我的骰子的結果
			if (check_point == 5)							 //擲出一色了
				break;
			point1 = point_counter(&Dice1[0], check_point);	 //計算玩家的得分
															 //電腦擲骰子
			Time++;
			do
			{
				roll(&Dice2[0]);
				bubble(&Dice2[0]);
				check_point = finalproject(&Dice2[0]);
			} while (check_point == 1);
			print_result(&Dice2[0], Time, check_point);
			if (check_point == 5)
				break;
			point2 = point_counter(&Dice2[0], check_point);  //計算電腦的得分
			VS(point1, point2);								 //比較玩家與電腦的分數
			break;
		case 2:
			print_rule();                                    //印出規則
			break;
		case 3:
			system("pause");                                 //退出遊戲
			return 0;
		default:
			break;
		}
	}


}

void print_rule()                                                 //印出規則
{
	printf("由電腦代表莊家\n"
		"本遊戲一律是分數大者獲勝\n"
		"玩家將擲下4顆骰子\n"
		"當擲到有2顆骰子的點數一樣時\n"
		"將其餘2顆骰子的點數相加及得分\n"
		"當有兩組骰子點數一樣時\n"
		"則以點數較大者之合計為其所得點數\n"
		"有3顆骰子相同且另一顆不同時仍須重擲\n"
		"當4顆骰子點數皆相同時無論點數直接獲勝"
		"\n");
}

void roll(int *Dice)                                              //擲骰子
{
	int i;
	for (i = 0; i < 4; i++)
		Dice[i] = 1 + (rand() % 6);
}



void bubble(int *material)                                         //美化點數的排列位置
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3 - i; j++)
		{
			if (material[j] >= material[j + 1])
				swap(&material[j], &material[j + 1]);
		}
	}
}

void swap(int *a, int*b)
{
	int p;
	p = *a;
	*a = *b;
	*b = p;
}

void print_result(int *result, int K, int check_point)      //印出骰子的結果
{
	int i;
	switch (check_point)                                   //確認骰子的分佈模式
	{
	case 2:
		if (K == 0)                                          //K==0 是玩家,K==1 是電腦
		{
			int total1 = result[3] + result[2];
			printf("你所擲出的骰子:\n");
			for (i = 0; i < 4; i++)                        //印出四顆骰子
				printf("%4d", result[i]);
			printf("\n玩家的得分:%d\n", total1);
			break;
		}
		else
		{
			int total2 = result[3] + result[2];
			printf("電腦所所擲出的骰子:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n電腦的得分:%d\n", total2);
			break;
		}
	case 3:
		if (K == 0)
		{
			int total1 = result[3] + result[0];
			printf("你所擲出的骰子:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n玩家的得分:%d\n", total1);
			break;
		}
		else
		{
			int total2 = result[3] + result[0];
			printf("電腦所所擲出的骰子:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n電腦的得分:%d\n", total2);
			break;
		}
	case 4:
		if (K == 0)
		{
			int total1 = result[1] + result[0];
			printf("你所擲出的骰子:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n玩家的得分:%d\n", total1);
			break;
		}
		else
		{
			int total2 = result[1] + result[0];
			printf("電腦所所擲出的骰子:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n電腦的得分:%d\n", total2);
			break;
		}
	case 5:
		if (K == 0)
		{
			printf("你所擲出的骰子:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n你擲出了'一色'\n你贏了!!\n");
			break;
		}
		else
		{
			printf("電腦所所擲出的骰子:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n電腦擲出了'一色'\n你輸了!!\n");
			break;
		}
	case 6:
		if (K == 0)
		{
			int total1 = result[3] + result[2];
			printf("你所擲出的骰子:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n玩家的得分:%d\n", total1);
			break;
		}
		else
		{
			int total2 = result[3] + result[2];
			printf("電腦所所擲出的骰子:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n電腦的得分:%d\n", total2);
			break;
		}
	default:
		break;
	}

}

void VS(int player, int computer)                         //比較得分
{
	if (player > computer)
		printf("你贏了!!\n");
	else if (player < computer)
		printf("你輸了!!\n");
	else
		printf("平手!!\n");
}

int point_counter(int *result, int check_point)            //計算並回傳得分
{
	int total;

	switch (check_point)
	{
	case 2:
		total = result[3] + result[2];
		break;
	case 3:
		total = result[3] + result[0];
		break;
	case 4:
		total = result[1] + result[0];
		break;
	case 6:
		total = result[2] + result[3];
		break;
	default:
		break;
	}
	return total;
}