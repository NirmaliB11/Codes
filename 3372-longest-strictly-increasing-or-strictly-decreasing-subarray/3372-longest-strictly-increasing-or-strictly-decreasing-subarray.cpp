class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int mxlen=0;
        //increasing
        for(int i=0;i<n-1;i++)
        {
            int cnt=0;
            for(int j=i;j<n-1;j++)
            {
                if(nums[j+1]>nums[j]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            mxlen=max(mxlen,cnt+1);
        }
        //decreasing 
        for(int i=0;i<n-1;i++)
        {
            int cnt=0;
            for(int j=i;j<n-1;j++)
            {
                if(nums[j+1]<nums[j]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            mxlen=max(mxlen,cnt+1);
        }
        return mxlen;
    }
};