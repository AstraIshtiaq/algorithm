#include <iostream>
using namespace std;

void arraySum(int A[],int n) //define a arraySum function
{
    int sum=0;
    for (int i=0;i<n;i++)
    {
        sum=sum+A[i]; // add current element to the sum
    }
   cout<<"Sum of the array: "<<sum<<endl; //output of sum
}

int main()
{
    int arr[]={1,2,3,4,5}; // creating integer array
    int size=sizeof(arr)/sizeof(arr[0]); // calculate size
    arraySum(arr,size);// calling arraySum
    return 0;
}
