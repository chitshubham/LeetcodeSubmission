class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
       unordered_map<int ,int >mp;
       int cnt =0 , n =arr.size() , sum=0;
       ++mp[sum];
       for( int i =0; i< n ; ++i)
       {
            sum +=arr[i];
            int rem = sum % k;
             if (rem < 0) rem += k;
            if(mp.find(rem)!=mp.end())
            {
                cnt +=mp[rem];
            }
            ++mp[rem];
       }
       return cnt;
    }
};