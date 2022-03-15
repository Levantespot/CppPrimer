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

Notes: Initialization is not assignment. Initialization happens when a variable is given a value when it is created. Assignment obliterates an object’s current value and replaces that value with a new one.  

#### List Initialization 列表初始化

For example, we can use any of the following four different ways to define an `int` variable named `units_sold` and initialize it to `0`:  

```c++
int units_sold = 0;
int units_sold = {0};
int units_sold{0};
int units_sold(0);
```

The compiler will reject us list initializing variables of built-in type if the initializer might lead to the **loss** of information when used with variables of built-in type: 将初始值放在花括号内即为列表初始化。当用于内置类型的变量时，若初始值在类型转换中会丢失信息（精度），编译器则会报错。

```c++
long double ld = 3.1415926536;
int a{ld}, b = {ld}; // error: narrowing conversion required
int c(ld), d = ld; // ok: but value will be truncated
```

#### Default Initialization 默认初始化

When we define a variable without an initializer, the variable is default initialized. What that default value is depends on the type of the variable and may also depend on where the variable is defined:

- Variables of built-in type defined outside any function body are initialized to zero.
- Variables of built-in type defined inside a function are **uninitialized 不被初始化的**. The value of an uninitialized variable of built-in type is **undefined**. The compiler will complain an error when trying to access the undefined variables.

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

### 2.2.2 Variable Declarations & Definitions & `extern`

C++ supports **Separate compilation 分离式编译**, which lets us split our programs into several files, each of which can be compiled independently. To support that, C++ distinguishes between declarations and definitions. A **declaration 声明** makes a name known to the program. A file that wants to use a name defined elsewhere needs to include a declaration for that name. A **definition 定义** creates the associated entity. **声明**规定变量的类型和名字，同时我们就可以使用该变量。定义则是在声明的基础上申请空间，也可能为变量赋初始值。

To obtain a declaration that is not also a definition, we add the `extern` keyword and may not provide an explicit initializer:

```c++
extern int i;	// declares but does not define i
int j; 			// declares and defines j
```

*Any declaration that includes an explicit initializer is a definition.* We can provide an initializer on a variable defined as `extern`, but doing so overrides the `extern`. An `extern` that has an initializer is a definition.

```c++
int main()
{
	extern int i = 1;		// error

	extern int j; j = 1;	// ok    
}
```

Note

- It is an error to provide an initializer on an `extern` inside a function. 不能在函数体内部初始化含有 `extern` 关键字的变量。
- Variables must be defined exactly once but can be declared many times. 一个变量只能被定义一次，但可以被多次声明。

```c++
// test.h
int i = 0;

// test.cpp
// Note: The initialization or declaration of i and j separately occurs only once in this source code file.
# include "test.h"
extern int j = 2;	// ok
extern int i;		// ok
extern int i = 1;	// error, multiple initialization
extern const int i;	// error, different type modifier
int main()
{
    extern int i = 1; 		// error, can't initialize a variable defined as extern in a block
    extern int i; i = 1; 	// ok
}
```

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

Note: Once we have defined a reference, there is no way to make that reference refer to a different object.

### 2.3.2 Pointers

A pointer is a compound type that “points to” another type. 

Unlike a reference:

- A pointer is an object in its own right. 指针本身就是一个对象。
- A pointer can be assigned and copied, and can point to several different objects over its lifetime. 
- A pointer need not be initialized at the time it is defined. 
- Like other built-in types, pointers defined at block scope have undefined value if they are not initialized.

We define a pointer type by writing a declarator of the form `*d`, where `d` is the name being defined. The `*` **must** be repeated for each pointer variable:

```c++
int *ip1, *ip2; // both ip1 and ip2 are pointers to int
double dp, *dp2; // dp2 is a pointer to double; dp is a double
```

#### Taking the Address of an Object

A pointer holds the address of another object. We get the address of an object by using the address-of operator 取地址符 (the `&` operator):

```c++
int ival = 42;
int *p = &ival; // p holds the address of ival; p is a pointer to ival
```

Notes: Because references are not objects, they don’t have addresses. Hence, we may not define a pointer to a reference. Also, the types of the pointer and the object to which it points must match, except const pointer and class inheritance.

#### Pointer Value

The value (i.e., the address) stored in a pointer can be in one of four states:

