class Solution {
public:
    int ans =0;
    string intToBinary(int num) {
    string binary = "";
    while (num > 0) {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;
    }
    return binary;
}
     void recurPermute(vector < int > & ds, vector < int > & nums, int freq[]) {
      if (ds.size() == nums.size()) {
          string s ;
         for(int ele : ds){
             string temp = intToBinary(ele);
             s  = s + temp;
         }
           ans = max(ans , stoi(s,0,2)); 
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }
     void permute(vector < int > & nums) {
      
      vector < int > ds;
      int freq[nums.size()];
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;
      recurPermute(ds, nums, freq);
      
    }

    int maxGoodNumber(vector<int>& nums) {
        ans = 0;
        permute(nums);
        return ans;
    }
};