#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        int x, y, l, r;
        int ret = 0;

    Solution()
    {
        cin >> this->x >> this->y >> this->l >> this->r;
    }

    void process()
    {
        this->ret = this->x;

        int l = this->l;
        while(l++ <= this->r)
        {
            if(this->y & (1 << (l - 2)))
            {
                this->ret |= 1 << (l - 2);
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
}