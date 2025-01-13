class Solution {
public:
    string truncateSentence(string s, int k) {
        int n=s.size();
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ') 
            {
                k--;
            }
            if(k<=0)
            {
                idx=i;
                break;
            }
        }
        return s.substr(0,idx);
    }
};