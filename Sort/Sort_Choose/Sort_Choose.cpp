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
		for(j = i+1;j < l;j++)
		{
			if(Arr[i] > Arr[j])
			{
				tem = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = tem;
			}	
			 
		}  
	}
	return;
}
