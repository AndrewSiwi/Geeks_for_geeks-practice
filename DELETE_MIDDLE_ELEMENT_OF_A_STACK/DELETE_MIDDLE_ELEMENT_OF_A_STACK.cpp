#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int n;
    stack<int> s;

    public:

    Solution()
    {
        cin >> this->n;
        int n = this->n;

        while(n--)
        {
            int x;
            cin >> x;
            this->s.push(x);
        }
    }

    void process()
    {
        this->recursive(0);
    }

    void recursive(int i)
    {
        int x = this->s.top();
        this->s.pop();
        if(i == (this->n / 2)) return;
        this->recursive(++i);
        this->s.push(x);
    }

    void print()
    {
        //cout << "\n";
        while(!this->s.empty())
        {
            cout << this->s.top() << " ";
            this->s.pop();
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
