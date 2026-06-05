
/*
Problem:USACO 2018 December Contest, Bronze Problem 1. Mixing Milk
Topic: Algorithms
Key idea: Calculate the total amount of milk in each bucket after the mixing process.
Time complexity: O(1)
Space complexity: O(1)
*/

#include <iostream>  // For std::cin, std::cout, std::endl
#include <vector>    // For std::vector
#include <string>    // For std::string
#include <algorithm> // For std::sort, std::reverse, std::min, std::max
#include <map>       // For std::map
#include <set>       // For std::set
#include <queue>     // For std::queue, std::priority_queue
#include <cmath>     // For math functions like std::sqrt, std::pow
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
    freopen("problem.in", "r", stdin);
    freopen("problem.out", "w", stdout);
    */
    vector<int> c(3);
    vector<int> m(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> c[i];
        cin >> m[i];
    }
    for (int n = 0; n < 100; ++n)
    {
        int now = n % 3;
        int next = (n + 1) % 3;
        int sum = m[now] + m[next];
        if (sum <= c[next])
        {
            m[next] = sum;
            m[now] = 0;
        }
        else
        {
            m[next] = c[next];
            m[now] = sum - c[next];
        }
    }

    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << '\n';
    }
    return 0;
}