/*
 * Input : List of objects with weights and values. Max allowed weight.
 * Output: Most value that can be gotten for such weight.
 *
 * items  : a b c d e f
 * weights: 1 2 3 7 8 9
 * values : 2 3 4 6 7 8
 * max weight=10, output=a,b,d value=11
 * */
#include <iostream>
#include <algorithm>

using namespace std;

size_t binary_knapsack(size_t weights[], size_t values[], size_t max_weight, bool chosen_items[], size_t n, size_t sum_values[6][11])
{
    if (n==0)
        return 0;
    else if (max_weight==0)
        sum_values[n-1][max_weight]=0;
    else 
    {
        chosen_items[n-1]=true;
        if (sum_values[n-1][max_weight]<=0)
        {
            if (weights[n-1] > max_weight)
            {
                chosen_items[n-1]=false;
                sum_values[n-1][max_weight]=binary_knapsack(weights, values, max_weight, chosen_items, n-1, sum_values);
            }
            else
            {
                size_t val1 = values[n-1]+binary_knapsack(weights, values, max_weight-weights[n-1], chosen_items, n-1, sum_values);

                bool chosen_items2[n-1];
                size_t val2 = binary_knapsack(weights, values, max_weight, chosen_items2, n-1, sum_values);
                if (val2>val1)
                {
                    chosen_items[n-1]=false;
                    copy(&chosen_items2[0], &chosen_items2[n-1], &chosen_items[0]);
                }
                sum_values[n-1][max_weight]=max(val1, val2);
            }
        }
    }

    return sum_values[n-1][max_weight];
}

int main()

{
    size_t max_weight=10;
    size_t weights[] ={1, 2, 3, 7, 8, 9};
    size_t values[]  ={2, 3, 4, 6, 7, 8};
    bool chosen_items[]    ={false, false, false, false, false};
    size_t num_items=6;
    cout <<"Max. Weight"<<endl;
    cout << max_weight << endl;
    cout<<"Weights"<<endl;
    for(size_t i=0; i<num_items; ++i)
        cout<< weights[i] << " ";
    cout << endl;
    cout<<"Values"<<endl;
    for(size_t i=0; i<num_items; ++i)
        cout<< values[i] << " ";
    cout << endl;
    size_t sum_values[6][11];
    memset( &sum_values[0][0], 0, sizeof(sum_values) );
    
    size_t max_value=binary_knapsack(weights, values, max_weight, chosen_items, 6, sum_values);
    cout<<"Chosen Items"<<endl;
    for(size_t i=0; i<num_items; ++i)
        cout<< chosen_items[i] << " ";
    cout << endl;
    cout <<"Max. Value"<<endl;
    cout << max_value << endl;

}
