#include<iostream>
using namespace std;
void dijkstra(int n,int v,int cost[10][10],int dist[10])
{
	int i,u,count,w,flag[10],min;

	for(i=1;i<=n;i++)
	{
		flag[i]=0;
		dist[i]=cost[v][i];
	}

	flag[v]=1;
	dist[v]=1;
	count=2;

	while(count<=n)
	{
		min=999;

		for(w=1;w<=n;w++)
			if(dist[w]<min && !flag[w])
			      {
				     min=dist[w];
				     u=w;
			      }

		flag[u]=1;
		count++;

		for(w=1;w<=n;w++)
		       if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
				  dist[w]=dist[u]+cost[u][w];
	}
}

int main()
{
	int n,v,i,j,cost[10][10],dist[10];
	cout<<"Enter the no. of nodes\n";
	cin>>n;

	cout<<"\nEnter the cost matrix\n";
	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	    {
		cin>>cost[i][j];
		if(cost[i][j]==0)
		    cost[i][j]=999;
	    }

	cout<<"\nEnter the source vertex\n";
	cin>>v;
	dijkstra(n,v,cost,dist);

	cout<<"\nShortest path from\n";
	for(j=1;j<=n;j++)
	   if(j!=v)
	       cout<<"\n  "<<v<<"-->"<<j<<"::"<<dist[j]<<"\n";
	
	return 0;
}