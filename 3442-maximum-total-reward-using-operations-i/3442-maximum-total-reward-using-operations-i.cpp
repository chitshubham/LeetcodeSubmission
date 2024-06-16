class Solution {
public:
int dp[2000][4001];
   int solve(vector<int>&arr , int x , int ind )
   {
    if(ind>=arr.size() ) 
    {
         return x;
    }
    if(dp[ind][x]!=-1)
    {
         return dp[ind][x];
    }
    int notpick = solve(arr,x,ind+1);
    
    int pick = 0;
    if(x<arr[ind]) 
     pick = solve(arr , x+arr[ind],ind+1);
     dp[ind][x] =max(pick,notpick);
     return dp[ind][x];
    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin() , rewardValues.end());
        memset(dp,-1,sizeof(dp));
        return solve(rewardValues,0,0);
    }
};