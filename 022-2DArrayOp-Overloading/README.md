# 2D Array Using Operator Overloading

The project shows operator overloading to call the values inside of 2D array.

## Challenge

In the project, by using operator overloading, data saving and pointing to 2D array, arr2d[n][m], should work.
However, we can not overload two operator [ ] at the same time. (No "operator[ ][ ]".)

For that reason, we should make the compiler interpret this:

      arr2d[n][m];
      
Like:

      (arr2d.operator[](n))[m];

And then:

      (('RETURN_VALUE').operator[])(m);

Oh, now you might think you should overload several operator[ ]s to get different return types, but there is another problem.

In C++, it is impossible to overload the functions whose only difference is their return types.
The compiler finds two things when it calls the function; the name of the function, and parameter declaration.
Therefore, it is not able to distinguish one function from the other, and then overload,
if they have the same name and the same parameters, no matter what they return.

For example, we can not overload these together:

      char myFunction (int x);
      int myFunction (int x);
      
Since the compiler does not know which one is to call for this:

      myFunction(10);

Hence, we have to find other ways to make it...

## My Solution

There will be various answers for the problem. I suggest a simple solution mainly using inheritance.

![022classes](https://user-images.githubusercontent.com/48712088/140599260-a8b12df5-758b-4bd7-9165-75017d2979ae.png)

I set 'BoundCheck2DIntArray' as a derived class from the base, 'RowArray'.
The base class has these variables: int row, int col, int ptr.
'row' contains the number of rows in the 2D array, 'col' of columns, and 'ptr' is the array for int data.

Meanwhile, 'BoundCheck2DIntArray' additionally has 'arr', which is the array for 'RowArray' objects.

The constructor of 'BoundCheck2DIntArray' makes 'arr' to take 'RowArray' 'row' times,
and each 'RowArray' gets 'ptr' with 'col' integers by RowArray(int x, int y).

Look at these codes again step by step:

      (arr2d.operator[](n))[m];
      
Because 'arr2d' is 'BoundCheck2DIntArray'-typed object, it will call operator[ ] from 'BoundCheck2DIntArray' class.
Let's make the return type of this operator 'RowArray'.

      (('RETURN_VALUE').operator[])(m);
      
Now, as you can see, 'RETURN_VALUE' is 'RowArray' object. In this time, it will call the operator from 'RowArray' class.
If you allow it to return int type, the 2D array will finally call its int values.
Oh, of course, do not forget to check the validity of input row and column arguements!

You can see the detail in the [BoundCheck2DIntArray.h](https://github.com/reruo321/Cplus_Practice/blob/main/022-2DArrayOp-Overloading/BoundCheck2DIntArray.h) file.
