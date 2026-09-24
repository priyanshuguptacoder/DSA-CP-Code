/*
    Competitive Programming Template
    Author: Priyanshu Gupta
    Submission At : 2026-09-25 03:47:12
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
ll power(ll a,ll b){
    ll ans=1;
    while(b){if(b&1){if(a&&ans>INF/a)return INF;ans*=a;}if(a&&a>INF/a)a=INF;else a*=a;b>>=1;}
    return ans;
}

void solve() {
    double a, b, c;
    cin >> a >> b >> c;

    if(a == 0 && b == 0 && c == 0){ //This case will become infinte root
        cout << -1 << endl;
        return ;
    }
    
    if(a == 0){ //Linear Equation
        if(b == 0){
            cout << 0 << endl;
            return ;
        }
        else{
            double x = -1 * c / b;
            cout << 1 << endl;
            cout << fixed << setprecision(10) << x << endl;
            return ;
        }
    }

    double d = b * b - 4 * a * c; //Discriminant
    if(d < 0){
        cout << 0 << endl;
    }
    else if(d == 0){ //Only one root
        double x = -1 * b / (2 * a);
        cout << 1 << endl;
        cout << fixed << setprecision(10) << x << endl;
    }
    else{ //This is where we two root
        double x = (-1 * b - sqrt(d)) / (2 * a);
        double y = (-1 * b + sqrt(d)) / (2 * a);
        if(x > y){ //Ascending order
            swap(x, y);
        }

        cout << 2 << endl;
        cout << fixed << setprecision(10) << x << endl;
        cout << fixed << setprecision(10) << y << endl;
    }
}

int main() {
    fastIO();
    solve();
    return 0;
}