```c++ 
#include <iostream>
using namespace std;

int main ()
{
  int firstvalue = 5, secondvalue = 15;
  int * p1, * p2;

  p1 = &firstvalue;  // p1 = address of firstvalue
  p2 = &secondvalue; // p2 = address of secondvalue
  *p1 = 10;          // value pointed to by p1 = 10
  *p2 = *p1;         // value pointed to by p2 = value pointed to by p1
  
  cout << p1 << " " << p2 << '\n';
  
  p1 = p2;           // p1 = p2 (value of pointer is copied) p2의 address가 p1에게 전달되어 p1도 p2의 adress를 가리키는 pointer가 됨. 
  
  cout << p1 << " " << p2 << '\n';
  cout << *p1 << " " << *p2;
  *p1 = 20;          // value pointed to by p1 = 20
  
  cout << "firstvalue is " << firstvalue << '\n';
  cout << "secondvalue is " << secondvalue << '\n';
  return 0;
}
// 0x7ffd5e5a6ebc 0x7ffd5e5a6eb8
// 0x7ffd5e5a6eb8 0x7ffd5e5a6eb8
// 10 10firstvalue is 10
// secondvalue is 20
```
