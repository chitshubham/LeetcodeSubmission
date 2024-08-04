class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>ans;
        for(int i =0 ;i<n;++i)
        {
            int sum = nums[i];
            ans.push_back(nums[i]);
            for(int j = i+1;j<n;++j) 
            {
                sum+=nums[j];
                ans.push_back(sum);
            }
            
        }
        sort(ans.begin(),ans.end());
        int res = 0;
        const int mod = 1e9+7;
        for(int i =left-1;i<right && i<ans.size();++i ) 
        {
            res=(res+ans[i])%mod;
        }
        return res;

    }
};