# BoundCheckArray Template

Made a BoundCheckArray class template for int, 'Point', and 'Point' pointer types.

※ Beware of adding

     template <class T>
  
to all member functions from a class template, when you separate their definition from header file.
(For example, I divided 'BoundCheckArray.cpp' from 'BoundCheckArray.h' in this project.)
  
Moreover, if you DO have distinct .cpp file that contains the definition of member functions,
you must
  
      #include "BoundCheckArray.cpp"
  
include it to your main.cpp, or the compiler will think the information for class template is not enough.

A translation unit is the basic unit of compilation in C++,
and it consists of the contents of a single source file. (+(in)directly included header files)
Because of this, even if all files in a project are compiled simultaneously, the compiler does not refer other source files
while it compiles one.

Therefore, the compiler does not take a look at 'BoundCheckArray.cpp' that contains the definition of member functions from the class template, when compiling 'main.cpp' in the project.
By including the source file, the information of template will be given to the compiler, and then no further errors.
