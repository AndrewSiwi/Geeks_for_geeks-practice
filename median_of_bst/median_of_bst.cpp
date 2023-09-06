#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define N 10

#define ITER_ARR(start, end) for(int i = (start); i < (end); i++)
#define ITER_ARR_ALL ITER_ARR(0, this->n)
#define ITER_ARR_REVERSE for(int i = this->n - 1; i <= 0; i--)

#define ITER_VEC for(int x: this->ret)

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
    float i = -1, ret = 0, med = -1;
    Node* root = NULL;
    
    public:

    Solution()
    {
        int t;
        string tc;
        getline(cin, tc);
        t = stoi(tc);
        //cout << t << endl;
        while(t--)
        {
            string s;
            getline(cin, s);
            this->buildTree(s);
            
            this->process();
            this->print();
        }
    }

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

    void process()
    {
        this->recursive(this->root);
        this->med = this->i / 2.f;
        this->i = -1;
        this->recursive(this->root);
        if(this->med != (int)this->med) this->ret /= 2.f;
    }

    void recursive(Node* node)
    {
        if(node == NULL) return;
        
        this->recursive(node->left);
        this->i++;
        if(this->med == this->i || this->med + 0.5f == this->i || this->med - 0.5f == this->i) this->ret += node->data;
        this->recursive(node->right);
    }

    void print()
    {
        cout << this->ret << "\n";
    }
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution* sl = new Solution();
    //sl->process();
    //sl->print();

    return 0;
}
