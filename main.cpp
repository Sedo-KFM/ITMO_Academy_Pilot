#include <utility>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <vector>
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
    } && !std::is_same_v<T, std::string>;

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

    vector<int> z_function(string s, bool leading_value = true) {
        int n = (int) s.length();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        if (leading_value) {
            z[0] = n;
        }
        return z;
    }

    vector<int> z_function(string p, string s) {
        int sn = (int) s.length();
        vector<int> pz = z_function(p, false);
        vector<int> z(sn);
        for (int i = 0, l = 0, r = 0; i < sn; ++i) {
            if (i <= r)
                z[i] = min(r - i + 1, pz[i - l]);
            while (i + z[i] < sn && p[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }

    vector<int> reversed_z_function(string s, bool leading_value = true) {
        int n = (int) s.length();
        vector<int> z(n);
        for (int i = n - 2, l = n - 1, r = n - 1; i >= 0; --i) {
            if (i >= l)
                z[i] = min(i - l + 1, z[n - (r - i) - 1]);
            while (i - z[i] >= 0 && s[n - 1 - z[i]] == s[i - z[i]])
                ++z[i];
            if (i - z[i] + 1 < l)
                r = i, l = i - z[i] + 1;
        }
        if (leading_value) {
            z[n - 1] = n;
        }
        return z;
    }

    vector<uint> suffix_array(string s) {
        uint s_size = s.size();
        uint eq_size = s_size + 1;
        auto indexes = vector<uint>(eq_size);
        iota(++indexes.begin(), indexes.end(), 0);
        indexes[0] = s_size;
        sort(++indexes.begin(), indexes.end(), [&](uint i, uint j) {
            return s[i] < s[j];
        });
        auto eq = vector<uint>(eq_size);
        uint cur_eq = 0;
        for (uint i = 1; i < eq_size; ++i) {
            if (s[indexes[i - 1]] == s[indexes[i]]) {
                eq[indexes[i]] = cur_eq;
            } else {
                eq[indexes[i]] = ++cur_eq;
            }
        }

        for (int k = 0; cur_eq < s_size; ++k) {
            int shift = 1 << k;

            auto tail = indexes.begin();
            for (auto head = ++indexes.begin(); head != indexes.end(); ++head) {
                if (eq[*head] != eq[*tail]) {
                    if (head - tail > 1) {
                        sort(tail, head, [&](uint l, uint r) {
                            uint l_shift = l + shift;
                            if (l_shift >= eq_size) l_shift -= eq_size;
                            uint r_shift = r + shift;
                            if (r_shift >= eq_size) r_shift -= eq_size;
                            return eq[l_shift] < eq[r_shift];
                        });
                    }
                    tail = head;
                }
            }
            if (indexes.end() - tail > 1) {
                sort(tail, indexes.end(), [&](uint l, uint r) {
                    uint l_shift = l + shift;
                    if (l_shift >= eq_size) l_shift -= eq_size;
                    uint r_shift = r + shift;
                    if (r_shift >= eq_size) r_shift -= eq_size;
                    return eq[l_shift] < eq[r_shift];
                });
            }

            auto eq_next = vector<uint>(eq.size());
            cur_eq = 0;
            for (int i = 1; i < eq_size; ++i) {
                if (eq[indexes[i - 1]] == eq[indexes[i]]) {
                    uint prev_shift = indexes[i - 1] + shift;
                    if (prev_shift >= eq_size) prev_shift -= eq_size;
                    uint cur_shift = indexes[i] + shift;
                    if (cur_shift >= eq_size) cur_shift -= eq_size;
                    if (eq[prev_shift] == eq[cur_shift]) {
                        eq_next[indexes[i]] = cur_eq;
                    } else {
                        eq_next[indexes[i]] = ++cur_eq;
                    }
                } else {
                    eq_next[indexes[i]] = ++cur_eq;
                }
            }
            eq.swap(eq_next);
        }
        return indexes;
    }
}

using namespace my;

namespace z_function_block {

    // ✅
    void step_1_A() {
        CIN_INIT(int, n);
        for (int gi = 0; gi < n; ++gi) {
            CIN_INIT(string, s);
            if (s.size() == 1) {
                cout << 1 << '\n';
                continue;
            }
            bool is_palindrome = true;
            for (uint i = s.size() - 1; i != 0; --i) {
                is_palindrome = true;
                for (uint shift = 0; shift < (i + 1) / 2; ++shift) {
                    if (s[shift] != s[i - shift]) {
                        is_palindrome = false;
                        break;
                    }
                }
                if (is_palindrome) {
                    cout << i + 1 << '\n';
                    break;
                }
            }
            if (!is_palindrome) {
                cout << 1 << '\n';
            }
        }
    }

    // ✅
    void step_1_B() {
        CIN_INIT(uint, gn);
        for (uint gi = 0; gi < gn; ++gi) {
            CIN_INIT(string, s);
            uint count = 0;
            auto fz = z_function(s);
            auto rz = reversed_z_function(s);
            for (uint l = 0; l < s.size(); ++l) {
                for (uint r = l; r < s.size(); ++r) {
                    uint len = r - l + 1;
                    if ((fz[l] >= len) ^ (rz[r] >= len)) {
                        ++count;
                    }
                }
            }
            cout << count << endl;
        }
    }

    // ✅
    void step_1_C() {
        CIN_INIT(uint, gn);
        for (uint gi = 0; gi < gn; ++gi) {
            CIN_INIT(string, t);
            CIN_INIT(string, p);
            if (t.size() < p.size()) {
                cout << 0 << endl << endl;
                continue;
            }
            list<uint> finds;
            for (uint start_index = 0; start_index <= t.size() - p.size(); ++start_index) {
                for (uint i = 0; i < p.size(); ++i) {
                    if (t[start_index + i] != p[i] && p[i] != '?') {
                        goto s1c_1;
                    }
                }
                finds.push_back(start_index);
                s1c_1:
                continue;
            }
            cout << finds.size() << '\n' << finds << endl;
        }
    }

    // ❌
    void step_1_D() {
        CIN_INIT(uint, gn);
        for (uint gi = 0; gi < gn; ++gi) {
            CIN_INIT(string, s);
            CIN_INIT(string, t);
            auto finds = list<uint>();
            if (t.size() <= s.size()) {
                for (uint start_index = 0; start_index <= s.size() - t.size(); ++start_index) {
                    for (uint i = 0; i < t.size(); ++i) {
                        if (s[start_index + i] != t[i]) {
                            goto s1d;
                        }
                    }
                    finds.push_back(start_index + 1);
                    s1d:
                    continue;
                }
            }
            finds.push_back(s.size() - t.size() + 2);

            ull count = 0;
            count += (s.size() - t.size() + 2) * (t.size() - 1);
            count += (t.size() - 2) * (t.size() - 1) / 2;
            ull prev = 0;
            for (auto it = finds.begin(); it != finds.end(); ++it) {
                ull width = *it - prev + t.size() - 2;
                for (ull n = 1; width >= t.size(); ++n, --width) {
                    count += n;
                }
                prev = *it;
            }
            cout << count << endl;
        }
    }

    // ✅
    void step_2_A() {
        CIN_INIT(string, s);
        cout << z_function(s, false) << endl;
    }

    // ✅
    void step_2_B() {
        CIN_INIT(uint, gn);
        for (uint gi = 0; gi < gn; ++gi) {
            CIN_INIT_S2(ull, k, j);
            k = 0;
            while (!(j & 1) && j) {
                ++k;
                j >>= 1;
            }
            cout << (1 << k) - 1 << endl;
        }
    }

    // ❌
    void step_2_C() {
        auto alphabet = list<char>();
        for (char c = 'a'; c <= 'z'; ++c) {
            alphabet.push_back(c);
        }
        for (char c = 'A'; c <= 'Z'; ++c) {
            alphabet.push_back(c);
        }

        CIN_INIT(uint, gn);
        for (uint gi = 0; gi < gn; ++gi) {
            CIN_INIT(uint, n);
            auto z = vector<uint>(n);
            for (uint i = 0; i < n; ++i) {
                CIN_INIT(uint, zi);
                z[i] = zi;
            }
            if (z[0]) {
                cout << '!' << endl;
                continue;
            }
            string s = string(n, '-');
            auto next_letter = alphabet.cbegin();
            s[0] = *next_letter;
            try {
                for (uint i = 0; i < n; ++i) {
                    if (z[i]) {
                        uint z_local = z[i];
                        for (uint i_local = 0; i_local < z_local; ++i_local, ++i) {
                            s[i] = s[i_local];
                        }
                        --i;
                    } else {
                        s[i] = *next_letter++;
                    }
                }
                auto z2 = z_function(s, false);
                if (!std::equal(z2.begin(), z2.end(), z.begin())) {
                    cout << '!' << endl;
                } else {
                    cout << s << endl;
                }
            } catch (const exception& e) {
                cout << '!' << endl;
            }
        }
    }

    // ✅
    void step_3_A() {
        CIN_INIT(string, s);
        cout << z_function(s, false) << endl;
    }

    // ✅
    void step_3_A_alt() {
        CIN_INIT(string, s);
        auto z = z_function(s, s);
        z[0] = 0;
        cout << z << endl;
    }

    // ✅
    void step_4_A() {
        CIN_INIT(uint, gn);
        for (uint gi = 0; gi < gn; ++gi) {
            CIN_INIT(string, s);
            auto z = z_function(s, false);
            for (uint i = 0; i < s.size(); ++i) {
                if (z[i] == s.size() - i) {
                    cout << s.substr(0, i) << endl;
                    goto s4a;
                }
            }
            cout << s << endl;
            s4a:
            continue;
        }
    }

    // ✅
    void step_4_B() {
        CIN_INIT(uint, gn);
        for (uint gi = 0; gi < gn; ++gi) {
            CIN_INIT(string, s2);
            CIN_INIT(string, s);
            s.append("$").append(s2).append(s2);
            auto z = z_function(s);
            for (uint i = s2.size() + 1; i < z.size(); ++i) {
                if (z[i] >= s2.size()) {
                    cout << i - s2.size() - 1 << endl;
                    goto s4b;
                }
            }
            cout << -1 << endl;
            s4b:
            continue;
        }
    }

    // ✅
    void step_4_C() {
        CIN_INIT(uint, gn);
        for (uint gi = 0; gi < gn; ++gi) {
            CIN_INIT(string, s);
            auto z = z_function(s, false);
            auto p = priority_queue<uint, deque<uint>, greater<>>();
            uint p_cur_val = 1;
            for (auto z_value: z) {
                if (z_value) {
                    p.push(z_value);
                    ++p_cur_val;
                }
            }
            for (uint index = 0; index < s.size(); ++index) {
                cout << p_cur_val << ' ';
                while (!p.empty() && p.top() <= index + 1) {
                    p.pop();
                    --p_cur_val;
                }
            }
            cout << endl;
        }
    }

    // ✅
    void step_4_D() {
        CIN_INIT(string, s);
        {
            auto rs = s;
            reverse(rs.begin(), rs.end());
            s.append(rs);
        }
        auto z = z_function(s);
        int z_max = 0;
        for (uint i = z.size() - 1; i >= z.size() / 2; --i) {
            if (z[i] + i == s.size()) {
                z_max = z[i];
            }
        }
        cout << z_max << endl;
    }

    // ✅
    void step_4_E() {
        CIN_INIT_S2(string, s, sm);
        if (s.size() != sm.size()) {
            cout << "No" << endl;
            return;
        }
        auto z = z_function(sm, s);
        for (int i = 0; i < z.size(); ++i) {
            if (z[i] + i == z.size()) {
                if (equal(s.cbegin(), s.cbegin() + i, sm.crbegin())) {
                    cout << "Yes\n" << i << endl;
                    return;
                }
            }
        }
        cout << "No" << endl;
    }

    void step_4_F() {
        CIN_INIT(uint, gn);
        for (uint gi = 0; gi < gn; ++gi) {
            CIN_INIT_S2(string, sa, sb);
            auto zab = z_function(sa, sb);
            auto zba = z_function(sb, sa);
            uint zab_max = 0;
            uint zab_max_index = 0;
            uint zba_max = 0;
            uint zba_max_index = 0;
            for (uint i = 0; i < zab.size(); ++i) {
                if (zab[i] + i == zab.size() || zab[i] == sa.size()) {
                    zab_max = zab[i];
                    zab_max_index = i;
                    break;
                }
            }
            for (uint i = 0; i < zba.size(); ++i) {
                if (zba[i] + i == zba.size() || zba[i] == sb.size()) {
                    zba_max = zba[i];
                    zba_max_index = i;
                    break;
                }
            }
            if (zab_max == 0 && zba_max == 0) {
                cout << sb << sa << endl;
            } else if (zab_max == sa.size()) {
                cout << sb << endl;
            } else if (zba_max == sb.size()) {
                cout << sa << endl;
            } else if (zba_max > zab_max) {
                cout << sa.substr(0, zba_max_index) << sb << endl;
            } else {
                cout << sb.substr(0, zab_max_index) << sa << endl;
            }
        }
    }

    // ❌
    void step_4_G() {
        CIN_INIT_S2(int, n, m);
        auto vs = vector<uint>(n);
        for (int i = 0; i < n; ++i) {
            cin >> vs[i];
        }
        for (int i = 0; i <= n / 2; ++i) {
            for (int il = i - 1, ir = i; il >= 0; --il, ++ir) {
                if (vs[il] != vs[ir]) {
                    goto s4g;
                }
            }
            cout << n - i << ' ';
            s4g:
            continue;
        }
        cout << endl;
    }

    // ❌
    void step_4_H() {}

    // ❌
    void step_4_I() {}

    // ❌
    void step_4_J() {}
}

namespace suffix_array_block {

    // ✅
    void step_1_A() {
        CIN_INIT(string, s);
        cout << suffix_array(s) << endl;
    }

    // ❌
    void step_2_A() {
        CIN_INIT(string, s);
        // cout << suffix_array_t_opt(s) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    suffix_array_block::step_2_A();

    return 0;
}
