class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string p="";
        for(int i=0;i<word1.size();i++)
        {
            p+=word1[i];
        }
        string q="";
        for(int i=0;i<word2.size();i++)
        {
            q+=word2[i];
        }
        return p==q;
    }
};