class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&res,vector<bool>&freq,vector<int>&nums){
        if(res.size()==nums.size()){
            ans.push_back(res);
            return;
        }
        for(int i = 0;i<nums.size();++i){

            if(!freq[i]){
                freq[i] = true;
                res.push_back(nums[i]);
                solve(ans,res,freq,nums);
                res.pop_back();
                freq[i]= false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>res;
        vector<bool>freq(nums.size(),false);
        vector<vector<int>>ans;
        // for(int i = 0;i<)
        solve(ans,res,freq,nums);
        return ans;
    }
};