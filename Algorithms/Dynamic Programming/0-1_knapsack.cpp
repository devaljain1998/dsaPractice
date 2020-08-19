#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value, weight;
    bool chosen;

    Item() : value(0), weight(0), chosen(false) {}
    Item(int value, int weight) : value(value), weight(weight), chosen(false) {}
};

int input(vector<Item> &items, int n)
{
    int weights[n] = {0}, values[n] = {0};
    int capacity;
    cin >> capacity;
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++)
    {
        items.push_back(Item(values[i], weights[i]));
    }
    return capacity;
}

int maximumProfit(vector<Item> &items, int capacity)
{
    vector<vector<int>> profits(items.size() + 1, vector<int>(capacity + 1, -1));

    for (int i = 0; i < items.size() + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            //Fill the first row and columns with zeros
            if (i == 0 || j == 0)
                profits[i][j] = 0;
            //Agar weight current capacity se kam ho
            //toh uper waala copy karna hai
            else if (items[i].weight > j)
                profits[i][j] = profits[i - 1][j];

            else
                profits[i][j] = max(
                    profits[i - 1][j],                                   //Either profit from the above item
                    items[i].value + profits[i - 1][j - items[i].weight] //Or profit by adding value of the current item
                                                                         // and the profits got from weights of other items
                                                                         // by subtracting the weight of the current item
                );
        }
    }

    // for(int i=0; i<items.size()+1; i++){
    //     for(int j=0; j<capacity+1; j++){
    //         cout << profits[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return (profits.back()).back();

    return profits[items.size()][capacity]; //The maximum output
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<Item> items;
        auto capacity = input(items, n);
        cout << maximumProfit(items, capacity) << endl;
    }
    return 0;
}