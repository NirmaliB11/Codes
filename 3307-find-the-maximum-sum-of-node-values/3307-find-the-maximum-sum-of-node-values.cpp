class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        long long sum=0;
        long long sac=INT_MAX,cnt=0;
        for(auto &x:nums)
        {
            long long val=x^k;
            if(val>x){
                sum+=val;
                sac=min(sac,val-(long long)x);
                cnt++;
            }
            else{
                sum+=(long long)x;
                sac=min(sac,(long long)x-val);
            }
        }
        return (cnt%2==0)?sum:sum-sac;
    }
};