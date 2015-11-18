/*
 * Input            : String S (of length s) and pattern P (of length p)
 * Output           : Find start index of pattern in string
 * Time Complexity  : O(p+s)
 * 
 * Naive algorithm will require O(p*s) comparisons in the worst case.
 * Knuth Morris Pratt reduces the number of comparisons by using a preprocessed array
 * with lengths of longest proper prefix suffixes at each index.
 */

#include <iostream>
#include <vector>
using namespace std;

// Returns first matching index for pattern or -1
// Runs in O(len(p)xlen(s))
int naive_search(const string& s, const string& p)
{
    int result=-1;
    size_t s_size=s.size(), p_size=p.size();
    for(size_t i=0; i<s_size-p_size+1; ++i)
    {
        for(size_t j=0;j<p_size; ++j)
        {
            if (s[i+j]!=p[j])
                break;
            else if (j==p_size-1)
                return i;
            else
                continue;
        }
    }
    return -1;
}

// Prepare lps[] array
// This will store length of longest proper prefix suffix at each index
// This will allow us to skip certain indices every time we mismatch
// Runs in O(len(p))
void prepare_lps(const string& p, vector<int>* _lps)
{
    size_t p_size = p.size();
    vector<int>& lps=*_lps;
    size_t len=0; lps[0]=0;
    for (size_t i=1; i<p_size;)
    {
        if (p[len]==p[i])
        {
            ++len;
            lps[i]=len;
            ++i;
        }
        else
        {
            if (len>0)
            {
                --len;
            }
            else
            {
                lps[i]=0;
                ++i;
            }
        }
    }
}

// Returns first matching index for pattern or -1
// By itself runs in O(len(s)) time
// Since prepare_lps needs to be called, runs in O(len(p)+len(s)) total
// If mismatch, change i to i+j-lps[j]
int kmp_search(const string& s, const string& p)
{
    size_t p_size=p.size(), s_size=s.size();
    vector<int> lps(p_size);
    prepare_lps(p, &lps);
    size_t i=0;
    while (i<(s_size-p_size+1))
    {
        size_t j=0;
        while (j<p_size)
        {
            if (s[i+j]!=p[j])
            {
                if (lps[j]==0)
                    break;
                else
                    i=i+j-lps[j];
            }
            else
            {
                if (j+1==p_size)
                    return i;
            }
            ++j;
        }
        ++i;
    }
    return -1;
}

int main()
{
    string s[] = {"abbaccabcc", "cdeabbcabbabba", "abcdbabbabba"};
    string p = "abbabba";
    cout << "Naive Search" << endl;
    for(size_t i=0;i<3; ++i)
        cout<<"String: " << s[i] << ", Pattern: " << p << ", Found at: " << naive_search(s[i], p) << endl;
    cout << "KMP Search" << endl;
    for(size_t i=0;i<3; ++i)
        cout<<"String: " << s[i] << ", Pattern: " << p << ", Found at: " << kmp_search(s[i], p) << endl;
}
