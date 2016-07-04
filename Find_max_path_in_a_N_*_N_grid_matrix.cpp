#include<iostream>
#define n 3
using namespace std;
void print(int grid[n][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		cout<<grid[i][j]<<"  ";
	cout<<endl;
	}
}
//Recursion + using memory
/*********************************************/
int aux(int grid[n][n],int i,int j,int arr[n][n])
{
	if(i < 0 || j < 0) return 0;
	if(arr[i][j]!=0) return arr[i][j];
	else
	{
	int m_l = aux(grid,i,j-1,arr);
	int m_u = aux(grid,i-1,j,arr);
	arr[i][j] =  max(m_l,m_u)+grid[i][j];
	}
	return arr[i][j];
}

void max_path(int grid[n][n])
{
	int arr[n][n];
	int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	arr[i][j]=0;
	cout<<aux(grid,n-1,n-1,arr);

}
//-------*--------------------------------------*
//DP solution----------------------------------
int dp_aux(int grid[n][n],int arr[n][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		arr[i][j] = max(i==0?0:arr[i-1][j],j==0?0:arr[i][j-1])+grid[i][j];
		}
	}
	return arr[n-1][n-1];

}

void dp_sol(int grid[n][n])
{
	int arr[n][n]={0};
	cout<<dp_aux(grid,arr);	
}

int main()
{
int grid[n][n]= {
		{5,2,3},
		{4,7,6},
		{7,1,2},	
		};
print(grid);
max_path(grid);
dp_sol(grid);

}
