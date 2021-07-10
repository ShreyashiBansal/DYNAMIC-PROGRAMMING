#include <bits/stdc++.h>
using namespace std;
int static t[1001][1001];
bool ispalindrome(string s, int i, int j){
    if(i==j)
      return true;
    if(i>j)            //empty string
      return true;
    
    while(i<j){
        if(s[i]!=s[j])
          return false;
        i++;
        j--;
    }
    return true;
}
int solve(string s, int i, int j){
    if(i>=j){
      return 0;
    }
    if(ispalindrome(s,i,j)==true)
      return 0;
      
    if(t[i][j]!=-1)
      return t[i][j];
      
    int temp;
    int mn = INT_MAX;
    for(int k=i;k<=j-1;k++){
       temp = solve(s,i,k) + solve(s,k+1,j) + 1;
        
        if(temp<mn)
          mn=temp;
    }
    return t[i][j]=mn;
}

int main() {
    string s;
    cin>>s;
    int n=s.size();
    memset(t,-1,sizeof(t));
    cout<< "Palindrome Partitioning of  "<<solve(s,0,n-1);
	// your code goes here
	return 0;
}
/*
geek
output: Palindrome Partitioning 2
*/
