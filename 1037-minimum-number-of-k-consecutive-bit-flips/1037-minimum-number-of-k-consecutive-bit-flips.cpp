class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        vector<bool>isFippled(n,false);
        int Flippedfromi = 0;
        for(int i = 0 ;i<n;++i) 
        {
            if(i>=k && isFippled[i-k]) 
            {
                Flippedfromi--;
            }
            if(nums[i]==(Flippedfromi%2))
            {
                if(i+k>n) return -1;
                flips++;
                Flippedfromi++;
                isFippled[i] = true;
            }
        }
        return flips;
    }
};