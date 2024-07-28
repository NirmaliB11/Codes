class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0,maxlen=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==0) sum-=1;
            else sum+=1;
            if(mp.find(sum)!=mp.end())
            {
                int prev_idx=mp[sum];
                int curr_idx=j;
                int len=curr_idx-prev_idx;
                maxlen=max(maxlen,len);
            }
            else
            {
                mp[sum]=j;
            }
        }
        return maxlen;
    }
};