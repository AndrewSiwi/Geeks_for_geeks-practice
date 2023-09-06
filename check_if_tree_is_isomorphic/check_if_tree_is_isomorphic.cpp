#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont, comm) for(auto var = cont.begin(); var != cont.end(); comm)

const int N = 1e1;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->data = x;
        this->left = this->right = NULL;
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

    Node* buildTree(string str)
    {
        if(str.length() == 0 || str[0] == 'N')
            return NULL;
        
        vector<string> ip;
        
        istringstream iss(str);
        for(string str; iss >> str; )
            ip.push_back(str);
        
        Node* root = new Node(stoi(ip[0]));
        
        queue<Node*> queue;
        queue.push(root);
        
        int i = 1;
        while(!queue.empty() && i < ip.size())
        {
            Node* currNode = queue.front();
            queue.pop();
        
            string currVal = ip[i];
        
            if(currVal != "N")
            {
                currNode->left = new Node(stoi(currVal));
                queue.push(currNode->left);
            }

            i++;
            if(i >= ip.size())
                break;
            currVal = ip[i];
            
            if(currVal != "N")
            {
                currNode->right = new Node(stoi(currVal));
                queue.push(currNode->right);
            }
            i++;
        }
        
        return root;
    }


    private: int ct;

    Node* root1, *root2;
    bool ret = true;

    public: Solution(int ct)
    {
        this->ct = ct;

        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);

        this->root1 = Solution::buildTree(s1);
        this->root2 = Solution::buildTree(s2);
    }

    void process()
    {
        this->ret = this->recursive(this->root1, this->root2);
    }

    bool recursive(Node* root1, Node* root2)
    {
        if(root1 == NULL && root2 == NULL) return true;
        if((root1 == NULL && root2 != NULL) ||
           (root2 == NULL && root1 != NULL)) return false;
        if(root1->data != root2->data) return false;
        
        bool ret1 = false;
        if(this->recursive(root1->left, root2->left)) ret1 = true;
        if(this->recursive(root1->left, root2->right)) ret1 = true;
        bool ret2 = false;
        if(this->recursive(root1->right, root2->left)) ret2 = true;
        if(this->recursive(root1->right, root2->right)) ret2 = true;
        
        return (ret1 && ret2);
    }

    void print()
    {
        cout << this->ret << "\n";
        //cout << "\n";
    }
};

int Solution::t = 1;

#undef int
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution::init();

    return 0;
}