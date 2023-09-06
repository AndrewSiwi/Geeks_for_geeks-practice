#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

#define N 10000

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t
        ITER_FIX(i, 0, t)
        {
            Solution* sl = new Solution(i);
            sl->process();
            sl->print();
            delete sl;
        }
    }

    private: int ct;

    int n, x;
    Node* head;
    bool ret = false;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n;
        int n = this->n;

        int x;
        cin >> x;
        Node* current = new Node(x);
        this->head = current;
        n--;
        while(n--)
        {
            cin >> x;
            current->next = new Node(x);
            current = current->next;
        }
        
        cin >> this->x;

        if(this->x > 0)
        {
            Node* loop = this->head;
            ITER_FIX(i, 1, this->x) loop = loop->next;
            current->next = loop;
        }
    }

    void process()
    {
        Node* current = this->head;
        for(int i = 1; i <= N && current != NULL; i++) current = current->next;
        if(current != NULL) this->ret = true;
    }

    void print()
    {
        cout << this->ret << "\n";
        //cout << "\n";
    }
};

int Solution::t = 1;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution::init();

    return 0;
}