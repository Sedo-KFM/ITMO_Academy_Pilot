#include <utility>
#include <algorithm>
#include <array>
#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <numeric>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <random>
#include <unordered_set>
#include <unordered_map>

// #define DEBUG
#ifdef DEBUG
#define CONTAINER_DELIMITER ", "
#define CONTAINER_LEFT_BORDER "["
#define CONTAINER_RIGHT_BORDER "]"
#else
#define CONTAINER_DELIMITER " "
#define CONTAINER_LEFT_BORDER ""
#define CONTAINER_RIGHT_BORDER ""
#endif

using namespace std;

namespace my {

#define named(block_name) goto block_name; \
                         block_name##_skip: if (false) \
                         block_name:

#define break(block_name) goto block_name##_skip

#define CIN_INIT(t, v) \
    t v;               \
    cin >> v

#define CIN_INIT_S2(t, v1, v2) \
    t v1, v2;                  \
    cin >> v1 >> v2

#define CIN_INIT_D2(t1, v1, t2, v2) \
    t1 v1;                             \
    t2 v2;                             \
    cin >> v1 >> v2

#define CIN_INIT_S3(t, v1, v2, v3) \
    t v1, v2, v3;                  \
    cin >> v1 >> v2 >> v3

#define CIN_INIT_D3(t1, v1, t2, v2, t3, v3) \
    t1 v1;                                  \
    t2 v2;                                  \
    t3 v3;                                  \
    cin >> v1 >> v2 >> v3

#define CIN_INIT_S4(t, v1, v2, v3, v4) \
    t v1, v2, v3, v4;                  \
    cin >> v1 >> v2 >> v3 >> v4

#define CIN_INIT_D4(t1, v1, t2, v2, t3, v3, t4, v4) \
    t1 v1;                                          \
    t2 v2;                                          \
    t3 v3;                                          \
    t4 v4;                                          \
    cin >> v1 >> v2 >> v3 >> v4

#define CIN_INIT_S5(t, v1, v2, v3, v4, v5) \
    t v1, v2, v3, v4, v5;                  \
    cin >> v1 >> v2 >> v3 >> v4 >> v5

#define CIN_INIT_D5(t1, v1, t2, v2, t3, v3, t4, v4, t5, v5) \
    t1 v1;                                                  \
    t2 v2;                                                  \
    t3 v3;                                                  \
    t4 v4;                                                  \
    t5 v5;                                                  \
    cin >> v1 >> v2 >> v3 >> v4 >> v5

#define CIN_INIT_S6(t, v1, v2, v3, v4, v5, v6) \
    t v1, v2, v3, v4, v5, v6;                  \
    cin >> v1 >> v2 >> v3 >> v4 >> v5 >> v6

#define CIN_INIT_D6(t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6) \
    t1 v1;                                                          \
    t2 v2;                                                          \
    t3 v3;                                                          \
    t4 v4;                                                          \
    t5 v5;                                                          \
    t6 v6;                                                          \
    cin >> v1 >> v2 >> v3 >> v4 >> v5 >> v6

    typedef unsigned int uint;
    typedef long long ll;
    typedef unsigned long long ull;

    template<class T>
    concept ReadableCollection = requires(T t) {
{ t.cbegin() } -> std::same_as<typename T::const_iterator>;
{ t.cend() } -> std::same_as<typename T::const_iterator>;
{ t.size() } -> std::convertible_to<size_t>;
};

template<ReadableCollection T>
ostream& operator<<(ostream& os, const T& input) {
    os << CONTAINER_LEFT_BORDER;
    if (input.size() > 0) {
        auto it_last = --input.cend();
        auto it = input.cbegin();
        for (; it != it_last; ++it)
            os << *it << CONTAINER_DELIMITER;
        os << *it;
    }
    os << CONTAINER_RIGHT_BORDER;
    return os;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& input) {
    os << input.first << CONTAINER_DELIMITER << input.second;
    return os;
}

ll bin_power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll bin_power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
}

using namespace my;

void solution_X() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution_X();

    return 0;
}
