#include <iostream>
#include <cstdlib>
using namespace std;
void inc_order (int);
void dec_order (int);
void ran_order (int);
void lsearch (int [],int,int);
void bsearch (int [],int,int,int);
void isort (int [],int );
int a[100],c=0,cb=0,cl=0;

int main()
{
	int n,key,ch1,ch2;
	cout<<"\nEnter the number of elements\n";
	cin>>n;
	cout<<"\nEnter the order of elements\n1.Increasing\n2.Decreasing\n3.Random\n ";
	cin>>ch1;
	switch(ch1)
	{
		case 1:inc_order(n);
			break;
			
		case 2:dec_order(n);
			break;
			
		case 3:ran_order(n);
			break;
	}
	cout<<"\nEnter the key element to be searched\n";
	cin>>key;
	int l=0,r=n-1;
	cout<<"\nEnter the type of search\n1.Linear\n2.Binary\n";
	cin>>ch2;
	switch(ch2)
	{
		case 1:cl=0;lsearch (a,n,key);
			cout<<"\nThe number of key comparisons is "<<cl+1<<"\n";
			break;
			
		case 2:isort (a,n);cb=0;
			   bsearch (a,key,l,r);
			if (c==0)
			{
			      	cout<<"\nKey not found";
			}
			cout<<"\nThe number of key comparisons is "<<cb+1<<"\n";
			break;
			
		case 3:exit(0);
			break;
	}

}

void inc_order (int n)
{
	int i;
	for (i=0;i<n;i++)
		a[i]=i+1;
	cout<<"\nThe elements in increasing order are ";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
}

void dec_order (int n)
{
	int i;
	for (i=0;i<n;i++)
		a[i]=n-i;
	cout<<"\nThe elements in decreasing order are ";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
}

void ran_order (int n)
{
	int i;
	for (i=0;i<n;i++)
		a[i]=random()%100;
	cout<<"\nThe elements in random order are ";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
}

void lsearch (int a[],int n,int key)
{
	if (n<0)
		cout<<"\nNot found";
	if (key==a[n-1])
		cout<<"\nElement found at :"<<n;
	else 
	{
		cl++;lsearch(a,n-1,key);
	}
}

void bsearch (int a[],int key,int l,int r)
{
	if (l<=r)
	      	{
	      		int mid=(l+r)/2;
	      		if (key>a[mid])
	      		{
	      			cb++;
	      			bsearch (a,key,mid+1,r);
	      		}
	      		else if (key<a[mid])
	      		{
	      			cb++;
	      			bsearch (a,key,l,mid-1);
	      		}
	      		else if (key==a[mid])
	      		{
	      			cout<<"\nKey found at "<<mid+1<<"\n";
	      			c=1;
	      		}
		}
}

void isort (int a[],int n)
{
	int i,j,v;
	for (i=1;i<n;i++)
	{
		v=a[i];
		j=i-1;
		while ((j>=0) && a[j]>v)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=v;
	}	
	cout<<"\n\n";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
}

