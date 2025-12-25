#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int f=0;
        ll tot_h=0;
        sort(h.begin(),h.end(),greater<int>());
        int l=k;
        for(int i=0;i<h.size()&&l;i++)
        {
            ll diff=(ll)h[i]-(ll)f;
            if(diff>0) tot_h=tot_h+(ll)diff;
            else{
                break;
            }
            f+=1;
            l-=1;
        }
        return (ll)tot_h;
    }
};