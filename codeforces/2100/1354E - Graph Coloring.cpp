/*
     ██╗ █████╗ ██╗    ███████╗██╗  ██╗██████╗ ███████╗███████╗    ██████╗  █████╗ ███╗   ███╗
     ██║██╔══██╗██║    ██╔════╝██║  ██║██╔══██╗██╔════╝██╔════╝    ██╔══██╗██╔══██╗████╗ ████║
     ██║███████║██║    ███████╗███████║██████╔╝█████╗  █████╗      ██████╔╝███████║██╔████╔██║
██   ██║██╔══██║██║    ╚════██║██╔══██║██╔══██╗██╔══╝  ██╔══╝      ██╔══██╗██╔══██║██║╚██╔╝██║
╚█████╔╝██║  ██║██║    ███████║██║  ██║██║  ██║███████╗███████╗    ██║  ██║██║  ██║██║ ╚═╝ ██║
 ╚════╝ ╚═╝  ╚═╝╚═╝    ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝

    Competitive Programming Template
    Author: Priyanshu Gupta
    Submission At : 2026-10-27 21:46:58
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
    int n, m;
    cin >> n >> m;

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<vector<int>> adj(n);
    loop(i, 0, m){
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi side(n, -1);
    vector<array<vector<int>, 2>> comps;

    loop(st, 0, n){
        if(side[st] != -1){
            continue;
        }

        array<vector<int>, 2> comp;
        queue<int> q;

        side[st] = 0;
        q.push(st);
        comp[0].push_back(st);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : adj[u]){
                if(side[v] == -1){
                    side[v]= side[u] ^ 1;
                    comp[side[v]].push_back(v);
                    q.push(v);
                }
                else if(side[v] == side[u]){ //This iss not a bipartite graph
                    no();
                    return ;
                }
            }
        }
        comps.push_back(move(comp));
    }

    int k = (int)comps.size();
    vector<vector<char>> dp(k+1, vector<char>(n2+1, false)); //dp[i][j] : can the first i component contribute exactly j vertices labeled 2 or not

    dp[0][0] = true;
    loop(i, 0, k){
        int a = comps[i][0].size();
        int b = comps[i][1].size();

        loop(j, 0, n2+1){
            if(!dp[i][j]){
                continue;
            }

            if(j + a <= n2){
                dp[i+1][j+a] = true;
            }
            if(j + b <= n2){
                dp[i+1][j+b] = true;
            }
        }
    }

    if(!dp[k][n2]){
        no();
        return ;
    }

    vector<int> choosen(k); //Reconstuct which side of each component gets label 2
    int rem = n2;

    loopb(i, k-1, 0){
        int a = comps[i][0].size();
        int b = comps[i][1].size();

        if(rem >= a && dp[i][rem - a]){
            choosen[i] = 0;
            rem -= a;
        }
        else{
            choosen[i] = 1;
            rem -= b;
        }
    }
    
    string ans(n, '?'); //Construct the answer
    loop(i, 0, k){
        int twoSide = choosen[i];
        for(int v : comps[i][twoSide]){
            ans[v] = '2';
        }
    }

    int ones = 0; //Assign exactly n1 vertices lable 1 and all other non - 2 vertices receive label 3
    loop(i, 0, n){
        if(ans[i] == '2'){
            continue;
        }

        if(ones < n1){
            ans[i] = '1';
            ones++;
        }
        else{
            ans[i] = '3';
        }
    }

    yes();
    cout << ans << endl;
}

int main() {
    fastIO();
    solve();
    return 0;
}