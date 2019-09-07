## C++/STL

1. vector
<int, int>를 쓰기 위해서는, pair을 사용해야 한다.
이 때, utility를 include 해야 함

```#include <utility>```
```
pair<int, int> p;
pair<int, int> p=make_pair(a, b);

vector<pair<int, int>> pv;
pv.push_back(make_pair(2, 4));
```
2. queue, stack

- queue
FIFO
용도: BFS, FIFO 구조를 가지는 문제

```#include <queue>```
```
push, pop, front, back, size, empty
```
- stack
LIFO
용도: DFS, LIFO 구조를 가지는 문제

```#include <stack>```
```
size, empty, top, push, pop
```
3. map, set

- map
key-value
용도: 검색 빠르게
요소 접근 시, 반복자(iterator)이용 또는 인덱스(key)이용

```#include <map>```
```
m.insert(make_pair(k, v))
m.find(k)
```
```
map<char, int>::iterator it;
map<char, int> m;
m['b'] = 2;
m.insert(make_pair('A', 1);
m['c'] = 3;
m.erase('A');

// m 전체를 순회하면서 key, value 출력
for(it=m.begin();it!=m.end();it++)
	cout << it->first << ' ' << it->second << '\n';

if(m.find('b') != m.end())
	cout << "존재\n";
else
	cout << "존재X\n";
```

- set
key만 있는 map, key만 있기 때문에, 중복을 허용치 않음
용도: 빠른 검색

4. string
==, !=사용 가능

```#include <string>```
```
str1+=str2;
str1.insert(n, str2);
str.substr(position,, length)
```

5. sort

```#include <algorithm>```
```
sort(s.begin(), s.end());
reverse(s.begin(), s.end());
```