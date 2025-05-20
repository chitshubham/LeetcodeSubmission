class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int zero = 0 , two = nums.size()-1;
        while(i<=two){
            if(nums[i]==0){
                swap(nums[i++],nums[zero++]);
            }
            else if(nums[i]==2){
                swap(nums[i],nums[two--]);
            }
            else i++;
        }
    
    }
};