1. It can point to an object.
2. It can point to the location just immediately past the end of an object.
3. It can be a null pointer, indicating that it is not bound to any object.
4. It can be invalid; values other than the preceding three are **invalid**.

#### Using a Pointer to Access an Object

When a pointer points to an object, we can use the dereference operator 解引用符 (the `*` operator) to access that object:

```c++
int ival = 42;
int *p = &ival; // p holds the address of ival; p is a pointer to ival
cout << *p; // * yields the object to which p points; prints 42
*p = 0; // * yields the object; we assign a new value to ival through p
cout << *p; // prints 0
```

>KEY CONCEPT: SOME SYMBOLS HAVE MULTIPLE MEANINGS
>
>Some symbols, such as `&` and `*`, are used as both an operator in an expression and as part of a declaration. The context in which a symbol is used determines what the symbol means:  
>
>```c++
>int i = 42;
>int &r = i; // & follows a type and is part of a declaration; r is a reference
>int *p; // * follows a type and is part of a declaration; p is a pointer
>p = &i; // & is used in an expression as the address-of operator
>*p = i; // * is used in an expression as the dereference operator
>int &r2 = *p; // & is part of the declaration; * is the dereference operator
>```
>
>Because the same symbol is used with very different meanings, it can be helpful to ignore appearances and think of them as if they were different symbols.  

#### Null Pointers

A **null pointer 空指针** does not point to any object. Code can check whether a pointer is null before attempting to use it.  There are several ways to obtain a null pointer:

```c++
int *p1 = nullptr; // equivalent to int *p1 = 0;
int *p2 = 0; // directly initializes p2 from the literal constant 0

// must #include cstdlib
int *p3 = NULL; // equivalent to int *p3 = 0;
```

Older programs sometimes use a **preprocessor variable 预处理变量** named `NULL`, which the cstdlib header defines as `0`.  Preprocessor variables are managed by the preprocessor, and are not part of the `std` namespace. As a result, we refer to them directly without the `std::` prefix. When we use a preprocessor variable, the preprocessor automatically replaces the variable by its value. Hence, initializing a pointer to NULL is equivalent to initializing it to `0`.

Note: It is illegal to assign an `int` variable to a pointer, even if the variable’s value happens to be `0`.

Suggestion: 

- Modern C++ programs generally should avoid using `NULL` and use `nullptr` instead.
- Initialize all pointers because uninitialized pointers are a common source of run-time errors.

#### `void*` Pointers

he type `void*` is a special pointer type that can hold the address of any object. Like any other pointer, a `void*` pointer holds an address, but the type of the object at that address is unknown:

```c++
double obj = 3.14, *pd = &obj;
// ok: void* can hold the address value of any data pointer type
void *pv = &obj; // obj can be an object of any type
pv = pd; // pv can hold a pointer to any type
```

Generally, we use a `void*` pointer to deal with memory as memory, rather than using the pointer to access the object stored in that memory.

We can:

- compare it to another pointer
- pass it to or return it from a function
- assign it to another void* pointer

We can't:

- use a void* to operate on the object it addresses—we don’t know that object’s type, and the type determines what operations we can perform on the object.

```c++
int a = 1, b = 2;
void *pa = nullptr, *pb = nullptr, *pbig = nullptr;
pa = &a; pb = &b;	// valid
if(pa != pb){		// valid
    std::cout << *pa << *pb << std::endl;	// invalid
    if(*pa > *pb){	// invalid
        pbig = pa;	// valid
    }else{
        pbig = pb;	// valid
    }
}
```

§ 4.11.3 will show how we can retrieve the address stored in a `void*` pointer.

### 2.3.3 Understanding Compound Type Declarations

Type modifications, like `*` and `&`, are part of declarators. They say nothing about any other objects that might be declared in the same statement.

```c++
// i is an int; p is a pointer to int; r is a reference to int
// They all have a basic type of int. With differecnt type modifications, they become different objects eventually.
int i = 1024, *p = &i, &r = i;
```

#### Defining Multiple Variables

```c++
int* p; // legal but might be misleading
int* p1, p2; // p1 is a pointer to int; p2 is an int
int *p1, *p2; // both p1 and p2 are pointers to int, easy to understand
```

#### Pointers to Pointers

In general, there are no limits to how many type modifiers can be applied to a declarator. A pointer is an object in memory, so like any object it has an address. Therefore, we can store the address of a pointer in another pointer.

