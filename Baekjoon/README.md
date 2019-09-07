## C++/STL

1. vector
<int, int>�� ���� ���ؼ���, pair�� ����ؾ� �Ѵ�.
�� ��, utility�� include �ؾ� ��

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
�뵵: BFS, FIFO ������ ������ ����

```#include <queue>```
```
push, pop, front, back, size, empty
```
- stack
LIFO
�뵵: DFS, LIFO ������ ������ ����

```#include <stack>```
```
size, empty, top, push, pop
```
3. map, set

- map
key-value
�뵵: �˻� ������
��� ���� ��, �ݺ���(iterator)�̿� �Ǵ� �ε���(key)�̿�

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

// m ��ü�� ��ȸ�ϸ鼭 key, value ���
for(it=m.begin();it!=m.end();it++)
	cout << it->first << ' ' << it->second << '\n';

if(m.find('b') != m.end())
	cout << "����\n";
else
	cout << "����X\n";
```

- set
key�� �ִ� map, key�� �ֱ� ������, �ߺ��� ���ġ ����
�뵵: ���� �˻�

4. string
==, !=��� ����

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