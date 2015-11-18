#include <iostream>
#include <vector>
#include <algorithm>

// Input: N points and an integer K<=N
// N (number of x co-ordinates)
// ... x1
// ... x2
// ...
// ... xN 
// N (number of y co-ordinates)
// ... y1
// ... y2
// ...
// ... yN 
// K
// Output: Smallest area for a coordinate axes parallel square that strictly contains K of these N points
using namespace std;

long areaOfSquare(int lowX, int lowY, int highX, int highY)
{
    return (highX-lowX) * (highX-lowX);
}

long areaOfSmallestEncompassingSquare(vector<int> x_, vector<int> y_)
{
    long result=0;
    return result;
}

int main()
{


}
