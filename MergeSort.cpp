#include <iostream>
using namespace std;
void merge(int *a, int f, int mid, int l)
{
    int *b = new int[l - f + 1];
    int i = f;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= l)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (j <= l)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    j = f;
    for (int i = 0; i < l - f + 1; i++)
    {
        a[j++] = b[i];
    }
    delete[] b;
}
void mergeSort(int *a, int f, int l)
{
    if (f < l)
    {
        int mid = (f + l) / 2;
        mergeSort(a, f, mid);
        mergeSort(a, mid + 1, l);
        merge(a, f, mid, l);
    }
}
int main()
{
    int arr[] = {12, 4, 22, 57, 4, 2};
    mergeSort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << "\n";
}