#include <iostream>
using namespace std;
long long data[500005], temp[500005];
long long ans=0;
int n;
void msort(int l, int r) {
	if (l == r)
		return;
	int mid = (l + r) / 2;
	int change=0;
	msort(l, mid);
	msort(mid + 1, r);
	int i = l, j = mid + 1;
	int k = l;
	while (i <= mid && j <= r) {
		if (data[i] <= data[j]) {
			temp[k++] = data[i++];
		} else {
			temp[k++] = data[j++];
			change+=mid - i + 1;
			ans += mid - i + 1;
		}
	}
	while (i <= mid)
		temp[k++] = data[i++];
	while (j <= r)
		temp[k++] = data[j++];
	for (int i = l; i <= r; i++) {
		data[i] = temp[i];
	}
	/*cout<<l<<'-'<<r<<'('<<change<<"):\n";
	for (int i = l; i <= r; i++) {
		cout<< data[i]<<' ';
	}
	cout<<'\n';*/
	return;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> data[i];
	}
	msort(1, n);
	cout<< ans;
}
