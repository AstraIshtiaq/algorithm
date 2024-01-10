#include <iostream>
using namespace std;
// Function to merge two subarrays of arr[].
// First subarray is arr[p..q]
// Second subarray is arr[q+1..r]
void merge(int arr[], int p, int q, int r)
{
    int n1=q-p+1;
    int n2=r-q;
    // Create temporary arrays on the stack
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for(int i=0; i<n1; i++)
        L[i]=arr[p+i];

    for(int j=0; j<n2; j++)
        R[j]=arr[q+1+j];

    int i=0, j=0, k=p;
    // Merge the temporary arrays back into arr[p..r]
    while(i<n1 && j<n2)
        {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        } else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
// Main Merge Sort function
void mergeSort(int arr[], int p, int r) {
    if(p<r)
    {
        int q = (p + r) / 2;  // Find the middle point
        // Sort first and second halves
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);  // Merge the sorted halves
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Create an array to store the elements
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    cin >> arr[i];

    mergeSort(arr, 0, n - 1);   // Apply Merge Sort

     cout << endl;
    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
    return 0;
}

