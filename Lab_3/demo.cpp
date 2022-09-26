// Rakesh Jhunjhunwala has recently announced the launch of his dream airline “Akasha”. Since Jhunjhunwala are new to airline business so they have a single plane to operate between Mumbai and Chennai. To grow up the business Akasha airline has a tie up with the giant airlines like VISTARA and AIR INDIA. During the festive seasons, when the customer rush is quite high, giant airlines rent the airplanes to accommodate the customer load. Airlines sent their order request mentioning the duration for which they want to hold the aircraft. During heavy rush durations many airlines submit their request to Akasha for their aircarfts. Hence, due to limited availability, few requests should be declined. However, to maximize the profit the optimal solution must be computed with minimal rejections and maximum approvals.

// Let us consider an scenario in which the Akasha airline received four requests:

// Request 1: (Start time=0, Duration = 5, Cost = 10)

// Request 2: (Start time=3, Duration = 7, Cost = 8)

// Request 3: (Start time=5, Duration = 9, Cost = 7)

// Request 4: (Start time=6, Duration = 9, Cost = 8)

// In the above scenarios, if the request 2 and 3 are rejected then the gain is 10+8 = 18. It is worth noting that accepting request 1 and 3 is feasible but this solution is not the optimal one.

// Input

// First line of test case has number of requests R i.e. R <= 10000. This is followed by number of requests. Each request has 3 integer values representing start time (T), duration of request (D) and cost (S) customer to pay for the order. The constraints are as follows: 0<=T<1000000, 0<D<1000000 and 0<S<1000000.

// Output.

// Task is to determine the optimal solution for the requests received. For each test case print the total cost paid by the airlines for renting the aircraft.

// Input:

// 4

// 0 5 10

// 3 7 14

// 5 9 7

// 6 9 8

// Output:

// 18


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct request
{
    int start;
    int duration;
    int cost;
};

bool compare(request a, request b)
{
    return a.start < b.start;
}

int main()
{
    int n;
    cin >> n;
    vector<request> req(n);
    for (int i = 0; i < n; i++)
    {
        cin >> req[i].start >> req[i].duration >> req[i].cost;
    }

    sort(req.begin(), req.end(), compare);

    int dp[n];
    dp[0] = req[0].cost;
    for (int i = 1; i < n; i++)
    {
        int temp = req[i].cost;
        int low = 0;
        int high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (req[mid].start + req[mid].duration <= req[i].start)
            {
                if (req[mid + 1].start + req[mid + 1].duration <= req[i].start)
                {
                    low = mid + 1;
                }
                else
                {
                    temp += dp[mid];
                    break;
                }
            }
            else
            {
                high = mid - 1;
            }
        }
        dp[i] = max(temp, dp[i - 1]);
    }

    cout << dp[n - 1];
    return 0;
}