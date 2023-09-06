#include <bits/stdc++.h>

using namespace std;

#define N 10000


class Solution
{
    public:
        int n, arr[N];
        bool ret = true;

    Solution()
    {
        cin >> this->n;

        int n = this->n;

        while(n--)
        {
            int i;
            cin >> i;

            this->arr[this->n - n - 1] = i;
        }
    }

    void process()
    {
        sort(this->arr, this->arr + this->n);

        for(int i = 0; i < this->n; i++)
        {
            int j = i + 1;
            int k = this->n - 1;

            while(j < k)
            {
                int sum = this->arr[i] + this->arr[j] + this->arr[k];
                if(sum == 0) return;
                else if(sum < 0) j++;
                else k--;                
            }
        }

        this->ret = false;
    }

    void print()
    {
        //cout << "\n";

        cout << this->ret << "\n";
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