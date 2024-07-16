class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        int i = 0;
        int n = nums.size();
        if(n==1) return true;
        while(i<n)
        {
            int jump = i+nums[i];
           
          
            // cout<<jump<<" "<<maxJump<<" ";
            maxJump = max(jump,maxJump);
            if(i==maxJump) return false; 
            if(maxJump==n-1) return true;
            i++;
        }
         return maxJump>=n-1;
    }
};