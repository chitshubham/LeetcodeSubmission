class Solution {
public:
    int countSeniors(vector<string>& details) {

        if(details.empty()) {
            return 0;
        }

        int age = 0;
        int counter = 0;
        for(auto str : details) {
            age = std::stoi(str.substr(11, 2));
            if(age > 60) {
                ++counter;
            }
        }
        return counter;
    }
};