下面提到的页数为中文5th版的页数



### Ex 2.3 无符号与有符号的运算

在相同算数类型的情况下：

- 若无符号数和无符号数运算结果为负数，则会把负数的结果自动转换为正数

  ```c++
  unsigned int a = 5, b = 10;
  std::cout << typeid(a-b).name() << std::endl;
  std::cout << a-b << std::endl;
  
  > unsigned int
  > 4294967291
  ```

  

- 当表达式中既有带符号类型又有无符号类型，若带符号类型变量是负数，则带符号数会先转换成无符号数再运算

  ```c++
  unsigned int a = 5;
  int b = -1;
  std::cout << typeid(a + b).name() << std::endl;
  
  > unsigned int
  ```

  

在不同算数类型的情况下：

- 位数少的算术类型会被提升为位数多的算数类型，

  ```python
  unsigned char a = 5;
  int c = -10;
  std::cout << typeid(a+c).name() << std::endl;
  std::cout << a+c << std::endl;
  
  > int
  > 5
  ```

- 无符号运算结果为负，会把结果自动转换为正

  ```python
  unsigned char a = 5, b = 10;
  unsigned int c = 10;
  std::cout << typeid(a-c).name() << std::endl;
  std::cout << a-c << std::endl;
                  
  > unsigned int
  > 4294967291
  ```




### P.55 const 引用

- 非常值引用不能指向一个常值引用

  ```c++
  const int a = 1;
  int &ref = a; 
  
  error C2440: 'initializing': cannot convert from 'const int' to 'int &'
  ```

- 只有常值引用才能绑定（引用）常值，普通引用必须绑定到一个对象



### P.56 指针和 const

- 普通（非 const 类型）指针不能指向常值

- 指向常量的指针（pointer to const）可以指向变量，但不能通过该指针改变变量

  ```c++
  int a = 1;
  const int b = 1;
  const int *pa = &a;	// OK
  int *pb = &b;		// error C2440: 'initializing': cannot convert from 'const int *' to 'int *'
  *pa = 5;			// error
  ```

- 常量指针（const pointer）本身为常量，类型可以为常量或者非常量

  ```c++
  const int *const p1 = &a;	// p1 为常量指针，类型为常量整形
  int *const p2 = &a;			// p2 为常量指针，类型为整形
  ```

- 常量指针也可以用 constexpr 表示

  ```c++
  int *const p1 = nullptr;
  constexpr int *p2 = nullptr; // 等价于
  ```

  

### P88 列表初始化

```c++
int a = 0;		// assign			- copy initialization
int b(0);		// construct		- direct initialization
int c = {0};	// list initialize 	- copy initialization
int d{0};		// list initialize 	- direct initialization

vector<string> v0{"a", "an", "the"}; 	// list initialization
vector<string> v1 = {"a", "an", "the"}; // list initialization
vector<string> v2("a", "an", "the"); 	// error

vector<int> ivec(10, -1); 		// ten int elements, each initialized to -1
vector<string> svec(10, "hi!"); // ten strings; each element is "hi!"
```

1. 若使用圆括号，则认为值是用来构造 `vector` 对象的：

   ```c++
   vector<int> v1(10);		// v1 has 10 elements with value zero
   vector<int> v2{10};      // v1 has 1 elements with value 1
   ```

2. 若使用花括号，当提供的值可以用来列表初始化时，可以表述为列表初始化该 `vector`：

   ```c++
   vector<int> v3(10, 1);   // v3 has 10 elements with value 1
   vector<int> v4{10, 1};   // v4 has 2 elements with value 10 and 1
   ```

   

3. 若使用花括号，当提供的值不能用来列表初始化时，就考虑用该值来构造 `vector` 对象：

   ```c++
   vector<string> v5{"hi"}; 	// list initialization: v5 has 1 element
   vector<string> v6("hi"); 	// error: can’t construct a vector from a string literal
   vector<string> v7{10}; 		// v7 has 10 default-initialized elements
   vector<string> v8{10, "hi"}; // v8 has 10 elements with value "hi"



### P202 函数不能返回局部对象的引用或指针

函数返回：

- 局部对象、值：OK，因为是通过临时复制对象来传值、对象。
- 局部对象的引用、指针：ERROR，因为引用、指针所指的对象在函数结束后就被释放，因此会指向不可用的内存空间。

### P213 函数默认实参

用作默认实参的名字在函数声明所在的作用域内解析，而这些名字的求值过程发生在函数调用时。



### P223 返回指向函数的指针、函数指针形参

```c++
using PF = double(*)(const double);

double scale1(const double a) {
    return a * 3 + 10;
}
double scale2(const double b) {
    return b * 5 + 2;
}

// version 1
double (*choose_bigger(double a, double pf1(const double), double pf2(const double)))(const double){
    double out1 = pf1(a);
    double out2 = pf2(a);
    if (out1 >= out2) {
        return pf1;
    } else {
        return pf2;
    }
}

// version 2
PF choose_bigger(double a, double pf1(const double), double pf2(const double)){
    double out1 = pf1(a);
    double out2 = pf2(a);
    if (out1 >= out2) {
        return pf1;
    } else {
        return pf2;
    }
}

// version 3
auto choose_bigger(double a, double pf1(const double), double pf2(const double)) -> double (*)(const double)
{
    double out1 = pf1(a);
    double out2 = pf2(a);
    if (out1 >= out2) {
        return pf1;
    } else {
        return pf2;
    }
}

int main(int argc, char *argv[]){
    double input;
    while (cin >> input) {
        cout << "Input : " << input << ", scale1 = " << 
            scale1(input) << ", scale2 = " << scale2(input) << endl;
        cout << "Choose " << choose_bigger(input, scale1, scale2)(input) << endl;
    }

    return 0;
}
```



### P261 函数的构造函数只能有一个是使用默认实参的

```c++
class C {
public:
    C(int a = 0): val(a) {}
    C(string s): str(s) {}		// ok
    C(string s = ""): str(s) {}	// error, ambiguous call to overloaded function
private:
    int val;
    std::string str;
};
```

