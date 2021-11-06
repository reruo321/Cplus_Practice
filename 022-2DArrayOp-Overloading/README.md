# 2D Array Using Operator Overloading

The project shows operator overloading to call the values inside of 2D array.

## Challenge

It's impossible to overload the functions with the same name and the same parameters, but different return types.
The compiler is not able to distinguish one from the other.

For example, we can not overload these together:

      char myFunction (int x);
      int myFunction (int x);
      
Since the compiler does not know which one is to call in this case:

      myFunction(10);
      
