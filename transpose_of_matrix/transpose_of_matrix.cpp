#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        int n;
        vector<vector<int>> matrix;

    Solution()
    {
        cin >> this->n;
        int row = this->n;

        while(row--)
        {
            matrix.push_back(vector<int>());
            int col = this->n;
            while(col--)
            {
                int i;
                cin >> i;

                this->matrix[this->n - row - 1].push_back(i);
            }
        }
        
    }

    void process()
    {
        for(int i = 0; i < this->n; i++)
        {
            for(int j = i + 1; j < this->n; j++)
            {
                int tmp = this->matrix[i][j];
                this->matrix[i][j] = this->matrix[j][i];
                this->matrix[j][i] = tmp;
            }
        }
    }

    void print()
    {
        //cout << "\n";

        for(int i = 0; i < this->n; i++)
        {
            for(int j = 0; j < this->n; j++)
            {
                cout << this->matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution* sl = new Solution();
    sl->process();
    sl->print();

    return 0;
}