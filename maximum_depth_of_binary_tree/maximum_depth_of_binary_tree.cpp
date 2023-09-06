#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += (diff))
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

#define N 10

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};


class Solution
{
    static int t;
    public: static void init()
    {
        cin >> t;
        ITER_FIX(i, 0, t)
        {
            Solution* sl = new Solution();
            sl->process();
            sl->print();
            delete sl;
        }
    }

    private:

    Node* root;
    int ret = 0;

    void buildTree(string str)
    {
        if(str.length() == 0 || str[0] == 'N') return;

        vector<string> ip;
        istringstream iss(str);
        for(string str; iss >> str;) ip.push_back(str);

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
        if(i >= ip.size()) break;
        currVal = ip[i];
                
        if(currVal != "N")
        {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
        }

        this->root = root;
    }

    public:

    Solution()
    {
        string s;
        cin.ignore();
        getline(cin, s);
        this->buildTree(s);
    }

    void process()
    {
        this->recursive(this->root, 1);
    }
    
    void recursive(Node* current, int height)
    {
        if(height > this->ret) this->ret = height;

        if(current->left != NULL) this->recursive(current->left, height + 1);
        if(current->right != NULL) this->recursive(current->right, height + 1);
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