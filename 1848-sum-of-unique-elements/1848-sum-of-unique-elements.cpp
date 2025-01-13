class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto &[k,v]:mp)
        {
            if(v==1) sum+=k;
        }
        return sum;
    }
};