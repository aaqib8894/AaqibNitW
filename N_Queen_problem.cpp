#include<iostream>
#include<cmath>
using namespace std;
//----------------Only For Display in Matrix form can b avoided------------------ 
void print(int *out,int d)
{
		char display[d][d];
	for(int i=0;i<d;i++)
		{
		for(int j=0;j<d;j++)
		display[i][j] = '0';
		}
	int j=0;
	for(int i=0;i<d;i++)
		display[j++][out[i]]='X';

	for(int i=0;i<d;i++)
	{
		for(j=0;j<d;j++)
			cout<<"\t"<<display[i][j]<<"    ";
		cout<<endl;
	}
cout<<endl;
}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------

bool isvalid(int *out,int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(abs(i-j)==abs(out[i]-out[j]) || out[i] == out[j])
			return false;
		}
	}
return true;
}


void aux_n_queen(int *out,int d,int n)
{
	if(d == n)
	{
		if(isvalid(out,d))
		{
		print(out,d);	
		}
		return;	
	}
	for(int i=0;i<n;i++)
	{
		out[d]=i;
		aux_n_queen(out,d+1,n);
		
	}
}

void n_queen(int n)
{	
	int out[n];
	aux_n_queen(out,0,n);
}

int main()
{
int size;
cin>>size;
int mat[size];
n_queen(size);

}
