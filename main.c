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
		printf("��(1)�Y��l�A��(2)�T�{�W�h�A��(3)�h�X�C��");
		scanf_s("%d", &mode);
		switch (mode)
		{
		case 1:
			//���a�Y��l
			do
			{
				roll(&Dice1[0]);					       	 //�Y��l
				bubble(&Dice1[0]);							 //���Ƽƾ�
				check_point = finalproject(&Dice1[0]);				 //�T�{���ƪ�������l����m
			} while (check_point == 1);						 //�p�G�S�Y���\�N�~���Y��l
			print_result(&Dice1[0], Time, check_point);		 //�L�X�ڪ���l�����G
			if (check_point == 5)							 //�Y�X�@��F
				break;
			point1 = point_counter(&Dice1[0], check_point);	 //�p�⪱�a���o��
															 //�q���Y��l
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
			point2 = point_counter(&Dice2[0], check_point);  //�p��q�����o��
			VS(point1, point2);								 //������a�P�q��������
			break;
		case 2:
			print_rule();                                    //�L�X�W�h
			break;
		case 3:
			system("pause");                                 //�h�X�C��
			return 0;
		default:
			break;
		}
	}


}

void print_rule()                                                 //�L�X�W�h
{
	printf("�ѹq���N����a\n"
		"���C���@�߬O���Ƥj�����\n"
		"���a�N�Y�U4����l\n"
		"���Y�즳2����l���I�Ƥ@�ˮ�\n"
		"�N��l2����l���I�Ƭۥ[�αo��\n"
		"����ջ�l�I�Ƥ@�ˮ�\n"
		"�h�H�I�Ƹ��j�̤��X�p����ұo�I��\n"
		"��3����l�ۦP�B�t�@�����P�ɤ������Y\n"
		"��4����l�I�ƬҬۦP�ɵL���I�ƪ������"
		"\n");
}

void roll(int *Dice)                                              //�Y��l
{
	int i;
	for (i = 0; i < 4; i++)
		Dice[i] = 1 + (rand() % 6);
}



void bubble(int *material)                                         //�����I�ƪ��ƦC��m
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

void print_result(int *result, int K, int check_point)      //�L�X��l�����G
{
	int i;
	switch (check_point)                                   //�T�{��l�����G�Ҧ�
	{
	case 2:
		if (K == 0)                                          //K==0 �O���a,K==1 �O�q��
		{
			int total1 = result[3] + result[2];
			printf("�A���Y�X����l:\n");
			for (i = 0; i < 4; i++)                        //�L�X�|����l
				printf("%4d", result[i]);
			printf("\n���a���o��:%d\n", total1);
			break;
		}
		else
		{
			int total2 = result[3] + result[2];
			printf("�q���ҩ��Y�X����l:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n�q�����o��:%d\n", total2);
			break;
		}
	case 3:
		if (K == 0)
		{
			int total1 = result[3] + result[0];
			printf("�A���Y�X����l:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n���a���o��:%d\n", total1);
			break;
		}
		else
		{
			int total2 = result[3] + result[0];
			printf("�q���ҩ��Y�X����l:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n�q�����o��:%d\n", total2);
			break;
		}
	case 4:
		if (K == 0)
		{
			int total1 = result[1] + result[0];
			printf("�A���Y�X����l:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n���a���o��:%d\n", total1);
			break;
		}
		else
		{
			int total2 = result[1] + result[0];
			printf("�q���ҩ��Y�X����l:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n�q�����o��:%d\n", total2);
			break;
		}
	case 5:
		if (K == 0)
		{
			printf("�A���Y�X����l:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n�A�Y�X�F'�@��'\n�AĹ�F!!\n");
			break;
		}
		else
		{
			printf("�q���ҩ��Y�X����l:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n�q���Y�X�F'�@��'\n�A��F!!\n");
			break;
		}
	case 6:
		if (K == 0)
		{
			int total1 = result[3] + result[2];
			printf("�A���Y�X����l:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n���a���o��:%d\n", total1);
			break;
		}
		else
		{
			int total2 = result[3] + result[2];
			printf("�q���ҩ��Y�X����l:\n");
			for (i = 0; i < 4; i++)
				printf("%4d", result[i]);
			printf("\n�q�����o��:%d\n", total2);
			break;
		}
	default:
		break;
	}

}

void VS(int player, int computer)                         //����o��
{
	if (player > computer)
		printf("�AĹ�F!!\n");
	else if (player < computer)
		printf("�A��F!!\n");
	else
		printf("����!!\n");
}

int point_counter(int *result, int check_point)            //�p��æ^�Ǳo��
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