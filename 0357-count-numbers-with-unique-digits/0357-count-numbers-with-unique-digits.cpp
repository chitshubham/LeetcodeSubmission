class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
         int ans = 1;
         int dig = 9; 
         for(int i =1 ;i<=n;++i)
         {
            if(i<=2 )  ans*=dig;
            else{
                dig--;
                ans*=dig;
            }
         }
         return ans+countNumbersWithUniqueDigits(n-1);

    }
};