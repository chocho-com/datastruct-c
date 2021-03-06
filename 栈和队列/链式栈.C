#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -10000
#define OK 1
#define ERROR 0
typedef int SElemType;
typedef int Status;
//-----��ʽջ�Ĵ洢�ṹ-----
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStack;

//-----��ʽջ�Ļ�������-----
Status InitStack(LinkStack *S);         //��ʼ��
Status Push(LinkStack *S, SElemType e); //��ջ
Status Pop(LinkStack *S, SElemType *e); //��ջ
SElemType GetTop(LinkStack S);             //ȡջ��Ԫ��
void print(LinkStack S);               //��ӡ

void main()
{
	LinkStack S;
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

	//��ջ
	Pop(&S, &e);
	printf("\n��ջԪ��Ϊ%d:", e);
	print(S);

	//ȡջ������
	printf("\nջ��Ԫ��Ϊ%d\n", GetTop(S));
}

Status InitStack(LinkStack *S)
{
	//1.������ջ
	(*S) = NULL;
	return OK;
}

Status Push(LinkStack *S, SElemType e)
{
	LinkStack node = NULL;

	//1.�����½��
	node  = (LinkStack)malloc(sizeof(SElemType));
	if(node == NULL)
	{
		printf("\n�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	node->data = e;

	//��ջ
	node->next = *S;
	*S = node;

	return OK;
}

Status Pop(LinkStack *S, SElemType *e)
{

	//1.�ж�ջ��
	if(*S == NULL)
	{
		printf("\nջ��\n");
		return ERROR;
	}

	//2.��ջ
	*e = (*S)->data;
	(*S) = (*S)->next;

	return OK;
}

SElemType GetTop(LinkStack S)
{
	if(S != NULL)
	{
		return S->data;
	}
	else
	{
		printf("\nջ��\n");
		return OVERFLOW;
	}
}

void print(LinkStack S)
{
	LinkStack p = S;

	if(S == NULL)
	{
		printf("\nջ��\n");
	}
	else
	{
		printf("\nS->[");
		while(p != NULL)
		{
			printf("->%d", p->data);
			p = p->next;
		}
		printf("]\n");
	}
}