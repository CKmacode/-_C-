#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <malloc.h>//malloc��̬�ڴ���亯�� 
#include <stdlib.h>//exit���� 
struct Arr
{
	int * pBase;
	int len;
	int cnt;
};
void init_Arr(struct Arr * pArr,int length);//�����ʼ�� 
bool is_empty (struct Arr * pArr); 
bool is_full (struct Arr * pArr);
void show_Arr(struct Arr * pArr);
bool append_Arr(struct Arr * pArr,int val);//׷������ 
bool insert_Arr(struct Arr * pArr,int pos,int val);
void inversion_Arr(struct Arr * pArr);//����Ԫ�� 
bool delate_Arr (struct Arr * pArr,int pos,int* pval);
void sort_Arr(struct Arr * pArr);
bool getelem_Arr(struct Arr *pArr,int pos,int* pval); 
bool locateelem_Arr(struct Arr *pArr,int val,int* pos) ;
/*  ����ĳ�ʼ�� ,��̬�ڴ���� 
���룺�ṹ���׵�ַpArr������ĳ�ʼ������length 
���أ��� 
*/
void init_Arr(struct Arr * pArr,int length)
{
	pArr->pBase = (int *) malloc(sizeof(int)*length);
	if (pArr->pBase==NULL)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	} 
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}
/*�ж������Ƿ�Ϊ�� 
���룺�ṹ���׵�ַpArr
���أ�true/false 
*/
bool is_empty (struct Arr * pArr)
{
	if (pArr->cnt == 0)
	return true;
	else
	return false;
}
/*�ж������Ƿ�Ϊ�� 
���룺�ṹ���׵�ַpArr
���أ�true/false 
*/
bool is_full (struct Arr * pArr)
{
	if (pArr->cnt == pArr->len)
	return true;
	else
	return false;
}
/*���������� 
���룺�ṹ���׵�ַ 
������� 
*/
void show_Arr(struct Arr * pArr)
{
	if (is_empty(pArr))
	printf("����Ϊ��\n");
	else
	{
		for (int i = 0;i < pArr->cnt;i++)
		printf("%d ",pArr->pBase[i]);
	}
	printf("\n");	
	return;
} 
/*��������׷����������
���룺�ṹ���׵�ַpArr��Ҫ׷�ӵ�����val 
�����true/false 
*/
bool append_Arr(struct Arr *pArr,int val)
{
	if (is_full(pArr))
	return false;
	else
	{
		pArr->pBase[pArr->cnt] = val;
		pArr->cnt++;
	}
	return true;
}
/*��������posλ��ǰ����Ԫ�� 
���룺�ṹ���׵�ַpArr������λ��pos������Ԫ��val
�����true/false 
*/ 
bool insert_Arr(struct Arr *pArr,int pos,int val)
{
	int i;
	if (is_full(pArr)) 
		return false;
	if (pos > pArr->cnt||pos <= 0)
		return false;
	else
		{
			for(i = pArr->cnt-1;i >= pos-1;i--)
			{
				pArr->pBase[i+1] = pArr->pBase[i]; 
			}
			pArr->pBase[pos-1] = val;
			pArr->cnt++;
			return true;
		}
}
/*
ɾ������Arr��posλ���µ�Ԫ�أ������������ص�pvalָ��ĵ�ַ��
���룺�ṹ���׵�ַpArr��λ��pos������ָ�� pval
�����true/false 
*/ 
bool delate_Arr (struct Arr * pArr,int pos,int* pval)
{
	int i;
	if (is_empty(pArr))
		return false;
	else if (pos < 1||pos > pArr->cnt) 
		return false;
	else
		{
			*pval = pArr->pBase[pos-1];	
			for (i = pos;i < pArr->cnt;i++)
				pArr->pBase[i-1] = pArr->pBase[i];
			pArr->cnt--;
			return true;
		}		
	return true;
}
/*
�������и�Ԫ�ؽ���ǰ����
���룺�ṹ���׵�ַpArr
������� 
*/
void inversion_Arr(struct Arr*pArr)
{
	int i,tem;
	for (i = 0;i < (pArr->cnt/2);i++)
	{
		tem = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[pArr->cnt-i-1];
		pArr->pBase[pArr->cnt-i-1] = tem;
	}
	return;
}
/*
��������д�С�������������ʹ��ѡ�����򷨣�
���룺�ṹ���׵�ַ
������� 
*/
void sort_Arr(struct Arr * pArr)
{
	int i,j,min,tem;
	for (i = 0;i < pArr->cnt-1;i++)
	{
		min = i;
		for(j = i;j < pArr->cnt-1;j++)
		{
			if (pArr->pBase[min] > pArr->pBase[j+1])
				min = j+1;
		}
		tem = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[min];
		pArr->pBase[min] = tem;	 
	}
	return;
}
/*��������Arr�е�pos��Ԫ�أ�������ֵ���ص�pvalָ��Ķ���
���룺�ṹ���׵�ַpArr������λ��pos��ָ�����pval 
�����true/false
*/
bool getelem_Arr(struct Arr *pArr,int pos,int* pval)
{
	int val;
	if (is_empty(pArr))
	{
		printf("����Ϊ�գ�������ֹ\n"); 
		return false;
	}
	else if (pos < 1||pos > pArr->cnt) 
	{
		printf("��Ҫ�õ������ݲ����ڣ�������ֹ\n"); 
		return false;
	}
	
	val = pArr->pBase[pos-1];
	*pval = val;
	return true;
}
/*
���������г���valԪ�صĵ�һ�������������䷵�ص�posָ��ı�����
���룺�ṹ���׵�ַpArr��Ԫ��val������ָ��pos
�����true/false 
*/
bool locateelem_Arr(struct Arr *pArr,int val,int* pos) 
{
	int i;
	for(i = 0;i < pArr->cnt;i++)
	{
		if(pArr->pBase[i]==val)
			{
				*pos = i;
				return true;
			}
	} 
	printf("��Ҫ�ҵ����ݲ����ڣ�\n");
	return false; 
}



#endif
