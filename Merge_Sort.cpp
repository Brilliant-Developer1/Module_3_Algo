// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

const int N = 1e5 + 7;
int nums[N];

void merge(int L, int R, int mid)
{
    // left array size
    int left_size = mid - L + 1;
    int l[left_size + 1];

    // right array size
    int right_size = R - (mid + 1) + 1;
    int r[right_size + 1];

    // sort left array
    for (int i = L, j = 0; i <= mid; i++, j++)
    {
        l[j] = nums[i];
    }
    // sort right array
    for (int i = mid + 1, j = 0; i <= R; i++, j++)
    {
        r[j] = nums[i];
    }
    // if left or right pointer reach to last index so other array can compare with infinity
    l[left_size] = INT_MAX;
    r[right_size] = INT_MAX;

    int LP = 0, RP = 0;
    for (int i = L; i <= R; i++)
    {
        if (l[LP] <= r[RP])
        {
            nums[i] = l[LP];
            LP++;
        }
        else
        {
            nums[i] = r[RP];
            RP++;
        }
    }
}
void mergSort(int L, int R)
{

    // base case
    if (L == R)
        return;

    int mid = (L + R) / 2;

    mergSort(L, mid);
    mergSort(mid + 1, R);
    merge(L, R, mid);
}
int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // sort(nums, nums + n);
    mergSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}

/*
input
8
12 7 3 9 2 5 4 18

output
2 3 4 5 7 9 12 18
*/