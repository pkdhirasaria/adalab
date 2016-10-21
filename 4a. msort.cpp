# include <iostream>
# include <cstdlib>
using namespace std;
void inc_order (int,int []);
void dec_order (int,int []);
void ran_order (int,int []);
void merge (int [],int,int [],int,int [],int);
void mergesort (int [],int);

int cmp=1;

int main()
{
	int i,j,a[1000],n,ch,t;
	while (1)
	{
	
	cout<<"\nEnter the number of elements\n";
	cin>>n;
	cout<<"\n1.Increasing\n2.Decreasing\n3.Random";
	cout<<"\nEnter the choice\n";
	cin>>ch;
	switch (ch)
	{
		case 1 : inc_order(n,a);break;
		case 2 : dec_order(n,a);break;
		case 3 : ran_order(n,a);break;
	}
	
	mergesort(a,n);
	cout<<"\nElements after sorting are\n";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
		
		cout<<"\n\nTotal number of comparisons is :\n"<<cmp-1;
		
		cout<<"\nAgain ???? \n";
	cin>>t;
	if (t==0)
	break;
	}
}


void mergesort (int a[],int n)
{
	int p=n/2,i,j;
	int q=n-p;
	int b[p],c[q];
	if (n>1)
	{
		for (i=0;i<p;i++)
 		{
 			b[i]=a[i];
 		}

 		for (j=0;i<n;i++,j++)
 		{
 			c[j]=a[i];
 		}
		mergesort(b,p);
		mergesort(c,q);
		merge(b,p,c,q,a,n);
	}
}

void merge (int b[],int p,int c[],int q,int a[],int n)
{
	int i=0,j=0,k=0,l=0;
	while (cmp++ && i<p && j<q)
	{
		if (b[i]<c[j])
			a[k++]=b[i++];
		else
			a[k++]=c[j++];			
	}
	
	if (i==p)
	{
		for (l=j;l<q;k++,l++)
		a[k]=c[l];
	}
	else
	{
		for (l=i;l<p;k++,l++)
		a[k]=b[l];
	}
}


void inc_order (int n,int a[])
{
	int i;
	for (i=0;i<n;i++)
		a[i]=i+1;
	cout<<"\nThe elements in increasing order are ";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
}

void dec_order (int n,int a[])
{
	int i;
	for (i=0;i<n;i++)
		a[i]=n-i;
	cout<<"\nThe elements in decreasing order are ";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
}

void ran_order (int n,int a[])
{
	int i;
	for (i=0;i<n;i++)
		a[i]=random()%n;
	cout<<"\nThe elements in random order are ";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
}
