# Chapter 9: Sequential Containers



## Exercises

### Exercises Section x.y.z

9.1

| 支持（快速地）     | vector   | deque    | list     | forward_list                                       | array        | string             |
| ------------------ | -------- | -------- | -------- | -------------------------------------------------- | ------------ | ------------------ |
| 别名               | 可变数组 | 双端队列 | 双向链表 | 单向链表                                           | 固定大小数组 | 用于字符的可变数组 |
| 大小可变           | ✔        | ✔        | ✔        | ✔                                                  | ✖            | ✔                  |
| 随机访问           | ✔        | ✔        | ✖        | ✖                                                  | ✔            | ✔                  |
| 访问顺序           | 随机     | 随机     | 双向     | 单向                                               | 随机         | 随机               |
| 头部抽入、删除     | ✖        | ✔        | ✔        | ✔                                                  | 非法         | ✖                  |
| 尾部插入、删除     | ✔        | ✔        | ✔        | ✔                                                  | 非法         | ✔                  |
| 任何位置插入、删除 | ✖        | ✖        | ✔        | ✔                                                  | 非法         | ✖                  |
| 空间额外开销       | 小       | 小       | 有       | 有                                                 | 小           | 小                 |
| 备注               |          |          |          | 不支持 `.size()`<br />迭代器不支持递减 `--` 运算符 |              |                    |

- (a) list 因为要按字母顺序派别，故每次插入都可能插入在中间插入
- (b) deque 需要头删除，尾增加，适合链表
- (c) vector 只需要在尾部插入，结构方便排序

9.2 

```c++
std::list<std::deque<int>> a;
```

9.3 9.4 9.5 9.6 pass

9.7

```c++
vector<int>::size_type index
```

9.8

```c++
list<string>::const_iterator // 读
list<string>::iterator // 写
```

9.9 pass

9.10

- it1 `vector<int>::iterator`
- it2 `vector<int>::const_iterator`
- it3 `vector<int>::const_iterator`
- it4 `vector<int>::const_iterator`

9.11

```c++
vector<int> vec1;			// 0
vector<int> vec2(10);		// 10个0
vector<int> vec3(10, 1);	// 10个1
vector<int> vec4{0, 1, 2, 3, 4, 5 }; // 0, 1, 2, 3, 4, 5,
vector<int> vec5(vec4);		// 拷贝 vec4 的元素
vector<int> vec6(vec4.begin(), vec4.end()); // 拷贝 vec4 的元素
```

9.12

- 接受一个容器创建其拷贝的构造函数，必须容器类型和元素类型都相同。
- 接受两个迭代器创建拷贝的构造函数，只需要元素的类型能够相互转换，容器类型和元素类型可以不同。

9.13

```c++
list<int> ilst(5, 0);	// 5 个 0
vector<int> ivc(5, 1);	// 5 个 1

vector<double> dvc(ilst.begin(), ilst.end());
vector<double> dvc2(ivc.begin(), ivc.end());
```

9.14

```c++
list<char *> cl{"Hello", "World"}; 
vector<string> sv;
sv.assign(cl.cbegin(), cl.cend());
```

9.15 9.16 9.17 pass

9.18 9.19 see code

9.20 9.21 9.22 pass

9.23 9.24 pass

9.25 9.26 pass

9.27 9.28 pass

9.29 9.30 pass

9.31

```c++
/* list */
...
if (*iter % 2) {
    iter = lst.insert(iter, *iter);
    ++iter; ++iter;
} else
    iter = lst.erase(iter);
...

/* forward_list */
auto prev = f_lst.before_begin();
...
if (*iter % 2) {
    iter = f_lst.insert_after(iter, *iter);
    prev = iter;
    ++iter;
} else {
    iter = f_lst.erase_after(prev);
}
...
```



9.32 非法，因为参数的求值顺序是未指定的。

9.33 `begin` 会失效

9.34 将遇到的第一个奇数循环复制到其后面，直到溢出。
