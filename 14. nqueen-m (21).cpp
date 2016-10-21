#include<iostream>
#include<cmath>
using namespace std;
int count=0,x[100];
void nqueen(int k,int n);
int  place(int k,int i);
int main()
{
	int n;
	
	cout<<"\nEnter the number of queens:";
	cin>>n;
	nqueen(1,n);
	if(count==0)
	   cout<<"\n There is no solution for queens\n"<<n;
	else
	  cout<<"\nTotal number of solutions :"<<count;
	return 0;
}
int  place(int k,int i)
{
	int j;
	for(j=1;j<k;j++)
	    if((x[j]==i) ||(abs(x[j]-i)==abs(j-k)))
		return(0);
	return(1);
}
void nqueen(int k,int n)
{
	int i,j,p;
	for(i=1;i<=n;i++)
	   if(place(k,i))
	   {
		x[k]=i;
		if(k==n)
		{
		    count++;
		    for(j=1;j<=n;j++)
		    {
			for(p=1;p<=n;p++)
			if(x[j]==p)
			    cout<<" q\t ";
			 else
			    cout<<" 0\t ";
		     cout<<"\n";
		     }
			
		}
		else
		  nqueen(k+1,n);
	}
	cout<<"\n";
}

