#include<iostream>
#include<algorithm> // For min function

using namespace std;

struct Item {
    float profit;
    float quantity;
    float ratio;
};

// Function to perform fractional knapsack
float fractionalKnapsack(Item items[], float knapsackContents[], float capacity, int n);

// Function to sort items by decreasing order of profit per unit weight
void insertionSort(Item items[],int n);

int main()
{
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    cout<<endl;

    Item items[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the profit and quantity of item "<<i+1<<": ";
        cin>>items[i].profit>>items[i].quantity;
        items[i].ratio=items[i].profit/items[i].quantity;
    }

    float capacity;
    cout<<endl;
    cout<<"Enter the knapsack capacity: ";
    cin>>capacity;

    float knapsackContents[n]={0}; // let 𝐴[1 … 𝑤.𝑙𝑒𝑛𝑔𝑡ℎ] be an array initialized to 0

    float totalProfit=fractionalKnapsack(items, knapsackContents, capacity, n);

    cout<<endl;
    cout<<"Total profit: "<<totalProfit<< endl;
    cout<<endl;

    cout<<"Kilograms made of each item:"<<endl;
    for(int i=0; i<n; i++) {
        cout<<"Item "<<i+1<<": "<<knapsackContents[i]<<" kg"<<endl;
    }
    return 0;
}
// FRACTIONAL-KNAPSACK(W, w, v)
float fractionalKnapsack(Item items[], float knapsackContents[], float capacity, int n)
{
    float totalProfit=0;  // 𝑉 = 0
    insertionSort(items,n);  // sort items by decreasing order of 𝑣[ 𝑖 ]/𝑤[ 𝑖 ]

    for(int i=0; i<n; i++)  // for 𝑖 = 1 to 𝑤.𝑙𝑒𝑛𝑔𝑡ℎ
    {
        if(capacity==0)   // if 𝑊 == 0
        {
            return totalProfit; // return (𝑉, 𝐴)
        }

        float a=min(items[i].quantity,capacity); // 𝑎 = min( w[ i ] , W)

        totalProfit+=a*items[i].ratio; // 𝑉 = 𝑉 + 𝑎 ( 𝑣[ 𝑖 ]/𝑤[ 𝑖 ] )

        items[i].quantity -=a;    // 𝑤[ 𝑖 ] = 𝑤[ 𝑖 ] − 𝑎
        knapsackContents[i]+=a;  // A[ 𝑖 ] = 𝐴[ 𝑖 ] + 𝑎
        capacity-=a;             // 𝑊 = 𝑊 − 𝑎
    }

    return totalProfit;            // return (𝑉, 𝐴)
}

void insertionSort(Item items[], int n)
{
    for(int i=1; i<n; i++)
        {
        Item key=items[i];
        int j=i-1;

        while(j>=0 && items[j].ratio<key.ratio)
        {
            items[j+1]=items[j];
            j=j-1;
        }
        items[j+1]=key;
    }
}

