class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>indegree(numCourses,0);
        vector<int>adj[numCourses];
        for(int i = 0;i<prerequisites.size();++i)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i =0;i<numCourses;++i)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto it : adj[front])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()<numCourses) return {};
        return ans;
    }
};