```c++
int ival = 1024;
int *pi = &ival; // pi points to an int
int **ppi = &pi; // ppi points to a pointer to an int
```

Just as dereferencing a pointer to an `int` yields an `int`, dereferencing a pointer to a pointer yields a pointer. To access the underlying object, we must dereference the original pointer twice:  

```c++
cout << "The value of ival\n"
	 << "direct value: " << ival << "\n"
	 << "indirect value: " << *pi << "\n"
	 << "doubly indirect value: " << **ppi
	 << endl;
```

#### References to Pointers

A reference is not an object. Hence, we may not have a pointer to a reference. However, because a pointer is an object, we can define a reference to a pointer:

```c++
int i = 42;
int *p; // p is a pointer to int
int *&r = p; // r is a reference to the pointer p
r = &i; // r refers to a pointer; assigning &i to r makes p point to i
*r = 0; // dereferencing r yields i, the object to which p points; changes i to 0
```

The easiest way to understand the type of `r` is to read the definition right to left. The symbol closest to the name of the variable (in this case the `&` in `&r`) is the one that has the most immediate effect on the variable’s type. Thus, we know that `r` is a reference. The rest of the declarator determines the type to which `r` refers. The next symbol, `*` in this case, says that the type `r` refers to is a pointer type. Finally, the base type of the declaration says that `r` is a reference to a pointer to an `int`.

## 2.4 const Qualifier 限定符

We can make a variable unchangeable by defining the variable’s type as `const`:

```c++
const int bufSize = 512; // input buffer size
```

defines bufSize as a constant. Any attempt to assign to `bufSize` is an error. 

```c++
bufSize = 512; // error: attempt to write to const object
```

#### Initialization

Because we can’t change the value of a `const` object after we create it, it must be initialized:

```c++
const int i = get_size(); 	// ok: initialized at run time
const int j = 42; 			// ok: initialized at compile time
const int k; 				// error: k is uninitialized const
```

When we use an object to initialize another object, it doesn’t matter whether either or both of the objects are `const`s:

```c++
int i = 42;
const int ci = i; 	// ok: the value in i is copied into ci
int j = ci; 		// ok: the value in ci is copied into j
```

#### By Default, const Objects Are Local to a File 不是特别懂

When a `const` object is initialized from a compile-time constant 编译时初始化, the compiler will usually replace uses of the variable with its corresponding value during compilation. 有时候编译器会直接用字面量替换变量。To substitute the value for the variable, the compiler has to see the variable’s initializer.

Sometimes we have a `const` variable that we want to share across multiple files but whose initializer is not a constant expression. In this case, we want to define the `const` in one file, and declare it in the other files that  use that object. To define a single instance of a const variable, we use the keyword `extern` on both its definition and declaration(s):

```c++
// file_1.cc defines and initializes a const that is accessible to other files
extern const int bufSize = fcn();
// file_1.h
extern const int bufSize; // same bufSize as defined in file_1.cc
```

To sum up, to share a `const` object among multiple files, you must define the variable as `extern`.

### 2.4.1  Reference to const

As with any other object, we can bind a reference to an object of a `const` type. To do so we use a **reference to const 对常量的引用**, which is a reference that refers to a `const` type. Unlike an ordinary reference, a reference to `const` cannot be used to change the object to which the reference is bound:

```c++
const int ci = 1024;
const int &r1 = ci;	// ok: both reference and underlying object are const
r1 = 42;			// error: r1 is a reference to const
int &r2 = ci;		// error: nonconst reference to a const object
```

#### Initialization and References to const

Generally a reference must match the type of the object to which it refers. But we can initialize a **reference to const 常量引用** from any expression that can be converted (§ 2.1.2) to the type of the reference. In particular, we can bind a reference to `const` to a non`const` object, a **literal**, or a more general expression. 通常来说引用需要类型配对，但是在初始化常量引用时，可以使用任意可被转化为引用类型的表达式（对象、字面量等均可），即 `const type_A &var_A = var_B`，其中 `var_B` 的类型 `type_B` 可被转化为 `type_A` 即可，两者不一定相同。

```c++
// when type_A == type B
int i = 42;
const int &r1 = i;		// ok: we can bind a const int& to a plain int object
const int &r2 = 42; 	// ok: r1 is a reference to const
const int &r3 = r1 * 2; // ok: r3 is a reference to const
int &r4 = r1 * 2; 		// error: r4 is a plain, nonconst reference
```

