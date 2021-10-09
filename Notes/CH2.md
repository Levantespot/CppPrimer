# Chapter 2: Variables and Basic Types

**Types** determine the meaning of the data and operations in our programs.

## 2.1 Primitive Built-in Types

- arithmetic types
  - can represent: characters, integers, boolean values, and floating-point values.
- void type

### 2.1.1 Arithmetic Types

| Type        | Meaning                                  | Minimum Size          |
| ----------- | ---------------------------------------- | --------------------- |
| `bool`      | boolean                                  | NA                    |
| `char`      | character                                | 8 bits                |
| `wchar_t`   | wide character                           | 16 bits               |
| `char16_t`  | Unicode character                        | 16 bits               |
| `char32_t`  | Unicode character                        | 32 bits               |
| `short`     | short integer                            | 16 bits               |
| `int`       | integer                                  | 16 bits               |
| `long`      | long integer                             | 32 bits               |
| `long long` | long integer                             | 64 bits               |
| `float`     | single-precision floating-point          | 6 significant digits  |
| `double`    | double-precision floating-point          | 10 significant digits |
| `long`      | double extended-precision floating-point | 10 significant digits |

Note: The size of the arithmetic types varies across machine. The standard guarantees minimum sizes only.

#### Signed and Unsigned Types

1. Except for `bool` and the extended character types, the integral types may be `signed` or `unsigned`.
2. The types `int`, `short`, `long`, and `long long` are all signed. We obtain the corresponding unsigned type by adding `unsigned` to the type, such as `unsigned long`.
3. `unsigned` alone is an abbreviation for `unsigned int`.
4. `char`, `signed char`, and `unsigned char` are three distinct types. The (plain) `char` type uses one of two representations, `signed char` and `unsigned char`, depending on complier.

#### Advice: deciding which typed to use.

- Use an unsigned type when you know that the values cannot be negative.
- Use `int` for integer arithmetic. `short` is usually too small and, in practice, `long` often has the same size as `int`.
- Do not use plain `char` or `bool` in arithmetic expressions. Use them only to hold characters or truth values.
- Use `double` for floating-point computations; `float` usually does not have enough precision, and the cost of double-precision calculations versus single-precision is negligible.

### 2.1.2 Type conversions

| Target(below) | bool                                         | integer                                  | float-point                                                  |
| ------------- | -------------------------------------------- | ---------------------------------------- | ------------------------------------------------------------ |
| bool          | -                                            | False, if integer is 0; True, otherwise. | False, if float-point is 0; True, otherwise.                 |
| integer       | 1, if bool is True; 0, if bool is False.     | -                                        | Truncated, i.e., only the part before the decimal point will remain. |
| float-point   | 1.0, if bool is True; 0.0, if bool is False. | The fraction part is 0.                  | -                                                            |

Note: When assign a integer to a float-point number, precision may be lost if the integer has more bits than the floating-point object can accommodate.

| Target(below) | unsigned                                                     | signed                                                       |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| unsigned      | -                                                            | The result is the remainder of the value mod the size the target type can hold. |
| signed        | If we assign an out-of-range value to an object of signed type, the result is **undefined 未定义的**. The program might appear to work, it might crash, or it might produce garbage values. | -                                                            |

Examples:

```c++
// Assume that char is 8-bit. signed char can hold [-128, 127].
// out-of-range situation:
unsigned char c = -1; // c = -1 mod 256 = 255
signed char c = 128; // undefined. On my computer, it complied successfully, but printing €.
```

#### Expression Involving Unsigned Types

```c++
// Wrong code below: u can never be less than 0; 
// The condition will always succeed because an unsigned cannot be less than zero.
// When u = 0, --u equals the calculation: -1 mode 2^32 = 4294967295
for (unsigned u = 10; u >= 0; --u)
	std::cout << u << std::endl;
```

### 2.1.3 Literals 字面值常量

#### Integer and Floating-Point Literals

```c++
// Integer literals (e.g., 20) can be write in three ways:
20 /* decimal */ 024 /* octal */ 0x14 /* hexadecimal */
```

- Type of decimal = min(sizeof(`int`), sizeof(`long`), sizeof(`long long`))
- Type of octal or hexadecimal = min(sizeof(`int`), sizeof(`unsigned int`), sizeof(`long`), sizeof(`unsigned long`), sizeof(`long long`), sizeof(`unsigned long long`))

>Although integer literals may be stored in signed types, technically speaking, the value of a decimal literal is never a negative number. If we write what appears to be a negative decimal literal, for example, -42, the minus sign is not part of the literal. The minus sign is an operator that negates the value of its (literal) operand.

``` c++
// Floating-point literals include either a decimal point or an exponent specified using scientific notation (AeB = A * 10^B). The exponent is indicated by either E or e:
3.14159 3.14159E0 0. 0e0 .001
```

