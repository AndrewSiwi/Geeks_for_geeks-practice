#include <bits/stdc++.h>

using namespace std;

void quicksort(int* arr, int left, int right)
{
    if(left < right)
    {
        int m = left;
        for(int i = left + 1; i <= right; i++)
        {
            if(arr[i] < arr[left])
            {
                int tmp = arr[i];
                arr[i] = arr[++m];
                arr[m] = tmp;
            }
        }
        int tmp = arr[left];
        arr[left] = arr[m];
        arr[m] = tmp;

        quicksort(arr, left, m - 1);
        quicksort(arr, m + 1, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int arr[n];
    int count = n;
    while(n--)
    {
        int k;
        cin >> k;
        arr[n] = k;
    }

    quicksort(arr, 0, count - 1);


    cout << arr[0];
    for(int i = 1; i < count; i++)
    {
        cout << " " << arr[i];
    }
    cout << "\n";

    return 0;
}