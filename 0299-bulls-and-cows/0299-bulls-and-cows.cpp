class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0,cows=0;
        unordered_map<char,int> mp;
        string sol="";
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i]) bulls++;
            else
            {
                sol+=guess[i];
                mp[secret[i]]++;
            }
        }
        for(int i=0;i<sol.size();i++)
        {
            if(mp.find(sol[i])!=mp.end())
            {
                cows++;
                mp[sol[i]]--;
                if(mp[sol[i]]==0)
                {
                    mp.erase(sol[i]);
                }
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};