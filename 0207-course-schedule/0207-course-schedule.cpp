class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses,0);
        for(int i = 0; i<prerequisites.size();++i)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]+=1;
        }
        queue<int>q;
        for(int i = 0;i<numCourses;++i)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int cnt =0;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[front])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return cnt==numCourses;
    }
};