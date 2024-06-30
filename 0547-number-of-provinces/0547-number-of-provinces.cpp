class Solution {
    int n;
    public:
    void bfs(vector<vector<int>>& isConnected,int u,vector<bool> &visited)
    {
        queue<int> que;
        que.push(u);
        visited[u]=true;

        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int v=0;v<n;v++)
            {
                if(!visited[v] && isConnected[u][v]==1)
                {
                    bfs(isConnected,v,visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<bool> visited(n,false);
        //BFS
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};