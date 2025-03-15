#include <bits/stdc++.h>
using namespace std;

int a[100005], segment[4 * 100005], lazy[4 * 100005];

void build(int index, int low, int high) {
  if (low == high) {
    segment[index] = a[low];
    return;
  }

  int mid = low + (high - low) / 2;
  build(2 * index + 1, low, mid);
  build(2 * index + 2, mid + 1, high);

  // if finding minimum
  // segment[index] = min(segment[2*index+1], segment[2*index+2]);

  // if finding sum
  // segment[index] = segment[2*index+1] + segment[2*index+2];

  segment[index] = max(segment[2 * index + 1], segment[2 * index + 2]);
}

int query(int index, int low, int high, int l, int r) {
  // if the node completely lies inside the range
  if (low >= l && high <= r) {
    return segment[index];
  }
  if (high < l || low > r)
    return INT_MIN; // since we are finding the max
  int mid = low + (high - low) / 2;
  int left = query(2 * index + 1, low, mid, l, r);
  int right = query(2 * index + 2, mid + 1, high, l, r);
  return max(left, right);
}

// single update
// call from the main as update(0, 0, n-1, node, val);
void pointUpdate(int index, int low, int high, int node, int val) {
  if (low == high) {
    segment[low] += val;
  } else {
    int mid = (low + high) >> 1;
    if (node <= mid && node >= low)
      pointUpdate(2 * index + 1, low, mid, node, val);
    else
      pointUpdate(2 * index + 2, mid + 1, high, node, val);

    segment[index] = segment[2 * index + 1] + segment[2 * index + 2];
  }
}

// l, r -> range to increase value with val
void rangeUpdate(int index, int low, int high, int l, int r, int val) {
  if (lazy[index] != 0) {
    segment[index] += (high - low + 1) * lazy[index];

    // checking if it is a leaf node
    if (low != high) {
      // if not leaf nodes then we are postponing the updates
      lazy[2 * index + 1] += lazy[index];
      lazy[2 * index + 2] += lazy[index];
    }
    lazy[index] = 0;
  }

  // check if the segment tree node lies completely out of the given range
  // then we simply return
  if (r < low || l > high || low > high)
    return;

  // segment lies nodes lies within the range
  if (low >= l && high <= r) {
    segment[index] += (high - low + 1) * val;
    if (low != high) {
      // if not leaf nodes then propagate the updates down
      lazy[2 * index + 1] += lazy[index];
      lazy[2 * index + 2] += lazy[index];
    }
    return;
  }

  // if any of the above conditions are not met it means
  // that there is a partial overlap
  int mid = low + (high - low) >> 1;
  rangeUpdate(2 * index + 1, low, mid, l, r, val);
  rangeUpdate(2 * index + 2, mid + 1, high, l, r, val);
  segment[index] = segment[2 * index + 1] + segment[2 * index + 2];
}

int queryLazySum(int index, int low, int high, int l, int r, int val) {
  if (lazy[index] != 0) {
    segment[index] += (high - low + 1) * lazy[index];
    if (low != high) {
      lazy[2 * index + 1] += lazy[index];
      lazy[2 * index + 2] += lazy[index];
    }
    lazy[index] = 0;
  }

  if (r < low || l > high || low > high)
    return 0;

  if (low >= l && high <= r) {
    return segment[index];
  }

  int mid = low + (high - low) / 2;
  return queryLazySum(2 * index + 1, low, mid, l, r, val) +
         queryLazySum(2 * index + 2, mid + 1, high, l, r, val);
}

int main() {

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int q;
  cin >> q;

  build(0, 0, n - 1);
  while (q) {
    int l, r;
    cin >> l >> r;
    q--;
  }
  return 0;
}