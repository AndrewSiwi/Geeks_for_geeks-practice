#include <bits/stdc++.h>

using namespace std;

#define ITER_ARR(start, end) for(int i = (start); i < (end); i++)
#define ITER_ARR_REVERSE(start, end) for(int i = (start); i > (end); i--)
#define ITER_ARR_ALL ITER_ARR(0, this->n)

#define N 10000000

class Solution
{
    int n, arr[N];
    stack<int> ret;

    public:

    Solution()
    {
        cin >> this->n;
        int n = this->n;
        while(n--)
        {
            int x;
            cin >> x;
            this->arr[this->n - n - 1] = x;
        }
    }

    void process()
    {
        this->ret.push(this->arr[this->n - 1]);
        ITER_ARR_REVERSE(this->n - 2, -1)
        {
            if(this->arr[i] >= this->ret.top()) this->ret.push(this->arr[i]);
        }
    }

    void print()
    {
        //cout << "\n";

        while(!this->ret.empty())
        {
            cout << this->ret.top() << " ";
            this->ret.pop();
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution* sl = new Solution();
    sl->process();
    sl->print();

    return 0;
}