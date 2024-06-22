class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) -atmost(nums,k-1);
    }
    int atmost(vector<int>&nums, int k ) 
    {
        int start = 0 ,widowSize = 0, n = nums.size() , subArray = 0;
        for(int end = 0; end<n;++end)
        {
            widowSize+=(nums[end]%2);
            while(widowSize>k) 
            {
                widowSize-=(nums[start]%2);
                start++;
            }
            subArray+=(end-start+1);
        }
        return subArray;
    }
};