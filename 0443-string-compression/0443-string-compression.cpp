class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int write=0;
        int i=0;
        while(i<n)
        {
            char current=chars[i];
            int count=0;
            while(i<n && chars[i]==current)
            {
                count++;
                i++;
            }
            chars[write]=current;
            write++;

            if(count>1)
            {
                string s=to_string(count);
                for(int j=0;j<s.size();j++)
                {
                    chars[write]=s[j];
                    write++;
                }
            }
        }
        return write;
        
    }
};