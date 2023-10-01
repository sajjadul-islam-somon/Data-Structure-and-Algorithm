//Quick sort using general algorithm

#include <iostream>
#include <algorithm>
using namespace std;

int partition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l-1;
    for (int j = l; j < r; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int pivot = partition(a, l, r);
        quicksort(a, l, pivot-1);
        quicksort(a, pivot+1, r);
    }   
}

int main()
{
    int a[] = {5, 2, 1, 3, 4};
    int n = sizeof(a)/sizeof(a[0]);
    quicksort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
