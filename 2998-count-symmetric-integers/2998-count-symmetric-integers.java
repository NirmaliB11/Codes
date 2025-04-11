class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++)
        {
            String s=Integer.toString(i);
            int diff=0,len=s.length();
            for(int j=0;j<len/2;j++){
                diff+=s.charAt(j)-s.charAt(len-j-1);
            }
            if(len%2==0&&diff==0)
            count++;
        }
        return count;
    }
}