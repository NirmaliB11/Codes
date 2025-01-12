class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        int max=-1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=max;
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
        return ans;
    }
};