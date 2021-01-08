/*
选择排序：用动态数组实现		 
*/ 
#include <stdio.h>
#include <malloc.h>
void sort_Arr(int * Arr,int l);
int main()
{
	int i;
	int length;
	
	printf("请输入数组长度：\n"); 
	scanf("%d",&length);
	int* Arr = (int*) malloc (sizeof(int)*length);
	
	printf("请输入这%d个数\n",length);
	for(i=0;i <length;i++)
	scanf("%d",Arr+i);
	
	sort_Arr(Arr,length);
	
	for( i=0;i <length;i++)
	printf("%d ",*(Arr+i));
	return 0;
} 

void sort_Arr(int * Arr,int l)
{
	int i,j,tem,max;
	for (i = 0;i < l-1;i++ )//定基引（注意这里是从0—l-2） 
	{
		max = i;
		for (j = i;j < l-1;j++)//求出定域内的最大值，将其索引与基引互换 
		{
			if (Arr[max] > Arr[j+1])	
			max = j+1;
		} 
	    tem = Arr[i];//交换索引 
		Arr[i] = Arr[max];
		Arr [max] = tem;  
	}
	return;
}