```c++
// when type_A != type B
double dval = 3.14;		
const int &ri = dval;	// ok, ri refers to an int
```

When types are different, to ensure that the object to which `ri` is bound is an `int`, the compiler transforms last line into something like:

```c++
const int temp = dval; 	// create a temporary const int from the double
const int &ri = temp; 	// bind ri to that temporary    
```

#### A Reference to const May Refer to an Object That Is Not const

It is important to realize that a reference to `const` restricts only what we can do through that reference. Binding a reference to `const` to an object says nothing about whether the underlying object itself is `const`. 引用本身是否是 `const` 并不会影响被引用的对象。Because the underlying object might be `nonconst`, it might be changed by other means:

```c++
int i = 42;
int &r1 = i; 		// r1 bound to i
const int &r2 = i; 	// r2 also bound to i; but cannot be used to change i
r1 = 0; 			// ok: r1 is not const; i is now 0
r2 = 0; 			// error: r2 is a reference to const
```

Binding `r2` to the (non`const`) `int i` is legal. However, we cannot use `r2` to change `i`. Even so, the value in `i` still might change. We can change `i` by assigning to it directly, or by assigning to another reference bound to `i`, such as `r1`.

### 2.4.2 Pointers and const

Like a reference to `const`, **a pointer to const 指向常量的指针** (§ 2.4.1) may not be used to change the object to which the pointer points. We may store the address of a `const` object only in a pointer to `const`:

```c++
const double pi = 3.14; 	// pi is const; its value may not be changed
double *ptr = &pi; 			// error: ptr is a plain pointer
const double *cptr = &pi; 	// ok: cptr may point to a double that is const
*cptr = 42; 				// error: cannot assign to *cptr
```

Usually the types of a pointer and the object to which it points must match. The first exception is that we can use a pointer to `const` to point to a `nonconst` object:

```c++
double dval = 3.14; // dval is a double; its value can be changed
const double *cptr = &dval; 		// ok: but can’t change dval through cptr
```

Like a reference to `const`, a pointer to `const` says nothing about whether the object to which the pointer points is `const`. Defining a pointer as a pointer to `const` affects only what we can do with the pointer. It is important to remember that there is no guarantee that an object pointed to by a pointer to `const` won’t change.

#### `const` Pointers 常量指针

Like any other `const` object, a `const` pointer must be initialized, and once initialized, its value (i.e., the address that it holds) may not be changed.  We indicate that the pointer is `const` by putting the `const` after the `*`. This placement indicates that it is the pointer, not the pointed-to type, that is `const`:

```c++
int a = 0;
int *const pa = &a; // pa is a const pointer and will always point to a
const double pi = 3.14159;
const double *const pip = &pi; // pip is a const pointer to a const object
```

The fact that a pointer is itself `const` says nothing about whether we can use the pointer to change the underlying object. Whether we can change that object depends entirely on the type to which the pointer points.

```c++
*pip = 2.72;// error: pip is a pointer to const
*pa = 1; 	// ok: equals a = 1, the object to which curErr points is non-const.
int b = 2;
pa = &b;	// error, curErr is a const pointer.
```

### 2.4.3 Top-Level const

We use the term **top-level 顶层** `const` to indicate that the pointer itself is a `const`. When a pointer can point to a `const` object, we refer to that `const` as a **low-level 底层** `const`.

更广泛来说，顶层 `const` 可以指任何对象类型（如运算类型、类类型、指针类型），且该对象类型是 `const`；底层 `const` 可以指复合类型，如指针和引用。

```c++
int i = 0;
int *const p1 = &i; 	// we can’t change the value of p1; const is top-level
const int ci = 42; 		// we cannot change ci; const is top-level
const int *p2 = &ci; 	// we can change p2; const is low-level
const int *const p3 = p2; 	// right-most const is top-level, left-most is not
const int &r = ci; 		// const in reference types is always low-level
```

The distinction between top-level and low-level matters when we copy an object. When we copy an object, top-level `consts` are ignored: 当复制的时候，顶层 const 被忽略：

```c++
i = ci; // ok: copying the value of ci; top-level const in ci is ignored
p2 = p3; // ok: pointed-to type matches; top-level const in p3 is ignored
```

