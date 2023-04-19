## C
scanf返回值为读取个数
```c
while(scanf("%d", &x) == 1) {
        printf("%d ", x);
    }
```

文件读写
```c
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
fclose(stdin);
fclose(stdout);
```
printf输出格式
```c
```
kill进程
taskkill /f /im test_grammer.exe

## C++
iostream和cstdio最好都加上

multiset
```cpp
multimap<string,int> mp;
mp.insert(make_pair("aa",2));
mp.insert(make_pair("aa",3));
auto t = mp.equal_range("aa");
for(auto i = t.first; i!= t.second; i++) {
    cout<<(*i).first<<endl;
    cout<<(*i).second<<endl;
    }
```

pair
```cpp
#include <utility>
```

priority_queue

vs2012用greater要加#include <functional>

```cpp
priority_queue<int, vector<int>, less<int> > q;//top是最大
priority_queue<int, vector<int>, greater<int> > q;//top是最小

//top是最大
bool cmp(int a, int b) {
    return a < b;
}
//top是最小
bool cmp(int a, int b) {
    return a > b;
}
priority_queue<int, vector<int>, decltype(&cmp)> q(cmp);

//按first最小
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&cmp)> q(cmp);
```

vector二维数组n行m列
```cpp
vector<vector<int>> a = vector<vector<int>> (n, vector<int>(m,100));
```

读取一行
```cpp
string s;
getline(cin, s);
```

读取指定长度
```cpp
char s[4];
cin.getline(s,4);
cout<<s;//包括了'\0',输入1234，输出123
```