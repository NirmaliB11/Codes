class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        int prefSum=0;
        for(int i=0;i<n;i++)
        {
            prefSum+=nums[i];
            int reqSum=prefSum-k;
            count+=mp[reqSum];
            mp[prefSum]+=1;
        }
        return count;
    }
};