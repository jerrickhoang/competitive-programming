Use bitset<n> b; for 1D boolean array. # b.test(i) tests if the ith bit is set, b[i] gets the ith bit. b.set(i) sets the ith bit. Example UVA 10038.

Use bool next_permutation(a.begin(), a,end()) to get the next permutation of a string or iterator.

To find median, either sort sort(v.begin(), v.end()) SORT(v) and access l = (n-1)/2, r=n/2 or do use nth_element(v.begin(), v.begin() + n/2, v.end()) v[n/2]

uper_bound(v.begin(), v.end(), m) find the last index of m (not inclusive), and lower_bound(v.begin(), v.end(), m) find the first index of m. Elements need to be sorted. UVA 10057

accumulate(v.begin(), v.end(), static_cast<string>("")) to concatenate all strings. sort(v.begin(), v.end(), cmp) cmp returns boolean to sort using custom comparison function UVA 10905

Use std::priority_queue in <queue> to get max. Use q.push(a) to push element in the queue, q.top() to peek at the element, void q.pop() to remove an element from the queue. Use priority_queue<int, VI, greater<int> > q for increasing queue. UVA 10954

Use std::stack<int> s , s.push(), s.top(), s.pop() similar to priority_queue described above. UVA 514

Use map<int, int> m, m.find()!=m.end() or EXIST(m, k) to check if an element is in the map. UVA 11572. Note that map<int, int> is comparable be default, so you can have map <map<int, int> > or set< map<int, int> > UVA 11286

Use multiset to maintain sorted list of items. multiset<int> m be default is increasing sequence. m.insert(v) to insert, m.erase() to erase. UVA 11136

Use getline(cin, line); stringstreem ss(line), ss >> a >> b >> c; to read lines when using cin is hard. When mixing cin and getline, remember to flush new line character after cin read. UVA 793

Union-find (disjoint sets) idea is to keep 2 arrays, p and h where p[i] points to the parent of i, and h[i] points to the "rank" of i (height of the tree from i to parent). When merging 2 sets, we always merge the smaller tree (lower h) into the bigger tree (higher h). We also do pruning where whenever we find(i) = j, we will point i directly to j.
