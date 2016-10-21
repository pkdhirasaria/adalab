#include <iostream>
 using namespace std;
int a[20][20],q[20],visited[20],f=0,r=-1,i,n,j,v,m=0;
void bfs(int v)
{
   
     for(i=1;i<=n;i++)
     {
          if(a[v][i] && !visited[i])
          {
          	q[++r]=i;
          	cout<<"\t"<<v<<"-->"<<i<<"\n";
          }
                 
     }
     while (f<=r)
     {
         visited[q[f]]=1;
         bfs(q[f++]);
     }
     
}
int main()
{
  
      cout<<"\nEnter the no. of vertices\n";
      cin>>n;
      for(i=1;i<=n;i++)
      {
          visited[i]=0;
          q[i]=0;
      }
      cout<<"enter adjacency matrix for the graph\n";
      for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
      cin>>a[i][j];
      cout<<"enter the starting vertex\n";
      cin>>v;
      bfs(v);
      cout<<"nodes reachable from the given starting vertex "<<v<<" is\n";
      for(i=1;i<=n;i++)
      {
            if(visited[i])
            {
                m=1;
                cout<<"\t"<<i;
            }
            
              
      }  
      if(m==0)
          cout<<"no nodes are reachable from the starting vertex\n";
         
           cout<<"\n";
     return 0;
  
}