When we copy an object, both objects must have the same low-level `const` qualification or there must be a conversion between the types of the two objects. 复制的时候，底层 const 必须相同，或者两对象的类型可以被相互转换。In general, we can convert a `nonconst` to `const` but not the other way round:

```c++
int *p = p3; 	// error: p3 has a low-level const but p doesn’t
p2 = p3; 		// ok: p2 has the same low-level const qualification as p3
p2 = &i; 		// ok: we can convert int* to const int*
int &r = ci; 	// error: can’t bind an ordinary int& to a const int object
const int &r2 = i; // ok: can bind const int& to plain int
```

### 2.4.4 constexpr and Constant Expressions

A **constant expression 常量表达式** is an expression whose value cannot change and that can be evaluated at compile time. 常量表达式值不会改变，且在编译的时候就能得到值。

A literal is a constant expression. A `const` object that is initialized from a constant expression is also a constant expression. Whether a given object (or expression) is a constant expression depends on the **types** and the **initializers**:

```c++
const int max_files = 20; 	// max_files is a constant expression
const int limit = max_files + 1; 	// limit is a constant expression
int staff_size = 27; 		// staff_size is not a constant expression
const int sz = get_size(); 	// sz is not a constant expression, because the value of its initializer is not known until run time
```

#### `constexpr` Variables

Variables declared as `constexpr` are implicitly `const` and must be initialized by constant expressions:

```c++
constexpr int mf = 20; 			// 20 is a constant expression
constexpr int limit = mf + 1; 	// mf + 1 is a constant expression
constexpr int sz = size(); 		// ok only if size is a constexpr function
```

#### Pointers and `constexpr`

It is important to understand that when we define a pointer in a `constexpr` declaration, the `constexpr` specifier applies to the pointer, not the type to which the pointer points:

```c++
const int *p = nullptr; 	// p is a pointer to a const int
constexpr int *q = nullptr; // q is a const pointer to int
constexpr const int *r = nullptr;	// r is a const pointer to a const int
```

## 2.5 Dealing with  Types

### 2.5.1 Type Aliases

A **type alias 类型别名** is a name that is a synonym for another type. Type aliases let us simplify complicated type definitions, making those types easier to use. Type aliases also let us emphasize the purpose for which a type is used.

We can define a type alias in one of two ways. Traditionally, we use a `typedef`:

```c++
typedef double wages; 	// wages is a synonym for double
typedef wages base, *p; // base is a synonym for double, p for double*
```

The new standard introduced a second way to define a type alias, via an **alias declaration 别名声明**. An alias declaration starts with the keyword `using` followed by the alias name and an `=`.   

```c++
using SI = Sales_item; // SI is a synonym for Sales_item
```

A type alias is a type name and can appear wherever a type name can appear:

```c++
wages hourly, weekly; // same as double hourly, weekly;
SI item; // same as Sales_item item
```

#### Pointers, `const`, and Type Aliases

```c++
typedef char *pstring;
const pstring cstr = 0; // cstr is a constant pointer to char
const pstring *ps; 		// ps is a pointer to a constant pointer to char
```

The base type in these declarations is `const pstring`. As usual, a `const` that appears in the base type modifies the given type. The type of `pstring` is “pointer to char.” So, `const pstring` is a constant pointer to char—not a pointer to `const char`.

It can be tempting, albeit incorrect, to interpret a declaration that uses a type alias by conceptually replacing the alias with its corresponding type:  不能用「直接替换原类型」的方法来理解别名：

```c++
const pstring cstr = 0; 
const char *cstr = 0;	// wrong interpretation of the previous line
```

When we use `pstring` in a declaration, the base type of the declaration is a pointer type. When we rewrite the declaration using `char*`, the base type is `char` and the `*` is part of the declarator. In this case, `const char` is the base type. This rewrite declares `cstr` as a pointer to` const char` rather than as a `const` pointer to `char`.

### 2.5.2 The auto Type Specifier

Unlike type specifiers, such as double, that name a specific type, `auto` tells the compiler to deduce the type from the initializer. By implication, a variable that uses auto as its type specifier must have an initializer:

```c++
// the type of item is deduced from the type of the result of adding val1 and val2
auto item = val1 + val2; // item initialized to the result of val1 + val2
```

As with any other type specifier, we can define multiple variables using `auto`. Because a declaration can involve only a single base type, the initializers for all the variables in the declaration must have types that are consistent with each other:

