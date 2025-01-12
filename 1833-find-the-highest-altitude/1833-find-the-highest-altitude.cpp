class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> alt(n+1);
        alt[0]=0;
        int maxalt=INT_MIN;
        for(int i=1;i<n+1;i++)
        {
            alt[i]=gain[i-1]+alt[i-1];
        }
        for(int i=0;i<alt.size();i++)
        {
            maxalt=max(maxalt,alt[i]);
        }
        return maxalt;
    }
};