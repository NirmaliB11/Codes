class Solution {
public:
    int maxScore(string s) {
        string l,r;
        int n=s.size();
        int ans=-1;
        for(int i=0;i<n-1;i++)
        {
            l=s.substr(0,i+1);
            r=s.substr(i+1,n);
            int c=count(l.begin(),l.end(),'0')+count(r.begin(),r.end(),'1');
            ans=max(ans,c);
        }
        return ans;
    }
};