#include <bits/stdc++.h>

using namespace std;

#define ITER_ARR(start, end) for(int = (start); i < (end); i++)
#define ITER_ARR_ALL ITER_ARR(0, this->n)
#define ITER_ARR_REVERSE for(int i = this->n - 1; i >= 0; i--)

#define N 10

class Solution
{
  int n, arr[N];

  public:

  Solution()
  {
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
    vector<int> vals;
        
        for(int i = 0; i < 3; i++)
        {
            Node* current = head;
            while(current != NULL)
            {
                if(current->data == i) vals.push_back(current->data);
                current = current->next;
            }
        }
        
        Node* start = new Node(vals[0]);
        Node* current_end = start;
        
        for(int i = 1; i < vals.size(); i++)
        {
            current_end->next = new Node(vals[i]);
            current_end = current_end->next;
        }
        
        return start;
  }

  void print()
  {
    ITER_ARR_ALL
    {
      cout << this->arr[i] << " ";
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
