#include <iostream>
using namespace std;
bool isSubsetSum(int set[], int n, int sum){
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0)
              dp[i][j]=false;
            if(j==0)
              dp[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(set[i-1]<=sum)
                dp[i][j]=dp[i-1][j-set[i-1]] || dp[i-1][j];
            else
                 dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 0;
    int n = sizeof(set) / sizeof(set[0]);
    for(int i=0;i<n;i++)
      sum+=set[i];
     if(sum%2!=0){
       printf("NOT EQUAL SUM PARTITION");
       return 0;
     }
    else if(isSubsetSum(set, n, sum)==true)
       printf("EQUAL SUM PARTITION");
    return 0;
}
