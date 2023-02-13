#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{
    vector<string> check(26, "");
    stringstream ss(s);
    vector<string> words;
    string word;
    while (ss >> word)
    { // Extract word from the stream.
        words.push_back(word);
    }

    set<char> l;
    set<string> w;

    if (pattern.length() != words.size())
    {
        return false;
    }

    for (int i = 0; i < pattern.length(); i++)
    {
        l.insert(pattern[i]);
        w.insert(words[i]);
        if (check[pattern[i] - 'a'] == "" || check[pattern[i] - 'a'] == words[i])
        {
            check[pattern[i] - 'a'] = (words[i]);
        }
        else
        {

            return false;
        }
    }
    if (l.size() != w.size())
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string p, s;
        cin >> p;
        // cout<<p;
        getline(cin >> ws, s);
        // cout<<s;
        bool ans = wordPattern(p, s);
        if (ans)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
}