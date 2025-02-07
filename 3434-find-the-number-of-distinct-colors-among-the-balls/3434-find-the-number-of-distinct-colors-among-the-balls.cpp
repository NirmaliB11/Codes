class Solution {
public:
    void find(int n,map<int,int> &mp,set<int> &st,vector<int> &ans,vector<vector<int>>& queries,int limit)
    {
        map<int,int> col;
        for(auto &q:queries)
        {
            mp[col[q[0]]]--;
            if(mp[col[q[0]]]==0) st.erase(col[q[0]]);
            mp[q[1]]++;
            if(mp[q[1]]==1) st.insert(q[1]);
            col[q[0]]=q[1];
            ans.push_back(st.size());
        }
    }
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        map<int,int> mp;
        set<int> st;
        vector<int> ans;
        find(n,mp,st,ans,queries,limit);
        return ans;
    }
};