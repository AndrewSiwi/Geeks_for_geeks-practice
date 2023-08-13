#include  <bits/stdc++.h>

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
    map<int, Node*> children;

    Node(int x)
    {
        this->data = x;
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

    int n, arr[N] = { 0 }, ret = 0;
    Node* node_arr[N];
    map<int, Node*> roots;


    public: Solution(int ct)
    {
        this->ct = ct;

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
        ITER_ARR(i) this->node_arr[i] = new Node(this->arr[i]);
        this->roots.insert({ this->node_arr[0]->data, this->node_arr[0] });

        ITER_ARR(i)
        {
            if(i == 0) continue;

            Node* x = this->node_arr[i];
            this->recursive(x, &(this->roots), 0);
        }
    }

    void recursive(Node* x, map<int, Node*>* currents, int length)
    {
        if(++length > this->ret) this->ret = length;

        bool inserted = false;
        ITER_CONT_IT(it, *(*currents))
        {
            Node* child = it.second;
            if(x->data > child->data)
            {    
                this->recursive(x, &(child->children), length);
                inserted = true;
                advance(it, 1);//??
                continue;
            }
            break;
        }
        if(!inserted) currents->insert({ x->data, x });
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