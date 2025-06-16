class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn=INT_MAX;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(mn<nums[i]){
                ans=max(ans,nums[i]-mn);
            }
            mn=min(mn,nums[i]);
        }
        return ans;
    }
};