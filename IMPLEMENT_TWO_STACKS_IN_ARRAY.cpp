#include <bits/stdc++.h>

using namespace std;

#define N 200

class Solution
{
    int arr[N];
    int top1 = -1, top2 = N;
    int Q;

    public:

    Solution()
    {
        cin >> this->Q;
        int Q = this->Q;
        while(Q--)
        {
            int stack;
            cin >> stack;
            int op;
            cin >> op;

            int x;
            if(op == 1)
            {
                cin >> x;
            }

            if(stack == 1 && op == 1) this->push1(x);
            else if(stack == 1) cout << this->pop1() << "\n";
            else if(stack == 2 && op == 1) this->push2(x);
            else cout << this->pop2() << "\n";
        }
    }

    void push1(int x)
    {
        this->arr[++this->top1] = x;
    }

    int pop1()
    {
        if(this->top1 == -1) return -1;
        return this->arr[this->top1--];
    }

    void push2(int x)
    {
        this->arr[--this->top2] = x;
    }

    int pop2()
    {
        if(this->top2 == N) return -1;
        return this->arr[this->top2++];
    }

    void process()
    {

    }

    void print()
    {
        //cout << "\n";
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