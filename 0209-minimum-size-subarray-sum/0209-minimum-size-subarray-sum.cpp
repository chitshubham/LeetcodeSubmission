class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0 , j = 0 , n = nums.size() , currSum = 0,minLength = INT_MAX;
        while(i<n)
        {
            currSum+=nums[i];
            while(currSum>=target)
            {
                minLength = min(minLength,i-j+1);
                currSum-=nums[j];
                j++;
            }
            i++;

        }
        return minLength==INT_MAX? 0 : minLength;
    }
};