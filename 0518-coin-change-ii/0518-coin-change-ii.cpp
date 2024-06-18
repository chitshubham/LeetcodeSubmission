class Solution {
public:
    // int solve(vector<int>&coins , int amount , int ind,vector<vector<int>>&dp) 
    // {
    //      if(ind==0)
    //      {
    //         return (amount%coins[ind]==0);
           
    //      }
    //      if(dp[ind][amount]!=-1) return dp[ind][amount];
    //      int notpick = solve(coins,amount , ind-1,dp);
    //      int pick = 0; 
    //      if( amount>=coins[ind]) 
    //       pick = solve(coins,amount-coins[ind],ind,dp);
    //        dp[ind][amount]=pick+notpick;
    //        return dp[ind][amount]; 
    // }
    int change(int amount, vector<int>& coins) {
        
         int n = coins.size();
         vector<vector<int>>dp(n,vector<int>(amount+1,0));
        //  return solve(coins,amount ,coins.size()-1,dp);
        for(int T =0 ; T<=amount;++T)
        { 
        dp[0][T] = (T%coins[0]==0);
        }
        for(int ind = 1; ind<n;++ind)
        {
             for(int T = 0; T<=amount;++T) 
             {
                 int notpick = dp[ind-1][T];
                 int pick = 0;
                 if(T>=coins[ind]){
                 pick = dp[ind][T-coins[ind]];
                 }
                 dp[ind][T] = pick+notpick;
             }
        } 
        return dp[n-1][amount];

    }
};