#include <stdio.h>
#include <malloc.h>//malloc动态内存分配函数 
#include <stdlib.h>//exit函数 
struct Arr
{
	int * pBase;
	int len;
	int cnt;
};
void init_Arr(struct Arr * pArr,int length);//数组初始化 
bool is_empty (struct Arr * pArr); 
bool is_full (struct Arr * pArr);
void show_Arr(struct Arr * pArr);
bool append_Arr(struct Arr * pArr,int val);//追加数据 
bool insert_Arr(struct Arr * pArr,int pos,int val);
void inversion_Arr(struct Arr * pArr);//倒置元素 
bool delate_Arr (struct Arr * pArr,int pos,int* pval);
void sort_Arr(struct Arr * pArr);
bool getelem_Arr(struct Arr *pArr,int pos,int* pval) ;
bool locateelem_Arr(struct Arr *pArr,int val,int* pos) ;
//*********************************************************
int main ()//主函数用于测试各板块是否成功 
{
	struct Arr array;
	int l = 8,val,val_1,val_2 = 666;
	int pos = 10;
	init_Arr (&array,l);
	append_Arr (&array,5);
	append_Arr (&array,1);
	append_Arr (&array,8);
	append_Arr (&array,1);
	append_Arr (&array,3);
	insert_Arr(&array,3,2);
	insert_Arr(&array,4,666);
	
	printf("Inited:\n");
	show_Arr (&array);
	
	
	printf("Delated:\n");
	delate_Arr(&array,4,&val);
	show_Arr (&array);
	printf("删掉的元素是：%d\n",val);
	
	printf("Sorted:\n");
	sort_Arr(&array);
	show_Arr (&array);
	
	printf("inverted\n");
	inversion_Arr(&array);
	show_Arr (&array);
	
	if (getelem_Arr(&array,pos,&val_1)) 
	printf("第%d个元素是%d\n",pos,val_1);
	
	if (locateelem_Arr(&array,val_2,&pos))
	printf("数组中第一次出现%d的索引为%d\n",val_2,pos);
	 

	return 0;
}

/*  数组的初始化 ,动态内存分配 
输入：结构体首地址pArr，数组的初始化长度length 
返回：无 
*/
void init_Arr(struct Arr * pArr,int length)
{
	pArr->pBase = (int *) malloc(sizeof(int)*length);
	if (pArr->pBase==NULL)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	} 
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}
/*判断数组是否为空 
输入：结构体首地址pArr
返回：true/false 
*/
bool is_empty (struct Arr * pArr)
{
	if (pArr->cnt == 0)
	return true;
	else
	return false;
}
/*判断数组是否为满 
输入：结构体首地址pArr
返回：true/false 
*/
bool is_full (struct Arr * pArr)
{
	if (pArr->cnt == pArr->len)
	return true;
	else
	return false;
}
/*对数组的输出 
输入：结构体首地址 
输出：无 
*/
void show_Arr(struct Arr * pArr)
{
	if (is_empty(pArr))
	printf("数组为空\n");
	else
	{
		for (int i = 0;i < pArr->cnt;i++)
		printf("%d ",pArr->pBase[i]);
	}
	printf("\n");	
	return;
} 
/*向数组中追加其他数据
输入：结构体首地址pArr，要追加的数据val 
输出：true/false 
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
/*向数组中pos位置前插入元素 
输入：结构体首地址pArr，插入位置pos，插入元素val
输出：true/false 
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
删除数组Arr中pos位置下的元素，并将该数返回到pval指向的地址中
输入：结构体首地址pArr，位置pos，接受指针 pval
输出：true/false 
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
对数组中各元素进行前后倒置
输入：结构体首地址pArr
输出：无 
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
对数组进行从小到大的排序（我们使用选择排序法）
输入：结构体首地址
输出：无 
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
/*查找数组Arr中第pos个元素，并将其值返回到pval指向的对象
输入：结构体首地址pArr，查找位置pos，指针变量pval 
输出：true/false
*/
bool getelem_Arr(struct Arr *pArr,int pos,int* pval)
{
	int val;
	if (is_empty(pArr))
	{
		printf("数组为空，程序中止\n"); 
		return false;
	}
	else if (pos < 1||pos > pArr->cnt) 
	{
		printf("您要得到的数据不存在，程序中止\n"); 
		return false;
	}
	
	val = pArr->pBase[pos-1];
	*pval = val;
	return true;
}
/*
查找数组中出现val元素的第一个索引，并将其返回到pos指向的变量中
输入：结构体首地址pArr，元素val，索引指针pos
输出：true/false 
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
	printf("您要找到数据不存在！\n");
	return false; 
}








