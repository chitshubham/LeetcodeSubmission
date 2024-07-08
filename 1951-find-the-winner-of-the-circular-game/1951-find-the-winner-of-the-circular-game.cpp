class Solution {
public:
    int accurate(int n, int k){
        if(n==1)
            return 0; 
            
        return ((accurate(n-1, k)+k)%n);
    }
    int findTheWinner(int n, int k) {
         return (accurate(n, k))+1; 
    }
};