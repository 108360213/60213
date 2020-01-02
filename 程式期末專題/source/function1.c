#include<stdio.h>
#include<stdlib.h>

int finalproject(int *dice1)
{
	if (dice1[0] == dice1[1] == dice1[2] == dice1[3])             //(5)全部一樣
		return 5;
	else if (dice1[3] == dice1[2] && dice1[2] != dice1[1] && dice1[1] != dice1[0])  //(4)EX:1355
		return 4;
	else if (dice1[2] == dice1[1] && dice1[3] != dice1[2] && dice1[1] != dice1[0])  //(3)EX:1335
		return 3;
	else if (dice1[1] == dice1[0] && dice1[2] != dice1[1] && dice1[3] != dice1[2])  //(2)EX:1135
		return 2;
	else if (dice1[1] == dice1[0] && dice1[2] != dice1[1] && dice1[3] == dice1[2])  //(2)EX:1122
		return 6;
	else                                                                            //(1)擲失敗 EX:1234 或 EX:1115 
		return 1;
}