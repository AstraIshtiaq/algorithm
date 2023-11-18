#include <iostream>
using namespace std;
int main()
{
    int k;       //maximum value array A.
    cout<<"Enter the maximum value (k): ";
    cin>>k;
    int n;       //number of elements array A.
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int A[n];    // Create an array A of size n to store the elements.
    cout<<"Enter "<<n<<" elements for the array:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    int C[k+1];   // Create an array C of size k+1 to count occurrences.
    // Setting 0 to each of the elements of C
    for(int i=0; i<=k; i++)
    {
        C[i]=0;
    }
    // store in C of each element in A
    for(int j=0; j<n; j++)
    {
        C[A[j]]++;
    }
    // applying cumulative sum on C
    //so that C[i] contains the number of elements less than or equal to i.
    for(int i=1; i<=k; i++)
    {
        C[i]+=C[i-1];
    }
    int B[n];       // Create an array B to store the sorted elements.

    // Build the sorted array B.
    for(int j=n-1; j>=0; j--)
    {
        B[C[A[j]]-1]=A[j];     //Putting the elements of A into B in sorted order
        C[A[j]]--;
    }
    cout<<endl;
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<B[i]<< " ";
    }
    return 0;
}
