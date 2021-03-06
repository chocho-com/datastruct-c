#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -10000
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int SElemType;
typedef int Status;
//-----˳��ջ�Ĵ洢�ṹ-----
typedef struct
{
	SElemType *base;         //ջ��ָ��
	SElemType *top;          //ջ��Ԫ��
	int stackSize;           //ջ��������
}SqStack;

//-----˳��ջ�Ļ�������-----
Status InitStack(SqStack *S);           //��ʼ��
Status Push(SqStack *S, SElemType e);   //��ջ
Status Pop(SqStack *S, SElemType *e);   //��ջ
SElemType GetTop(SqStack S);            //ȡջ��Ԫ��
void print(SqStack S);                  //��ӡ

void main()
{
	SqStack S;
	int i;
	SElemType e;

	//��ʼ������
	InitStack(&S);

	//��ջ����
	for(i = 0; i < 10; i++)
	{
		Push(&S, i);
	}
	print(S);

	//��ջ����
	Pop(&S, &e);
	printf("\n��ջ%d:", e);
	print(S);

	//ȡջ��Ԫ��
	printf("\nջ��Ԫ��Ϊ%d\n", GetTop(S));
}

Status InitStack(SqStack *S)
{
	//1.��������ռ�
	(*S).base = (SElemType*)malloc(sizeof(SElemType)*MAXSIZE);
	if((*S).base == NULL)
	{
		printf("\nError:�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}

	//2.��ʼ��ָ����������
	(*S).top = (*S).base;
	(*S).stackSize = MAXSIZE;

	return OK;
}

Status Push(SqStack *S, SElemType e)
{
	//1.�ж�ջ��
	if((*S).top - (*S).base == (*S).stackSize)
	{
		printf("\nջ��\n");
		return ERROR;
	}

	//2.ѹջ
	*((*S).top) = e;
	(*S).top++;

	return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
	//1.�ж�ջ��
	if((*S).base == (*S).top)
	{
		printf("\nջ��\n");
		return ERROR;
	}

	//2.��ջ
	--(*S).top;
	*e = *((*S).top);

	return OK;
}

SElemType GetTop(SqStack S)
{
	//1.ȡջ��
	if(S.base != S.top)
	{
		S.top--;
		return *(S.top);
	}
	else
	{
		return OVERFLOW;
	}
}

void print(SqStack S)
{
	int i;

	if(S.base == S.top)
	{
		printf("\nջ��\n");
	}
	else
	{
		printf("\nbase->[");
		for(i = 0; i < S.top-S.base; i++)
		{
			printf(" %d", *(S.base+i));
		}
		printf(" ]<-top\n");
	}
}