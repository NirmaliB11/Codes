class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int sum=0;
        int idx=INT_MAX;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>=target)
            {
                idx=min(idx,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return idx==INT_MAX?0:idx;
    }
};