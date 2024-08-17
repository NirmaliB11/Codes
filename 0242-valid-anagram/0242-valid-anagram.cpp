class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(auto &ch:t)
        {
            if(mp.find(ch)==mp.end()) return false;
            else 
            {
                mp[ch]--;
                if(mp[ch]==0) mp.erase(ch);
            }
        }
        if(mp.size()==0) return true;
        else return false;
    }
};