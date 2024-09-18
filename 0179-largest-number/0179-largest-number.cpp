class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(int i : nums){
            arr.push_back(to_string(i));
        }
        sort(arr.begin(),arr.end(),[](string &s1 , string &s2){
            return s1+s2>s2+s1;
        });
        string ans;
        if(arr[0]=="0") return "0";
        for(string st : arr) {
            ans= ans + st;
        }
        return ans;
    }
};