#### Character and Character String Literals

```c++
’a’ // character literal enclosed within single quotes
"Hello World!" // string literal enclosed in double quotation marks
```

- The type of a string literal is array of constant chars. 

- The compiler appends a null character (’\0’) to every string literal. 

- Two string literals that appear adjacent to one another and that are separated only by spaces, tabs, or newlines are concatenated into a single literal.  

  ```c++
  // multiline string literal
  std::cout << "a really, really long string literal "
  			 "that spans two lines" << std::endl;
  ```

#### Escape Sequences 转义序列

| Meaning         | ES   | Meaning        | ES   | Meaning      | ES   |
| --------------- | ---- | -------------- | ---- | ------------ | ---- |
| newline         | `\n` | horizontal tab | `\t` | alert(bell)  | `\a` |
| vertical tab    | `\v` | backspace      | `\b` | double quote | `\"` |
| backslash       | `\\` | question mark  | `\?` | single quote | `\'` |
| carriage return | `\r` | formfeed       | `\f` |              |      |

Generalized escape sequence (泛化的转义序列) : which is `\x` followed by one or more *hexadecimal* digits or a `\` followed by one, two, or three *octal* digits.

```c++
\115 ('M') == \x4d ('M')
```

Note that if a `\` is followed by more than three octal digits, only the first three are associated with the `\`.  In contrast, `\x` uses up all the hex digits following it;

#### Specifying the Type if a Literal

```c++
L’a’     // wide character literal, type is wchar_t
u8"hi!"  // utf-8 string literal (utf-8 encodes a Unicode character in 8 bits)
42ULL    // unsigned integer literal, type is unsigned long long
1E-3F    // single-precision floating-point literal, type is float
3.14159L // extended-precision floating-point literal, type is long double
```

| Prefix | Meaning                      | Type     |
| ------ | ---------------------------- | -------- |
| `u`    | Unicode 16 character         | char16_t |
| `U`    | Unicode 32 character         | char32_t |
| `L`    | wide character               | wchar_t  |
| `u8`   | utf-8 (string literals only) | char     |

| Integer      |              | Floating-Point |               |
| ------------ | ------------ | -------------- | ------------- |
| Suffix       | Minimum Type | Suffix         | Type          |
| `u` or `U`   | `unsigned`   | `f` or `F`     | `float`       |
| `l` or `L`   | `long`       | `l` or `L`     | `long double` |
| `ll` or `LL` | `long long`  |                |               |

#### Boolean and Pointer Literals

The words `true` and `false` are literals of type bool:

```c++
bool test = false;
```

The word `nullptr` is a pointer literal.

## 2.2 Variables

### 2.2.1 Variable Definitions 变量定义

A simple variable definition consists of a **type specifier 类型说明符**, followed by a list of one or more variable names separated by commas `,`, and ends with a semicolon `;`. Each name in the list has the type defined by the type specifier. A definition may (optionally) provide an initial value for one or more of the names it defines:

```c++
TYPE_SPECIFIER VARIABLE_NAME_1, VARIABLE_NAME_2 = INITIAL_VALUE;

int sum = 0, value, // sum, value, and units_sold have type int
	units_sold = 0; // sum and units_sold have initial value 0
