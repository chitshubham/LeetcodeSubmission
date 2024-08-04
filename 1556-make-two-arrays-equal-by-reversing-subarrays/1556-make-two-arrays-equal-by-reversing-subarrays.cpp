class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()!=arr.size()) return  false;
        for(int i = 0;i<arr.size();++i)
        {
            auto it = find(target.begin(),target.end(),arr[i]);
            if(it==target.end()) return false;
            else {
                int index = it - target.begin();
                target[index] = 0;
            }
        }
        return true;
    }
};