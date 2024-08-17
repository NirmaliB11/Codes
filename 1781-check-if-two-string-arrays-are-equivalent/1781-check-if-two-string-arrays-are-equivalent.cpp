class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string p="";
        for(auto &s:word1){
            for(auto &ch:s) p.push_back(ch);
        }
        string q="";
        for(auto &s:word2){
            for(auto &ch:s) q.push_back(ch);
        }
        return p==q;
    }
};