Sales_item item; // item has type Sales_item (see § 1.5.1 (p. 20))
std::string book("0-201-78345-X"); // book initialized from string literal
```

#### Initializers 初始值

An object that is **initialized 初始化** gets the specified value at the moment it is created. When a definition defines two or more variables, the name of each object becomes visible immediately. Thus, it is possible to initialize a variable to the value of one defined earlier in the same definition.

```c++
// <price> is defined and initialized before it is used to initialize <discount>
double price = 109.99, discount = price * 0.16;
```

#### List Initialization 列表初始化

For example, we can use any of the following four different ways to define an `int` variable named `units_sold` and initialize it to `0`:  

```c++
int units_sold = 0;
int units_sold = {0};
int units_sold{0};
int units_sold(0);
```

The compiler will reject us list initializing variables of built-in type if the initializer might lead to the **loss** of information when used with variables of built-in type: 

```c++
long double ld = 3.1415926536;
int a{ld}, b = {ld}; // error: narrowing conversion required
int c(ld), d = ld; // ok: but value will be truncated
```

#### Default Initialization 默认初始化

When we define a variable without an initializer, the variable is default initialized. What that default value is depends on the type of the variable and may also depend on where the variable is defined.

The value of an object of built-in type that is not explicitly initialized depends on where it is defined: Variables defined outside any function body are initialized to zero. Variables of built-in type defined inside a function are **uninitialized 不被初始化的**. The value of an uninitialized variable of built-in type is **undefined**.

```c++
#include <iostream>
int a;
int main()
{   
    int b;
	std::cout << a << std::endl;	// ok, a has default initialization of value 0.
    std::cout << b << std::endl;	// error or warning, b is uninitialized.
    return 0;
}
```

Objects of class type that we do not explicitly initialize have a value that is defined by the class.

### 2.2.2 Variable Declarations（声明）and Definitions（定义）

C++ supports **Separate compilation 分离式编译**, which lets us split our programs into several files, each of which can be compiled independently. To support that, C++ distinguishes between declarations and definitions. A **declaration** makes a name known to the program. A file that wants to use a name defined elsewhere needs to include a declaration for that name. A **definition** creates the associated entity. **声明**规定变量的类型和名字，同时我们就可以使用该变量。定义则是在声明的基础上申请空间，也可能为变量赋初始值。

To obtain a declaration that is not also a definition, we add the `extern` keyword and may not provide an explicit initializer:

```c++
extern int i;	// declares but does not define i
int j; 			// declares and defines j
```

*Any declaration that includes an explicit initializer is a definition.* We can provide an initializer on a variable defined as `extern`, but doing so overrides the `extern`. An `extern` that has an initializer is a definition.

Note

- It is an error to provide an initializer on an `extern` inside a function.
- Variables must be defined exactly once but can be declared many times.

### 2.2.3 Identifiers 标识符

- Identifiers in C++ can be composed of letters, digits, and the underscore character.
- Identifiers are case-sensitive. 大小写敏感。
- Identifiers must begin with either a letter or an underscore. 只能以字母或者下划线开头。

Conventions 约定俗成（建议） for writing identifiers:

- The identifiers we define in our own programs may not contain two consecutive underscores. 不能有两个连续下划线。
- An identifier can't begin with an underscore followed immediately by an uppercase letter. 下划线后不能紧跟大写字母。
- Identifiers defined outside a function may not begin with an underscore. 函数外定义的标识符不能以下划线开头。
- An identifier should give some indication of its meaning. 标识符要能体现其含义。
- Variable names normally are lowercase. 变量通常都是小写的。
- Classes we define usually begin with an uppercase letter. 类名通常都是大写开头。
- Identifiers with multiple words should visually distinguish each word, for example, `student_loan` or `studentLoan`, not `studentloan`. 多个单词组成的标识符，单词间应该有明显的区分。

Table: C++ Keywords (pass)

Table: C++ Alternative Operator Names (pass)

### 2.2.4 Scope of a Name 作用域

- C++ 使用花括号 curly braces 来分隔大多数作用域。
- 名字的有效区域始于改名字的声明语句，终于其作用域的末端 `}`。
- 同一个作用域内，一个标识符只能被定义一次；不同的作用域内，可以定义相同的标识符。

The types of scope:

- 在任何其它作用域之外定义的名字具有 global 全局作用域，全局作用域中的名字可以在任何地方访问。
- 定义在类中的名字具有 class 作用域。
- 定义在名称空间中的名字具有 namespace 作用域。
- 定义在块中的名字具有 block 作用域。

#### Nested Scopes

Scopes can contain other scopes. The contained (or nested) scope is referred to as an **inner scope 内层作用域**, the containing scope is the **outer scope 外层作用域**.

- Names declared in the outer scope can also be redefined in an inner scope.
- The name can be used by scopes nested inside that scope.  
- The global scope has no name. Hence, when the scope operator has an empty left-hand side, it is a request to fetch the name on the right-hand side from the global scope.

```c++
int i = 1;		// i has global scope
int main()		// main has global scope
{
    int j = 2;	// j has block scope
    std::cout << j << std::endl;	// cout & endl has namespace scope
    {
        int i = 2;	// i has nested block scope
        std::cout << i << std::endl;	// this line will print 2 (nested block scope)
        std::cout << ::i << std::endl;	// this line will print 1 (global scope)
    }
}
```

## 2.3 Compound Types

### 2.3.1 References

A reference defines an alternative name for an object, i.e., just another name for an already existing object. (When we use the term reference, we mean **lvalue reference 右值引用**. ) We define a reference type by writing a declarator of the form `&d`, where `d` is the name being declared:

```c++
int ival = 1024;
int &refVal = ival; // refVal refers to (is another name for) ival
int &refVal2; // error: a reference must be initialized
refVal = 2; // assigns 2 to the object to which refVal refers, i.e., to ival
int i = refVal; // initializes i to the same value as ival
int &refVal3 = refVal; // ok: refVal3 is bound to the object to which refVal is bound, i.e., to ival
```

The type of a reference and the object to which the reference refers must match exactly. Moreover, a reference may be bound only to an object, not to a literal or to the result of a more general expression:

```c++
int &refVal4 = 10; // error: initializer must be an object
double dval = 3.14;
int &refVal5 = dval; // error: initializer must be an int object
```

### 2.3.2 Pointers

A pointer is a compound type that “points to” another type. 

Unlike a reference:

- A pointer is an object in its own right. 指针本身就是一个对象。
- A pointer can be assigned and copied, and can point to several different objects over its lifetime. 
- A pointer need not be initialized at the time it is defined. 
- Like other built-in types, pointers defined at block scope have undefined value if they are not initialized.

## 2.4 const Qualifier

## 2.5 Dealing with  Types

## 2.6 Defining Our Own Data Structures



---

##  Exercises

### Exercises Section 2.1.1

2.1

|              | short       | int                | long                   | long long        |
| ------------ | ----------- | ------------------ | ---------------------- | ---------------- |
| bits         | 16          | 16 or 32           | 32                     | 64               |
| size ranking | short ≤ int | short ≤ int ≤ long | int ≤ long ≤ long long | long ≤ long long |

|             | signed                                                       | unsigned            |
| ----------- | ------------------------------------------------------------ | ------------------- |
| differences | Can be negative. But the maximum positive number it can express is less than the unsigned ones. | Always be positive. |
| e.g. char   | [-128, ... ,127]                                             | [0, ... 255]        |

|      | float | double |
| ---- | ----- | ------ |
| bits | 32    | 64     |

2.2

|        | rate            | principal       | payment         |
| ------ | --------------- | --------------- | --------------- |
| choice | unsigned double | unsigned double | unsigned double |



### Exercises Section 2.1.2

2.3

```powershell
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;	// 32
std::cout << u - u2 << std::endl;	// 2^32-32 or 2^16-32
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;	// 32
std::cout << i - i2 << std::endl;	// -32
std::cout << i - u << std::endl;	// 0
std::cout << u - i << std::endl;	// 0
```

2.4

```powershell
> .\2.4
32
4294967264
32
-32
0
0
```

### Exercises Section 2.1.3

2.5

```c++
(a) ’a’, L’a’, "a", L"a" // char, wchar_t, char string, wide char string
(b) 10, 10u, 10L, 10uL, 012, 0xC // min(int, unsigned int), unsigned int, long, unsigned long, min(int, unsigned int), min(int, unsigned int)
(c) 3.14, 3.14f, 3.14L // double, float, long double
(d) 10, 10u, 10., 10e-2 // min(int, unsigned int), unsigned int, double, double
```

2.6

```c++
int month = 9, day = 7;
int month = 09, day = 07;
```

The first row will create two decimal variables, while the next line will produce two octal ones. However, `09` is an incorrect literal expression for octal number. Thus the second line will report error. 

2.7

```c++
(a) "Who goes with F\145rgus?\012" // Who goes with Fergus?  Type is char string(const char*).
(b) 3.14e1L // 31.4 Type is long double.
(c) 1024f // 1024. Type is float
(d) 3.14L // 3.14 Type is long double
```

2.8

```c++
> .\2.8
2M

