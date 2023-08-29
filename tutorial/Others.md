# Others 

## Compare 함수 

- example 
  ```c++ 
  vector<int> v(10, 10); //10개, 10으로 initialization 

  bool compare(int i , int j) {return i > j;}

  sort(v.begin(), v.end(), compare);
  ```
- 위의 예시와 같이, compare 함수를 만들고 인자로 넣어줄때는 ()를 제거하고 넣어준다. 
- Binary function that accepts two elements in the range as arguments, and **returns a value convertible to bool** (따라서, 0과 1을 반환하는 함수도 가능). The value returned indicates whether **the element passed as first argument is considered to go before the second** in the specific strict weak ordering it defines.
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.

## Sort 

- example 
  ```c++ 
  // sort algorithm example
  #include <iostream>     // std::cout
  #include <algorithm>    // std::sort
  #include <vector>       // std::vector

  bool myfunction (int i,int j) { return (i<j); }

  struct myclass {
    bool operator() (int i,int j) { return (i<j);}
  } myobject;

  int main () {
    int myints[] = {32,71,12,45,26,80,53,33};
    std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

    // using default comparison (operator <):
    std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

    // using function as comp
    std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

    // using object as comp
    std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

    // print out content:
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
  }
  ```

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

## auto  와 lamdba function 

- auto:
  - 컴파일러에게 변수 선언문으로부터 변수의 타입을 추론하여 결정하도록 지시 
  ```c++

  #include <vector>
  #include <iostream>
  using namespace std;

  auto pi = 3.14 //pi는 complier에 의해 double 타입으로 결정됨

  vector<int> v = {1, 2, 3, 4, 5};
  //vector<int>::iterator it;
  //for (it = v.begin(); it != v.end(); it++){
  //  cout << *it << endl;
  //}

  for (auto it = v.begin(); it != v.end(); it++){
    cout << *it << endl;
  }
  ```

- lamdba 
  - 람다는 이름없는 함수 (anonymous function) 로 람다식, 람다 함수라고 불림. 
  - when to use 
    - 한 번만 호출하고 재사용하지 않기 때문에 함수에 이름을 붙일 필요가 없는 경우 
    - STL 알고리즘 함수의 배개 변수에 연산 코드를 넘기는 경우 ,연산 코드를 익명의 람다식으로 작성 
  - [capture clause] (parameters) -> return-type {definition of method}
    - capture clause 
      - 람다식 외부에 선언된 변수 (지역 변수, 전역변수 목록)을 람다식에서 사용하고자 할 때 나열 
      - .[x] : x변수의 값 활용 
      - [&x] : 참조 변수 x 활용 
      - [=] : 모든 변수의 값 활용 
      - [&] : 모든 참조 변수 활용  
    - return type 생략 가능 
    - 

  ```c++
  // 람다식 선언 예시 

  [](int x, int y) {cout << x+ y;}; // 매개 변수 x, y의 합을 출력하는 람다 작성 
  [](int x, int y) -> int {cout << x+ y;}; // 매개 변수 x, y의 합을 출력하는 람다 작성 
  [](int x, int y) -> int {cout << x+ y;} (2,3); // x에 2, y에 3을 대입하여 코드 실행, 5가 출력됨
  ```
  ```c++ 
  
  [] (int x, int y) {
    cout << "합은 " << x + y;
  } (2,3);

  // output 5 
  
  ```

- auto로 람다식 저장 및 호출 
  - 람다식의 형식은 컴파일러에만 알려져 있어서, 람다식을 저장하는 변수를 직접 선언할 수는 없고 
  - auto을 이용한다. 

```c++
#include <iostream>
#include <string>
using namespace std;

int main(){
  auto love = [](string a, string b){
    cout << a << "보다" << b << "가 좋아" << endl ;
    };

    love("돈", "너"); //람다식 호출, "돈보다 너가 좋아" 

}

```

## pair, make_pair 

- 오직 두개의 원소를 넣을 수 있음 
- #include <utility> 의 std::pair의 타입을 가짐 
- first, second로 element를 access할 수 있음 

```c++
// make_pair example
#include <utility>      // std::pair
#include <iostream>     // std::cout

int main () {
  std::pair <int,int> foo;
  std::pair <int,int> bar;

  foo = std::make_pair (10,20);
  bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

  std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

  return 0;
}

```