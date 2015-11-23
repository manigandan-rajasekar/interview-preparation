/*
Problem Statement

You are situated in an N dimensional grid at position (x1,x2,...,xN). The dimensions of the grid are (D1,D2,...DN). In one step, you can walk one step ahead or behind in any one of the N dimensions. (So there are always 2×N possible different moves). In how many ways can you take M steps such that you do not leave the grid at any point? You leave the grid if at any point xi, either xi≤0 or xi>Di.

Input Format 
The first line contains the number of test cases T. T test cases follow. For each test case, the first line contains N and M, the second line contains x1,x2,…,xN and the 3rd line contains D1,D2,…,DN.

Output Format 
Output T lines, one corresponding to each test case. Since the answer can be really huge, output it modulo 1000000007.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

long number_of_walks(const vector<int>& positions, const vector<int>& dimensions)
{
    return 0l;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t=0;
    string line;
    getline(cin, line);
    istringstream iss(line);
    iss>>t;
    iss.clear();
    while(t>0)
    {
        int m=0, n=0;
        
        getline(cin, line);
        iss.str(line);
        iss>>n>>m;
        iss.clear();
        
        vector<int> positions(n), dimensions(n);

        getline(cin, line);
        iss.str(line);
        for(size_t i=0; i<n; ++i)
            iss>>positions[i];
        iss.clear();
        
        getline(cin, line);
        iss.str(line);
        for(size_t i=0; i<n; ++i)
            iss>>dimensions[i];
        iss.clear();

        //for(size_t i=0; i<n; ++i)
        //    cout<<positions[i]<<" ";
        //cout<<endl;
        //for(size_t i=0; i<n; ++i)
        //    cout<<dimensions[i]<<" ";
        //cout<<endl;
        long result = number_of_walks(positions, dimensions);
        cout<<result<<endl;
        t--;
    }
    return 0;
}

