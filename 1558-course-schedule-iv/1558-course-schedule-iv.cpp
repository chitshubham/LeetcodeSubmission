class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
     vector<vector<bool>>isReach(numCourses,vector<bool>(numCourses,false));
     vector<int>adjList[numCourses];
     for(auto it :prerequisites ) 
     {
        int u = it[0];
        int v = it[1];
         adjList[u].push_back(v);
     }

    for(int i = 0;i<numCourses;++i)
    {
         vector<int>visited(numCourses,0);
        queue<int>q;
        q.push(i);
        visited[i] = true;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            isReach[i][front] = true;
            visited[front] = true;
            for(auto it : adjList[front])
            {
                if(!visited[it]) {
                    q.push(it);
                }
            }
        }
    }
    vector<bool>ans;
    for(auto it : queries){
        ans.push_back(isReach[it[0]][it[1]]);
    }
    return ans;
    }
};