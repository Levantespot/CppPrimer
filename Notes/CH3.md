# Chapter 3: STRINGS, VECTORS, AND ARRAYS

## 3.1 Namespace `using` Declarations

There is a simplified, also the safest way to using namespace members by **using declaration（`using` 声明）**. § 18.2.2 covers another way to use names from a namespace.  

A `using` declaration lets us use a name from a namespace without qualifying the name with a `namespace_name::` prefix. A `using` declaration has the form

```c++
using namespace::name;
```

Once the `using` declaration has been made, we can access *name* directly:

```c++
#include <iostream>
// using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;
int main()
{
    int i;
    cin >> i; 		// ok: cin is a synonym for std::cin
    cout << i; 		// error: no using declaration; we must use the full name
    std::cout << i; // ok: explicitly use cout from namepsace std
    return 0;
}
```

#### A Separate using Declaration Is Required for Each Name

The important part is that there must be a `using` declaration for **each** name we use, and each declaration must end in a semicolon:

```c++
#include <iostream>
// using declarations for names from the standard library
using std::cin;
using std::cout; using std::endl;
int main()
{
    cout << "Enter two numbers:" << endl;
    int v1, v2;
    cin >> v1 >> v2;
    cout << "The sum of " << v1 << " and " << v2
    	 << " is " << v1 + v2 << endl;
    return 0;
}
```

#### Headers Should Not Include `using` Declarations

Code inside headers ordinarily should not use using declarations. The reason is that the contents of a header are copied into the including program’s text. If a header has a using declaration, then every program that includes that header gets that same `using` declaration. As a result, a program that didn’t intend to use the specified library name might encounter unexpected name conflicts.

## 3.2 Library `string` Type

A `string` is a variable-length sequence of characters. The usage of `string` type:

```c++
#include <string>
using std::string;
```

### 3.2.1 Defining and Initializing `string`s

A class may define many different ways to initialize objects of its type. Each way must be distinguished from the others either by the number of initializers that we supply, or by the types of those initializers.

Table 3.1 Ways to Initialize a `string`

| Code                  | Notes                                                        |
| --------------------- | ------------------------------------------------------------ |
| `string s1`           | Default initialization; `s1` is the empty string.            |
| `string s2(s1)`       | `s2` is a copy of `s1`.                                      |
| `string s2 = s1`      | Equivalent to `s2(s1)`, `s2` is a copy of `s1`.              |
| `string s3("value")`  | `s3` is a copy of the string literal, not including the null. |
| `string s3 = "value"` | Equivalent to `s3("value")`, `s3` is a copy of the string literal. |
| `string s4(n, ’c’)`   | Initialize `s4` with `n` copies of the character ’`c`’.      |

#### Direct and Copy Forms of Initialization

When we initialize a variable using `=`, we are asking the compiler to **copy initialize 拷贝初始化** the object by copying the initializer on the right-hand side into the object being created. Otherwise, when we omit the `=`, we use **direct initialization 直接初始化**.

When we have a single initializer, we can use either the direct or copy form of initialization. When we initialize a variable from more than one value, such as in the initialization of `s4` above, we must use the direct form of initialization:

```c++
string s5 = "hiya";	// copy initialization
string s6("hiya");	// direct initialization
string s7(10, ’c’); // direct initialization; s7 is cccccccccc
```

### 3.2.2 Operations on `string`s

Table 3.2: `string` Operations