```c++
auto i = 0, *p = &i; 	// ok: i is int and p is a pointer to int
auto sz = 0, pi = 3.14; // error: inconsistent types for sz and pi
```

#### Compound Types, `const`, and `auto`

The type that the compiler infers for auto is not always exactly the same as the initializer’s type. Instead, the compiler adjusts the type to conform to normal initialization rules.

First, when we use a reference as an initializer, the initializer is the corresponding object. The compiler uses that object’s type for `auto`’s type deduction:  

```c++
int i = 0, &r = i;
auto a = r; // a is an int (r is an alias for i, which has type int)
```

Second, `auto` ordinarily ignores top-level `const`s (§ 2.4.3). As usual in initializations, low-level `const`s, such as when an initializer is a pointer to `const`, are kept: 通常 `auto` 会忽略掉顶层 `const`，保留底层 `const`：

```c++
const int ci = i, &cr = ci;
auto b = ci; 	// b is an int (top-level const in ci is dropped)
auto c = cr; 	// c is an int (cr is an alias for ci whose const is top-level)
auto d = &i; 	// d is an int* (& of an int object is int*)
auto e = &ci; 	// e is const int* (& of a const object is low-level const)
```

If we want the deduced type to have a top-level `const`, we must say so explicitly:

```c++
const auto f = ci; // deduced type of ci is int; f has type const int
```

We can also specify that we want a reference to the auto-deduced type. Normal initialization rules still apply:

```c++
auto &g = ci; 	// g is a const int& that is bound to ci
auto &h = 42; 	// error: we can’t bind a plain reference to a literal
const auto &j = 42; // ok: we can bind a const reference to a literal
```

When we ask for a reference to an auto-deduced type, top-level `consts` in the initializer are not ignored. 对自动类型的引用时，初始值的顶层 `const` 则不会省略。

### 2.5.3 The `decltype` Type Specifier

`decltype` will return the type of its operand without evaluating the expression 并不会计算表达式的值:

```c++
decltype(f()) sum = x; // sum has whatever type f returns
```

Here, the compiler does not call `f`, but it uses the type that such a call would return as the type for `sum`.

略微不同于 `auto`，若 `decltype` 使用的是变量，则会保留变量的顶层 `const` 和引用：

```c++
const int ci = 0, &cj = ci;
decltype(ci) x = 0; // x has type const int
decltype(cj) y = x; // y has type const int& and is bound to x
decltype(cj) z; 	// error: z is a reference and must be initialized
```

若 `decltype` 使用的表达式不是变量，则会返回表达式结果对应的类型：

```c++
// decltype of an expression can be a reference type
int i = 42, *p = &i, &r = i;
decltype(r) a = i;	// ok, a has type int&
decltype(r + 0) b; 	// ok: addition yields an int; b is an (uninitialized) int
```

如果表达式的内容是解引用操作，则 `decltype` 将得到引用类型：

```c++
int i = 42, &r = i, *p = &i;
decltype(*p) t1 = i;	// ok, c has a type int&
decltype(*r) t2 = i;	// error
```

如果给变量加上一层或多层括号，编译器则会把它当作表达式。*赋值如果作为表达式，则等于其左值的引用*。同时变量本身可以作为一个特殊表达式，这个表达式只有左值，且左值就是自己，故以这样的 `decltype` 就会得到引用类型：

```c++
// decltype of a parenthesized variable is always a reference
decltype((i)) d; // error: d is int& and must be initialized
decltype(i) e; // ok: e is an (uninitialized) int
```

## 2.6 Defining Our Own Data Structures (Types)

In C++ we define our own data types by defining a class.

### 2.6.1 Defining the `Sales_data` Type

