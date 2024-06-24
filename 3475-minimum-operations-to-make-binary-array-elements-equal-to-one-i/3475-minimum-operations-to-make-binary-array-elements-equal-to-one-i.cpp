class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0;
        vector<bool>isFippled(n,false);
        int Flippedfromi = 0;
        for(int i = 0 ;i<n;++i) 
        {
            if(i>=3 && isFippled[i-3]) 
            {
                Flippedfromi--;
            }
            if(nums[i]==(Flippedfromi%2))
            {
                if(i+3>n) return -1;
                flips++;
                Flippedfromi++;
                isFippled[i] = true;
            }
        }
        return flips;
    }
};