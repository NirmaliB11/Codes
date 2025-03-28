class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &x:nums)
        {
            mp[x]++;
        }
        int n=nums.size();
        vector<int> ans;
        for(auto &[k,v]:mp)
        {
            if(v>(n/3))
            {
                ans.push_back(k);
            }
        }
        return ans;
    }
};