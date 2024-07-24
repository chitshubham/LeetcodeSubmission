class Solution {
public:
    int solve(vector<int>&mapping,int ele)
    {
        int ans = 0 , cnt = 0;
        if(ele==0) {
            return mapping[ele];
        }
        while(ele!=0)
        {
            int rem = ele%10;
             
            ans = (mapping[rem])*(pow(10,cnt)) + ans;
            ele/=10;
            cnt++;
        }
       
        return  ans;
    }
 static bool comparefn(pair<int,int> a, pair<int,int> b)
{
    if(a.second!=b.second)
    return a.first<b.first; // instead of <=
    return false;
}
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
       vector<pair<int,int>>res;
       for(int ele : nums)
       {
        int new_value = solve(mapping , ele);
        res.push_back({new_value,ele});
       } 
       sort(res.begin(),res.end(),comparefn);
       vector<int>ans;
       for(auto it : res)
       {
        ans.push_back(it.second);
       }
       return ans;
     
    }
};