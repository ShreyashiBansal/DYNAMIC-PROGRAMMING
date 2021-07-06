**TOP DOWN APPROACH**     

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
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}

**MEMORIZATION**     


#include <bits/stdc++.h>
using namespace std;

// Taking the matrix as globally
int tab[2000][2000];
int subsetSum(int a[], int n, int sum)
{
	if (sum == 0)
		return 1;
		
	if (n <= 0)
		return 0;
  
	if (tab[n - 1][sum] != -1)
		return tab[n - 1][sum];
  
	if (a[n - 1] > sum)
		return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
	else
	{
		return tab[n - 1][sum] = subsetSum(a, n - 1, sum) ||
					subsetSum(a, n - 1, sum - a[n - 1]);
	}
}

// Driver Code
int main()
{
	// Storing the value -1 to the matrix
	memset(tab, -1, sizeof(tab));
	int n = 5;
	int a[] = {1, 5, 3, 7, 4};
	int sum = 12;

	if (subsetSum(a, n, sum))
	{
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;

	/* This Code is Contributed by Ankit Kumar*/
}
