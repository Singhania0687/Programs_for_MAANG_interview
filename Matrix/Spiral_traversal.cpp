/**
 * The above code implements a solution to print the elements of a matrix in spiral order.
 * 
 * @return The function `spiralOrder` returns a vector of integers.
 */
# include<iostream>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int>v;
        int top,left,right,bottom,i;
        bottom=matrix.size()-1;
        top=0;
        left=0;
        right=matrix[0].size()-1;
        
        while(top<=bottom && left<=right)
        {
            for(i=left;i<=right;++i)
                v.push_back(matrix[top][i]);
                ++top;

                for(i=top;i<=bottom;++i)
                v.push_back(matrix[i][right]);
                --right;

                if(top<=bottom)
               { 
                   for(i=right;i>=left;--i)
               v.push_back( matrix[bottom][i]);
                --bottom;
                }

                if(left<=right)
               { 
                   for(i=bottom;i>=top;--i)
                v.push_back(matrix[i][left]);
                ++left;
                }

        }
        
        return v;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> >matrix(n,vector<int>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        cin>>matrix[i][j];
    }
    Solution obj;
    vector<int>ans=obj.spiralOrder(matrix);
    for(int i=0;i<ans.size();++i)
    cout<<ans[i]<<" ";
    return 0;
}