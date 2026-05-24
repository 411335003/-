class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges,int source, int destination) {
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> queue;
        vector<bool> visited(n,false);
        queue.push_back(source);
        visited[source]=true;
        int front=0;
        while(front < queue.size())
        {
            int cur = queue[front++];
            if(cur == destination)return true;
            for(int i=0;i<graph[cur].size();i++)
            {
                int next = graph[cur][i];
                if(!visited[next])
                {
                    visited[next]=true;
                    queue.push_back(next);
                }
            }
        }
        return false;
    }
};