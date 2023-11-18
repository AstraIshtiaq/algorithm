#include <iostream>
using namespace std;
void arraySum(int A[], int n) //Define a function to calculate sum
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum=sum+A[i];
    }
    cout<<endl;
    cout<<"Sum of the array: "<<sum<<endl; //print the sum
}
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int* arr =new int[size]; //Dynamically allocate memory
    cout<<"Enter "<<size<<" integers for the array: ";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    arraySum(arr,size); //calculate & display sum of array
    return 0;
}
