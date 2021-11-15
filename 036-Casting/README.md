# Casting

The program presents four casting operators in C++.

## Program Explanation

Class 'Animal' has its derived class, 'Pig'. They have polymorphic version, 'VirtualAnimal' and 'VirtualPig', which have at least one virtual member function.

Examples on C-Style Casting, Dynamic Casting, and Static Casting is to test three cases:

  1. Base*-type pointer (pointing a Derived object) ▶ Derived*-type pointer
  2. Base*-type pointer (pointing a Base object) ▶ Derived*-type pointer
  3. Derived*-type pointer (pointing a Derived object) ▶ Base*-type pointer

## ※ Old C-Style Casting

C-Style casting looks like this:

    Derived * dptr = (Derived *)base;
    
It is very powerful cast operator to change every type forcibly, but it may cause so serious problems that even compilers cannot catch.

![036ccasting](https://user-images.githubusercontent.com/48712088/141679517-41a7ade0-d642-4bc5-83c0-ac8ff7fce4ba.png)

The weight output in the second case results in garbage value.
The problems are:

  1. Even if it points to base-type object, it tries to call member function in the derived class. (Logical Error)
  2. The base object being pointed has no member, 'weight'. Therefore, calling it will cause the garbage.

Additionally, the compiler also does not know whether the cast in the first case is deliberate or not.
This case can be programmer's intention, since the pointer was originally created to point to the derived object, and then was converted to the derived-type pointer by his/her codes.
However, in the perspective of conversion process, if he/she had created the pointer as a derived one at the beginning, casting would have been unnecessary.
Because of this controversial situation, these new four operators are provided to use in C++; Dynamic Casting, Static Casting, Const Casting, and Reinterpret Casting.

## 1. Dynamic Casting

Dynamic Casting only allows to convert derived-class-type pointer or reference to base type.
The operator can be used as this form:

    dynamic_cast<TYPE>(expr)

![036dynamic](https://user-images.githubusercontent.com/48712088/141686882-8c2b06b5-6a78-4ba2-82d8-962b16b29862.png)

The first and the second casts are not possible because they try to change the types to base → derived.
By the way, there's a way to make them to work.

### 1-a. Dynamic Casting with Polymorphic Class

If the base class is polymorphic, in other words if it has one or more virtual functions, the base-type pointer or reference data can be derived-type.

![036dynamicpoly](https://user-images.githubusercontent.com/48712088/141687427-b4111095-6cfb-4c8e-8c0b-d590d55572c7.png)

The first conversion now becomes okay, but the second one makes the result pointer to be NULL.
Static Casting is similar, but they treat the safety issue in different ways. Let me give more explanation below.

## 2. Static Casting

Static Casting allows both base → derived and derived → base type conversions, but the programmer should be charge of the results.
The grammar for this cast is the same as the dynamic one.

    static_cast<TYPE>(expr)

![036static](https://user-images.githubusercontent.com/48712088/141688069-453e0a70-acd7-436e-893f-8157ceed0bfd.png)

With the programmer's carelessness, the second one produced the issue.

While casting as Dynamic, the compiler creates binary code to check the safety during the program runtime, so it guarantees stable casts.
Meanwhile, Static Casting does not ensure the safety, but it is faster since it skips the examination.
Thus, programmers can choose Static Casting for higher execution speed, even some cases where Dynamic one can be the option too.

### 2-a. Static Casting with C++ Basic Data Types

Static Casting can be also used to convert the data of C++ basic types.

![036staticdivision](https://user-images.githubusercontent.com/48712088/141691913-f9889269-dedd-4190-a917-b277da3061f7.png)

For example, if you want ( 20 / 3 ) to be a real number division, you need to convert 20 into double-type data.
Instead of doing

    double result = (double)20/3;
    
utilize the casting like this:
    
    double result = static_cast<double>(20)/3;
    
Static Casting is safer to use than C-type casting, because the latter can cause a bigger disaster, such as converting the value of const. (by using pointer and reference)

## 3. Const Casting

Const Casting is the operator that is able to remove the constant nature (or volatile nature) of pointer or reference temporarily.

    const_cast<TYPE>(expr)

It is useful when the const-type data needs to be passed to a non-const type function argument.

![036const](https://user-images.githubusercontent.com/48712088/141774239-7f61c495-eb8d-4c52-b114-b184e66add66.png)

The compiler makes the error if const-type char or int tries to be an argument of void ShowConstData(char * str, int &i, int &ii).
Putting it with const_cast would solve this problem.

## 4. Reinterpret Casting

Reinterpret Casting converts a pointer to any other types of pointer, no matter the what the relations of the types or classes are. It can also change the types between int ↔ pointer.

    reinterpret_cast<TYPE>(expr)

![036reinterpret](https://user-images.githubusercontent.com/48712088/141793852-38f1c400-2cfe-4602-87b8-a18e37193329.png)

This is the second most dangerous cast, but it is useful in some special conditions
when receiving data as a pointer in the packet telecommunication, or interfacing with opaque data types.
