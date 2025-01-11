class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        for(int i=0;i<mat.size();i++)
        {
            sum+=mat[i][i];
            int j=mat.size()-1-i;
            if(i!=j)
            {
                sum+=mat[i][j];
            }
        }
        return sum;
    }
};