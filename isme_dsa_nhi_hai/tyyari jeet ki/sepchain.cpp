#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> v[27];

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int j = s[0] - 'a';
        v[j].push_back(s);
    }

    for (int i = 0; i < 27; ++i)
    {
        vector<string> temp = v[i];
        cout << i << " ";
        for (auto &s : temp)
        {
            cout << s << " ";
        }

        cout << endl;
    }

    string search;
    cin >> search;
    int j = search[0] - 'a';
    bool ok = 0;

    for (auto s : v[j])
    {
        if (s == search)
        {
            ok = 1;
            break;
        }
    }

    if (ok)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}