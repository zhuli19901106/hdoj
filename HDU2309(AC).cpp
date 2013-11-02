#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool comparator(const int &a, const int &b)
{
    return a < b;
}

int main()
{
    vector<int> a;
    int i;
    int n;
    int sum;

    while(cin>>n && n)
    {
        a.clear();
        for(i = 0; i < n; i++){
            cin>>sum;
            a.push_back(sum);
        }
        sort(a.begin(), a.end(), comparator);

        sum = 0;
        for(i = 1; i < n - 1; i++)
        {
            sum = sum + a[i];
        }
        cout << sum / (n - 2) << endl;
    }

    return 0;
}

