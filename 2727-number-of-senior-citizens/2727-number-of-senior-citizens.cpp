class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            string s=details[i];
            int val=(s[11]-'0')*10+(s[12]-'0');
            if(val>60) c++;
        }
        return c;
    }
};