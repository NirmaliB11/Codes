class Solution {
public:
    int missingNumber(vector<int>& nums) {
       unordered_set<int> st;
       int n=nums.size();
       for(auto &x:nums) st.insert(x);
       for(int i=0;i<=n;i++){
        if(st.find(i)==st.end()) return i;
       }
       return 0;
    }
};