#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int n;
    queue<int> q;

    public:

    Solution()
    {
        cin >> this->n;
        int n = this->n;
        while(n--)
        {
            int x;
            cin >> x;
            this->q.push(x);
        }
    }

    void process()
    {
        this->recursive(this->n - 1);
    }

    void recursive(int i)
    {
        int x = this->q.front();
        this->q.pop();
        if(i > 0) this->recursive(--i);
        this->q.push(x);
    }

    void print()
    {
        //cout << "\n";

        while(!this->q.empty())
        {
            cout << this->q.front() << " ";
            this->q.pop();
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