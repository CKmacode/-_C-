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
void push(PSTACK,int);//压栈 
void traverse(PSTACK);
bool pop(PSTACK,int*);//出栈
void clear(PSTACK);
 
/*
栈的初始化
输入：栈结构体地址
输出：无 
*/
void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(pS->pTop == NULL)
	{
		printf("分配内存失败，程序中止！\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pBottom->pNext = NULL;
	}
	
}
/*
压栈
输入：栈结构体地址
输出：无 
*/
void push(PSTACK pS,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		printf("分配内存失败，程序中止！\n");
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
遍历 
输入：栈结构体地址
输出：无 
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
出栈
输入： 栈结构体地址，出栈存储地址
输出：true/false 
*/
bool pop(PSTACK pS,int* pVal)
{
	if(pS->pTop == pS->pBottom)
	{
		printf("出栈失败！\n");
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
清栈 
输入：栈结构体地址
输出：无 
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
