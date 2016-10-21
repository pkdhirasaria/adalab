# include <iostream>
using namespace std;

int main()
{
	int i,j,k,a[10][10],n;
	cout<<"\nEnter the number of vertices";
	cin>>n;
	cout<<"\nEnter the adjacency matrix\n";
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
			
	for (k=1;k<=n;k++)
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			{
				if  (a[i][k]+a[k][j]<a[i][j])
				a[i][j]=a[i][k]+a[k][j];
			}
			
	cout<<"The all-pair shortest path is\n";
	for (i=1;i<=n;i++)
	{	
		cout<<"\n";
		for (j=1;j<=n;j++)
			{
				cout<<a[i][j]<<" ";
			}
	}
	cout<<"\n";
	return 0;	
	
}

