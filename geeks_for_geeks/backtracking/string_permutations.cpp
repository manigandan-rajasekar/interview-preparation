/*
 * Input : String
 * Output: All permutations of a string
 *
 */

#include <iostream>
#include <string>

using namespace std;

void swap(string& s, int i, int j)
{
    char tmp = s[j];
    s[j] = s[i];
    s[i] = tmp;
}
void permute(string& s, int start, int end)
{
    if (start==end)
        cout<<s<<endl;
    else
    {
        for(size_t i=start; i<=end; ++i)
        {
            swap(s, start, i);
            permute(s, start+1, end);
            swap(s, start, i);
        }
    }
}

int main()
{
    {
        string s="abcd";
        int s_size=s.size();
        permute(s, 0, s_size-1);
    }
}
