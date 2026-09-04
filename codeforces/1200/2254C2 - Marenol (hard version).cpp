/*
    Competitive Programming Template
    Author: Priyanshu Gupta
    Submission At : 2026-09-04 19:36:49
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

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

template<typename T> void sortAsc(vector<T> &v) { sort(all(v)); }
template<typename T> void sortDesc(vector<T> &v) { sort(rall(v)); }
template<typename T> ll vecSum(vector<T> &v) { return accumulate(all(v), 0LL); }
template<typename T> T vecMax(vector<T> &v) { return *max_element(all(v)); }
template<typename T> T vecMin(vector<T> &v) { return *min_element(all(v)); }
void reverseStr(string &s) { reverse(all(s)); }
int toInt(string &s) { return stoi(s); }
string toString(int n) { return to_string(n); }

ll gcdll(ll a,ll b) {
    while(b) { a%=b; swap(a,b); }
    return a;
}
ll lcmll(ll a,ll b) { return (a/gcdll(a,b))*b; }
ll ceilDiv(ll a,ll b) { return a/b+((a^b)>0&&a%b); }
bool isPrime(ll n) {
    if(n<2) return false; if(n==2||n==3) return true;
    if(n%2==0||n%3==0) return false;
    for(ll i=5;i*i<=n;i+=6) if(n%i==0||n%(i+2)==0) return false;
    return true;
}

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a;
    cin >> b;

    vi oA, eA, oB, eB;
    int oddA = 0, evenA = 0, oddB = 0, evenB = 0;

    loop(i, 0, n){
        if(a[i] == '1'){
            if(i % 2 == 0){
                evenA++;
                eA.push_back(i);
            }
            else{
                oddA++;
                oA.push_back(i);
            }
        }
        if(b[i] == '1'){
            if(i % 2 == 0){
                evenB++;
                eB.push_back(i);
            }
            else{
                oddB++;
                oB.push_back(i);
            }
        }
    }

    if(oddA != oddB || evenA != evenB){
        cout << -1 << endl;
        return ;
    }

    ll dist = 0;
    loop(i, 0, oA.size()){
        dist += abs(oA[i] - oB[i]) / 2;
    }
    loop(i, 0, eA.size()){
        dist += abs(eA[i] - eB[i]) / 2;
    }

    cout << dist << endl;
}

int main() {
    fastIO();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}