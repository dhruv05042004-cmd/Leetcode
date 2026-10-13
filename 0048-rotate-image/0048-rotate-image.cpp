class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        //----BRUTE FORCE----T.C=O(n*2)----------

        // vector<vector<int>> rotated(n, vector<int>(n));
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         rotate[j][n-i-i]=matrix[i][j];
        //     }
        // }

        //-------OPTIMAL SOLUTION------
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);//yaha pe transpose ho raha hai
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end()); //ab transpose ke row ko reverse kr diye
        }
        
    }
};