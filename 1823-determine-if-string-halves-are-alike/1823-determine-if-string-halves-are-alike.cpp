class Solution {
public:
    bool isVowel(char x)
    {
        if(x=='a'|| x=='e'|| x=='i' || x=='o'|| x=='u') return true;
        if(x=='A'|| x=='E'|| x=='I' || x=='O' || x=='U') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        int c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(i<n/2)
            {
                if(isVowel(s[i])) c1++;
            }
            else
                if(isVowel(s[i])) c2++;
        }
        return c1==c2;
    }
};