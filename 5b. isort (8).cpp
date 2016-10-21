# include <iostream>
#include<cstdlib>
using namespace std;
void inc_order (int);
void dec_order (int);
void ran_order (int);
int a[100];
int main()
{
	int i,j,v,ch,n,c=0,f1=0,f2=0,c1=0,c2=0,f3=0,c3=0;
	cout<<"\nEnter the number of elements";
	cin>>n;
	cout<<"\n1.Increasing\n2.Decreasing\n3.Random";
	cout<<"\nEnter the choice";
	cin>>ch;
	switch (ch)
	{
		case 1 : inc_order(n);f1=1;break;
		case 2 : dec_order(n);f2=1;break;
		case 3 : ran_order(n);f3=1;break;
	}
	
	for (i=1;i<n;i++)
	{
		v=a[i];
		j=i-1;
		c3++;
		if (f1==1)
		c1++;
		while ((j>=0) && a[j]>v)
		{
			if (f2==1)
			c2++;
			if (f3==1)
			c3++;
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=v;
	}	
	cout<<"\n\n";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
	if (f1==1)
	cout<<"\nThe no. of comparisons are  "<<c1;
	if (f2==1)
	cout<<"\nThe no. of comparisons are  "<<c2;
	if (f3==1)
	cout<<"\nThe no. of comparisons are  "<<c3-1;
	return 0;
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
		a[i]=random()%n;
	cout<<"\nThe elements in random order are ";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
}