2       M
```

### Exercises Section 2.2.1

2.9

```c++
(a) std::cin >> int input_value;	// error C2062: type 'int' unexpected

int input_value;
std::cin >> input_value;
```

```c++
(b) int i = { 3.14 };	// error C2397: conversion from 'double' to 'int' requires a narrowing conversion
```

```c++
(c) double salary = wage = 9999.99;	// error C2065: 'wage': undeclared identifier

double wage;
double salary = wage = 9999.99;
```

```c++
(d) int i = 3.14;	// correct
```

2.10

```c++
std::string global_str;		// empty string
int global_int;				// 0
int main()
{
    int local_int;			// uninitialized
	std::string local_str;	// uninitialized
}
```

### Exercises Section 2.2.2

2.11

```c++
(a) extern int ix = 1024;	// definition
(b) int iy;					// definition
(c) extern int iz;			// declaration
```

### Exercises Section 2.2.3

2.12

```c++
(a) int double = 3.14;		// invalid
(b) int _;					// valid
(c) int catch-22;			// invalid
(d) int 1_or_2 = 1;			// invalid
(e) double Double = 3.14;	// valid
```

### Exercises Section 2.2.4

2.13

```
j = 100
```

2.14

```
The program is legal.

The answer is:
i = 100
sum = (0+9)*10/2 = 45
```

### Exercises Section 2.3.1

2.15

```c++
(a) int ival = 1.01;	// valid
(b) int &rval1 = 1.01;	// invalid, initializer can't be a literal
(c) int &rval2 = ival;	// valid
(d) int &rval3;			// invalid, initializer must be an object
```

2.16

```c++
int i = 0, &r1 = i; double d = 0, &r2 = d;
(a) r2 = 3.14159;	// valid, d = 3.14159
(b) r2 = r1;		// valid, d = double(0) = 0
(c) i = r2;			// valid, i = int(0.0) = 0
(d) r1 = d;			// valid, i = int(d) = 0
```

2.17

```powershell
10 10
```



### Exercises Section x.y.z

x.1

```c++

```

