# include <iostream>
# include <cstdlib>
using namespace std;
void inc_order (int,int []);
void dec_order (int,int []);
void ran_order (int,int []);
int partition(int [],int,int);
void quicksort (int [],int,int);
int cmp=1;

int main()
{
	int i,j,a[1000],n,ch,t;
	//while (1)
	//{
	
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
	
	quicksort (a,0,n-1);
	cout<<"\nElements after sorting are\n";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
		
		cout<<"\n\nTotal number of comparisons is :\n"<<cmp-1;
		
		/*cout<<"\nAgain ???? \n";
	cin>>t;
	if (t==0)
	break;
	}*/
}



int partition(int a[],int l,int r)
{
	int p,i=l,j=r+1,temp;
	p=a[l];
	do
	{
		do
		{
		     i++;
		     
		}while(cmp++ && a[i]<p);
		
		do
		{
			j--;
			
		}while(cmp++ && a[j]>p);
		
		temp=a[i];a[i]=a[j];a[j]=temp;
		
	}while(i<j);
	temp=a[i];a[i]=a[j];a[j]=temp;
	temp=a[l];a[l]=a[j];a[j]=temp;
	return j;
} 

void quicksort (int a[],int l,int r)
{
	int s;
	if (l<r)
	{
		s=partition(a,l,r);
		quicksort(a,l,s-1);
		quicksort(a,s+1,r);
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
		a[i]=random()%200;
	cout<<"\nThe elements in random order are ";
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
}
