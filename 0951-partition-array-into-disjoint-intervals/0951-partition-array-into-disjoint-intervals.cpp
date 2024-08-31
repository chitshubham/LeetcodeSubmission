class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int>mini(n);
        vector<int>maxi(n);
        for(int i = 0; i< n; ++i ) 
        {
             if(i==0) 
             {
                maxi[i] = nums[0];
                mini[n-1]  = nums[n-1]; 
             }
             else {
             mini[n-i-1] = min(mini[n-i],nums[n-i-1]);
             maxi[i] = max(maxi[i-1],nums[i]);
             }
        }
        for(int i = 1; i< n; ++i )
        {
            // cout<<mini[i]<<" "<<maxi[i]<<endl;
            if(mini[i]>=maxi[i-1]) return i;
        }
        return 0;
    }
};