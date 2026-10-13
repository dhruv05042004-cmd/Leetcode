class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        //--t.c=O(mn*(m+n))
        //------------------brute force-------
        // int n=matrix.size();
        // int m=matrix[0].size();
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(matrix[i][j]==0)
        //         {
        //             for(int col=0;col<n;col++)
        //             {
        //                 if(matrix[i][col]!=0) matrix[i][col]=-1;
        //             }
        //             for(int row=0;row<m;row++)
        //             {
        //                 if(matrix[row][j]!=0) matrix[row][j]=-1;
        //             }
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(matrix[i][j]==-1)    matrix[i][j]==0;

        //     }
        // }

        //------------------//
        //-----t.c=0(2mn) but this approch is not good as this is using extra space of 0(m) and 0(n)
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i]||col[j])
                {
                    matrix[i][j]=0;
                }
            }
        }
        

    }
};