class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &x:nums)
        {
            mp[x]++;
        }
        int ans=INT_MIN;
        int n=nums.size();
        int size=n/2;
        for(auto &[k,v]:mp)
        {
            if(v>(n/2))
            {
                ans=max(ans,k);
            }
        }
        return ans;
    }
};