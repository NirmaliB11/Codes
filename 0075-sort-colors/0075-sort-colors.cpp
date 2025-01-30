class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int z=count(nums.begin(),nums.end(),0);
        int o=count(nums.begin(),nums.end(),1);
        int t=n-z-o;
        for(int i=0;i<n;i++)
        {
            if(i<z) nums[i]=0;
            else if(i<z+o) nums[i]=1;
            else nums[i]=2;
        }
    }
};