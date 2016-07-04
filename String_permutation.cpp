#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

void aux(char *str,char *buf,int d,int n)
{
	if(d == n)
	{
	buf[d]='\0';
	cout<<buf<<endl;
	return;
	}
	for(int i=0;str[i]!='\0';i++)
	{
	buf[d] = str[i];
	aux(str,buf,d+1,n);
	}
}


void permute(char *str,int n)
{
	char buf[n+1];
	aux(str,buf,0,n);

}

int main()
{
char  str[]="ABCDEF";
int len;
len=strlen(str);
//cout<<len;
permute(str,len);
}

