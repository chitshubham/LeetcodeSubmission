class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>isPrime(n+1,true);
     isPrime[0] = isPrime[1] = false;
     for(int i =2 ; i< n ; ++ i)
     {
        if(isPrime[i])
        {
            for(int j= i*2;j<n;j=j+i)
            {
                isPrime[j] = false;
            }
        }
     }
     vector<vector<int>>ans;
     for(int i = 2 ; i<=n/2;++i)
     {
         if(isPrime[i]){
            int rem = n - i;
            if(isPrime[rem])
            {
                ans.push_back({i,rem});
            }
         }
     }
     return ans;

    }
};