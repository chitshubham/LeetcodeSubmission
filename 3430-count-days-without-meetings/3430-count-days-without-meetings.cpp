class Solution {
public:

std::ostream& printVector(std::ostream& os, const std::vector<std::vector<int>>& vec) {
  for (const auto& row : vec) {
    for (int col : row) {
      os << col << " ";
    }
    os << std::endl;
  }
  return os;
 }
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>ans;
        for(auto it : meetings) 
        {
            if(ans.empty())
            {
                ans.push_back(it);
            }
            else 
            {
                if(ans.back()[1]>=it[0]) 
                {
                    ans[ans.size()-1][1] = max(ans[ans.size()-1][1] , it[1]);
                }
                else {
                    ans.push_back(it);
                }
            }
         }
         printVector(std::cout, ans);
         int cnt = 0;
         if(ans.size()==1  ) 
         {
           
            return (ans[0][0]-1)+(days-ans[0][1]);
         } 
         else{
           cnt = ans[0][0] - 1;
            for(int i = 1; i< ans.size();++i)
            {
               cnt = cnt + (ans[i][0]-ans[i-1][1] - 1);
            
            }
            if(ans.back()[1]!=days)
            cnt += (days-ans.back()[1]);
         }
         return cnt;
    }
};