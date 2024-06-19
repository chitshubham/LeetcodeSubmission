class Solution {
    private:
    bool isPossible(vector<int>bloomDay,int mid,int m , int k )
    {
        int cnt = 0,n=bloomDay.size(),days=0;
        for(int i =0; i < n ;++i)
        {
            if(bloomDay[i]<=mid)
            {
                cnt++;
            }
            else 
            {

                days+=cnt/k;
                cnt=0;
            }
        }
        days+=cnt/k;
        return m<=days;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int val = 1LL* m *1LL *k;
        int n = bloomDay.size();
       if(val>n)
       {
           return -1;
       } 
       int low = *min_element(bloomDay.begin(),bloomDay.end());
       int high = *max_element(bloomDay.begin(),bloomDay.end());
       while(low<=high)
       {
           int mid = low +(high-low)/2;
           if(isPossible(bloomDay,mid,m,k))
           {
               high = mid-1;
           }
           else
           {
               low = mid+1;
           }
       }
       return low;
    }
};