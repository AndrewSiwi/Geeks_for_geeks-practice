#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += (diff))
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont, comm) for(auto var = cont.begin(); var != cont.end(); comm)

const int N = 1e5;

struct Node
{
    int data;
    Node* left;
    Node* right;

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

    static Node* buildTree(string str)
    {
        // Corner Case
        if(str.length() == 0 || str[0] == 'N')
            return NULL;

        // Creating vector of strings from input
        // string after spliting by space
        vector<string> ip;

        istringstream iss(str);
        for(string str; iss >> str; )
            ip.push_back(str);

        // Create the root of the tree
        Node* root = new Node(stoi(ip[0]));

        // Push the root to the queue
        queue<Node*> queue;
        queue.push(root);

        // Starting from the second element
        int i = 1;
        while(!queue.empty() && i < ip.size()) {

            // Get and remove the front of the queue
            Node* currNode = queue.front();
            queue.pop();

            // Get the current node's value from the string
            string currVal = ip[i];

            // If the left child is not null
            if(currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->left);
            }

            // For the right child
            i++;
            if(i >= ip.size())
                break;
            currVal = ip[i];

            // If the right child is not null
            if(currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->right);
            }
            i++;
        }

        return root;
    }


    private: int ct;

    Node* root;
    vector<int> ret;

    public: Solution(int ct)
    {
        this->ct = ct;

        string s;
        getline(cin, s);
        this->root = Solution::buildTree(s);
    }

    void process()
    {
        queue<Node*> q;
        this->ret.push_back(this->root->data);
        if(this->root->left != NULL) q.push(this->root->left);
        if(this->root->right != NULL) q.push(this->root->right);
        while(!q.empty())
        {
            int size = q.size();
            Node* first = q.front();
            this->ret.push_back(first->data);
            if(q.size() > 1)
            {
                Node* last = q.back();
                this->ret.push_back(last->data);
            }

            ITER_FIX(i, 0, size)
            {
                Node* current = q.front();
                if(current->left != NULL) q.push(current->left);
                if(current->right != NULL) q.push(current->right);

                q.pop();
            }
        }
    }

    void print()
    {
        ITER_CONT(x, this->ret)
            cout << x << " ";
        cout << "\n";
        //cout << "\n";
    }
};

int Solution::t = 1;

#undef int
#define int int
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution::init();

    return 0;
}