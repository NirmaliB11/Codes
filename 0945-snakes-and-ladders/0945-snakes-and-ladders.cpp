class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n=board.size();
        int len=n*n;
        vector<int> cell(len+1,0);
        int f=0;
        int x=1;
        for(int i=n-1;i>=0;i--)
        {
            if(f==0)
            {
                for(int j=0;j<n;j++)
                {
                    cell[x++]=board[i][j];
                }
                f=1;
            }
            else{
                for(int j=n-1;j>=0;j--)
                {
                    cell[x++]=board[i][j];
                }
                f=0;
            }
        }
        unordered_map<int,vector<int>> mp;
        for(int u=1;u<len;u++)
        {
            for(int dice=1;dice<=6;dice++)
            {
                int v=u+dice;
                if(v<=len){
                    if(cell[v]!=-1) mp[u].push_back(cell[v]);
                    else mp[u].push_back(v);
                }
            }
        }
        queue<int> q;
        q.push(1);
        vector<int> visited(len+1,0);
        visited[1]=1;
        vector<int> distance(len+1,0);
        distance[1]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto nbr:mp[node]){
                if(visited[nbr]==0)
                {
                    visited[nbr]=1;
                    distance[nbr]=distance[node]+1;
                    q.push(nbr);
                }
            }
        }
        return distance[len]==0?-1:distance[len];
    }
};