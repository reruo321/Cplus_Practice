# NameCard Program

Deep Copy for constructor is applied.

## Shallow Copy & Deep Copy

Copy Constructor is automatically called and it copies all reference variables to object members, even if it is not defined by us.
This type of copy is called Shallow Copy, and it does not matter when all variables are not in the heap.

Then, what if some variables are in the heap? Let's look at these pictures.


We construct two objects in the program, 'manClerk' (Name: Lee) and 'manSenior'. (Name: Hong)
After that, we also makes two copies from the objects. 'copy1' is the copy of 'manClerk', and 'copy2' is the copy of 'manSenior'.

It seems there is no problem so far. Finally, it's time to destruct all these objects like Thanos!

![shallowcopy](https://user-images.githubusercontent.com/48712088/138698767-d35fba2c-229d-4658-bbf4-f69be98debd0.png)

Now, can you see what happened?

It's natural that after four objects are constructed, four destruction will be expected.
Unfortunally, half of them do not make it.


Let's see how members in 'manClerk' and 'copy1' objects refer their data, with this simple diagram.

![copy](https://user-images.githubusercontent.com/48712088/138708034-f6dbeff4-7d53-40f3-bbe6-4beb860338ba.png)

Shallow Copy LITERALLY COPIES the same as the original variables, but not the reference.

By the way, when we use Deep Copy, not only members but also pointer references (string literals such as "Lee", "ABCEng", "010-1111-2222") are copied.
Therefore, pointers in 'manClerk' and 'copy1' refer the different ones.

Now you can guess why "delete []string" in the destructor gets the error on the shallow case.

![delete](https://user-images.githubusercontent.com/48712088/138710882-48fb3b7c-89c9-4532-869e-d1046fa0fd6f.png)

When the first destruction for 'copy1' is performed, it deletes all string references.
Since the members in both objects shared the same references, pointers in the rest object 'manClerk' now have nothing to refer.
In this situation, the second destruction will cause the error on "delete []string", because it tries to delete inexistent strings.

However, by using Deep Copy, we can avoid this problem.
Even if the first destruction erases the references for 'copy1' object, the ones for 'manClerk' still remain.
Therefore, we can perform destructions safely in this case.

## Codes
In the program, the codes will look like these:

### Shallow Copy
NameCard::NameCard(const NameCard &copy)

: name(copy.name), company_name(copy.company_name), phone_number(copy.phone_number), comp_pos(copy.comp_pos)

{ }

### Deep Copy
NameCard::NameCard(const NameCard &copy)

: comp_pos(copy.comp_pos)

{

  name = new char[strlen(copy.name)+1];
  
  company_name = new char[strlen(copy.company_name)+1];
  
  phone_number = new char[strlen(copy.phone_number)+1];

  strcpy(name, copy.name);
  
  strcpy(company_name, copy.company_name);
  
  strcpy(phone_number, copy.phone_number);

}

## Deep Copy Result

![deepcopy](https://user-images.githubusercontent.com/48712088/138722484-3a72e383-ea54-434f-9892-deff297c7215.png)

Applying Deep Copy, we can enjoy the perfect destructions.
