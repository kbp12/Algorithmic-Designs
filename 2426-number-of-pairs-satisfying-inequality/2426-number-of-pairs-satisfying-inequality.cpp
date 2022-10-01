typedef long long int lli;
const lli N = 1e6 + 5;
const lli OFF_SET = 5e4;
class Fenwick {
public:
	lli* arr;
	lli n;
	Fenwick(lli n) {
		arr = new lli[n]();
		this->n = n;
	}
	void add(lli idx, lli val) {
		idx += OFF_SET;
		while (idx < n) {
			arr[idx] += val;
			idx += idx & -idx;
		}
	}
	lli query(lli idx) {
		idx += OFF_SET;
		lli ret  = 0;
		while (idx > 0) {
			ret += arr[idx];
			idx -= idx & (-idx);
		}
		return ret;
	}
};
class Solution {
public:
	long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
		lli ret = 0;
		vector<lli> v2;
		lli n = nums1.size();
		Fenwick f = Fenwick(N);
		for (int i = 0; i < n; i++) {
			lli val = nums1[i] - nums2[i];
			ret += f.query(val);
			f.add(nums1[i]-nums2[i]-diff, 1);
		}
		return ret;
	}
};
