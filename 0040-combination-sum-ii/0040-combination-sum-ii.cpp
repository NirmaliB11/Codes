class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx,vector<int> &candidates,int target,vector<int> &temp)
    {
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx&&candidates[i-1]==candidates[i]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(0,candidates,target,temp);
        return ans;
    }
};