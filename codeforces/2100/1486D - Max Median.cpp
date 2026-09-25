/*
     ██╗ █████╗ ██╗    ███████╗██╗  ██╗██████╗ ███████╗███████╗    ██████╗  █████╗ ███╗   ███╗
     ██║██╔══██╗██║    ██╔════╝██║  ██║██╔══██╗██╔════╝██╔════╝    ██╔══██╗██╔══██╗████╗ ████║
     ██║███████║██║    ███████╗███████║██████╔╝█████╗  █████╗      ██████╔╝███████║██╔████╔██║
██   ██║██╔══██║██║    ╚════██║██╔══██║██╔══██╗██╔══╝  ██╔══╝      ██╔══██╗██╔══██║██║╚██╔╝██║
╚█████╔╝██║  ██║██║    ███████║██║  ██║██║  ██║███████╗███████╗    ██║  ██║██║  ██║██║ ╚═╝ ██║
 ╚════╝ ╚═╝  ╚═╝╚═╝    ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝

    Competitive Programming Template
    Author: Priyanshu Gupta
    Submission At : 2026-09-25 22:43:14
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

bool check(int mid, vi& arr, int k, int n){
    int bal = 0;
    vi prefSum(n+1, 0);
    vi minPrefSum(n+1, 0);

    loop(i, 0, n){
        if(arr[i] >= mid){
            bal++;
        }
        else{
            bal--;
        }

        //We want median of atleast k size and its take low index when even then it means grtaer thsn mid have to more so greater mid - smaller mid > 0 this concept we use in this we can do prefSum[r] - prefSum[l] and maximize it so prefSum[l] to be minimum so take smallest prefSumix sum and so why prefSumSum and minimum prefSumix sum to be stored
        prefSum[i+1] = bal;
        minPrefSum[i+1] = min(bal, minPrefSum[i]); //Store minimum prefSumix sum
    }

    loop(i, k, n+1){
        if(prefSum[i] - minPrefSum[i-k] > 0){
            return true;
        }
    }

    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vi arr(n);
    vin(arr);

    int low = 1, high = n;
    int ans = 0;

    while(low <= high){ //Check that number becomes median when k atleast length
        int mid = (low + high) / 2;
        if(check(mid, arr, k, n)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout << ans << endl;
}

int main() {
    fastIO();
    solve();
    return 0;
}