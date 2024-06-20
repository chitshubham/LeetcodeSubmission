class Solution {
    private:
    bool isPossible(vector<int>position , int mid , int n , int m )
    {
        int basket=1,last = position[0] ;
        for( int i =1; i< n ;++i)
        {
             if(position[i]-last>=mid)
             {
                basket++;
                last = position[i];
                 
             }
        } 
        return basket >=m; 
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 0 , high = position[n-1]-position[0];
        while(low<=high)
        {
         int mid=low +(high - low)/2;
         if(isPossible(position,mid ,n,m))
         {
             low = mid+1;
         }
         else 
         {
            high= mid-1;         
         }
        }
        return high;
       
    }

};