#include <iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int arr[size];  // Declare a fixed-size array

    cout<<"Enter "<<size<<" integers for the array: ";

    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    // Insertion sort
    for(int j=1; j<size; j++)
        {
        int key=arr[j];  // Getting the key to put in the right position
        int i=j-1;     // Getting the start part of the sorted subarray
        while(i>=0 && arr[i]<key)
        {
            arr[i+1]=arr[i];  // Moving sorted elements to the right
            i--;
        }
        arr[i+1]=key;  // Putting the key in the right position
    }
    cout<<endl;
    cout<<"Sorted array: ";
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<< " ";
    }
    return 0;
}
