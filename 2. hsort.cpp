# include <iostream>
using namespace std;
int cmp=0;
void heap (int a[],int n)
{
	int i,j,k,h,v;
	for (i=n/2;i>=1;i--)
	{
		h=0;k=i;v=a[k];
		while (h==0 && 2*k<=n)
		{
			j=2*k;
			if (j<n)
			{
				cmp++;
				if (a[j]<a[j+1])
				{
					j++;cmp++;
				}
			}
			
			if (v>=a[j])
			{
				cmp++;
				h=1;
			}
			else
			{
				a[k]=a[j];
				k=j;
			}
		}
		a[k]=v;
	}
}

void del (int a[],int n)
{
	int t;
	t=a[1];
	a[1]=a[n];
	a[n]=t;
}

int main ()
{
	int a[500],i,j,n; 
	cout<<"\nEnter the number of elements\n";
	cin>>n;
	cout<<"\nEnter the elements\n";
	for (i=1;i<=n;i++)
	cin>>a[i];
	j=n;
	heap(a,n);
	for (i=1;i<=n;i++)
	{
		del(a,j);
		heap(a,j-1);
		j--;
	}
	cout<<"\nElements after sorting are\n";
	for (i=1;i<=n;i++)
	cout<<a[i]<<"\t";
	cout<<"\nNumber of comparisons made is\t"<<cmp;
	return 0;
}
