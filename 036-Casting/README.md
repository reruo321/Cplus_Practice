# Casting

The program presents four casting operators in C++.

## Program Explanation

Class 'Animal' has its derived class, 'Pig'. They have polymorphic version, 'VirtualAnimal' and 'VirtualPig', which have at least one virtual member function.

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
However, in the perspective of conversion process, if he/she had created the pointer as a derived one at the beginning, casting would have been unnecessary.
Because of this controversial situation, these new four operators are provided to use in C++; Dynamic Casting, Static Casting, Const Casting, and Reinterpret Casting.

## 1. Dynamic Casting

Dynamic Casting only allows to convert derived-class-typed pointer or reference to base type.
The operator can be used as this form:

    dynamic_cast<TYPE>(expr)

![036dynamic](https://user-images.githubusercontent.com/48712088/141686882-8c2b06b5-6a78-4ba2-82d8-962b16b29862.png)

The first and the second casts are not possible because they try to change the types to base → derived.
By the way, there's a way to make them to work.

## 1-i. Dynamic Casting with Polymorphic Class

If the base class is polymorphic, in other words if it has one or more virtual functions, the base-typed pointer or reference data can be derived-typed.

![036dynamicpoly](https://user-images.githubusercontent.com/48712088/141687427-b4111095-6cfb-4c8e-8c0b-d590d55572c7.png)

The first conversion now becomes okay, but the second one makes the result pointer to be NULL.
After examining the outcomes from Static Casting, let me give more explanation for this.

## 2. Static Casting

Static Casting allows both base → derived and derived → base type conversions, but the programmer should be charge of the results.
The grammar for this cast is the same as the dynamic one.

    static_cast<TYPE>(expr)

![036static](https://user-images.githubusercontent.com/48712088/141688069-453e0a70-acd7-436e-893f-8157ceed0bfd.png)

With the programmer's carelessness, the second one produced the issue.

While casting a Dynamic one, the compiler creates binary code to check the safety during the program runtime, so it guarantees stable casts.
Meanwhile, Static Casting does not ensure the safety, but its execution speed is faster since it skips the safety examination.
