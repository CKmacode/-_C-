#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Node//定义存储类型：结点Node 
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

int main (void)
{
	int val;
	PNODE pHead;
	pHead = creat_list();
	traverse_list(pHead);
/*	printf("链表的长度是%d\n",length_list(pHead));
	insert_list(pHead,3,666);
	traverse_list(pHead);
	delate_list(pHead,4,&val);
	traverse_list(pHead);
*/	sort_list(pHead);
	traverse_list(pHead);
	return 0;
}
/*
创建一个新的链表
输入：无
输出：头节点的地址 
*/
PNODE creat_list(void)
{
	int len,i;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
		{
			printf("分配内存失败，程序中止！\n");
			exit(-1);	
		} 
	PNODE pTail = pHead;
	printf("请输入您需要生成的链表字节数：\n");
	scanf("%d",&len);	
	for(i = 0;i < len;i++)
	{
		printf("请输入第%d个节点的值：\n",i+1);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL== pNew)
		{
			printf("分配内存失败，程序中止！");
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
遍历链表的每一个元素
输入：链表头节点的地址
输出：无 
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
判断链表是否为空
输入：头节点地址
输出：true/false 
*/
bool is_empty(PNODE pHead)
{
	if(pHead->pNext == NULL)
		return true;
	else
		return false;
}
/*
计算链表的长度
输入：头节点地址
输出：长度 
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
向链表第pos位置前插入元素val
输入：头节点地址、位置pos、插入元素val
输出：true/false 
*/
bool insert_list(PNODE pHead,int pos,int val)
{
	int i;
	PNODE p = pHead->pNext;
	if (pos > length_list(pHead)||pos < 1)
		{
			printf("插入位置不合理，插入失败！\n");
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
对链表中pos位置处的元素进行删除处理，并将删除元素的值放到val中 
输入：头节点地址、删除位置、存储删除元素的地址 
输出：true/false 
*/
bool delate_list(PNODE pHead,int pos,int *val)
{
	int i;
	PNODE p = pHead->pNext,q;
	if (pos > length_list(pHead) || pos < 1)
		{
			printf("地址无效，删除失败！\n");
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
对链表中的各元素按从小到大的顺序排序（这里选择用选择排序）
输入：头节点地址pHead
输出：无 
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


