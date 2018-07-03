Use bitset<n> b; for 1D boolean array. # b.test(i) tests if the ith bit is set, b[i] gets the ith bit. b.set(i) sets the ith bit. Example UVA 10038.

Use bool next_permutation(a.begin(), a,end()) to get the next permutation of a string or iterator.

To find median, either sort sort(v.begin(), v.end()) SORT(v) and access l = (n-1)/2, r=n/2 or do use nth_element(v.begin(), v.begin() + n/2, v.end()) v[n/2]

uper_bound(v.begin(), v.end(), m) find the last index of m (not inclusive), and lower_bound(v.begin(), v.end(), m) find the first index of m. Elements need to be sorted. UVA 10057

accumulate(v.begin(), v.end(), static_cast<string>("")) to concatenate all strings. sort(v.begin(), v.end(), cmp) cmp returns boolean to sort using custom comparison function UVA 10905
