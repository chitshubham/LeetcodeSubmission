class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        int prefixMod = 0;
        mp[0] =-1;
        for(int i =0;i<nums.size();++i){
            prefixMod= (prefixMod+nums[i])%k;
             if(mp.find(prefixMod) !=mp.end())
             {
                if(i-mp[prefixMod]>1) {
                    return 1;
                }
             }
             else 
             {
                mp[prefixMod] = i;
             }
        }
        return 0;
    }
   
};