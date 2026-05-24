class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // 建圖
        vector<vector<int>> graph(n + 1);
        for(int i = 0; i < dislikes.size(); i++)
        {
            int a = dislikes[i][0];
            int b = dislikes[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        // 0 = 未染色
        // 1 = 紅色
        // -1 = 藍色
        vector<int> color(n + 1, 0);
        for(int i = 1; i <= n; i++)
        {
            // 已染色跳過
            if(color[i] != 0)continue;
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while(!q.empty())
            {
                int cur = q.front();
                q.pop();

                // 檢查鄰居
                for(int j = 0; j < graph[cur].size(); j++)
                {
                    int next = graph[cur][j];
                    // 沒染色
                    if(color[next] == 0)
                    {
                        color[next] = -color[cur];
                        q.push(next);
                    }
                    // 同色 -> 失敗
                    else if(color[next] == color[cur])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};