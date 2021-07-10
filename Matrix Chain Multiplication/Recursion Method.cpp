#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int i, int j){
    if(i>=j){
      return 0;
    }
    int temp;
    int mn = INT_MAX;
    for(int k=i;k<=j-1;k++){
       temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        
        if(temp<mn)
          mn=temp;
    }
    return mn;
}

int main() {
    int arr[]={1,2,3,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<< "Matrix chain multiplicaion "<<solve(arr,1,n-1);
	// your code goes here
	return 0;
}
/*
output: Matrix chain multiplicaion 30
*/
