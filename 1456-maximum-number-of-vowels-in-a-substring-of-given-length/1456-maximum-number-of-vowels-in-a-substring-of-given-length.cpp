class Solution {
public:
    bool isVowel(char ch)
    {
        return ch=='a' || ch=='e'||ch=='i' ||ch=='o'|| ch=='u';
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<k;i++)
        {
            if(isVowel(s[i])) cnt++;
        }
        int mx=cnt;
        int i=1;
        int j=k;
        while(j<n)
        {
            if(isVowel(s[j])) cnt++;
            if(isVowel(s[i-1])) cnt--;
            mx=max(mx,cnt);
            i++;
            j++;
        }
        return mx;
        
    }
};