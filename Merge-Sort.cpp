//Merge sort using only one temporary array instead of copying two left-right arrays

#include <iostream>
using namespace std;

void merge(int a[], int start, int mid, int end)
{
    int temp[end - start + 1];
    int index = 0;
    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (a[left] <= a[right])
        {
            temp[index] = a[left];
            index++;
            left++;
        }
        else
        {
            temp[index] = a[right];
            index++;
            right++;
        }
    }
    while (left <= mid)
    {
        temp[index] = a[left];
        index++;
        left++;
    }
    while (right <= end)
    {
        temp[index] = a[right];
        index++;
        right++;
    }
    for (int i = start; i <= end; i++)
    {
        a[i] = temp[i - start];
    }
}

void mergeSort(int a[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "After Marge Sort: ";
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
