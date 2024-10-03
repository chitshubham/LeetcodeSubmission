class Solution {
public:
    // int solve(vector<pair<int ,int>>&v ,int ind ,  int m , int n,vector<vector<vector<int>>>&dp ){
    //     if(ind==v.size()) return 0;
    //     if(m<0 || n<0) return -1e9;
    //     if(m==0  &&   n ==0 ) return 0 ;
    //     if(dp[ind][m][n]!=-1) return dp[ind][m][n];
    //     int notpick  = solve(v,ind+1,m,n,dp);
    //     int pick = -1e9;
    //     if(m-v[ind].first>=0 && n - v[ind].second>=0) {
    //         pick = 1 + solve(v,ind+1,m-v[ind].first,n-v[ind].second,dp);
    //     }
    //  dp[ind][m][n] =  max(pick , notpick);
    //  return dp[ind][m][n];
    // }
    int findMaxForm(vector<string>& strs, int m, int n) {
        // vector<pair<int , int>>v;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(auto  s : strs) {
            int one  = 0 , zero = 0;
            for(char ch :  s ){
                zero  =  zero+ (ch=='0') ;
                one = one + (ch=='1');
            }
            for(int i =  m ; i>=zero;i--){
                for( int j = n ; j>=one;j--){
                    dp[i][j] = max(dp[i][j],1+dp[i-zero][j-one]);

                }
            }

            // v.push_back(make_pair(zero , one));
        }
        return dp[m][n];
        //  int size = v.size();
        // vector<vector<vector<int>>> dp(v.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        // return solve(v,0,m,n,dp);

    }
};