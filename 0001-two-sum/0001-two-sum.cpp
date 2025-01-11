class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int x=0;x<n;x++)
        {
            if(mp.find(target-nums[x])!=mp.end())
            {
                return {x,mp[target-nums[x]]};
            }
            mp[nums[x]]=x;
        }
        return {};
    }
};