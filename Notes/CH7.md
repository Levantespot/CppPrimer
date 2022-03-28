# Chapter 7: Classes

## x.1 Heading 2

### x.1.1 Heading 3

#### Heading 4



---

##  Exercises

### Exercises Section x.y.z

7.1, 7.2, 7.3 pass

7.4, 7.5 see code

7.6, 7.7, 7.8 pass

7.9

```powershell
> Lee China
Name: Lee, adress: China
```

7.10

```
条件部分的作用是保证输入两次正确的数据
```

7.11, 7.12, 7.13, 7.14 pass

7.15  see code

7.16, 7.17, 7.18 pass

7.19 see code

7.20, 7.21 pass

7.22 see code

7.23, 7.24 see code

7.25

```
因为用的是 string，没有动态申请内存，故能安全地依赖于拷贝和赋值操作的默认版本。
```

7.26 pass

7.27 see code

7.28

```
如果返回类型没有引用，则会报错，不能进行连续的操作，如 myScreen.move(4,0).set('#')
```

7.29, 7.30 pass

7.31 使用前向声明即可。

7.32 see code 注意作用域，注意需要使用前向声明类。

7.33 `pos`是在`Screen`类的作用域外面，不能直接使用，因此需要改为`Screen::pos`。

7.34 会报错，因为在声明前就使用标识符会报「未定义的标识符」的错误。

7.35 首先，重复定义标识符大部分编译器都会报错。

```c++
typedef string Type;
Type initVal();	// Type 使用全局标识符
class Exercise {
public:
    typedef double Type;	// 很有可能会报错，应该删除
    Type setVal(Type);	// 两个 Type 都是类的成员
    Type initVal();		// Type 是类的成员
private:
	int val;
};
Type Exercise::setVal(Type parm) {	// 第一个 Type 是全局标识符（因此会报错，应该改为 Exercise::Type），第二个 Type 是类的成员
    val = parm + initVal();	// initVal 是类的成员
    return val;
}
```

7.36

```c++
struct X {
    X (int i, int j): base(i), rem(i % j) { }
        int rem, base;
};
```

7.37

```c++
Sales_data first_item(cin);  // Sales_data(std::istream &is);
int main() {
  Sales_data next;  // Sales_data(std::string s = "");
  Sales_data last("9-999-99999-9");  // Sales_data(std::string s = "");
}
```

7.38

```c++
Sales_data(std::istream &is=std::cin);
```

7.39 不行，两个构造函数都只有接受一个形参的时候，且都有默认实参，那么编译器将不能区分应该用哪一个。

7.40 pass

7.41. 7.42 pass

7.43 see code

7.44 不合法。`vector(10)`会创建 10 个对象，并且调用的是默认构造函数进行初始化，因为`NoDefault`类没有默认构造函数，故不合法。

7.46

1. 可以不提供构造函数，编译器会自己定义一个默认构造函数，也叫合成的默认构造函数。
2. 为每个参数都提供了默认值的构造函数也是默认构造函数。
3. 任何值都需要初始化。
4. 只有当一个类没有定义**任何构造函数**的时候，编译器才会生成一个默认构造函数。