class Solution {
public:
//    int solve(int n ,vector<int>&dp){
//     if(n<=0) return dp[0];
//     if(n==1)return dp[1];
//     if(dp[n]!=-1) return dp[n];
//     int max_product = 1;
//     for(int i = 1 ;i<=n;++i){
//         int product = i*solve(n-i,dp);
//         max_product = max({product,max_product,(n-i)*i});
//     }
//     dp[n] =max_product;
//     return dp[n];
//    }
    int integerBreak(int n) {
    //     vector<int>dp(n+1,-1);
    //     dp[0] = 0;
    //     dp[1] = 1;
    //  return solve(n,dp);   
      vector<int>dp(n+1,0);
      dp[1] = 1;
      for(int i = 2 ; i<=n;++i){

        for(int  j = 1 ;j<=i;++j){
            dp[i] = max({(i-j)*j ,j*dp[i-j],dp[i]  });
        }
      }
      return dp[n];
    }
};