```c++
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

Our class begins with the keyword `struct`, followed by the name of the class 类名 and a (possibly empty) class body 类体. The class body is surrounded by curly braces and forms a new scope. The names defined inside the class must be unique within the class but can reuse names defined outside the class.

The close curly that ends the class body must be followed by a semicolon. The semicolon is needed because we can define variables after the class body:

```c++
struct Sales_data { /* ... */ } accum, trans, *salesptr;
// equivalent, but better way to define these objects
struct Sales_data { /* ... */ };
Sales_data accum, trans, *salesptr;
```

#### Class Data Members

The class body defines the **members 成员** of the class. Each object has its own copy of the class data members. Modifying the data members of one object does not change the data in any other `Sales_data` object.  We define data members the same way that we define normal variables: We specify a base type followed by a list of one or more declarators.

Under the new standard, we can supply an **in-class initializer 类内初始值** for a data member. When we create objects, the in-class initializers will be used to initialize the data members. Members without an initializer are default initialized.

Note: 类内初始值可以放在花括号里，可以放在等号右边，但是不能使用圆括号。

```c++
struct my_class_name {}
    unsigned member1 = 0;	// ok
	unsigned member2 = {0}; // ok
    unsigned member3{0};	// ok
    unsigned member4(0);	// error
};
```

In § 7.2, we’ll see that C++ has a second keyword, `class`, that can be used to define our own data structures.

### 2.6.2 Using the `Sales_data` Class

Unlike the `Sales_item` class, our `Sales_data` class does not provide any operations, so we will have to write our own code to do the input, output, and addition operations.  

#### Reading Data into a `Sales_data` Object

```c++
double price = 0;	// price per book, used to calculate total revenue
// read the first transactions: ISBN, number of books sold, price per book
std::cin >> data1.bookNo >> data1.units_sold >> price;
// calculate total revenue from price and units_sold
data1.revenue = data1.units_sold * price;

// read second transaction
std::cin >> data2.bookNo >> data2.units_sold >> price;
data2.revenue = data2.units_sold * price;
```

#### Printing the Sum of Two `Sales_data` Objects

Our other task is to check that the transactions are for the same ISBN. If so, we’ll print their sum, otherwise, we’ll print an error message:

```c++
if (data1.bookNo == data2.bookNo){
    // sum to objects
    // std::cout ...
    return 0;	// indicate success
} else {
    // std::cerr ...
    return 1;	// indicate failure
}
```

### 2.6.3 Writing Our Own Header Files

尽管如之后的 19.7 节所讲，我们可以在函数体内定义类，但是会受到一些限制。因此，类一般都不定义在函数体内。为保证不同文件使用同一个类的定义一致，类通常被定义在头文件（header file）中，且类所在头文件的名字应该与类名一致。

头文件通常包含只能被定义一次的实体，如 `class`、`const` 和 `constexpr` 变量。由于头文件通常也需要其他头文件，则很可能出现多次包含（隐式）的情况，因此需要在书写头文件的时候进行适当处理，使遇到多次包含时也能安全和正常地工作。

#### A Brief Introduction to the Preprocessor

The most common technique for making it safe to include a header multiple times relies on the **preprocessor 预处理器**. The preprocessor—which C++ inherits from C—is a program that runs before the compiler and changes the source text of our programs. For example, when the preprocessor sees a `#include`, it *replaces* the `#include` with the contents of the specified header, i.e., copied into current program.

C++ programs also use the preprocessor to define **header guards 头文件保护符**. Header guards rely on preprocessor variables. Preprocessor variables have one of two possible states: *defined* or *not defined*. The `#define` directive takes a name and defines that name as a preprocessor variable. There are two other directives that test whether a given preprocessor variable has or has not been defined: `#ifdef` is true if the variable has been defined, and `#ifndef` is true if the variable has not been defined. If the test is true, then everything following the `#ifdef` or `#ifndef` is processed up to the matching `#endif`.

```c++
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif
```

WARNING: 预处理变量无视 C++ 语言中关于作用域的规则 (scoping rules)。预处理变量在整个程序中必须唯一，通常的做法时是基于头文件种类的名字来构筑保护符的名字，且要全部大写。

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
extern int ix = 1024;  // Definition
int iy;  // Definition
extern int iz;  // Declaration
int main() {
  //extern int ix2 = 1024;  // Error
  int iy2;  // Definition
  extern int iz2;  // Declaration

  return 0;
}
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

### Exercises Section 2.3.2

2.18

```c++
int a = 0;
int *pa = nullptr;
pa = &a;	// change the value of a pointer
*pa = 1;	// change the value to which it points
```

2.19

```
Key difference between references and pointers:

Pointers are objects, not references.
```

2.20

```
It equals i=i*i;
```

2.21

```c++
int i = 0;
(a) double* dp = &i;	// invalid, mismatched type
(b) int *ip = i; 		// invalid, cannot assign a variable to a pointer
(c) int *p = &i;		// valid
```

