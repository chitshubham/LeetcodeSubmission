class Solution {
public:
    void solve(vector<int>&arr,int index ,vector<int>&res ,vector<vector<int>>&ans, int target )
    {
        if(target==0)
        {
            ans.push_back(res);
            return;
        }
        for(int i = index;i<arr.size();++i)
        {
            if(i>index && arr[i-1]==arr[i]) continue;
            if(arr[i]>target) break;
            res.push_back(arr[i]);
            solve(arr,i+1,res,ans,target-arr[i]);
            res.pop_back();
                
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>res;
        vector<vector<int>>ans;
        solve(candidates,0,res,ans,target);
        return ans;
    }
};