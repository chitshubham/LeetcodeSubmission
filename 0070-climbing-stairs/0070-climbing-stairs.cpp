class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int prev1 = 2 ;
        if(n<=2) return n==2 ? prev1 : prev;
        for(int i = 3 ; i<=n;++i )
        {
           int  curr = prev+prev1;
            prev = prev1;
            prev1 = curr;
        }
        return prev1;

    }
};