#ifndef _LIST_H_
#define _LIST_H_


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Node//����洢���ͣ����Node 
	{
		int data;
		struct Node* pNext;
	}NODE,*PNODE;

PNODE creat_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
bool insert_list(PNODE pHead,int pos,int val);
bool delate_list(PNODE pHead,int pos,int *val);
void sort_list(PNODE pHead);	

/*
����һ���µ�����
���룺��
�����ͷ�ڵ�ĵ�ַ 
*/
PNODE creat_list(void)
{
	int len,i;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
		{
			printf("�����ڴ�ʧ�ܣ�������ֹ��\n");
			exit(-1);	
		} 
	PNODE pTail = pHead;
	printf("����������Ҫ���ɵ������ֽ�����\n");
	scanf("%d",&len);	
	for(i = 0;i < len;i++)
	{
		printf("�������%d���ڵ��ֵ��\n",i+1);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL== pNew)
		{
			printf("�����ڴ�ʧ�ܣ�������ֹ��");
			exit(-1);
		}
		scanf("%d",&pNew->data);
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
/*
���������ÿһ��Ԫ��
���룺����ͷ�ڵ�ĵ�ַ
������� 
*/
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while(p!=0)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	return; 
}
/*
�ж������Ƿ�Ϊ��
���룺ͷ�ڵ��ַ
�����true/false 
*/
bool is_empty(PNODE pHead)
{
	if(pHead->pNext == NULL)
		return true;
	else
		return false;
}
/*
��������ĳ���
���룺ͷ�ڵ��ַ
��������� 
*/
int length_list(PNODE pHead)
{
	int len = 0;
	PNODE p;
	p = pHead->pNext;
	while(p != NULL)
	{
		len++;
		p = p->pNext;
	}
	return len;
}
/*
�������posλ��ǰ����Ԫ��val
���룺ͷ�ڵ��ַ��λ��pos������Ԫ��val
�����true/false 
*/
bool insert_list(PNODE pHead,int pos,int val)
{
	int i;
	PNODE p = pHead->pNext;
	if (pos > length_list(pHead)||pos < 1)
		{
			printf("����λ�ò���������ʧ�ܣ�\n");
			return false;
		}
		
	else
		{
			PNODE pNew = (PNODE)malloc(sizeof(NODE));
			pNew->data = val;
			for (i = 1;i < pos-1;i++)
			{
				p = p->pNext;
			}
			pNew->pNext = p->pNext;
			p->pNext = pNew;
			return true;
		}
}
/*
��������posλ�ô���Ԫ�ؽ���ɾ����������ɾ��Ԫ�ص�ֵ�ŵ�val�� 
���룺ͷ�ڵ��ַ��ɾ��λ�á��洢ɾ��Ԫ�صĵ�ַ 
�����true/false 
*/
bool delate_list(PNODE pHead,int pos,int *val)
{
	int i;
	PNODE p = pHead->pNext,q;
	if (pos > length_list(pHead) || pos < 1)
		{
			printf("��ַ��Ч��ɾ��ʧ�ܣ�\n");
			return false;
		}
	else
	{
		for(i = 1;i < pos-1;i++)
			{
				p = p->pNext;	
			}
		q = p->pNext;
		*val = q->data;	
		p->pNext = p->pNext->pNext; 
		free(q);
		return true;
	}
}
/*
�������еĸ�Ԫ�ذ���С�����˳����������ѡ����ѡ������
���룺ͷ�ڵ��ַpHead
������� 
*/
void sort_list(PNODE pHead)
{
	int i,j,tem,len = length_list(pHead);
	PNODE p = pHead->pNext;
	PNODE q = p;
	for (i = 0;i < len-1;i++)
	{
		for(j = i+1;j < len;j++)
			{
				q = q->pNext;
				if(p->data > q->data)
				{
					tem = p->data;
					p->data = q->data;
					q->data = tem;
				}
			}
		p = p->pNext;
		q = p;
	}
}
#endif
