#include <iostream>

using namespace std;

int longest_common_subsequence(const string& s1, const string& s2, int l1, int l2, int** dp)
{
    if (l1<0 || l2<0)
        return 0;
    else if (dp[l1][l2]==0)
    {
        if (s1[l1]==s2[l2])
            dp[l1][l2]=1+longest_common_subsequence(s1, s2, l1-1,l2-1,dp);
        else
        {
            dp[l1][l2]=max(longest_common_subsequence(s1, s2, l1-1,l2,dp), longest_common_subsequence(s1, s2, l1, l2-1,dp));
        }
    }
    else
    {
        //do nothing
    }
    return dp[l1][l2];
}
int longest_common_subsequence(const string& s1, const string& s2)
{
    int l1 =s1.size();
    int l2 =s2.size();
    int** dp = new int*[l1];
    for(int i=0;i<l1; ++i)
    {
        dp[i] = new int[l2];
        for(int j=0;j<l2; ++j)
        {
        dp[i][j] = 0;
        }
    }
    int result=longest_common_subsequence(s1, s2, l1-1, l2-1, dp);
    
    for(int i=0;i<l1; ++i)
}

int main()
{
    string s1("abcboy");
    string s2("dachoij");
    string lcs_string;
    int length = longest_common_subsequence(s1, s2, &lcs_string);
    cout<<"s1="<<s1<<" s2="<<s2<<" lcs_length="<<length<<" lcs="<<lcs_string<<endl;
}
