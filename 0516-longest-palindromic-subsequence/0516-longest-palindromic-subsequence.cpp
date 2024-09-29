class Solution {
public: 
    // size_t ans;
    // bool isPalin(string s){
    //     int start = 0 , end = s.length()-1;
    //     while(start<=end){
    //         if(s[start]!=s[end]){
    //             return false;
    //         }
    //         start++;
    //         end--;
    //     }
    //     return true;
    // }
    // void solve(string s , int index , string& temp){
    //     if(index == s.length()){
    //         if(isPalin(temp)) ans = max(ans,temp.length());
    //         return;
    //     } 
    //     temp.push_back(s[index]);
    //     solve(s,index+1,temp);
    //     temp.pop_back();
    //     solve(s,index+1,temp);
    // }
    

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i =1 ; i<=n;++i){
            for(int j =1 ;j<=n;++j){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};
const static auto  _ = [](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}();