class Solution {
  public:
  
    bool check(string &str, int l,int r)
    {
        if(l>=r)return true;
        if(str[l]!=str[r]) return false;
        return check(str,l+1,r-1);
    }
    bool isPalindrome(int n) {
        string str=to_string((n));
        return check(str,0,str.size()-1);
    }
};