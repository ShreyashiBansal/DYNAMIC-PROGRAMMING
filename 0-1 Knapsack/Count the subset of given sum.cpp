#include <iostream>
using namespace std;
int isSubsetSum(int set[], int n, int sum){
    int dp[n+1][sum+1];
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(set[i-1]<=sum)
                dp[i][j]=dp[i-1][j-set[i-1]] + dp[i-1][j];
            else
                 dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    int x=isSubsetSum(set,n,sum);
    cout<<x<<endl;
    return 0;
}
