class Solution {
public:
    int numTrees(int n) {
         if(n<=1) return 1;
         int ans = 0;
         for(int i = 1;i<=n;++i )
         {
            ans += numTrees(n-i)*numTrees(i-1);
         }
         return ans;
    }
};