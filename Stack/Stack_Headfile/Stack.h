#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <malloc.h> 
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE,*PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;

void init(PSTACK);
void push(PSTACK,int);//ѹջ 
void traverse(PSTACK);
bool pop(PSTACK,int*);//��ջ
void clear(PSTACK);
 
/*
ջ�ĳ�ʼ��
���룺ջ�ṹ���ַ
������� 
*/
void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(pS->pTop == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pBottom->pNext = NULL;
	}
	
}
/*
ѹջ
���룺ջ�ṹ���ַ
������� 
*/
void push(PSTACK pS,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	else
	{
		pNew->pNext = pS->pTop;
		pS->pTop = pNew;
		pNew->data = val;
	}	
}
/*
���� 
���룺ջ�ṹ���ַ
������� 
*/
void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;
	while (p != pS->pBottom)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}
/*
��ջ
���룺 ջ�ṹ���ַ����ջ�洢��ַ
�����true/false 
*/
bool pop(PSTACK pS,int* pVal)
{
	if(pS->pTop == pS->pBottom)
	{
		printf("��ջʧ�ܣ�\n");
		return false;
	}
	else
	{
		PNODE p = pS->pTop;
		pS->pTop = p->pNext;
		*pVal = p->data;
		free(p);
		p = NULL;
		return true;
	}	
}
/*
��ջ 
���룺ջ�ṹ���ַ
������� 
*/
void clear(PSTACK pS)
{
	int val;
	while(pS->pTop != pS->pBottom)
	{
		pop(pS,&val);
	}
} 
 
#endif
