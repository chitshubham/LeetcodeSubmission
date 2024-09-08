class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
          vector<vector<pair<int, int>>> adj_list(n);
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], length = edge[2];
    
        adj_list[u].push_back({v, length});
        adj_list[v].push_back({u, length});
    }
    
    vector<int> minTime(n, numeric_limits<int>::max());
    vector<bool> processed(n, false);  
    minTime[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int current_time = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (processed[u]) continue;  
        if (current_time >= disappear[u]) continue; 
        processed[u] = true; 

        for (const auto& edge : adj_list[u]) {
            int v = edge.first;
            int length = edge.second;
            int travel_time = current_time + length;

            if (travel_time < disappear[v] && travel_time < minTime[v]) {
                minTime[v] = travel_time;
                pq.push({travel_time, v});
            }
        }
    }

    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = (minTime[i] == numeric_limits<int>::max()) ? -1 : minTime[i];
    }
    return result;
    }
};