| Code             | Notes                                                        |
| ---------------- | ------------------------------------------------------------ |
| `os << s`        | Writes  `s` onto output stream `os`. Returns `os`.           |
| `is >> s`        | Reads whitespace-separated string  from `is` into `s`. Returns `is`. |
| `getline(is, s)` | Reads a line of input from `is` into `s`. Returns `is`.      |
| `s.empty()`      | Returns `true` if `s` is empty; otherwise returns `false`.   |
| `s.size()`       | Returns the number of characters in `s`.                     |
| `s[n]`           | Returns a reference to the char at position `n` in `s`; positions start at 0. |
| `s1 + s2`        | Returns a string that is the concatenation of `s1` and `s2`. |
| `s1 = s2`        | Replaces characters in `s1` with a copy of `s2`.             |
| `s1 == s2`       | The strings `s1` and `s2` are equal if they contain the same characters. |
| `s1 != s2`       | Equality is case-sensitive.                                  |
| `<, <=, >, >=`   | Comparisons are case-sensitive and use dictionary ordering.  |

#### Reading an Unknown Number of `string`s

```c++
int main()
{
    string word;
    while (cin >> word) // read until end-of-file
    	cout << word << endl; // write each word followed by a new line
    return 0;
}
```

The condition tests the stream after the read completes. If the stream is valid—it hasn’t hit end-of-file (^z in windows) or encountered an invalid input—then the body of the while is executed.

#### Using `getline` to Read an Entire Line

```c++
string line;
// read input a line at a time until end-of-file
while (getline(cin, line))
    cout << line << endl;
```

#### The `string` `empty` and `size` Operations

```c++
string line;

// read input a line at a time and discard blank lines
while (getline(cin, line))
	if (!line.empty())
		cout << line << endl
        
// read input a line at a time and print lines that are longer than 80 characters
while (getline(cin, line))
	if (line.size() > 80)
		cout << line << endl;
```

#### The `string::size_type` Type

`size()` returns a `string::size_type` value. The type `size_type` is one of the companion types defined by `string`. Although we don’t know the precise type of `string::size_type`, we do know that it is an `unsigned` type big enough to hold the size of any `string`.  

Admittedly, it can be tedious to type `string::size_type`. Under the new standard, we can ask the compiler to provide the appropriate type by using `auto` or `decltype`:

```c++
auto len = line.size();	// len has type string::size_type
```

Because `size` returns an `unsigned` type, it is essential to remember that expressions that mix `signed` and `unsigned` data can have surprising results.

#### Comparing `string`s

The comparisons are case-sensitive—upper- and lowercase versions of a letter are different characters. Two `string`s are equal if they are the same length and contain the same characters.

1. 若两个 `string` 长度不同，短的 `string` 和长的 `string` 对应部分相同，则认为较短的更小。
2. 一旦两个 `string` 有不同的地方，则比较就发生在第一个不同的字符处。

```c++
string str = "Hello";
string phrase = "Hello World";
string slang = "Hiya";
```

Using rule 1, we see that `str` is less than `phrase`. By applying rule 2, we see that `slang` is greater than both `str` and `phrase`.

#### Assignment and Adding for `string`s

```c++
string st1(10, ’c’), st2; // st1 is cccccccccc; st2 is an empty string
st1 = st2; 	// assignment: replace contents of st1 with a copy of st2
			// both st1 and st2 are now the empty string
```

Adding two `string`s yields a new `string` that is the concatenation of the left-hand followed by the right-hand operand. The compound assignment operator (`+=`) appends the right-hand operand to the left-hand string:

```c++
string s1 = "hello, ", s2 = "world\n";
string s3 = s1 + s2; // s3 is "hello, world\n"
s1 += s2; // equivalent to s1 = s1 + s2
```

The `string` library lets us convert both character literals and character string literals to `string`s.

```c++
string s1 = "hello", s2 = "world"; // no punctuation in s1 or s2
string s3 = s1 + ", " + s2 + ’\n’;
```

When we mix `string`s and string or character literals, at least one operand to each `+` operator must be of `string` type:

```c++
string s4 = s1 + ", "; 				// ok: adding a string and a literal
string s5 = "hello" + ", "; 		// error: no string operand
string s6 = s1 + ", " + "world";	// ok: each + has a string operand
string s7 = "hello" + ", " + s2;	// error: can’t add string literals
```

