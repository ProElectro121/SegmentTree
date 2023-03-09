/*********************************
* Author -> Puspendra yadav      *
**********************************/

#include<bits/stdc++.h>
using namespace std;


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define idx(x)        find_by_order(x)
#define less_then(x)  order_of_key(x)

template<class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;



#define int long long int
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define mod 1000000007

/************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(float t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


/*************************************************************/

class segtree {
public:
	vector<int> sgt;
	segtree(int n) {
		sgt.resize(4 * n + 1);
	}

	void build(int index , int low , int high , vector<int>& arr) {
		if (low == high) {
			sgt[index] = arr[low];
			return;
		}
		int mid = (low + high) >> 1;

		build(2 * index + 1 , low , mid , arr);
		build(2 * index + 2 , mid + 1, high , arr);

		sgt[index] = min(sgt[2 * index + 1] , sgt[2 * index + 2]);
	}

	void pointUpdate(int index , int low , int high , int ind , int val) {
		if (low == high and low == ind) {
			sgt[index] = val;
			return;
		}

		int mid = (low + high) >> 1;

		if (ind <= mid) {
			pointUpdate(2 * index + 1 , low , mid , ind , val);
		}
		else {
			pointUpdate(2 * index + 2 , mid + 1, high , ind , val);
		}

		sgt[index] = min(sgt[2 * index + 1] , sgt[2 * index + 2]);
	}

	int query(int index , int low , int high , int l ,  int r) {
		if (low >= l and high <=  r) {
			return sgt[index];
		}
		if (l > high or r < low) {
			return INT_MAX;
		}

		int mid = (low + high) >> 1;

		int left = query(2 * index + 1 , low , mid , l , r);
		int right = query(2 * index + 2 , mid + 1 , high , l , r);

		return min(left , right);
	}
};


void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &i : a) cin >> i;

	segtree seg1(n);
	seg1.build(0 , 0 , n - 1, a);

	debug(seg1.sgt)

	int q;
	cin >> q;

	while (q--) {
		int l , r;
		cin >> l >> r;
		l--;
		r--;

		cout << seg1.query(0 , 0 , n - 1, l , r) << endl;
	}

	int x;
	cin >> x;

	while (x--) {
		int ind , val;
		cin >> ind >> val;
		ind--;
		seg1.pointUpdate(0 , 0 , n - 1, ind , val);
		a[ind] = val;
	}

	cin >> q;

	while (q--) {
		int l , r;
		cin >> l >> r;
		l--;
		r--;

		cout << seg1.query(0 , 0 , n - 1, l , r) << endl;
	}

}


main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;

	/*
	    Sorting using cmp --> return boolen in which order
	    order you want to Sort

	    using pbds

	    using only less --> normal set
	    using less_equal --> lower_bound gives result like upper
	                         bound in multiset and vice versa

	    eg ->  for in desecnding order --> return (a > b);
	*/
}
