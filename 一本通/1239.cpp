#include <iostream>
using namespace std;
int a[200005];
int ans[100005];
int counter[100005];
int partion(int left, int right)
{
    return (left + right) / 2;
}
void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
int Paritition1(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
        {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
        {
            ++low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high) 
{
    if (low < high)
    {
        int pivot = Paritition1(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int unicnt = 0, last = 0x33003300;
    QuickSort(a, 1, n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != last)
        {
            unicnt++;
            ans[unicnt] = a[i];
            counter[unicnt] += 1;
            last = a[i];
        }
        else
        {
            counter[unicnt]++;
        }
    }

    for (int i = 1; i <= unicnt; i++)
    {
        cout << ans[i] << " " << counter[i] << endl;
    }
}
