#include <iostream>

using namespace std;

int max(int a,int b)
{
	return((a>b)?a:b);
}

int main()
{
	int items,cap;
	cout<<"\nEnter the no.of items :";
	cin>>items;
	cout<<"\nEnter the maximum capacity :";
	cin>>cap;
	int value[items],weight[items];
	weight[0]=0;
	value[0]=0;
	int mat[items+1][cap+1];
	for(int i=1;i<=items;++i)
	{	
		cout<<"\nEnter the weight "<<i<<" :";
		cin>>weight[i];
		cout<<"\nEnter the value "<<i<<" :";
		cin>>value[i];
	}
	
	//Knapsack table construction
	
	for(int i=0;i<=items;++i)
	{
		for(int j=0;j<=cap;++j)
		{
			if(i==0 || j==0)
				mat[i][j]=0;
			else if(j-weight[i]<0)
				mat[i][j]=mat[i-1][j];
			else
			{
				mat[i][j]=max(mat[i-1][j],value[i]+mat[i-1][j-weight[i]]);
			}
		}
	}
	
	for(int i=0;i<=items;++i)
	{
		for(int j=0;j<=cap;++j)
			cout<<mat[i][j]<<"\t";
		cout<<endl;	
	}
	cout<<"\nMaximum Weight : "<<mat[items][cap];
	cout<<"\nOptimal subset : ";
	cout<<"{ ";
	int j=cap;
	for(int i=items;i>0;--i)
	{
		if(mat[i][j]!=mat[i-1][j])
		{
			cout<<"item"<<i<<" , ";
			j=j-weight[i];
		}
	}
	cout<<"}";
	cout<<endl;
	
	return 0;	
}
