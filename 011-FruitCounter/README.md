# Fruit Counter

This project is made to practice how to use Inheritance and Virtual Function myself.

## Classes

![011classes](https://user-images.githubusercontent.com/48712088/139434850-a852323a-393c-4c0b-b762-8fc3fb19ec9e.png)

## Pointers

![011pointers](https://user-images.githubusercontent.com/48712088/139434872-62e648d7-13f5-4dba-991b-4d5fdf27a89d.png)

## Overriding

In this program, GetPrice() and ShowInfo() need to work distinctly for each classes.
For example, ShowInfo() basically shows country of origin, number of fruits, and price.
However, we want to make this function to notify radius of fruits for orange, and number of box for gyul additionally.
Meanwhile, the same function should display sugar content only for mango.
Should we design different functions for each class to realize all those things? Or should we use overloading?

Thankfully, functions in derived classes in C++ are allowed to have the same name and type 
but also different contents with ones in the base.
Moreover, if there are duplicated functions both in base and derived classes,
the function in derived class overrides the base one.
For instance, both base class 'A' and its derived class 'B' have the same function 'void Say()'.
The function prints "Hello." in A, and "Bye." in B.
If we call Say() in class B, only "Bye." will be popped up, since Say() in B overrided the same function in A.

## Virtual Function

Okay, now utilizing overriding concept, we made GetPrice() and ShowInfo() suitably for each class.
However, when we try to call the functions in FruitCounter, it does not work properly. Why?

In the program, Fruit-type pointer in FruitCounter class tries to call these functions from derived classes like this:

    class FruitCounter {
      Fruit** fruitList = new Fruit*[100];

      ...
      
      public:
      void GetTotalPrice() const {
        int sum = 0;
        for (int i = 0; i < itemNum; i++)
          sum += fruitList[i]->GetPrice();
        cout << "과일 총 가격: " << sum << endl;
      }

      void ShowAllFruitInfo() const {
        for (int i = 0; i < itemNum; i++)
          fruitList[i]->ShowInfo();
      }

    };

![011notvirtual](https://user-images.githubusercontent.com/48712088/139441885-0ddf44f4-ae35-4cbf-9501-f7ddc7707f19.png)

Even if the Fruit-type pointer points 

Two functions, int GetPrice() and void ShowInfo() in 'Fruit' and its derived classes, are virtual.
