class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>nums(n+1,0);
        nums[0] = 0;
        for(int i  = 1 ; i<=n;++i){
            nums[i] = nums[i/2]+i%2;
        }
        return nums;
    }
};