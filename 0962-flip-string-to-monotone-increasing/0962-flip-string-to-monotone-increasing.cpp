class Solution {
public:
    //  int solve(string s , int prev , int index,vector<vector<int>>&dp){
    //     if(index==s.length()) return 0;
    //     int pick  = 1e9;
    //     if(dp[index][prev]!=-1) return dp[index][prev];
    //     if(prev<=s[index]-'0') pick = solve(s,s[index]-'0',index+1,dp);
    //     int flip = 1+solve(s,prev,index+1,dp);
    //     dp[index][prev]= min(flip , pick);
    //     return dp[index][prev];
    //  }
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return solve(s,0,0,dp);
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i = 1;i<=n;++i){
            int current = s[i - 1] - '0';
        dp[i][0] = dp[i - 1][0] + (current == 1);
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (current == 0);
        }
        return min(dp[n][0],dp[n][1]);
    }
};