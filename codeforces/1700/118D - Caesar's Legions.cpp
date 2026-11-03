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
#include <cstring>

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

const int MOD = 1e8;
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
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    int dp[101][101][2][11]; //We can make four state where first is a number of completed footmen and 2 is completed number of horse and 3 is a type of previous and 4 is consective of that type
    memset(dp, 0, sizeof(dp)); //Initailize all to zeros

    dp[1][0][0][1] = 1;
    dp[0][1][1][1] = 1;

    loop(i, 0, n1+1){
        loop(j, 0, n2+1){
            loop(k, 1, k1+1){ //Last soldier is a footman
                if(dp[i][j][0][k] == 0){
                    continue;
                }

                if(i < n1 && k < k1){ //Add another footman
                    dp[i+1][j][0][k+1] = (dp[i+1][j][0][k+1] + dp[i][j][0][k]) % MOD;
                }
                if(j < n2){ //Add a horseman
                    dp[i][j+1][1][1] = (dp[i][j+1][1][1] + dp[i][j][0][k]) % MOD;
                }
            }

            loop(k, 1, k2+1){ //Last soldier is a horseman
                if(dp[i][j][1][k] == 0){
                    continue;
                }

                if(j < n2 && k < k2){ //Add another horseman
                    dp[i][j+1][1][k+1] = (dp[i][j+1][1][k+1] + dp[i][j][1][k]) % MOD;
                }
                if(i < n1){ //Add a footman
                    dp[i+1][j][0][1] = (dp[i+1][j][0][1] + dp[i][j][1][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    loop(k, 1, k1+1){
        ans = (ans + dp[n1][n2][0][k]) % MOD; //All soldier tabhi count karenge
    }

    loop(k, 1, k2+1){
        ans = (ans + dp[n1][n2][1][k]) % MOD;
    }

    cout << ans << endl;
}

int main() {
    fastIO();
    solve();
    return 0;
}