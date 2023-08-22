#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        int n, ret = 0;

    Solution()
    {
        cin >> n;
    }

    void process()
    {
        int bit_count = log2(this->n) + 1;
        int n = this->n;

        while(n > 0)
        {
            int bit_number = pow(2, --bit_count);

            if(n - bit_number >= 0)
            {
                n -= bit_number;
                this->ret++;
            }
        }
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
};