# Casting

The program presents four casting operators in C++.

## Program Explanation

Class 'Animal' has its derived class, 'Pig'. They have polymorphic version, 'VirtualAnimal' and 'VirtualPig', which have a virtual member function.

Examples on C-Style Casting, Dynamic Casting, and Static Casting is to test three cases:

  1. Casts Base*-typed pointer that points derived object, to derived*-typed one.
  2. Casts Base*-typed pointer that points base object, to derived*-typed one.
  3. Casts Derived*-typed pointer that points derived object, to base*-typed one.

## ※ Old C-Style Casting

C-Style casting looks like this:

    Derived * dptr = (Derived *)base;
    
It is very powerful cast operator to change every type forcibly, but it may cause so serious problems that even compilers cannot catch the error.

![036ccasting](https://user-images.githubusercontent.com/48712088/141679517-41a7ade0-d642-4bc5-83c0-ac8ff7fce4ba.png)

The weight output in the second case results in garbage value.
The problems are:

  1. Even if it points to base-typed object, it tries to call member function in the derived class. (Logical Error)
  2. The base object being pointed has no member, 'weight'. Therefore, calling it will cause the garbage.

Additionally, the compiler also does not know whether the cast in the first case is deliberate or not.
This case can be programmer's intention, since the pointer was originally created to point to the derived object, and then was converted to the derived-typed pointer by his/her codes.
However, in the perspective of conversion process, if he/she created the pointer as a derived one at the beginning, casting would be unnecessary.
Because of this controversial situation, these new four operators are provided to use in C++; Dynamic Casting, Static Casting, Const Casting, and Reinterpret Casting.