The subexpression `s1 + ", "` of `s6` returns a `string`, which forms the left-hand operand of the second `+` operator. It is as if we had written:

```c++
string tmp = s1 + ", "; // ok: + has a string operand
s6 = tmp + "world"; // ok: + has a string operand
```

On the other hand, the initialization of `s7` is illegal, which we can see if we parenthesize the expression:

```c++
string s7 = ("hello" + ", ") + s2; // error: can’t add string literals
```

### 3.2.3 Dealing with the Characters in a `string`

>ADVICE: USE THE C++ VERSIONS OF C LIBRARY HEADERS
>In addition to facilities defined specifically for C++, the C++ library incorporates the C library. Headers in C have names of the form `name.h`. The C++ versions of these headers are named `cname`—they remove the `.h` suffix and precede the name with the letter `c`. The `c` indicates that the header is part of the C library. 
>Hence, `cctype` has the same contents as `ctype.h`, but in a form that is appropriate for C++ programs. In particular, the names defined in the `cname` headers are defined inside the `std` namespace, whereas those defined in the `.h` versions are not.
>Ordinarily, C++ programs should use the `cname` versions of headers and not the `name.h` versions. That way names from the standard library are consistently found in the `std` namespace. Using the `.h` headers puts the burden on the programmer to remember which library names are inherited from C and which are unique to C++.

Table 3.3: `cctype` Functions

| Code          | Notes                                                        |
| ------------- | ------------------------------------------------------------ |
| `isalnum(c)`  | true if `c` is a letter or a digit.                          |
| `isalpha(c)`  | true if `c` is a letter.                                     |
| `iscntrl(c)`  | true if `c` is a control character.                          |
| `isdigit(c)`  | true if `c` is a digit.                                      |
| `isgraph(c)`  | true if `c` is not a space but is printable.                 |
| `islower(c)`  | true if `c` is a lowercase letter.                           |
| `isprint(c)`  | true if `c` is a printable character (i.e., a space or a character that has a visible  representation) |
| `ispunct(c)`  | true if `c` is a punctuation character (i.e., a character that is not a control character, a digit, a letter, or a printable whitespace). |
| `isspace(c)`  | true if `c` is whitespace (i.e., a space, tab, vertical tab, return, newline, or formfeed). |
| `isupper(c)`  | true if `c` is an uppercase letter.                          |
| `isxdigit(c)` | true if `c` is a hexadecimal digit.                          |
| `tolower(c)`  | If `c` is an uppercase letter, returns its lowercase equivalent; otherwise returns `c` unchanged. |
| `toupper(c)`  | If `c` is a lowercase letter, returns its uppercase equivalent; otherwise  returns `c` unchanged. |

#### Use Range-Based `for`

If we want to do something to every character in a `string`, by far the best approach is to use a statement introduced by the new standard: the **range for (范围 for)** statement. This statement iterates through the elements in a given sequence and performs some operation on each value in that sequence. The syntactic form is

```c++
for (declaration : expression)
	statement
```

where `expression` is an object of a type that represents a sequence, and `declaration` defines the variable that we’ll use to access the underlying elements in the sequence. On each iteration, the variable in `declaration` is initialized from the value of the next element in `expression`:

```c++
string str("some string");
// print the characters in str one character to a line
for (auto c : str)		// for every char in str
	cout << c << endl; 	// print the current character followed by a newline
```

If we want to change the value of the characters in a `string`, we must define the loop variable as a reference type. For example, if we want to convert a `string` to all uppercase letters:

```c++
string s("Hello World!!!");
// convert s to uppercase
for (auto &c : s) 	// for every char in s (note: c is a reference)
	c = toupper(c); // c is a reference, so the assignment changes the char in s
cout << s << endl;	// The output will be "HELLO WORLD!!!"
```

#### Processing Only Some Characters

There are two ways to access individual characters in a `string`: We can use a **subscript 下标** or an **iterator 迭代器**. 

