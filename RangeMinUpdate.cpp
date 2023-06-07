/*--------------------------------
* Author -> Puspendra yadav      *
* Expert before 5th sem          *
---------------------------------*/

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

/*-----------------------------------------------------Pbds-------------------------------------------------------------------------*/

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define idx(x)        find_by_order(x)
#define less_then(x)  order_of_key(x)

template<class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;


/*-----------------------------------------------------Defines----------------------------------------------------------------------------*/

#define int long long int
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define mod 1000000007
const int inf = (int) (1e18 + 1);

/*---------------------------------------------------Random shuffle-----------------------------------------------------------------------*/


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//shuffle(all(a) , rng);


/*----------------------------------------------------Debugging-----------------------------------------------------------------------------*/

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


/*--------------------------------------------------Struggle starts----------------------------------------------------------------------*/


// class segTree {
// 	vector<int> sgt , lazy;
// 	int n;
// public:
// 	segTree(int x) {
// 		sgt.resize(4 * x + 1);
// 		lazy.resize(4 * x + 1 , 0);
// 		x = n;
// 	}

// 	void build(int ind , int low , int high , vector<int>& arr) {
// 		if (low == high) {
// 			sgt[ind] = arr[low];
// 			return;
// 		}
// 		int mid = (low + high) >> 1;
// 		build(2 * ind + 1 , low , mid , arr);
// 		build(2 * ind + 2 , mid + 1, high ,  arr);

// 		sgt[ind] = sgt[2 * ind + 1] + sgt[2 * ind + 2];
// 	}

// 	void Update(int ind , int low , int high , int l , int r , int val) {
// 		// if the current Node contain some values to update
// 		// we will update the current Node with the value and pass the
// 		// lazy update to child if any

// 		if (lazy[ind] != 0) {
// 			sgt[ind] += (high - low + 1) * lazy[ind];

// 			if (low != high) {
// 				lazy[2 * ind + 1] = lazy[ind];
// 				lazy[2 * ind + 2] = lazy[ind];
// 			}
// 			lazy[ind] = 0;
// 		}

// 		// case for no overlap

// 		if (low > r or l > high) {
// 			return;
// 		}

// 		// case for complete overlap
// 		if (low >= l and high <= r) {
// 			sgt[ind] += (high - low + 1) * val;

// 			if (low != high) {
// 				lazy[2 * ind + 1] += val;
// 				lazy[2 * ind + 2] += val;
// 			}
// 			return;
// 		}

// 		// case for partial overlap

// 		int mid = (low + high) >> 1;

// 		Update(2 * ind + 1 , low , mid , l , r , val);
// 		Update(2 * ind + 2 , mid + 1 , high , l , r , val);

// 		sgt[ind] = sgt[2 * ind + 1] + sgt[2 * ind + 2];
// 	}


// 	int query(int ind , int low , int high , int l , int r) {

// 		// if any update is remaining do it

// 		if (lazy[ind] != 0) {
// 			sgt[ind] += (high - low + 1) * lazy[ind];

// 			if (low != high) {
// 				lazy[2 * ind + 1] = lazy[ind];
// 				lazy[2 * ind + 2] = lazy[ind];
// 			}
// 			lazy[ind] = 0;
// 		}

// 		// caes for no overlap

// 		if (r < low or l > high) {
// 			return 0;
// 		}

// 		if (low >= l and high <= r) {
// 			return sgt[ind];
// 		}

// 		int mid = (low + high) >> 1;

// 		int left = query(2 * ind + 1 , low , mid , l , r);
// 		int right = query(2 * ind + 2 , mid + 1 , high , l , r);

// 		return (left + right);
// 	}


// };


class segTree {
	vector<int> sgt , lazy;
	int n;
public:
	segTree(int x) {
		sgt.resize(4 * x + 1);
		lazy.resize(4 * x + 1 , 0);
		x = n;
	}

	void build(int ind , int low , int high , vector<int>& arr) {
		if (low == high) {
			sgt[ind] = arr[low];
			return;
		}
		int mid = (low + high) >> 1;
		build(2 * ind + 1 , low , mid , arr);
		build(2 * ind + 2 , mid + 1, high ,  arr);

		sgt[ind] = min(sgt[2 * ind + 1] , sgt[2 * ind + 2]);
	}

	void Update(int ind , int low , int high , int l , int r , int val) {
		// if the current Node contain some values to update
		// we will update the current Node with the value and pass the
		// lazy update to child if any

		if (lazy[ind] != 0) {
			sgt[ind] += lazy[ind];

			if (low != high) {
				lazy[2 * ind + 1] = lazy[ind];
				lazy[2 * ind + 2] = lazy[ind];
			}
			lazy[ind] = 0;
		}

		// case for no overlap

		if (low > r or l > high) {
			return;
		}

		// case for complete overlap
		if (low >= l and high <= r) {
			sgt[ind] += val;

			if (low != high) {
				lazy[2 * ind + 1] += val;
				lazy[2 * ind + 2] += val;
			}
			return;
		}

		// case for partial overlap

		int mid = (low + high) >> 1;

		Update(2 * ind + 1 , low , mid , l , r , val);
		Update(2 * ind + 2 , mid + 1 , high , l , r , val);

		sgt[ind] = min(sgt[2 * ind + 1] , sgt[2 * ind + 2]);
	}


	int query(int ind , int low , int high , int l , int r) {

		// if any update is remaining do it

		if (lazy[ind] != 0) {
			sgt[ind] += lazy[ind];

			if (low != high) {
				lazy[2 * ind + 1] = lazy[ind];
				lazy[2 * ind + 2] = lazy[ind];
			}
			lazy[ind] = 0;
		}

		// caes for no overlap

		if (r < low or l > high) {
			return INT_MAX;
		}

		if (low >= l and high <= r) {
			return sgt[ind];
		}

		int mid = (low + high) >> 1;

		int left = query(2 * ind + 1 , low , mid , l , r);
		int right = query(2 * ind + 2 , mid + 1 , high , l , r);

		return min(left , right);
	}


};


void solve() {
	int n ;
	cin >> n;

	vector<int> a(n);
	for (auto &i : a) cin >> i;

	segTree ob(n);
	ob.build(0 , 0 , n - 1 , a);


	ob.Update(0 , 0 , n - 1 , 0 , 2 , 3);
	ob.Update(0 , 0 , n - 1 , 3 , 4 , 1);

}

/*
  	dp / bs / greedy / pq / graph /observation / try making example
*/

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
