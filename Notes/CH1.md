# Getting Started

A **type** defines both the contents of a data element and the operations that are possible on those data. When the type of a variable named v is T, we often say that “v has type T” or, interchangeably, that “v is a T.”

iostream:

- Standard Input : cin
- Standard Output : cout
- Standard Error : cerr
- Standard Log : clog

**Writing to a Stream**

output operator `<<` returns its left-hand operand.

operator `endl` is a special value called a manipulator, Writing `endl `has the effect of ending the current line and flushing the buffer associated with that device.  Flushing the buffer ensures that all the output the program has generated so far is actually written to the output stream, rather than sitting in memory waiting to be written.  

scope operator `::` indicates the name is defined in a particular namespace (library).

**Reading from a Stream**

Initialize a variable = give it the indicated value at the same time as the variable is created.

the input operator `>>` returns its left-hand operand as its result.  

**Control Flow**

When we use an `istream` as a condition, the input operator (§ 1.2, p. 8) returns its left operand, which in this case is `std::cin`. Therefore, condition tests `std::cin`.  the effect is to test the state of the stream. If the stream is valid—that is, if the stream hasn’t encountered an error—then the test succeeds. An `istream` becomes invalid when we hit `end-of-file` or encounter an invalid input, such as reading a value that is not an integer. An `istream` that is in an invalid state will cause the condition to yield false.  

