// not done
#include <iostream>
using namespace std;
int Hoare_P(int *a, int f, int l)
{
    int x = a[f];
    int i = f - 1;
    int j = l + 1;
    while (true)
    {
        do
        {
            j--;
        } while (a[j] > x);
        do
        {
            i++;
        } while (a[i] < x);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
        else
        {
            return j;
        }
    }
}

int Lomuto_P(int *a, int f, int l)
{
    int pivot = a[l];
    int i = f - 1;
    for (int j = f; j <= l; j++)
    {
        if (a[j] <= pivot)
        {
            i += 1;
            swap(a[i], a[j]);
        }
    }
    // swap(a[i + 1], a[l]);
    return i;
}

void QuickSort(int *a, int f, int l)
{
    if (f < l)
    {
        int p = Lomuto_P(a, f, l);
        // int p = Hoare_P(a, f, l);
        QuickSort(a, f, p - 1);
        QuickSort(a, p + 1, l);
    }
}
void QuickSortIt(int *a, int f, int l)
{
    while (f < l)
    {
        int p = Hoare_P(a, f, l);
        // int p = Lomuto_P(a, f, l);
        QuickSortIt(a, f, p - 1);
        f = p + 1;
    }
}
void display(int *a, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter number of values: ";
    int n;
    cin >> n;

    int arr[] = {12, 4, 22, 57, 4, 2, 0};
    QuickSort(arr, 0, 6);
    // QuickSortIt(arr, 0, 6);
    display(arr, 7);
}