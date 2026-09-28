class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> st;
        for(int i=0;i<n;i++)
        {
            if(asteroids[i]>0)
            {
                st.push_back(asteroids[i]);
            }
            else // for the left dir asteroid
            {
                while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i]))
                {
                    st.pop_back(); // if right moving asteroid is smaller destroy the right
                }
                if(!st.empty()&&st.back()==abs(asteroids[i]))
                {
                    st.pop_back(); // same +ve and -ve
                }
                else if(st.empty()|| st.back()<0)
                {
                    st.push_back(asteroids[i]); //last is -ve then just add the same dir for the left
                }
            }
            
        }
        return st;
    }
};