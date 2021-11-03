# Book Deep Copy

Deep Copy solution for copy constructor and operator=.

Since the class 'EBook' is derived from 'Book' class, we can call operator= from 'Book' for 'EBook' operator=.

Putting the 'EBook' reference to copy as an argument of 'Book' operator= in 'EBook' operator= is allowed,
because 'Book'-typed reference can refer 'Book' objects themselves or all 'Book'-derived objects.

     class EBook: public Book{
          ...
      EBook &operator=(const EBook &ref){
        Book::operator=(ref);     // 'EBook'-typed reference 'ref' as an argument of 'Book' operator=
          ...
       }
    }
