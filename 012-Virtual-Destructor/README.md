# Virtual Destructor

This example shows the importance of virtual destructor.

I made two groups for classes, 'Dog(base)-Poodle(derived)', and 'Dessert(base)-Pudding(derived)'.
All four classes print different lines when they are constructed or destructed. The messages are like these:

A. Dog: "Bark Bark!" (constructor), "Bye-Bye Dog~" (destructor)

a. Poodle: "I am Poodle." (constructor), "See Ya Poodle ~ ~ ~" (destructor)

B. Dessert: "Sweety Dessert!" (constructor), "Yummy Dessert~" (destructor)

b. Pudding: "Boing-Boing Pudding!" (constructor), "Tasty Pudding ~ ~ ~" (destructor)

Exclusive of the addition of 'virtual' in front of 'Dessert' destructor, two groups have the same structure.
Now, let's generate and delete a base-typed pointer that points the derived object, for each group like this:

    Dog * dog = new Poodle("a", "b");
    delete dog;
    Dessert * dessert = new Pudding("a", "b");
    delete dessert;
    
The result then looks like this picture:

![virtualdestructor](https://user-images.githubusercontent.com/48712088/139532987-a5a15c03-7f5b-410c-8fbb-4a03fa154c9c.png)

Everything went right, except the destructor for 'Poodle' was not called, which leads to memory leakage. Why this happened?

As we examined in the previous example, in C++, a "ABC"-typed pointer can point all objects including "ABC" objects,
or other objects derived from "ABC".
Meanwhile, when the compiler checks the possibility to pointer type operation, it investigates the type of pointer,
not the type of the object that is actually pointed to.
Therefore, in this example, 'Dog'-typed pointer can point to 'Poodle'-typed object,
but can not access the members in 'Poodle', including its destructor.

Since the concept of virtual function is also applied to destructor or reference, we can solve this problem by
adding 'virtual' in front of the destructor in the base class, like the one in the class 'Dessert':

    virtual ~Dessert(){ ... }
