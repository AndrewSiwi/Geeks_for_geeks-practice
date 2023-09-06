#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont, comm) for(auto var = cont.begin(); var != cont.end(); comm)

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
        int ct = 0;
        while(ct < t /*!cin.eof()*/)
        {
            Solution* sl = new Solution(ct++);
            sl->process();
            sl->print();
            delete sl;
        }
    }


    private: int ct;

    int n;
    Node* head;
    
    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n;
        int n = this->n;
        int x;
        cin >> x;
        this->head = new Node(x);
        Node* current = this->head;
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
        Node* tail = this->head;
        Node* current = this->head;
        while(current != NULL)
        {
            if(this->head->data < current->data)
                this->head = current;
            else if(tail->data < current->data)
            {
                Node* tmp = this->head;
                while(current != tmp->next && tmp->next->data >= current->data)
                    tmp = tmp->next;
                tmp->next = current;
            }

            tail = current;
            current = current->next;
        }
    }

    void print()
    {
        Node* current = this->head;
        while(current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
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