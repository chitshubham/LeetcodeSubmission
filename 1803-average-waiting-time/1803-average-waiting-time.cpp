class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int start = customers[0][0] + customers[0][1];
        double waiting = customers[0][1];
         cout<<waiting<<endl;
        for(int i = 1; i<customers.size();++i)
        {
            auto it = customers[i];
           
            if(start>=it[0])
            {
                int end = start+it[1];
                waiting+=(end -it[0]);
                start = end;
            }
            else {
                start = it[0];
                int end=start+it[1];
                waiting+=it[1];
                start = end;
            }
            
        }
        return (double)waiting/(double)customers.size();
    }
};