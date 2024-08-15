class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            int v=0;
            for(int j=i;j<n;j++)
            {
                v|=nums[j];
                if(v>=k)
                {
                    ans=min(ans,j-i+1);
                    break;
                }
            }
        }
        return ans==1e9?-1:ans;
    }
};