The subscript operator (the `[]` operator) takes a `string::size_type` value that denotes the position of the character we want to access. The operator returns a **reference** to the character at the given position. (Subscripts for `string`s start at zero;)

The value in the subscript is referred to as “a subscript” or “an **index 索引**”. The index we supply can be any expression that yields an integral value. However, if our index has a signed type, its value will be converted to the unsigned type that `string::size_type` represents.

#### Using a Subscript for Iteration

As a another example, we’ll change the first word in `s` to all uppercase:

```c++
// process characters in s until we run out of characters or we hit a whitespace
for (decltype(s.size()) index = 0;
	 index != s.size() && !isspace(s[index]); ++index)
		s[index] = toupper(s[index]); // capitalize the current character
```

## 3.3 Library `vector` Type

A `vector` is a collection of objects, all of which have the same type. Every object in the collection has an associated index, which gives access to that object. A `vector` is often referred to as a **container 容器** because it “contains” other objects.

要使用 `vector`，需要包含的头文件：

```c++
#include <vector>
using std::vector;
```

C++语言既有类模板 (class template)，也有函数模板 (function template)，其中 `vector` 是一个类模板。**模板本身不是类或函数**，相反可以将模板看作为编译器生成类或函数编写的一份说明。编译器根据模板创建类或函数的过程称为实例化 (instantiation)，当使用模板时，需要指出编译器应把类或函数实例化成何种类型。

对于类模板，需要提供额外信息来指定模板实例化成什么样的类，而需要提供的额外信息由模板决定。提供的方式为：在模板名字后面跟一对尖括号，在括号内放入信息，如下所示。

```c++
class_template_name<additional_information> class_name
```

`vector` 能容纳绝大多数类型的对象 (In particular, we can have `vectors` whose elements are themselves `vectors`.) 作为其元素，但是因为引用不是对象，所以不存在包含引用的`vector`。

> Note：在早期版本的 C++ 标准中如果 `vector` 的元素还是 `vector` (或者其他模板类型)，则其定义的形式与现在的 C++11 标准略有不同。过去必须在外层 `vector` 对象的右尖括号和其元素类型之间添加一个空格，如应该写成 `vector<vector<int> >` 而非 `vector<vector<int>>`。

### 3.3.1 Defining and Initializing vectors

Table 3.4: Ways to Initialize a `vector`

| Code                         | Notes                                                        |
| ---------------------------- | ------------------------------------------------------------ |
| `vector<T> v1`               | `vector` that holds objects of type `T`. Default  initialization; `v1` is empty. |
| `vector<T> v2(v1)`           | `v2` has a copy of each element in `v1`.                     |
| `vector<T> v2 = v1`          | Equivalent to `v2(v1)`, `v2` is a copy of the elements in `v1`. |
| `vector<T> v3(n, val)`       | `v3` has `n` elements with value `val`.                      |
| `vector<T> v4(n)`            | `v4` has `n` copies of a value-initialized object.           |
| `vector<T> v5{a,b,c ...}`    | `v5` has as many elements as there are initializers; elements are  initialized by corresponding initializers. |
| `vector<T> v5 = {a,b,c ...}` | Equivalent to `v5{a,b,c ...}`                                |

When we copy a `vector`, each element in the new `vector` is a copy of the corresponding element in the original `vector`. The two `vectors` must be the same type:

```c++
vector<int> ivec; 			// initially empty
// give ivec some values
vector<int> ivec2(ivec); 	// copy elements of ivec into ivec2
vector<int> ivec3 = ivec; 	// copy elements of ivec into ivec3
vector<string> svec(ivec2); // error: svec holds strings, not ints
```

#### List Initializing a `vector`

列表初始化 `vector`，即用花括号 curly braces 括起来的 0 个或多个初始元素值赋给 `vector` 对象：

```c++
vector<string> articles = {"a", "an", "the"};
```

