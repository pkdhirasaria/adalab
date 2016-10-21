#include<iostream>         
using namespace std;
int val[10],w[10],v[10][10];
int knapsack(int i,int j);
int max(int a,int b);         
void subset(int n,int wt);

int main()
{
	int i,j,n,wt,res;
	cout<<"enter the no of items\n";
	cin>>n;
	cout<<"enter the weight and value of the items\n";
	for(i=1;i<=n;i++)
	{
	      cout<<"\n enter the weight of"<<i<<"item=";
	      cin>>w[i];
	      cout<<"\tvalue=";
	      cin>>val[i];
	}
	cout<<"enter the knapsack capacity\n";
	cin>>wt;
	for(i=0;i<=n;i++)
	      for(j=0;j<=wt;j++)
	      {
		  if(i==0||j==0)
			v[i][j]=0;  
		  else
			v[i][j]=-1;
		}
	res=knapsack(n,wt);  
	subset(n,wt); 
	cout<<"Maximum profit="<<res<<"\n";


}

int knapsack(int i,int j)
{
int value;

	if(v[i][j]<0)
	{
	   if(j<w[i])
	       value=knapsack(i-1,j);
	   else
	       value=max(knapsack(i-1,j),val[i]+knapsack(i-1,j-w[i]));

	   v[i][j]=value;
	}
return v[i][j];
}

int max(int a,int b)
{
	if(a>b)
	   return a;
	   return b;
}

void subset(int n,int wt)
{
int i,c;
c=wt;

	cout<<"the items in the knapsack are\n";
	while(c!=0)
	{
	    for(i=n;i>=0;i--)
	    {
		if(v[i][c]!=v[i-1][c])
		{
			c=c-w[i];
			cout<<"item"<<i<<"\n";
		}
	    }
	 }
}
         
         
