# include <iostream>
using namespace std;

int main()
{
	int i,j,n,k,c[100][100],l;
	cout<<"\nEnter the values of n and k\n";
	cin>>n>>k;
	for (i=0;i<=n;i++)
	{
		if (i<k)
		l=i;
		else
		l=k;
		for (j=0;j<=l;j++)
		{
			if (j==0 || j==i)
			c[i][j]=1;
			else c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	cout<<"\nThe answer is  "<<c[n][k]<<"\n";
	return 0;
}
