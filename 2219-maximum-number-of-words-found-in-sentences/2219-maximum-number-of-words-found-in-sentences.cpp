class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n=sentences.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int c=1;
            string s=sentences[i];
            for(int j=0;j<s.size();j++)
            {
                if(s[j]==' ')
                {
                    c++;
                }
            }
            maxi=max(maxi,c);
        }
        return maxi;
    }
};