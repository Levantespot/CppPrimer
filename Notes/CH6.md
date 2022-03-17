# Chapter 6: Functions



##  Exercises

### Exercises Section 6.1

6.1 pass

6.2 pass

6.3

6.4 

Same as 6.3.

6.5

Use `double` to hold different types of input.

### Exercises Section 6.1.1

6.6 pass

6.7 pass

### Exercises Section 6.1.2

6.8

```powershell
> cl /EHsc 6.8.cpp # no need to add Chapter6.h in CLI
```

6.9

```powershell
> cl /EHsc fact.cpp factMain.cpp /Fe"factMain.exe" # It will generate fact.exe without /Fe<filename>, i.e., using the name of the first source file.
```

6.10

```
1 2
2 1
```

6.11 6.12 6.13 6.14 6.15

pass

6.16

```c++
# 未加 const 的版本不能传入 const string 类型、字面量类型的实参

bool is_empty(const string& s) { return s.empty() }
```

6.17

```
判断是否有大写字母的函数，形参为 const string& line，
改为小写的函数，形参为 string& line。
```

6.18

```c++
(a) bool compare(const matrix &, const matrix &);
(b) vector<int>::iterator change_val(const int, vector<int>::iterator &);
```

6.19

```
(a) ERROR, calc 形参列表只有一个参数
(b) OK
(c) OK
(d) OK
```

6.20

pass

6.21

```c++
const int *
```

6.22

pass

6.23

pass

6.24

```
函数声明等价于 void print (const int *ia)（见P193）
编译器只会检查传入的参数是否是 const int* 类型的，不会检查是否是 10 个元素大小的数组。因此，当传入的有效元素个数小于 10，就会出错（访问非法地址）。
```

6.27, 6.28, 6.29 pass

6.30

```
error C2561: 'str_subrange': function must return a value
```

6.31

```
当函数返回的引用指向函数中的局部对象，则该引用无效；
第二个问题没看懂
```

6.32

OK

6.33

see code

6.34

```
如果输入为正数，则相同；如果输入为负数，则会无限递归下去。
```

6.35

pass

6.36, 6.37, 6.38 pass

6.39 pass

6.40

pass

6.41

pass

6.42

pass

6.43

pass

6.44

6.45

pass

6.46

```
不能，返回的值要根据运行时传入的实参决定。
```

6.47

```
> cl /D DEBUG_SIZE /EHsc 6.47.cpp
> .\6.47.cpp
vector size = 7
0vector size = 6
1vector size = 5
2vector size = 4
3vector size = 3
4vector size = 2
5vector size = 1
6vector size = 0
```

6.48

```
应该使用 assert(s == sought); 
```

6.49

pass

6.50

```
(a) f(2.56, 42) 	二义性
(b) f(42) 			f(int)
(c) f(42, 0) 		f(int, int)
(d) f(2.56, 3.14)	f(double, double=3.14)
```

6.51

pass

