class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x==y) 
        {
            int ans = 2*x+2*y+2*z;
            return ans;
        }
      int ans = min(x,y);
      ans = ans*2+ans*2+2+2*z;
      return ans;
    }
};