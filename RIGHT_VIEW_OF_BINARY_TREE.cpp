#include <bits/stdc++.h>

using namespace std;

#define ITER_ARR(start, end) for(int i = (start); i < (end); i++)
#define ITER_ARR_ALL ITER_ARR(0, this->n)
#define ITER_ARR_REVERSE for(int i = this->n - 1; i >= 0; i--)

#define N 100000

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
  int n, height;
  Node* root = NULL;
  vector<int> ret;

  public:

  Solution()
  {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
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
    this->recursive(this->root, 1);
  }

  void recursive(Node* node, int height)
  {
    if(node == NULL) return;
       
    if(height > this->height) { this->ret.push_back(node->data); this->height++; }
    this->recursive(node->right, ++height);
    this->recursive(node->left, height);
  }

  void print()
  {
    for(int x: this->ret)
    {
      cout << x << " ";
    }        
    cout << "\n";
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
