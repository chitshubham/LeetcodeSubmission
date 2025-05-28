class Solution {
public:
    set<vector<int>>st;
    void solve(vector<int>nums,vector<vector<int>>&ans,int index){
        if(index==nums.size()){
            if(!st.count(nums)) ans.push_back(nums);
            st.insert(nums);
            return;
        }
        for(int i = index;i<nums.size();++i){
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,ans,0);
        return ans;
    }
};