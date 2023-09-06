#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long
#define N 1000000
#define MINIMUM -10000000

class Solution
{
    int n, arr[N];
    STEROID_NUMBER ret;

    public:

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
        this->ret = MINIMUM;
        STEROID_NUMBER current = 0;

        for(int i = 0; i < this->n; i++)
        {
            current += this->arr[i];
            if(this->ret < current) this->ret = current;
            if(current < 0) current = 0;
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