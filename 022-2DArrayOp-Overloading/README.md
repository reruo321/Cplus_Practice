# 2D Array Using Operator Overloading

The project shows operator overloading to call the values inside of 2D array.

## Challenge

In C++, it is impossible to overload the functions whose only difference is their return types.
The compiler finds two things when it calls the function; the name of the function, and parameter declaration.
Therefore, it is not able to distinguish one function from the other, and then overload,
because they have the same name and the same parameters.

For example, we can not overload these together:

      char myFunction (int x);
      int myFunction (int x);
      
Since the compiler does not know which one is to call for this:

      myFunction(10);
      
