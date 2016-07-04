#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const char wrd[10][5]={"","","ABC","DEF","GHI","JKL","MNO","PORS","TUV","WXYZ"};

void aux(int *num,int n,char *out,int d)
{
	if(d == n)
	{
	cout<<out<<endl;
	return;
	}
	for(int i=0;i<(strlen(wrd[num[d]]));i++)
	{
	out[d] = wrd[num[d]][i];
	aux(num,n,out,d+1);
	if((num[d] == 0) ||(num[d] == 1))
	return;
	}

}
void permute(int *num,int n)
{
	char out[n+1];
	out[n]='\0';
	aux(num,n,out,0);

}
int main()
{
int num[] = {2,3,4,5,6,7,8,9};
int n = sizeof(num)/sizeof(num[0]);
permute(num,n);
}
