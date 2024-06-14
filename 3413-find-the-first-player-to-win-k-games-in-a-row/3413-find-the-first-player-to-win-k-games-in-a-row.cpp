class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int i =0 , curr = 0 ;
        for(int j = 1;j<skills.size();++j) 
        {
            if(skills[i]<skills[j])
            {
                curr =0;
                i = j;
            }
            if(++curr==k) break;
        }
        return i;
    }
};