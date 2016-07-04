#include<iostream>
using namespace std;
int LCS(char *s1,int l1,int i,char *s2,int l2,int j)
{
	if(i==l1 ||j==l2)
	return 0;
	else if(s1[i]==s2[j])
	return 1+LCS(s1,l1,i+1,s2,l2,j+1);
	else 
	return max(LCS(s1,l1,i+1,s2,l2,j),LCS(s1,l1,i,s2,l2,j+1));

}

int main()
{
//char s1[]="ABCBDAB";
//char s2[]="BDCABA";
char s1[] = "OldSite:GeeksforGeeks.org";
char s2[] = "NewSite:GeeksQuiz.com";
int l1=sizeof(s1)/sizeof(s1[0]);
int l2=sizeof(s2)/sizeof(s2[0]);
int res=LCS(s1,l1-1,0,s2,l2-1,0);
cout<<"Longest Common Subsequence Length is "<<res;
}
