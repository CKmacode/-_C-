/*
ѡ�������ö�̬����ʵ��		 
*/ 
#include <stdio.h>
#include <malloc.h>
void sort_Arr(int * Arr,int l);
int main()
{
	int i;
	int length;
	
	printf("���������鳤�ȣ�\n"); 
	scanf("%d",&length);
	int* Arr = (int*) malloc (sizeof(int)*length);
	
	printf("��������%d����\n",length);
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
	for (i = 0;i < l-1;i++ )//��������ע�������Ǵ�0��l-2�� 
	{
		max = i;
		for (j = i;j < l-1;j++)//��������ڵ����ֵ������������������� 
		{
			if (Arr[max] > Arr[j+1])	
			max = j+1;
		} 
	    tem = Arr[i];//�������� 
		Arr[i] = Arr[max];
		Arr [max] = tem;  
	}
	return;
}
