//recursion + memorisation
#include <bits/stdc++.h>
using namespace std;
int static t[1001][1001];
int solve(int arr[], int i, int j){
    if(i>=j){
      return 0;
    }
    if(t[i][j]!=-1)
      return t[i][j];
      
    int temp;
    int mn = INT_MAX;
    for(int k=i;k<=j-1;k++){
       temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        
        if(temp<mn)
          mn=temp;
    }
    return t[i][j]=mn;
}

int main() {
    int arr[]={1,2,3,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    memset(t,-1,sizeof(t));
    cout<< "Matrix chain multiplicaion "<<solve(arr,1,n-1);
	// your code goes here
	return 0;
}
