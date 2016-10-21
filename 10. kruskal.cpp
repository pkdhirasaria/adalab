 #include<iostream>
using namespace std;
	int parent[10],ne=1,mincost=0,cost[10][10];
	
int main()
{
	int i,j,a,b,u,v,n,min;
	cout<<"\nEnter the no. of nodes\n";
	cin>>n;

	cout<<"\nEnter the cost matrix\n";
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	  {
	      cin>>cost[i][j];
	      if(cost[i][j]==0)
		 cost[i][j]=999;
	   }

	cout<<"\nEdges of minimum spanning tree are:\n";
	while(ne<n)
	{
		min=999;
	   for(i=1;i<=n;i++)
	      for(j=1;j<=n;j++)
		if(cost[i][j]<min)
		 {
		    min=cost[i][j];
		    a=u=i;
		    b=v=j;
		 }

		 while(parent[u])
		    u=parent[u];
		 while(parent[v])
		    v=parent[v];

	   if(u!=v)
	   {
	       cout<<ne++<<"  Edge ("<<a<<b<<") :"<<min<<"\n";
	       mincost+=min;
	       parent[v]=u;
	   }

	   cost[a][b]=cost[b][a]=999;
	}
	cout<<"Mincost ="<<mincost<<"\n";
	return 0;
}
