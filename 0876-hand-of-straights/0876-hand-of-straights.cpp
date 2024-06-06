class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int , int>mp;
        sort(hand.begin() ,hand.end() );
        if(hand.size()%groupSize) {
            return false;
        }
        for(int i : hand) 
        {
            mp[i]+=1;
        }
        while(!mp.empty())
        {
            int curr = mp.begin()->first;
            for(int i = 0;i<groupSize;++i) 
            {
                if(mp[i+curr]==0) {
                    return false;
                }
                mp[i+curr]-=1;
                if(mp[i+curr]<1) 
                {
                    mp.erase(i+curr);
                }
            }

        }
        return true;
    }
};