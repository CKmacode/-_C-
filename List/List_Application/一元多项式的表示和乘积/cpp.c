#include <stdio.h>
#include <malloc.h>
typedef struct Node
{
	int coef;//coefficient 系数
	int expn;//exponent 指数 
	struct Node* pNext;
}NODE,*PNODE;

PNODE create_polyn();
void sort_List(PNODE pHead)
int main()
{
	PNODE pPolyn = create_polyn();
	PNODE p = pPolyn->pNext;
	while(p!=NULL)
	{
		printf("%d*x^%d",p->coef,p->expn);
		if(p->pNext!=NULL)
		printf("+");
		p = p->pNext;
	}
	return 0;
}
PNODE create_polyn()//polyn多项式
{
	int coef1,expn1;
	PNODE pHead = (PNODE)malloc(sizeof(NODE)),pNew,pTop = pHead;
	while(1)
	{
		printf("请输入系数与对应指数：\n");
		scanf("%d %d",&coef1,&expn1); 
		if (coef1 == 0 && expn1 == 0)
			break;
		pNew = (PNODE)malloc(sizeof(NODE));
		pNew->coef = coef1;
		pNew->expn = expn1;
		pNew->pNext = NULL;
		pTop->pNext = pNew;
		pTop = pNew;
	} 
	return pHead;
} 
int length_List(PNODE pHead)
{
	int len = 0;
	PNODE p = pHead->pNext;
	while(p!=NULL)
	{
		len++;
		p = p->pNext;	
	} 
	return len;
}
void sort_List(PNODE pHead)
{
	int i,j,len;
	PNODE p = pHead->pNext,q = p->pNext;
	len = length_List(pHead);
	for (i = 0;i < len -1;i++)
	{
		for (j = i+1;j < len;j++)
		{
			if(p->expn < q->expn)
			{
				q与p的交换；
				q = q->pNext; 
			}
			p = p->pNext;
			q = p->pNext;
		}
	}
}