2.22

```c++
if (p) // whether the pointer p is nullptr
if (*p) // whether the variable to which the pointer p points equalls zero
```

2.23

```
It's only possible to determines if it is a null pointer. Otherwise we cannot figure out whether it points to a valid object.
```

2.24

```
Since void pointer can point to a memory of any types, it's legal to assign the address of i to pointer p.

Pointer lp has a different type to variable i, so it's illegal to assign the address of i to lp.
```

### Exercises Section 2.3.3

2.25

```c++
(a) int* ip, i, &r = i; // ip is a null pointer; i has a type of int; r is a reference to variable i;
(b) int i, *ip = 0; // i is a variable type of int; ip is a null pointer.
(c) int* ip, ip2; // ip is a uninitialized pointer; ip2 is a variable type of int.
```

### Exercises Section 2.4

2.26

```c++
(a) const int buf;	// illegal, uninitialized const variable
(b) int cnt = 0;	// legal
(c) const int sz = cnt;	// legal
(d) ++cnt; ++sz;	// illegal, the of value of variable modified by const can not be changed
```

### Exercises Section 2.4.2

2.27

```c++
(a) int i = -1, &r = 0; 		// ilegal, a nonconst reference cannot be initialized to a literal
(b) int *const p2 = &i2;		// legal
(c) const int i = -1, &r = 0; 	// legal !!
(d) const int *const p3 = &i2;	// legal
(e) const int *p1 = &i2; 		// legal
(f) const int &const r2;		// ilegal, reference must be initialized
(g) const int i2 = i, &r = i;	// legal
```

2.28

```c++
(a) int i, *const cp; 		// ilegal, const variable cp must be initialized.
(b) int *p1, *const p2;		// ilegal, const variable p2 must be initialized.
(c) const int ic, &r = ic; 	// ilegal, const variable ic must be initialized.
(d) const int *const p3;	// ilegal, const variable p3 must be initialized.
(e) const int *p;			// legal
```

2.29

```c++
(a) i = ic; 	// legal
(b) p1 = p3; 	// ilegal, const can't be convert to non const
(c) p1 = &ic; 	// ilegal, type mismatched
(d) p3 = &ic;	// legal
(e) p2 = p1; 	// legal
(f) ic = *p3;	// legal
```

### Exercises Section 2.4.4

2.32

```c++
int null = 0, *p = null;	// ilegal

constexpr int null = 0; int *p = null;	// legal
```

### Exercises Section 2.5.2

2.33

```c++
a = 42; // legal
b = 42; // legal
c = 42;	// legal
d = 42; // ilegal, d is int*
e = 42; // ilegal, e is const int*
g = 42;	// ilegal, g is a reference
```

2.34

pass

2.35

```c++
const int i = 42;
auto j = i; 		// int
const auto &k = i; 	// const int&
auto *p = &i;		// const int*
const auto j2 = i, &k2 = i;	// const int, const int&
```

### Exercises Section 2.5.3

2.36

```c++
int a = 3, b = 4;
decltype(a) c = a;		// int
decltype((b)) d = a;	// int& bound to a
++c;
++d;	
// a = 4, b = 4, c = 4, d = 4
```

2.37

```c++
int a = 3, b = 4;
decltype(a) c = a;		// c is an int
decltype(a = b) d = a;	// d is an int& bound to a
```

2.38

```c++
// auto will ignore the top-level const, while decltype remains it.

// code that deduce the same type:
int i = 1;
auto i1 = i;		// i1 is an int
decltype(i) i2 = i;	// i2 is an int 

// code that deduce the different types:
const int i = 1;
auto i1 = i;		// i1 is an int
decltype(i) i2 = i;	// i2 is a const int 
```

### Exercises Section 2.6.1

2.39

```powershell
test.cpp(7): error C2628: 'Foo' followed by 'int' is illegal (did you forget a ';'?)
test.cpp(8): error C3874: return type of 'main' should be 'int' instead of 'Foo'
test.cpp(9): error C2440: 'return': cannot convert from 'int' to 'Foo'
test.cpp(9): note: No constructor could take the source type, or constructor overload resolution was ambiguous
```

### Exercises Section 2.6.2

2.41 PASS

### Exercises Section 2.6.3

2.42 PASS



### Exercises Section x.y.z

x.1

```c++

```

