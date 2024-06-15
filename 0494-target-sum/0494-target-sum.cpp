class Solution {
public:
    int countWays(vector<int>&nums , int target) 
    {
        int totalSum =0 , n = nums.size();
        for(int i : nums)
        {
            totalSum+=i;
        }
        if(target>totalSum ||  (totalSum-target)%2==1) return 0;
        totalSum = (totalSum-target)/2;
        vector<vector<int>>dp(n,vector<int>(totalSum+1,0));
        if(nums[0]==0) dp[0][0]=2;
        else dp[0][0] = 1;
        if(nums[0]!=0 && nums[0]<=totalSum) dp[0][nums[0]] =1 ;
        for(int i = 1 ; i<n;++i) 
        {
            for(int t=0;t<=totalSum;++t) 
            {
                int notpick=dp[i-1][t];
                int pick = 0;
                if(t>=nums[i]) 
                pick = dp[i-1][t-nums[i]];
                dp[i][t] = pick+notpick;
            }
        }
        return dp[n-1][totalSum];

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countWays(nums,target);
    }
};