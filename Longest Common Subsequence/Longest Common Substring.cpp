class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int x=0;
        int t[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)
                    t[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                    x=max(x,t[i][j]);
                }
                else
                    t[i][j] = 0;
            }
        }
        //maximum length for repeated subarray
        return x;
    }
};
