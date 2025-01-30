class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<int> prev;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> curr(i+1);
            for(int j=0;j<=i;j++)
            {
                if(j==0) curr[j]=1;
                else if(j==i) curr[j]=1;
                else curr[j]=prev[j]+prev[j-1];
            }
            ans.push_back(curr);
            prev=curr;
        }
        return ans;
    }
};