class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 , r = 0 , n = nums.size(),zero =  0 , maxlen = 0 ;
   
         while(r<n)
         {
            if(nums[r]==0) zero++;
            if(zero>k) 
            {
                 
                    if(nums[l]==0) zero--;
                    l++;
            }
            if(zero<=k) maxlen = max(maxlen , r-l+1);
            r++;
         }
         return maxlen;
    }
};