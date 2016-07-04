#include<iostream>
using namespace std;

int tower_of_honai(int n,char src,char aux,char trgt)
{
	if(n==1)
	{
	cout<<" "<<src<<"->"<<trgt<<endl;
	}
	else
	{
	tower_of_honai(n-1,src,trgt,aux);
	cout<<" "<<src<<"->"<<trgt<<endl;
	tower_of_honai(n-1,aux,src,trgt);	
	}
}

int main()
{
	int n;
	cout<<"\nEnter number of disk";
	cin>>n;
	cout<<"\nWe are using three disk A (source) B (auxilary) C (Target)\n";
	tower_of_honai(n,'A','B','C');

}
