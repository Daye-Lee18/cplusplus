# Others 

## new, delete: Dynamic memory 

### functions 

- operator new <-> operator delete 
- operator new[] <-> operator delete[] 

```c++

//operator new[] example 

#include <iostream>
#include <new>

struct MyClass{
    int data;
    MyClass(){std::cout << '*';} // print an asterisk for each construction 
};

int main(){
    std::cout << "constructions (1): ";
    //allocates and constructs five objects
    MyClass * p1 = new MyClass[5];
    std::cout << '\n';

    // allocates and constructs five objects (nothrow):
    MyClass * p2 = new (std::nothrow) MyClass[5];
    std::cout << '\n';

    delete[] p2;
    delete[] p1;

    return 0;
}// output 
//constructions (1): *****
//constructions (2): *****

```

### Constants 
- nothrow : used as an argument for operator_new and new[] 
  - to indicate that these functions shall not throw an exception on failure (bad_alloc exception), but return a **null pointer** instead 
  
```c++
// nothrow example
#include <iostream>     // std::cout
#include <new>          // std::nothrow

int main () {
  std::cout << "Attempting to allocate 1 MiB... ";
  char* p = new (std::nothrow) char [1048576];

  if (!p) {             // null pointers are implicitly converted to false
    std::cout << "Failed!\n";
  }
  else {
    std::cout << "Succeeded!\n";
    delete[] p;
  }

  return 0;
}
```

### Types 

- bad_alloc: type of the exceptions thrown by the standard definitions of operator new and new[] when they fail to allocate the requested storage space 

```c++
//bac_alloc example 
#include <iostream>
#include <new>

int main(){
    try {
        int* myarray = new int[10000];
    }
    catch (std::bac_alloc& ba){
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    return 0; 
}

```

## String 

### Functions 

- stoi : string to integer 
  - string::stoi(string, index, base = 10)
    - index : Pointer to an object of type size_t, whose value is set by the function to position of the next character in str after the numerical value.
This parameter can also be a null pointer, in which case it is not used.
        -  아래 예시를 보면, stoi에서 sz가 그역할을 하고 있는데 sz에는 int 수 다음인 ", A Space Odyseey"가 저장되어 있다. 
 - substr:
   - returns a newly constructed string object with its value initialized to a copy of a substring of this object 
   - substr(int pos, int len)
 - length:
   - returns the length of the string, in terms of **bytes** 

```c++
// stoi example
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi

int main ()
{
  std::string str_dec = "2001, A Space Odyssey";
  std::string str_hex = "40c3";
  std::string str_bin = "-10010110001";
  std::string str_auto = "0x7f";

  std::string::size_type sz;   // alias of size_t

  int i_dec = std::stoi (str_dec,&sz);
  int i_hex = std::stoi (str_hex,nullptr,16);
  int i_bin = std::stoi (str_bin,nullptr,2);
  int i_auto = std::stoi (str_auto,nullptr,0);

  std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
  std::cout << str_hex << ": " << i_hex << '\n';
  std::cout << str_bin << ": " << i_bin << '\n';
  std::cout << str_auto << ": " << i_auto << '\n';

  return 0;
}
// output 
// 2001, A Space Odyssey: 2001 and [, A Space Odyssey]
// 40c3:  16579
// -10010110001: -1201
// 0x7f: 127

```

```c++
//string::substr 
#include <iostream>
#include <string>

int main(){
    std::string str ="We think in generalities, but we live in details.";

    std::string str2 = str.substr(3, 5); //"think"
    std::string str3 = str.find("live"); // position of "live" in str 
    
    std::cout << str2 << ' ' << str3 < '\n';
    return 0;
}
//output think live in details 
```

```c++
//string::length 
#include <vector>
#include <cout>

int main(){

    std::string str ("Test string");
    std::cout << "The size of str is " << str.length() << " bytes. \n"; 
    return 0;
}//output The size of str is 11 bytes 
```