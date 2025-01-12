class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            x+=nums[i];
        }
        int y=0;
        for(int i=0;i<nums.size();i++)
        {
            int p=nums[i];
            while(p!=0)
            {
                int rem=p%10;
                y+=rem;
                p/=10;
            }
        }
        return abs(x-y);
    }
};