#include<iostream>
using namespace std;

long long  sol1_simple(int num)
{
	long long a=0,b=1, c;
	int i;
	for(i=3;i<=num;i++)
	{
	c=a+b;
	a=b;
	b=c;
	}
return c;
}


int sol2_rec(int num)
{
	if(num==1)	
	return 0;
	if(num==2)
	return 1;
	return sol2_rec(num-1)+sol2_rec(num-2);

}
long sum(int num,long *arr)
{
	if(num==1)
	return 0;
	if(num==2)
	return 1;
	if(arr[num]!=0)
	return arr[num];
	
	arr[num]= sum(num-1,arr)+sum(num-2,arr);
	return arr[num];
}
long sol3_dp(int num)
{
	long arr[num+1];
	int i;
	for(i=0;i<num+1;i++)
	arr[i]=0;
	return sum(num,arr);

}

int main()
{
int n;
cout<<"What number";
cin>>n;
long long res1=sol1_simple(n);
cout<<res1<<endl;
/////////////////////////////////////////////----------------Hanged----------------//////////////////////////////
//int res2=sol2_rec(n);
//cout<<res2<<endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long  res3=sol3_dp(n);
cout<<res3<<endl;
}
