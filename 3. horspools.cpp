#include <iostream>
#include <cstring>
using namespace std;
char pattern[100],text[510],table[510];
int m,n,i,j,k;
int horsepool()
{
	for(i=0;i<n;i++)
		table[text[i]]=m;
	for(j=0;j<m-1;j++)
		table[pattern[j]]=m-1-j;
	i=m-1;
	while (i<n)
	{
		k=0;
		while((k<m)&&(pattern[m-1-k]==text[i-k]))
			k++;
		if(k==m)
			return i-m+1;
		else
			i=i+table[text[i]];
	}
	return -1;
}
int main()
{
	int indx;
	cout<<"enter a sentence with space indicated by _ or -\n";
	cin>>text;
	cout<<"enter the substring\n";
	cin>>pattern;
	n=strlen(text);
	m=strlen(pattern);
	indx=horsepool();
	for(k=0;k<m;)
	{
		if(text[indx++]==pattern[k++])
			continue;
		else
			break;
	}
	if(k==m)
		cout<<"substring found at pos:"<<indx-m+1<<"\n";
	else
		cout<<"substring not found\n";
        return 0;
}
		

