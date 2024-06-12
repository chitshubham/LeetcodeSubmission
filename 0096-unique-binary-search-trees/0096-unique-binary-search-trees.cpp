class Solution {
public:
    int solve(int n , vector<int>&dp)
    {
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
         int ans = 0;
         for(int i = 1;i<=n;++i )
         {
            ans += solve(n-i,dp)*solve(i-1,dp);
         }
         dp[n] = ans;
         return dp[n];
    }
    int numTrees(int n) {
         vector<int>dp(n+1);
        //  return solve(n,dp);
        dp[0] =1 ;
        dp[1] =1;
        for(int i =2 ;i<=n;++i)
        {
            for(int j = 1;j<=i;++j)
            {
                dp[i]+= (dp[i-j] *dp[j-1]);
            }
        }
        return dp[n];
    }
};