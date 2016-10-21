#include <iostream>
using namespace std;


int main()
{
	int a,b,u,v,n,i,j,ne=1;
	int visited[10],min=0,mincost=0,cost[10][10];
	cout<<"Enter the no. of nodes\n";
	cin>>n;

	cout<<"enter cost matrix\n";
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	  {
	     cin>>cost[i][j];
	     if(cost[i][j]==0)
		cost[i][j]=999;
	  }

	  for(i=2;i<=n;i++)
	     visited[i]=0;

	  cout<<"The edges of spanning tree are:\n";
	  visited[1]=1;

	  while(ne<n)
	  {
	     for(i=1,min=999;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					if(visited[i])
		      		{
			 			min=cost[i][j];
			 			a=i;
			 			b=j;
		      		}
				}
		      
			}
		   

	     if(visited[a]==0 ||visited[b]==0)
	     {
			cout<<ne++<<"edge("<<a<<b<<"):"<<min<<"\n";
			mincost+=min;
			visited[b]=1;
	     }
	     cost[a][b]=cost[b][a]=999;
	  }
	  cout<<"\n";
	  cout<<"Mincost ="<<mincost<<"\n";
	  return 0;
}
