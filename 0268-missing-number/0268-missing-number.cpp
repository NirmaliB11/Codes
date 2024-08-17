class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            x^=i;
        }
        for(auto &y:nums){
            x^=y;
        }
        return x;
    }
};