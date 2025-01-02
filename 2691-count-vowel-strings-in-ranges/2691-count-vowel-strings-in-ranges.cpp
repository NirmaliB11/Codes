class Solution {
public:
    bool isVowel(char ch)
    {
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=words.size();
        vector<int> pref(n,0);
        if(isVowel(words[0][0]) && isVowel(words[0][words[0].size()-1])){
            pref[0]=1;
        }
        for(int i=1;i<n;i++)
        {
            int len=words[i].size();
            if(isVowel(words[i][0]) && isVowel(words[i][len-1]))
            {
                pref[i]=pref[i-1]+1;
            }
            else
            {
                pref[i]=pref[i-1];
            }
        }
        for(auto &q:queries)
        {
            int l=q[0],r=q[1];
            if(l!=0) ans.push_back(pref[r]-pref[l-1]);
            else ans.push_back(pref[r]);
        }
        return ans;
    }
};