#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[],int l,int h)
{
	int pivot=a[l];
	int i=l,j=h;
	do
	{
	 do{i++;}while(a[i]<=pivot);
	 do{j--;}while(a[j]>pivot);
	 
	if(i<j)	swap(&a[i],&a[j]);
		
	}while(i<j);
	swap(&a[l],&a[j]);
	return j;
}
void quick_sort(int a[],int l,int h)
{
	int j;
	if(l<h)
	{
		j=partition(a,l,h);
	//	cout<<a[j]<<endl;
		quick_sort(a,l,j);
		quick_sort(a,j+1,h);
	}
}
void display(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
	cout<<a[i]<<" ";
	}
}
void both_merge(int a[],int l,int mid,int h)
{
	int i=l;
	int j=mid+1;
	int k=l;
	int b[h+1];
	while(i<=mid && j<=h)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	for( ;i<=mid;i++)
	{
		b[k++]=a[i];
	}
	for( ;j<=h;j++)
	{
		b[k++]=a[j];
	}
	for(int i=l;i<=h;i++)
	{
		a[i]=b[i];
	}
}
void merge_sort(int a[],int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		merge_sort(a,l,mid);
		merge_sort(a,mid+1,h);
		both_merge(a,l,mid,h);
	}
}
int main()
{
//	int a[10]={4,5,3,7,6,INT_MAX};
		int a[10]={4,5,3,11,10,7,6,1};
	int n=8;
 //	quick_sort(a,0,n-1);
   merge_sort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
	cout<<a[i]<<" ";
	}
	 // display(a,n);
}
