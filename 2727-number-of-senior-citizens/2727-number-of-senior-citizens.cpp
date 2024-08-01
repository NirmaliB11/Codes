class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int c=0;
        for(auto &s:details)
        {
            int val=stoi(s.substr(11,2));
            if(val>60) c++;
        }
        return c;
    }
};