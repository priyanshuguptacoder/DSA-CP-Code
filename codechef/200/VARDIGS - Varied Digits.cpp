/*
    Competitive Programming Template
    Author: Priyanshu Gupta
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <iomanip>
#include <climits>
#include <bitset>
#include <array>
#include <functional>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using mii = map<int,int>;
using umii = unordered_map<int,int>;
using si = set<int>;
using usi = unordered_set<int>;
using mll = map<long long,long long>;
using umll = unordered_map<long long,long long>;
using setl = set<long long>;
using usll = unordered_set<long long>;

const int MOD = 1e9 + 7;
const ll INF = 1000000000000000000LL;

#define pb push_back
#define ff first
#define ss second
#define endl '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define sz(x) (int)(x).size()

#define loop(i,a,b) for(int i=a; i<b; i++)
#define loopb(i,a,b) for(int i=a; i>=b; i--)

#define vin(v) for(auto &x : v) cin >> x
#define vout(v) {for(auto &x : v) cout << x << ' '; cout << endl;}

void yes() {
    cout << "YES\n";
}

void no() {
    cout << "NO\n";
}

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x << " = " << x << endl

template<typename T>
void debugVec(vector<T> &v) {
    for(auto &x : v) cerr << x << ' ';
    cerr << '\n';
}

#else

#define debug(x)

template<typename T>
void debugVec(vector<T> &v) {}

#endif

// GCD
ll gcdll(ll a, ll b) {
    if(b == 0){
        return a;
    }
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// LCM
ll lcmll(ll a, ll b) {
    return (a / gcdll(a, b)) * b;
}

// Ceiling Division
ll ceilDiv(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

// Prime Check
bool isPrime(ll n) {
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i=5; i*i<=n; i+=6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Binary Exponentiation
ll power(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) {
            if(a != 0 && ans > INF / a) return INF;
            ans *= a;
        }
        if(a != 0 && a > INF / a) a = INF;
        else a *= a;
        b >>= 1;
    }
    return ans;
}

// Modular Exponentiation
ll modPower(ll a, ll b, ll mod = MOD) {
    ll ans = 1;
    a %= mod;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

// Even Check
bool isEven(ll n) {
    return (n & 1) == 0;
}

// Odd Check
bool isOdd(ll n) {
    return (n & 1);
}

// Check ith Bit
bool checkBit(ll n, int i) {
    return (n & (1LL << i));
}

// Set ith Bit
ll setBit(ll n, int i) {
    return (n | (1LL << i));
}

// Clear ith Bit
ll clearBit(ll n, int i) {
    return (n & ~(1LL << i));
}

// Toggle ith Bit
ll toggleBit(ll n, int i) {
    return (n ^ (1LL << i));
}

// Count Set Bits
int countBits(ll n) {
    return __builtin_popcountll(n);
}

// Ascending Sort
template<typename T>
void sortAsc(vector<T> &v) {
    sort(all(v));
}

// Descending Sort
template<typename T>
void sortDesc(vector<T> &v) {
    sort(rall(v));
}

// Vector Sum
template<typename T>
ll vecSum(vector<T> &v) {
    return accumulate(all(v), 0LL);
}

// Maximum Element
template<typename T>
T vecMax(vector<T> &v) {
    return *max_element(all(v));
}

// Minimum Element
template<typename T>
T vecMin(vector<T> &v) {
    return *min_element(all(v));
}

// Count Element
template<typename T>
int countElement(vector<T> &v, T x) {
    return count(all(v), x);
}

// Lower Bound
template<typename T>
int lb(vector<T> &v, T x) {
    return lower_bound(all(v), x) - v.begin();
}

// Upper Bound
template<typename T>
int ub(vector<T> &v, T x) {
    return upper_bound(all(v), x) - v.begin();
}

// Prefix Sum
template<typename T>
vector<ll> prefixSum(vector<T> &v) {
    int n = sz(v);
    vector<ll> pref(n + 1);
    loop(i,0,n) pref[i + 1] = pref[i] + v[i];
    return pref;
}

// Suffix Sum
template<typename T>
vector<ll> suffixSum(vector<T> &v) {
    int n = sz(v);
    vector<ll> suff(n + 1);
    loopb(i,n-1,0) suff[i] = suff[i + 1] + v[i];
    return suff;
}

// Frequency Map
template<typename T>
map<T,int> frequencyMap(vector<T> &v) {
    map<T,int> freq;
    for(T x : v) freq[x]++;
    return freq;
}

// Unique Set
template<typename T>
set<T> uniqueSet(vector<T> &v) {
    set<T> s;
    for(T x : v) s.insert(x);
    return s;
}

// All Elements Same
template<typename T>
bool allSame(vector<T> &v) {
    if(v.empty()) return true;
    return count(all(v), v[0]) == sz(v);
}

// Sort Pair Second Value
bool comp(pair<int,int> &a, pair<int,int> &b) {
    return a.ss < b.ss;
}

// Reverse String
void reverseStr(string &s) {
    reverse(all(s));
}

// Decimal To Binary
string binary(ll n) {
    if(n == 0) return "0";
    string s = bitset<64>(n).to_string();
    return s.substr(s.find('1'));
}

// String To Integer
int toInt(string &s) {
    return stoi(s);
}

// Integer To String
string toString(int n) {
    return to_string(n);
}

// 4 Direction
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

// 8 Direction
int dx8[] = {-1,-1,-1,0,0,1,1,1};
int dy8[] = {-1,0,1,-1,1,-1,0,1};

// Binary Search
template<typename T>
int binarySearch(vector<T> &a, T target) {
    int l = 0, r = sz(a) - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(a[mid] == target) return mid;
        else if(a[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// Sliding Window
template<typename T>
T slidingWindow(vector<T> &a, int k) {
    int n = sz(a);
    if(k > n) return 0;
    T sum = 0;
    loop(i,0,k) sum += a[i];
    T mx = sum;
    loop(i,k,n) {
        sum += a[i];
        sum -= a[i-k];
        mx = max(mx, sum);
    }
    return mx;
}

// Two Pointer
template<typename T>
int twoPointer(vector<T> &a) {
    int n = sz(a);
    unordered_set<T> s;
    int l = 0, ans = 0;
    loop(r,0,n) {
        while(s.count(a[r])) {
            s.erase(a[l]);
            l++;
        }
        s.insert(a[r]);
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// Kadane Algorithm
template<typename T>
ll kadane(vector<T> &a) {
    if(a.empty()) return 0;
    ll curr = a[0], mx = a[0];
    loop(i,1,sz(a)) {
        curr = max((ll)a[i], curr + a[i]);
        mx = max(mx, curr);
    }
    return mx;
}

void solve() {
    int n;
    cin >> n;
    
    int first = n % 10;
    n /= 10;
    if(first == n){
        no();
    }
    else{
        yes();
    }
}

int main() {
    fastIO();

    solve();

    return 0;
}