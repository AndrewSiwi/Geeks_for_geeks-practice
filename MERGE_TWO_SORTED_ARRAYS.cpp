#include <bits/stdc++.h>

#define I_MAX 10000000

using namespace std;

class Solution
{
    public:
        int n, m;
        int arr1[I_MAX], arr2[I_MAX];

    Solution()
    {
        cin >> this->n >> this->m;

        int n = this->n;
        int m = this->m;

        while(n--)
        {
            int i;
            cin >> i;
            this->arr1[this->n - n - 1] = i;
        }

        while(m--)
        {
            int i;
            cin >> i;
            this->arr2[this->m - m - 1] = i;
        }
    }

    void process()
    {
        int i, j, k = this->n - 1;
        i = j = 0;

        while(i <= k && j < this->m)
        {
            if(this->arr1[i] > this->arr2[j])
            {
                int tmp = this->arr1[k];
                this->arr1[k--] = this->arr2[j];
                this->arr2[j++] = tmp;
            }
            else
            {
                i++;
            }
        }

        sort(arr1, arr1 + this->n);
        sort(arr2, arr2 + this->m);
    }

    void print()
    {
        for(int i = 0; i < this->n; i++)
        {
            cout << this->arr1[i] << " ";
        }
        for(int i = 0; i < this->m; i++)
        {
            cout << this->arr2[i] << " ";
        }
        cout << "\n";
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