# include <iostream>
using namespace std;
int main ()
{
	int i,j,n,k,g[10][10],m=0,sum=0;
	cout<<"\nEnter the number of nodes\n";
	cin>>n;
	int v[n],in[n];
	cout<<"\nEnter the adjcency matrix\n";
	for (i=0;i<n;i++)
	{
		v[i]=0,in[i]=0;
		for (j=0;j<n;j++)
		{
			cin>>g[i][j];
			if (g[i][j]==1)
				in[j]++;
		}
	}
	for (i=0;i<n;i++)
	{
		sum=0,m=0;
		for (j=0;j<n;j++)
		{
			sum+=g[j][i];
		}
		if (sum==0 && v[i]==0)
		{
			cout<<"\n"<<i+1;	
			v[i]=1;m=1;
			for (j=0;j<n;j++)
			{
				g[i][j]=0;
			}
		}
		if (m==1)
		i=0;
	}
} 