通常，四种初始化方法可以相互等价地使用：

```c++
int a = 0;		// assign			- copy initialization
int b(0);		// construct		- direct initialization
int c = {0};	// list initialize 	- copy initialization
int d{0};		// list initialize 	- direct initialization
```

目前的例外情况：

1. [Ref 3.2.1](#Direct and Copy Forms of Initialization) 拷贝初始化时，只能提供一个初始值；
2. [Ref 2.6.1](./CH2.md/#Class Data Members) class 类内初始值只能用拷贝初始化或花括号的形式，即不能用圆括号；
3. 若提供的是初值的列表（有很多个初值），则只能把初值都放在花括号里：

```c++
vector<string> v0{"a", "an", "the"}; 	// list initialization
vector<string> v1 = {"a", "an", "the"}; // list initialization
vector<string> v2("a", "an", "the"); 	// error
```

#### Creating a Specified Number of Elements

```c++
vector<int> ivec(10, -1); 		// ten int elements, each initialized to -1
vector<string> svec(10, "hi!"); // ten strings; each element is "hi!"
```

#### Value Initialization

We can usually omit the value and supply only a size. In this case the library creates a **value-initialized 值初始化的** element initializer for us. The value of the element initializer depends on the type of the elements stored in the vector.

If the `vector` holds elements of a built-in type, such as `int`, then the element initializer has a value of `0`. If the elements are of a class type, such as `string`, then the element initializer is itself default initialized 默认初始化:

```c++
vector<int> ivec(10); 		// ten elements, each initialized to 0
vector<string> svec(10); 	// ten elements, each an empty string
```

值初始化的限制：有些类显式要求提供初始值，即无法默认初始化，则使用值初始化就会报错。

区分是初始值还是元素数量：

1. 若使用圆括号，则认为值是用来构造 `vector` 对象的：

   ```c++
   vector<int> v1(10);		// v1 has 10 elements with value zero
   vector<int> v2(10, 1);	// v1 has 10 elements with value 1
   ```

2. 若使用花括号，当提供的值可以用来列表初始化时，可以表述为列表初始化该 `vector`：

   ```c++
   vector<int> v3{10};		// v3 has 3 elements with value 10
   vector<int> v4{10, 1};	// v4 has 3 elements with value 10 and 1
   ```

   

3. 若使用花括号，当提供的值不能用来列表初始化时，就考虑用该值来构造 `vector` 对象：

   ```c++
   vector<string> v5{"hi"}; 	// list initialization: v5 has 1 element
   vector<string> v6("hi"); 	// error: can’t construct a vector from a string literal
   vector<string> v7{10}; 		// v7 has 10 default-initialized elements
   vector<string> v8{10, "hi"};// v8 has 10 elements with value "hi"
   ```

### 3.3.2 Adding Elements to a `vector`

`vector` 的成员函数 `push_back` 可以将一个值「压」入 `vector` 的「尾部」：

```c++
vector<int> v2; 		// empty vector
for (int i = 0; i != 100; ++i)
	v2.push_back(i); 	// append sequential integers to v2
						// at end of loop, v2 has 100 elements, values 0 . . . 99
```

> Note: 通常，运行时向 vector 中添加元素是高效的（C++ 标准要求），提前定义 vector 的大小是没有必要甚至低效的；除非所有元素的值一样。一旦元素的值有所不同，更有效的方法是先定义一个空的 vector 对象，再往其中添加新的值。

### 3.3.3 Other `vector` Operations

Table 3.5: `vector` Operations

| Code                  | Notes                                                        |
| --------------------- | ------------------------------------------------------------ |
| `v.empty()`           | Returns `true` if `v` is empty; otherwise returns `false`.   |
| `v.size()`            | Returns the number of elements in `v`.                       |
| `v.push_back(t)`      | Adds an element with value `t` to end of `v`.                |
| `v[n]`                | Returns a reference to the element at position `n` in `v`.   |
| `v1 = v2`             | Replaces the elements in `v1` with a copy of the elements in `v2`. |
| `v1 = {a,b,c . . . }` | Replaces the elements in `v1` with a copy of the elements in the  comma-separated list. |
| `v1 == v2`            | `v1` and `v2` are equal if they have the same number of elements and each element in `v1` is equal to the corresponding element in `v2`. |
| `v1 != v2`            | See below.                                                   |
| `<, <=, >, >=`        | Have their normal meanings using dictionary ordering.        |

Note:

1. 要使用 `size_type`，需首先指定它是由哪种类型定义的。`vector` 对象的类型总是包含着元素的类型:

   ```c++
   vector<int>::size_type 	// ok
   vector::size_type 		// error
   ```

2. 只有当元素的值可以比较时，`vector` 对象才能被比较。如 `vector<string>` 可以被比较；`vector<Sales_item>` 不能被比较，因为没有定义比较的运算。

3. 不能用下标的形式向 `vector` 对象（以及 `string` 对象）添加元素：

   ```c++
   vector<int> ivec; // empty vector
   for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
   	ivec[ix] = ix; // disaster: ivec has no elements
   ```

   




## 3.4 Introducing Iterators

所有的标准库容器都可以使用**迭代器 iterator** 来访问其中的元素，但是只有少数几种标准容器支持下标运算。

类似于指针，迭代器提供了对对象的间接访问，能从一个位置移动到另一个位置，同时也有有效（指向某个元素或容器中尾元素的下一个位置）与无效（其他位置）之分。

### 3.4.1. Using Iterators

Types that have iterators have members that return iterators. In particular, these types have members named `begin` and `end`. 如果一个类型有迭代器，那么这个类型就会有「可以返回迭代器」的成员，比如 `begin` 和 `end`，其中 `begin` 返回指向第一个元素（或字符）的迭代器，`end` 指向尾元素的下一个位置，即一个不存在的位置，该迭代器通常被称为**尾后迭代器**或**尾迭代器**：

```c++
// the compiler determines the type of b and e;
// b denotes the first element and e denotes one past the last element in v
auto b = v.begin(), e = v.end(); // b and e have the same type
```

> Note：若容器为空，则 `begin` 和 `end` 返回都都是同一个尾后迭代器。

#### Iterator Operations

Table 3.6: Standard Container Iterator Operations

| Code            | Notes                                                        |
| --------------- | ------------------------------------------------------------ |
| `*iter`         | Returns a **reference** to the element denoted by the iterator `iter`. |
| `iter->mem`     | Dereferences `iter` and fetches the member named mem from the underlying element. Equivalent to (`*iter`).mem. |
| `++iter`        | Increments `iter` to refer to the next element in the container. |
| `--iter`        | Decrements `iter` to refer to the previous element in the container |
| `iter1==iter2`  | Compares two iterators for equality. Two iterators are equal if they denote the same element or if they are the off-the-end iterator for the same container. |
| `iter1!=iter2 ` | Compares two iterators for inequality.                       |

```c++
// Capitalize the first characte
string s("some string");
if (s.begin() != s.end()) { // make sure s is not empty
	auto it = s.begin(); // it denotes the first character in s
	*it = toupper(*it); // make that character uppercase
}
```

#### Moving Iterators

可以使用递增运算符 `++` 来将一个迭代器从一个元素移动到下一个元素：

```c++
// process characters in s until we run out of characters or we hit a whitespace
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
	*it = toupper(*it); // capitalize the current character
```

#### Iterator Types

标准库中使用两种类型：`iterator` 和 `const_iterator`，区别为前者可读写，后者只能读：

```c++
vector<int>::iterator it; 			// it can read and write vector<int> elements
string::iterator it2;				// it2 can read and write characters in a string
vector<int>::const_iterator it3;	// it3 can read but not write elements
string::const_iterator it4; 		// it4 can read but not write characters
```

通常来说，我们不需要关注迭代器的具体类型，使用 `auto` 即可。`begin` 和 `end` 返回的类型由对象是否是常量决定：

```c++
vector<int> v;
const vector<int> cv;
auto it1 = v.begin(); 	// it1 has type vector<int>::iterator
auto it2 = cv.begin(); 	// it2 has type vector<int>::const_iterator
```

若想指定使用常量的迭代器类型，则可以使用 `cbegin` 和 `cend`：

```c++
auto it3 = cv.cbegin()
```

#### Combining Dereference and Member Access and `->` operation

通过解引用操作符 `*` 可以获得迭代器所指的对象，若对象的类型是类，则访问其成员的方法如下：

```c++
(*it).member
```

其中括号不可省略，因为点运算的优先级高于解引用。为了简化，C++ 定义了箭头运算符 `->`，将解引用和成员访问结合在了一起：

```c++
```



## 3.5 Arrays

## 3.6 Multidimensional Arrays

##  Exercises

### Exercises Section 3.1

3.1 PASS

### Exercises Section 3.2.2

3.2 PASS

3.3 PASS

3.4 PASS

3.5

```powershell
> .\3.5
Hello, world!
HELLO, WORLD!
Hello, world!HELLO, WORLD!
Hello, world! HELLO, WORLD!
```

### Exercises Section 3.2.3

3.6

```powershell
> .\3.6
Original line : Hello
Line after modified : XXXXX
```

3.7

```powershell
Same as the previous.
```

3.8 PASS

3.9

```
Invalid. Because out-of-range subscript is undefined.
```

3.10

```powershell
> .\3.10
Please enter a line including characters and punctuations.
Hello, world!
After removing punctuation: Hello world
```

3.11

```
It depends on whether the c would be changed. If true, then ilegal. Otherwise legal. c has a type of const char&
```

### Exercises Section 3.3.1

3.12

```
(a) vector<vector<int>> ivec;		// ivec holds zero object type of vector<int>>
(b) vector<string> svec = ivec;			// ilegal
(c) vector<string> svec(10, "null");	// svec has 10 elements with value "null"
```

3.13

```
(a) vector<int> v1; 		// 0
(b) vector<int> v2(10);		// 10
(c) vector<int> v3(10, 42); // 10
(d) vector<int> v4{10};		// 1
(e) vector<int> v5{10, 42}; // 2
(f) vector<string> v6{10};	// 10
(g) vector<string> v7{10, "hi"};	// 10
```

### Exercises Section 3.3.2

3.14

```powershell
> .\3.14
1
3
5
-3
-1
0
^Z
135-3-10
```

3.15

```c++
> .\3.15
hello
,
world
!
^Z
hello,world!
```

### Exercises Section 3.3.3

3.16

```
v1 size :0
v2 size :10
v3 size :10
v4 size :1
v5 size :2
v6 size :10
v7 size :10
```

3.17

```
Read a sequence of words from cin and store the values a vector. After you’ve read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.
^Z
READ    A       SEQUENCE        OF      WORDS   FROM    CIN     AND
STORE   THE     VALUES  A       VECTOR. AFTER   YOU’VE READ
ALL     THE     WORDS,  PROCESS THE     VECTOR  AND     CHANGE
EACH    WORD    TO      UPPERCASE.      PRINT   THE     TRANSFORMED     ELEMENTS,
```

3.18

```c++
// Original code is ilegal.
// Fixed one is below:
vector<int> ivec;
ivec.push_back(42);

// Or we can do like:
vector<int> ivec{0};
ivec[0] = 42;
```

3.19

```c++
vector<int> v1(10, 42);	// way 1
vector<int> v1{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};	// way 2
vector<int> v1 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};	// way 3
```

3.20

```c++
```



### Exercises Section x.y.z

x.1

```powershell

```