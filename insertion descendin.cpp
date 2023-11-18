#include <iostream>
using namespace std;

int main() {
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    int* arr =new int[size]; // Dynamically allocate memory for the array
    cout<<"Enter "<<size<<" integers for the array: ";

    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    // Insertion sort for descending order
    for(int j=1; j<size; j++)
        {
        int key=arr[j]; // Getting the key to put in the right position
        int i=j-1; // Getting the start part of the sorted part
        while(i>=0 && arr[i]<key)
        { // Change comparison to sort in descending order
            arr[i+1]=arr[i]; // Moving sorted elements to the right
            i--;
        }
        arr[i+1]=key; // Putting key in the right position
    }

    cout<<endl;
    cout<<"Sorted array in descending order: ";
    for(int i=0; i<size; i++) {
        cout<<arr[i]<< " ";
    }

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}

