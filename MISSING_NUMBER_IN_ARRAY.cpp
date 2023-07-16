#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        int n;
        vector<int> array;
        int ret;

    Solution()
    {
        cin >> this->n;

        int n = this->n - 1;

        while(n--)
        {
            int i;
            cin >> i;

            this->array.push_back(i);
        }
    }

    void process()
    {
        int sum = ((this->n + 1) * this->n) / 2;

        int n = this->n - 1;

        while(n--)
        {
            sum -= this->array[n];
        }

        this->ret = sum;
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