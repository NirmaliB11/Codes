class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0;
        int n=start.size(),m=target.size();
        while(i<n&&j<m)
        {
            if(start[i]=='_'&&target[j]=='_'){
                i++;
                j++;
            }
            else if(start[i]=='_'){
                i++;
            }
            else if(target[j]=='_'){
                j++;
            }
            else if((start[i]==target[j])&&(start[i]=='L'&&i>=j || start[i]=='R'&&i<=j))
            {
                i++; j++;
            }
            else return false;
        }
        while(i<n&&start[i]=='_') i++;
        while(j<m&&target[j]=='_') j++;

        return (i==n)&&(j==n);
    }
};