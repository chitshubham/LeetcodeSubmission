class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>set;
        int start = 0 , maxlength = 0;
        for(int end = 0 ; end < nums.size();++end) 
        {
           set.insert(nums[end]);
            while(*set.rbegin()-*set.begin()>limit)
            {
                set.erase(set.find(nums[start]));
                start++;

            } 
            maxlength = max(maxlength,end-start+1);
        }
        return maxlength;
    }
};