class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pos,neg;
        vector<int> ans(n);
        for(auto &x:nums){
            if(x<0) neg.push_back(x);
            else pos.push_back(x);
        }
        int j=0,k=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0){
                ans[i]=pos[j];
                j++;
            }else{
                ans[i]=neg[k];
                k++;
            }
        }
        return ans;
    }
};