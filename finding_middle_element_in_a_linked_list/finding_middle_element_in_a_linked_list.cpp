#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

#define N 10

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
        //cin >> t;
        ITER_FIX(i, 0, t)
        {
            Solution* sl = new Solution(i);
            sl->process();
            sl->print();
            delete sl;
        }
    }

    
    private: int ct;

    int n, ret;
    Node* head;

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
    }

    void process()
    {
        this->n = 0;
        Node* current = this->head;
        while(current != NULL)
        {
            this->n++;
            current = current->next;
        }
        
        int n = 1;
        int max = (this->n % 2 == 0) ? this->n / 2 + 1 : ceil((float)this->n / 2);
        current = this->head;
        while(n++ < max) current = current->next;
        this->ret = current->data;
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