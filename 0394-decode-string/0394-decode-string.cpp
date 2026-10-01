class Solution {
public:
    string decodeString(string s) {
        stack<int> numstack;
        stack<string> strstack;
        int num=0;
        string curr="";
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='[')
            {
                numstack.push(num);
                strstack.push(curr);
                num=0;
                curr="";
            }

            else if(s[i]==']')
            {
                int k=numstack.top();
                numstack.pop();
                string prev=strstack.top();
                strstack.pop();

                string temp="";

                for(int j=0;j<k;j++)
                {
                    temp+=curr;
                }
                curr=prev+temp;
            }
            else curr+=s[i];
        }
        return curr; 
    }
};