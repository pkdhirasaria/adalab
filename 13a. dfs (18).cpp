# include <iostream>
# include <cstdlib>
using namespace std;
void dfs (int [],int,int);
int g[10][10],count=0;

int main ()
{
	int i,j,n,k;
	cout<<"\nEnter the number of nodes\n";
	cin>>n;
	int v[n];
	cout<<"\nEnter the adjcency matrix\n";
	for (i=0;i<n;i++)
	{
		v[i]=0;
		for (j=0;j<n;j++)
		cin>>g[i][j];
	}
	cout<<"\nEnter the starting node\n";
	cin>>k;
	cout<<"\n\n";
	dfs(v,k,n); 
	cout<<"\n\n";
	if (count==n)
	cout<<"\nConnected\n";
	else cout<<"\nNot connected\n";
	for (i=0;i<n;i++)
	{
		if (v[i]==0)
		cout<<"\n"<<i<<" is not reachable from "<<k<<"\n";
		else cout<<"\n"<<i<<" is reachable from "<<k<<"\n";
	}
}


void dfs (int v[],int k,int n)
{
	int j;
	count++;
	v[k]=1;
	cout<<k<<"\t";
	for (j=0;j<n;j++)
	{
		if (v[j]==0 && g[k][j]==1)
		{
			dfs (v,j,n);
			cout<<k<<"-->"<<j<<"\t";
		}
		
	}
}
