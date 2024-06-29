
#include <iostream>
using namespace std;
int main()
{
  char str[40];
  int m1, m2, m3, avg;

  cout << "Enter your name: ";
  cin >> str;
  cout << "MArks: ";

  cin >> m1 >> m2 >> m3;
  avg = (m1 + m2 + m3) / 3;

  cout << str << ":" << avg;
}
// endl manipulator "\n" but using endl is cleaner
// function prototypes is the declartion of the function
float square(int);
char *strconvert(char *int);

#include <iostream>
#include <string>
using namespace std;

int main()
{
  char str[] = "hell";
  strupr(str); // to convert to upper case
  cout << str;
}

int main()
{
  int f;
  cin >> f;
  int c = (f - 32) * 5 / 9;
  cout << c;

  for (int j = 10; j <= 100; j++)
    cout << j << endl;
}

struct employee
{
  int age;
  char name[20];
};
int main()
{
  employee e;        // does not need the use of keyword like struct union or enum unlike c
  e.name = "prince"; // structures can have functions as well
  e.age = 43;
  cout << sizeof(e); //
  // anonymous enums and unions
  union
  {
    int i;
    char name[20];
  };
  i = 10;

  enum enum1
  {
    first,
    second
  };
  int t = enum1::second;

  // type casting
}

int main()
{
  int y = 1002;
  int j = 365;
  int n;

  // n = (y - 1) * j; // out of range;
  // cout << n;
  // fix this
  n = (y - 1) * (long)j; // c style
  n = (y - 1) * long(j); // cpp style
  cout << n;
  s
}

// void pointers

int a = 90;
int main()
{
  void *p;
  char *s;
  p = s; // fine
  // s = p; // error<< void ko char is fien but char ko void si not fine
  // gotta type cast first
  s = (char *)p;

  //:: scope resolution operator
  // local or global scopes

  int a = 15;
  cout << "\nLocal a =" << a << "global a= " << ::a;
  ::a = 43;
  cout << "\nGlobal a= " << ::a;
}

// references

// like pointers

int main()
{
  int i = 10;
  int &j = i;
  cout << "i= " << i << " j= " << j << endl;
  j = 20;
  cout << "i= " << i << " j= " << j << endl;
  i = 30;

  cout << "i= " << i << " j= " << j << endl;

  cout << "address of i :" << &i << " address of j: " << &j << endl;
}
// reference is like a alias it refers to teh same entity
// rules
//  references must be always initalized
//  reference can only be made to point at one var cannot be changed later
//  multiple references can be made to a single variable
//  array of references is unacceptable

void swapv(int, int);
void swapr(int &, int &);
void swapa(int *, int *);

int main()
{
  int a = 10, b = 20;

  swapv(a, b); // 10 20
  cout << a << " " << b << endl;
  swapr(a, b); // 20 10
  cout << a << " " << b << endl;
  swapa(&a, &b);                 // addressese here
  cout << a << " " << b << endl; // 10 20
}

void swapv(int i, int j)
{
  int temp = i;
  i = j;
  j = temp;
}

void swapa(int *i, int *j)
{
  int t;
  t = *i;
  *i = *j;
  *j = t;
}

void swapr(int &i, int &j)
{
  int k;
  k = i;
  i = j;
  j = k;
}

#include <iostream>
#include <string>

using namespace std;
struct employee
{
  char name[30];
  int age;
  float salary;
};
int main()
{
  void modify_c(employee *);
  void modify_cpp(employee &);

  employee e1 = {"sanjay", 32, 3200.00};
  employee e2 = {"sammer", 28, 1950.00};
}

void modify_c(employee *e)
{
  strcpy(e->name, "santosh");
  e->age = 31;
  e->salary = 3970;
}

void modify_cpp(employee &e)
{
  strcpy(e.name, "sanket");
  e.age = 31;
  e.salary = 2500;
}

// returning by reference /
#include <iostream>
using namespace std;

struct emp
{
  char name[20];
  int age;
  float sal;
};

emp e1 = {"anmol", 21, 2345.00};
emp e2 = {"ajay", 23, 4500.75};

int main()
{
  emp &fun();
  fun() = e2;
  cout << e1.name << endl; // e1 gets assigned a value of e2
}
emp &fun()
{
  cout << endl
       << e1.name << endl
       << e1.age << endl;
  return e1;
}

// const used for fixed vars
#include <iostream>
using namespace std;

int main1()
{
  float r, a;
  const float PI = 3.14; // better than define because of scope problems

  cin >> r;
  a = PI * r * r;
  cout << endl
       << "area of circle is: " << a;
}

// const pointers pointers to object is constant the object itself is not constant
void xstrcpy(char *, char *);

int main()
{
  char str1[] = "Nagpur";
  char str2[10];

  xstrcpy(str2, str1);
  cout << endl
       << str2;
  cout << endl
       << str1; // the actual can be modififed how can we prevent thso
}

void xstrcpy(char *t, char *s)
{
  while (*s != '\0')
  {
    *t = *s;
    t++;
    s++;
  } // copies str1 to str2
  s = s - 3;
  *s = 'K';
  *t = '\0';
}

char *p = "hello"; // gives warning string to char *t
*p = 'M';
p = "Bye";

const char *q = "Hello"; // string fixed pointer is not
*q = 'M';                // error
q = "Bye";               // works can change pointer but not the value

char const *s = "Hello"; // string fazed pointer ont
*s = 'M';                /// error

char *const t = "Hello";      // pointer fixed ;
const char *const e = "hell"; // both fixed

// const refrences
#include <iostream>
using namespace std;
int main()
{
  void change(const int &);
  int i = 32;
  change(i);
  cout << endl
       << i;

  const char *fun();
  const char *p;
  p = fun(); // cannot assign constant to non constant variable
  *p = 'a';  // error we cannot const string with a pointer
}
void change(const int &j)
{
  j = 45; // cannot modify a const object
  // once declared as constant we cannot change the value of variable using refrence

  // returning const values
}

const char *fun()
{
  return "rain";
}

// boolean data type

// *
// *

// *
// *

// *
// *

// *
// *

// *
// *

// *
// *
// unit 3 functions
// *
// *

// function protoype double fool(float, int); strong type checking
// declartion and exectuion must match int value cannot be given to a float declration
double add(int a, int b)
{
  return a + b;
}

// function overloading
int abs(int);
long abs(long);
double abs(double);
// they can have their declartions here
// the compiler decides which function to call depending on the types
itoa(c);
ltoa(c);
// differentiate the fucntions on the input parameters and no of parrametes not on return type
// possibly let them have similar functions

#include <bits/stdc++.h>
void newprintf(int, int, int, long, char *);
void newprintf(int, int, int, double, char *);
void newprintf(int, int, int, char *, char *);
void writechar(char, int, int, char);

int main()
{
  int i = 22, j = 22222;
  long int l = 777777;
  float f = 0.77777;
  double d = 7777.5678;

  static char str[30] = "John O hara! O hara!";

  newprintf(14, 30, 112, (long)i, "999.99");
  newprintf(15, 30, 12, (long)j, "999");
  newprintf(18, 30, 112, l, "99.9");
}

void newprintf(int r, int c, int attr, long val, char *format)
{
  char *int_ptr, temp[20];
  int len, i, j, ltemp;

  len = strlen(format);
  itoa(val, temp, 10);

  itemp = strlen(temp);
  int_ptr = temp;
  c += len;
  int_ptr = temp + ltemp - 1;
  format = format + len - 1;

  for (i = 0; i < n; i++)
  {
    if (isdigit(*int_ptr))
    {
      if (*format == '.')
      {
        writechar(",", r, c, attr);
      }
    }
  }
}

// /d/define other fucntions simiilary
// default arguments in functions

// function receives arguments whose values are fixed
void box(int sr = 1; int sc = 3; int er = 4; int ext = 80); // we start from the right side while we are s
// assigngig these vars

// operator overloading
#include < iostream>
using namespace std;
struct complex
{
  double real, imag;
};
complex complex_set(double r, double i);
complex complex_add(complex, complex);
void complex_print(complex c);
complex operator+(complex c1, complex c2);
complex operator-(complex c1, complex c2);

int main()
{
  complex a, b, c;

  a = complex_set(1.0, 2.0);
  b = complex_set(3.0, 4.0);
  c = complex_set(a, b);
  cout << "c=";
  complex_print(c);
}

complex complex_set(double r, double i)
{
  complex temp;
  temp.real = r;
  temp.imag = i;
  return temp;
}

complex complex_print(complex t)
{
  cout << "(" << t.real << "," << t.imag << ")";
}
complex complex_add(complex a, complex b)
{
  complex temp;
  temp.real = a.real + b.real;
  temp.imag = a.imag + b.imag;
}

complex operator+(complex a, complex b)
{
  complex temp;
  temp.real = c1.real + c2.real;
  temp.imag = c2.imag + c2.imag;
  return temp;
}

complex operator-(complex a, complex b)
{
  complex temp;
  temp.imag = c1.imag - c2.imag;
  temp.real = c1.real - c2.real;
  return temp;
}

#include <iostream>
#include <iomanip>

using namespace std;
const int MAXROW = 3, MAXCOL = 3;
struct matrix
{
  int arr[MAXROW][MAXCOL];
};

matrix operator+(matrix a, matrix b);
matrix operator-(matrix a, matrix b);
matrix operator*(matrix a, matrix b);
void print_matrix(matrix p);

int main()
{
  matrix a = {
      1, 2, 3,
      4, 5, 6,
      7, 8, 9};
  matrix b = {
      1, 2, 3, 4, 5, 6, 7, 8, 9};
  matrix c = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  matrix d, e, f;
  d = a + b;
  e = a - b;
  f = a * b;
  print_matrix(d);
  print_matrix(e);
  print_matrix(f);
}

matrix operator+(matrix a, matrix b)
{
  matrix c;
  int i, j;
  for (i = 0; i < MAXROW; i++)
  {

    for (j = 0; j < MAXCOL; j++)
    {
      c.arr[i][j] = a.arr[i][j] + b.arr[i][j];
    }
  }

  return c;
}
matrix operator-(matrix a, matrix b)
{
  matrix c;
  int i, j;
  for (i = 0; i < MAXROW; i++)
  {
    for (j = 0; j < MAXCOL; j++)
    {
      c.arr[i][j] = a.arr[i][j] - b.arr[i][j];
    }
  }
  return c;
}

matrix operator*(matrix a, matrix b)
{
  matrix c;
  int i, j;
  int k;

  for (i = 0; i < MAXROW; i++)
  {
    for (int j = 0; j < MAXCOL; j++)
    {

      c.arr[i][j] = 0; // intatilaise every element as zero
      for (k = 0; k < MAXCOL; k++)
      {
        c.arr[i][j] += a.arr[i][k] * b.arr[k][j];
      }
    }
  }
  return c;
}

void print_matrix(matrix p)
{
  int i, j;

  cout << endl
       << endl;

  for (i = 0; i < MAXROW; i++)
  {
    cout << endl;
    for (j = 0; j < MAXCOL; j++)
    {
      cout << setw(5) << p.arr[i][j] << " ";
    }
  }
}

// setw is a manipulator iomanip.h  operators tha cannot be oveloaded
// . : ::  ?

// inline functions
// save space when we call an inline function the code is replaced at eh fuctions place instead of calling the function

#include <iostream>
#include <fstream>
using namespace std;

inline void reporterror(string str)
{
  cout << endl
       << str;
  return;
}

int main()
{
  // open file ffstream
  fstream file;
  auto fileptr = file.open("new_txt"); // char * to stirng si forbidden
  if (!fileptr)
  {
    reporterror("Unable to pen source file ");
  }
}
#include <iostream>
using namespace std;

#define SQUARE(s) s *s

inline float square(float x)
{
  return x * x;
}

int main()
{
  float a = 0.4, b = 0.5, c, d;
  c = SQUARE(++a); // 1.4  * 1.4
  d = square(++d);
  cout << c << endl;
  cout << d; // what the hell is inf
}
// staic friend and virtual functions

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

// classses and objects

// the only differece btw structure and class comes from the access modifiers

#include <iostream>
using namespace std;

class rectangle
{
private:
  int len, br;

public:
  void getData()
  {
    cout << "DATA: ";
    cin >> len >> br;
  }

  void setData(int l, int b)
  {
    len = l;
    br = b;
  }

  void displayData()
  {
    cout << "length: " << len << endl;
    cout << "br: " << br << endl;
  }

  void area_peri()
  {
    int a, p;
    a = len * br;
    p = 2 * (len + br);
    cout << "area: " << a << endl;
    cout << "perimeter: " << p;
  }
};
int main()
{
  rectangle r1, r2;
  r1.setData(10, 20);
  r1.displayData();
  r1.area_peri();
}

// data hiding public private vars
// default is private

// constructors
// default constructor define if other constructor are defined

#include <iostream>
using namespace std;

class integer
{
private:
  int i;

public:
  void getData()
  {
    cout << "Integer:  " << endl;
    cin >> i;
  }

  void setData(int i)
  {
    i = j;
  }

  integer()
  {
  }
  integer(int j)
  {
    i = j;
  }

  void display_data()
  {
    cout << "value of i: " << i;
  }
};
// write rest too boring

// destructors to delete the class called at desstruction

#include <iostream>
using namespace std;

class exp
{
private:
  int data;

public:
  example()
  {
    cout << "default cons" << endl;
  }

  ~example() // main function is destruction of memory
  {
    cout << "Destructor" << endl;
  }
};
// rest is all

#include <iostream>
using namespace std;

class Complex
{
private:
  float real, imag;

public:
  complex(){};
  complex(float r, float i)
  {
    real = r;
    imag = i;
  }

  void getData()
  {
    float r, i;
    cout << "enter :";
    cin >> r >> i;
    real = r;
    imag = i;
  }
  void setData(float r, float i)
  {
    real = r;
    imag = i;
  }
  void display_data()
  {
    cout << real << "+" << imag << "i" << endl;
  }

  void add_complex(complex a, complex b)
  {
    real = a.real + b.real; // this is gonna cause error
    imag = a.imag + b.imag;
  }
  void complex_mul(complex c2)
  {
    complex t;
    t.real = real * c2.real - imag * c2.imag;
    t.imag = real * c2.imag + imag * c2.real;
    return t;
  }
  complex operator+(complex c)
  {
    complex t;
    t.real = real + c.real;

    i.imag = imag + c.imag;
    return t;
  }

  complex operator*(complex c)
  {
    complex t;
    t.real = real * c.real - imag - c.imag;
    t.imag = real * c.imag + imag * c.real;
    return t;
  }
};

// hierarchy of operators remain same even upon overloading
//  this pointer last topic8u

// this pointer points the objetc itself
#include <iostream>
using namespace std;

class example
{
private:
  int i;

public:
  void setData(int ii)
  {
    i = ii;
    this->= ii; // this pointer points the same object
  }
};

#include <iostream>
using namespace std;
class circle
{
private:
  int radius;
  float x, y;

public:
  circle()
  {
  }
  circle(int rr, float xx, float yy)
  {
    radius = r;
    x = xx;
    y = yy;
  }

  circle operator=(circle &c)
  {
    cout << "assignment" << endl;
    radius = c.radius;
    x = c.x;
    y = c.y;
    return circle(radius, x, y);
  }

  void showData()
  {
    cout << "\nRadius: " << radius << endl;

    cout << "\nx: " << x << endl;
    cout << "\ny: " << y << endl;
  }
};

// write teh rest
int main()
{
}
#include <iostream>
using namespace std;
class circle
{
private:
  int radius;
  float x, y;

public:
  circle()
  {
  }
  circle(int rr, float xx, float yy)
  {
    radius = r;
    x = xx;
    y = yy;
  }

  circle operator=(circle &c) // we passed it using refrence we could have done it using value but the object needs to copied and it wastes a lot of space so we prefer refrecence
  {
    cout << "assignment" << endl;
    radius = c.radius;
    x = c.x;
    y = c.y;
    return circle(radius, x, y); // return *this
  }

  void showData()
  {
    cout << "\nRadius: " << radius << endl;

    cout << "\nx: " << x << endl;
    cout << "\ny: " << y << endl;
  }
};

// write teh rest
int main()
{
}

// overlaoding unary operators

#include <iostream>
using namespace std;

class index
{
private:
  int count;

public:
  index()
  {
    count = 0;
  }
  index(int i)
  {
    count = i;
  }
  index operator++() /// increments btu when we assing gives error a = ++d;gives erroas ++ has void return to fix thsi
  {
    ++count;

    // fixing the problem :
    index temp;
    temp.count = count;
    return temp; // return index(count);//return *this
  }
  index operator++(int) /// signal to compiler to create a post fix notation as well

  {
    return count(index++);
  }
  void showData()
  {
    cout << count; //
  }
};

// functions defined inside a class are inline(atlest tried)
#include <iostream>
#include <string>

using namespace std;
class employee
{
private:
  string name;
  int age;

public:
  employee();
  employee(string s, int a);
  void getData();
  void showData();
};

employee::employee()
{
  strcpy(name, "");
  age = 0;
}

employee::employee(string s, int a)
{
  name = s;
  age = a;
}

void employee::getData()
{
  cout << "Enter name and age: " << endl;
  cin >> name >> age;
}

void employee ::showData()
{
  cout << name << " " << age << endl;
}

// new and delete
// dynamic memory pool heap c malloc realloc free calloc
// but in cpp we have better way to deal with this
#include <iostream>
using namespace std;

int p1;
struct employee
{
  string name;
  int age;
  float sal;
} p2;

p1 = new int;      // allocate 4byte
p2 = new employee; // allocate 2bytes

// does the type need to a pointer
int *p3 = new int[30];
// usage of delete :
delete p1;
delete p2;
delete[] p3;

#include <bits/stdc++.h>

using namespace std;

struct employee
{
  string name;
  int age;
  float sal;
};

int sort_func(const void *a, const void *b);

int main()
{
  int num, i;
  employee *ptr_to_record;
  cout << "enter number of records: ";
  cin >> num;

  employee **ptr_to_array_ptr = new employee *[num];

  for (i = 0; i < num; i++)
  {
    ptr_to_record = new employee;
    cout << "Enter a record: ";
    cin >> ptr_to_record->name >> ptr_to_record->age >> ptr_to_record->sal;
    ptr_to_array_ptr[i] = ptr_to_record;
  }
  cout << "Entered " << endl;
  for (i = 0; i < num; i++)
  {
    ptr_to_record = ptr_to_array_ptr[i];
    cout << ptr_to_record->name << " " << ptr_to_record->age << " " << ptr_to_record->sal;
  }

  qsort(ptr_to_array_ptr, num, sizeof(ptr_to_array_ptr[0]), sort_func);

  cout << "sorted records : " << endl;
  for (i = 0; i < num; i++)
  {
    ptr_to_record = ptr_to_array_ptr[i];
    cout << ptr_to_record->name << " " << ptr_to_record->age << " " << ptr_to_record->sal << endl;
  }
  for (i = 0; i < num; i++)
    delete ptr_to_array_ptr[i];

  delete[] ptr_to_array_ptr;
}

int sort_func(const void *a, const void *b)
{
  employee *aa, *bb;
  aa = *((employee **)a);
  bb = *((employee **)b);

  return (aa->name < bb->name);
}

#include <bits/stdc++.h>
using namespace std;

class employee
{
private:
  string name;
  int age;
  float sal;

public:
  employee()
  {
    cout << "zero argument constructor";
    name = "";
    age = 0;
    sal = 0;
  }

  employee(string n, int a, float s)
  {
    cout << "three argument constructor " << endl;
    name = n;
    age = a;
    sal = s;
  }

  void setData(string n, int a, float s)
  {
    name = n;
    age = a;
    sal = s;
  }

  void showData()
  {
    cout << endl
         << name << "\t" << age << "\t" << sal << endl;
  }

  ~employee()
  {
    cout << endl
         << "reached destructor";
  }
};

int main()
{
  employee *p;
  p = new employee; // they create the objects as well destroy unlike the malloc which only allocates teh memory
  // calls the constructor depending upon teh no of arguments
  p->setData("sa", 23, 4500);
  delete p;
}

// maatrix class
#include <bits/stdc++.h>
using namespace std;

class matrix
{
private:
  int maxrow, maxcol;
  int *ptr;

public:
  matrix()
  {
    maxrow = 0;
    maxcol = 0;
  }
  matrix(int r, int c)
  {
    maxrow = r;
    maxcol = c;
    ptr = new int[r * c];
  }

  void getmat()
  {
    int i, j, mat_off;

    cout << endl
         << "Enter elements matrix: " << endl;

    for (i = 0; i < maxrow; i++)
    {
      for (j = 0; j < maxcol; j++)
      {
        mat_off = i * maxcol + j;
        cin >> ptr[mat_off];
      }
    }
  }

  void printMat()
  {
    int i, j, mat_off;
    for (i = 0; i < maxrow; i++)
    {
      for (j = 0; j < maxcol; j++)
      {
        mat_off = i * maxcol + j;
        cout << setw(3) << ptr[mat_off];
      }
      cout << endl;
    }
  }

  int detMat()
  {
    matrix q(maxrow - 1, maxcol - 1);

    int sign = 1, sum = 0, i, j, k, count;
    int newpos, newsize, pos, order;

    order = maxrow;

    if (order == 1)
      return (ptr[0]);

    for (i = 0; i < order; i++, sign *= -1)
    {
      for (j = 0; j < order; j++)
      {
        for (k = 0, count = 0; k < order; k++)
        {
          if (k == i)
            continue;
          pos = j * order + k;

          newpos = (j - 1) * (order - 1) + count;
          q.ptr[newpos] = ptr[pos]; // changing the elements from the ptr matrix to the q matrix
          count++;
        }
      }
      sum = sum + ptr[i] * sign * q.detMat();
    }
    return (sum);
  }

  matrix operator+(matrix b)
  {
    matrix c(maxrow, maxcol);

    int i, j, mat_off;

    for (i = 0; i < maxrow; i++)
    {
      for (j = 0; j < maxcol; j++)
      {
        mat_off = i * maxcol + j;
        c.ptr[mat_off] = ptr[mat_off] + b.ptr[mat_off];
      }
    }
    return (c);
  }

  matrix operator*(matrix b)
  {
    matrix c(b.maxcol, maxrow);
    int i, j, k, mat_off1, mat_off2, mat_off3;

    for (i = 0; i < c.maxrow; i++)
    {
      for (j = 0; j < maxcol; j++)
      {

        mat_off3 = i * c.maxcol + j;
        c.ptr[mat_off3] = 0;

        for (k = 0; k < b.maxrow; k++)
        {
          mat_off2 = k * b.maxcol + j;
          mat_off1 = i * maxcol + k;

          c.ptr[mat_off3] += (ptr[mat_off1] * b.ptr[mat_off2]);
        }
      }
    }

    return (c);
  }

  int operator==(matrix b)
  {
    int i, j, mat_off;
    if (maxrow != b.maxrow || maxcol != b.maxcol)
      return 0;

    for (i = 0; i < maxrow; i++)
    {
      for (j = 0; j < maxcol; j++)
      {
        mat_off = i * maxrow + j;
        if (ptr[mat_off] != b.ptr[mat_off])
          return 0;
      }
    }
    return 1;
  }
  // dfdad
};

int main()
{
  int rowa, rowb, cola, colb;

  cout << endl
       << "Enter dimension of a: ";
  cin >> rowa >> cola;

  matrix a(rowa, cola);
  a.getmat();

  cout << endl
       << "Enter the dimesnions if b: ";
  cin >> rowb >> colb;
  matrix b(rowb, colb);
  b.getmat();

  matrix c(rowa, cola); // sum requires ame order
  c = a + b;
  cout << endl
       << "sum:" << endl;
  c.printMat();

  matrix d(rowa, colb);
  d = a * b;
  cout << endl
       << "product : " << endl;
  d.printMat();

  cout << "determinant of c: " << endl;
  cout << a.detMat() << endl;

  if (a == b)
    cout << endl
         << "equal" << endl;
  else
  {
    cout << endl
         << "not equal" << endl;
  }
}

// finding teh sizeof obkjects using sizeof old friend
// the size of the objects is sumof data members and functions play no role in it
// becaue functions are declared only once and called

// structures and classes
// only difference is in class members are private by default while in sturct they are public in nature
// general use use class when functions and data while struct when only struct

// are nested classes allowded

// unit 5
//////////////
//////////////
//////////////
//////////////
//////////////
//////////////
//////////////
//////////////
//////////////
//////////////

// the free store
// new memory from heap (know as free store) always delete this memory
// deleting null has no effect
// delete deletes teh object not the pointer
// never delete a pointer twice
// program running for long time deleting the object becomes very important
// new return nulll pointer if unable to allocate memory

#include <bits/stdc++.h>
using namespace std;
int main()
{
  void memWarning();
  set_new_handler(memWarning); // used to set default warnings

  char *p = new char[100];
  cout << "first alloc: " << hex << long(p) << endl;

  p = new char[640000000000000ll]; // define our own
  set_new_handler(0);
  delete[] p;
}

void memWarning()
{
  cout << "Free store has gone empty!" << endl;
  return;
}

// custom new and delete
// overridign new and delete
#include <bits/stdc++.h>
using namespace std;

int main()
{
  void memwarning();
  void *operator new(size_t, int);
  void operator delete(void *);

  set_new_handler(memwarning);

  char *p = new char[100]; // this call still calls teh global new and delete operators
  cout << "FIrst allocation: " << hex << long(p) << endl;

  for (int i = 0; i < 100; i++)
  {
    cout << char(p[i]);
  }

  delete p;
  // p = ne
}

void memwarning()
{
  cout << "Free stire has gone out";
  exit(1);
}

void *operator new(size_t sz)
{
  void *p;
  p = malloc(sz);
  if (p == NULL)
  {
    memwarning();
  }

  memset(p, '$', sz);
  return p;
}

void operator delete(void *pp)
{
  free(pp);
}

// overloading new and delete expressions
#include <bits/stdc++.h>
using namespace std;

const int MAX = 5;
const int FREE = 0;
const int OCCUPIED = 1;

void memwarning()
{
  cout << endl
       << "Free store empty";
  exit(1);
}

class employee
{
private:
  string name;
  int age;
  float sal;

public:
  void *operator new(size_t bytes);
  void operator delete(void *q);
  void setData(string s, int a, float t);
  void showData();
  ~employee();
};

struct pool
{
  employee obj;
  int status;
};
int flag = 0;

struct pool *p = NULL;

void *employee::operator new(size_t sz)
{
  int i;
  if (flag == 0)
  {
    p = (pool *)malloc(sz * MAX);
    if (p == NULL)
      memwarning();

    for (i = 0; i < MAX; i++)
      p[i].status = FREE;

    flag = 1;
    p[0].status = OCCUPIED;

    return &p[0].obj;
  }
  else
  {
    for (i = 0; i < MAX; i++)
    {
      if (p[i].status == FREE)
      {
        p[i].status = OCCUPIED;
        return &p[i].obj;
      }
    }
    memwarning();
  }
}

void employee::operator delete(void *q)
{
  if (q == NULL)
    return;

  for (int i = 0; i < MAX; i++)
  {
    if (q == &p[i].obj)
    {
      p[i].status = FREE;
      p[i].obj.name = "";
      p[i].obj.age = 0;
      p[i].obj.sal = 0.0;
    }
  }
}

void employee::setData(string n, int a, float s)
{
  name = n;
  age = a;
  sal = s;
}

void employee::showData()
{
  cout << endl
       << name << '\t' << age << '\t' << sal;
}

employee::~employee()
{
  cout << "reached destructor";
  free(p);
}

int main()
{
  void memwarning();
  set_new_handler(memwarning);

  employee *e1, *e2, *e3, *e4, *e5, *e6;
  string s = "ajay";
  e1 = new employee;
  e1->setData(s, 34, 500.0);
  e2 = new employee;
  e2->setData(s, 34, 500.0);
  e3 = new employee;
  e3->setData(s, 34, 500.0);
  e4 = new employee;
  e4->setData(s, 34, 500.0);
  e5 = new employee;
  e1->showData();
  e2->showData();
  e3->showData();
  e4->showData();
  e5->showData();
  // e1->setData(s, 34, 500.0);
  e6 = new employee;
}

// the startegy  is create memory array of five once and then allocate the remaingin blocks whenever the new is invoked
// first argument is size_t
// delete the site address is passed and matched to the objetx beign freed
// the free slot can then be assigned to subsequnet slots
// allocate the sixth element the free space is empty
// no overload for delete only one per class

// new and delete are are static as called before the intialisation of the object

// we can control the address new creates
#include <iostream>
using namespace std;

class sample
{
private:
  int i;

public:
  sample()
  {
    i = 0;
  }
  sample(int ii)
  {
    i = ii;
  }
  ~sample()
  {
  }

  void *operator new(size_t sz, void *q)
  {
    return (sample *)q;
  }
  void showdata()
  {
    cout << i << endl;
  }
};

int main()
{
  void *address;
  address = (void *)0x4178908;
  sample *p = new (address) sample(10);
  p->showdata();
  p->~sample();
}

//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////

// unit 6 more on classes
// static members alll ibjecct store common data we use static for that
#include <iostream>
using namespace std;

class sample
{
private:
  static int index;
  int count;

public:
  sample()
  {
    index++;
    count++;
  }

  void showData()
  {
    cout << endl
         << "Index: " << index;
    cout << endl
         << "Count: " << count;
  }
};
int sample::index = 0;
int main()
{
  sample s1, s2, s3; /// index is shared while count is random variable here
  // when we wish to how many objects are created till now
  s1.showData();
  s2.showData();
  s3.showData();
}

// static member functions
#include <iostream>
using namespace std;

class sample
{
private:
  static int count;

public:
  sample()
  {
    count++;
  }

  static void showcount()
  {
    cout << endl
         << "count = " << count;
  }
};

int sample::count = 0; // initalise it
int main()
{
  sample s1;
  sample::showcount();
  sample s2;
  sample::showcount();
  sample s3;
  sample::showcount();
}

// const uses
// on normal vars to prevent modifications
// on function arguments form modfiying

// const
// on member functions
// on member function arguments
// on objects

#include <iostream>
using namespace std;

class sample
{
private:
  int data;

public:
  sample()
  {
    data = 0;
  }

  void changeData()
  {
    data = 10;
  }
  void modifyData const()
  {
    data = 20; // error cannot modify a const object
  }

  void showData()
  {
    cout << "data: " << data << endl;
  }

  void add(sample const &s, sample const &t)
  {
    data = s.data + t.data;
  }

  void getData()
  {
    cin >> data;
  }
};

int main()
{
  sample s1;
  s1.changeData();
  s1.modifyData();
  s1.showData();
  const sample s2;
  // use can use const member functions only with const objects

  s2.modifyData();
}

// copy adn assignment constructor
//  c1 = c2
//  circle c1, c2;
//  c1 = c2;//assignement
//  circle c3 = c3 //copy constructor

#include <iostream>
using namespace std;

class circle
{
private:
  int radius;
  float x, y;

public:
  circle()
  {
  }

  circle(int rr, float xx, float yy)
  {
    radius = rr;
    x = xx;
    y = yy;
  }

  circle operator=(circle &c)
  {
    cout << "assignement" << endl;
    radius = c.radius;
    x = c.x;
    y = c.y;
    return (circle(radius, x, y));
  }

  circle(circle &c) // desirable not necessary because copying takes place here to
  // passs by value for large objects this can get complicated

  {
    cout << "copy constructor:" << endl;
    radius = c.radius; // what if variable are of different types
    // routines for conversion already built in the another way is to type cast the operators
    x = c.x;
    y = c.y;
  }

  void showData()
  {
    cout << "Radius: " << radius << endl;
    cout << "x:= " << x;
    cout << "y:= " << y;
  }
};

// write the driver code
// converting user defined and basic types
#include <bits/stdc++.h>
using namespace std;
class string
{
private:
  char str[20];

public:
  string()
  {
    str[0] = '\0';
  }
  '
  
  ' string(char *s)
  {
    strcpy(str, s);
  }
  string(int a)
  {
    itoa(a, str, 10);
  }

  operator int()
  {
    int i = 0, ss = 0, k = 1;
    l = strlen(str) - 1;
    while (l >= 0)
    {
      ss = ss + (str[i] - 48) * k;
      l--;
      k *= 10;
    }
    return ss;
  }

  void displayData()
  {
    cout << str;
  }
};
/// write the driver code

// leave the conversion of one class to another for now pg 197 /

////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
// ch 7 data structures go through once some day

// unit 8 inheritence

// derived class form a base class
#include <iostream>
using namespace std;

class index
{          // base class
protected: // only public and protected can be accessed
  int count;

public:
  index()
  { // default constructor
    count = 0;
  }
  index(int c)
  {
    count = c;
  }

  void display()
  {
    cout << cout << endl;
  }
  void operator++()
  {
    count++;
  }
};

class index1 : public index
{ // derived class

public:
  // the constructor of base class gets called
  void operator--()
  {
    count--; // write the driver code yourself
  }
}

#include <iostream>
using namespace std;
const int MAX = 25;
class stack
{
protected:
  int s[MAX];
  int top;

public:
  stack()
  {
    top = -1;
  }

  void push(int num)
  {
    top++;
    s[top] = num;
  }
  int pop()
  {
    int num;
    num = s[top];
    top--;
    return num;
  }
};

class stack1 : public stack // derived class
{
public:
  void push(int num)
  {
    if (top == MAX - 1)
      cout << endl
           << "stack is full";
    else
      stack::push(num);
  }

  int pop()
  {
    int i;
    if (top == -1)
    {
      cout << "Stack is empty" << endl;
      return NULL;
    }
    else
    {
      n = stack::pop(); // call of base class
      return (n);
    }
  }
};
int main()
{
  int n;
  stack1 stk;
  stk.push(1); // function of derived class get higher priority
  stk.push(1);
  stk.push(1);
}

class a : public b;  // portected and public members are public in derived class
class c : private c; //(public and protected members are private members of the derived class )

// the compiler calls teh constructor of base then constructor of derived class
#include <bits/stdc++.h>
using namespace std;

class one
{
private:
  int a;

protected:
  int b;

public:
  int c;
};
class two : public one
{
public:
  void function1()
  {
    int x;
    z = a; // not accessible
    z = b; // other two works fine
    z = c;
  }
};

class three : private one
{
  void function2()
  {
    int y;
    y = a; // error
    y = b; // works
    y = c; // works
  }
};

int main()
{
  int x;
  two s;
  x = s.a; // error
  x = s.b; // error
  x = s.c;

  three t;
  x = t.a; // error
  x = t.b; // error
  x = t.c; // error
}

#include <iostream>
using namespace std;

class ll
{
protected:
  struct Node
  {
    int data;
    struct Node *next;
  } *p;

public:
  ll();
  ~ll();
  void append(int num);
  void addToHead(int num);
  void addAfter(int c, int num);

  void del(int num);
};
ll ::ll()
{
  p = NULL;
}

ll ::~ll()
{
  Node *t;
  while (p != NULL)
  {
    t = p;
    p = p->next;
    delete t;
  }
}
// add to the end

void ll ::append(int num)
{
  struct Node *ptr, *new_node = new Node;
  ptr = p;
  if (p == NULL)
  {
    p = new_node;
    p->data = num;
    p->next = NULL;
  }
  else
  {
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
    new_node->data = num;
  }
}

// add at the start

void ll ::addToHead(int num)
{
  struct Node *ptr, *new_node = new Node;

  new_node->data = num;
  new_node->next = p;
  p = new_node;
}

void ll ::addAfter(int c, int num)
{
  Node *ptr, *new_node;
  new_node = new_node;
  new_node->data = num;
  int i; // dont go decalring ptr as int as well
  for (i = 0, ptr = p; i < c; i++)
  {
    ptr = ptr->next;

    if (ptr == NULL)
    {
      cout << "There are less than required elements: " << endl;
      return;
    }
  }
  new_node->next = ptr->next;
  ptr->next = new_node;
}

void ll ::del(int num)
{
  Node *ptr, *r;
  ptr = p;

  if (ptr->data == num) // delete first ele
  {
    p = ptr->next;
    delete ptr;
    return;
  }
  r = ptr;
  while (ptr != NULL)
  {
    if (ptr->data == num) // error = instead of  ==
    {
      r->next = ptr->next;
      delete ptr;
      return;
    }
    r = ptr;
    ptr = ptr->next;
  }
}

class ll2 : public ll
{
public:
  void display();
  int count();
};

void ll2::display()
{
  Node *ptr = p;
  while (ptr != NULL)
  {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
}

int ll2 ::count()
{
  Node *ptr;
  int c = 0;
  while (ptr != NULL)
  {
    ptr = ptr->next;
    c++;
  }
  return c;
}
int main()
{
  ll2 l;
  l.append(11);
  l.append(11);
  l.append(11);
  l.append(11);
  l.append(11);
  l.append(11);
  l.append(11);
  l.append(11);
  l.append(11);
  l.display();
}

// multi level of inheritance
//  a>> b>>>c inheritance levels

// #include <bits/stdc++.h>
#include <graphics> //gotta install graphics first
using namespace std;

class rect
{
public:
  void drawRect(int x1, int y1, int x2, int y2, int boundarycolor)
  {
    setcolor(boundarycolor);
    rectangle(x1, y1, x2, y2);
  }
};

class filedrect : public rect
{
public:
  void drawRect(int x1, int y1, int x2, int y2, int boundaryColor, int pattern, int patternColor)
  {
    rect::drawRect(x1, y1, x2, y2, boundaryColor);

    struct filesettingstype t;
    getfillsettings(&t);                 // collect current fill pattern
    setfillstyle(pattern, patternColor); // new fill pattern
    floodfill(x1 + 1, y1 + 1, boundaryColor);
    setfillstyle(t.pattern, t.color); // reset to orginal
  }
};

class animatedfilledrect : public filedrect
{
public:
  void drawRect(int x1, int y1, int x2, int y2, int boundaryColor, int pattern, int patternColor)
  {
    filedrect::drawRect(x1, y1, x2, y2, boundaryColor, pattern, patternColor);

    int size = imagesize(x1, y1, x2, y2);
    char *p;
    p = new char[size];

    getimage(x1, y1, x2, y2);
    putimage(x1, y1, p, XOR_PUT);

    int x, y;
    while (!khbit())
    {
      x = random(getmaxx());
      y = y2 + random(getmaxy());

      putimage(x, y, p, OR_PUT);
      delay(100);
      putimage(x, y, p, XOR_PUT);
    }
  }
};

int main()
{
  int gd = DETECT, gm; // gm and gs are graphic monitor and graphic drivers resps

  initgraph(&gd, &gm, "//driver path"); // figure out the resolution of the screen
  rect x;
  x.drawRect(5, 5, 200, 100, RED);
  getch();
  closegraph();
  restorecrtmode();
  return 0;
}
// learn graphics later
// mutiple inheritance
// class derived from more than 1 class

#include <bits/stdc++.h>
using namespace std;
class item
{
private:
  char title[20];
  float price;

public:
  item()
  {
    strnset(title, 0, 20);
    price = 0;
  }
  void getData()
  {
    cout << "Enter tha title and price: ";
    cin >> title >> price;
  }

  void displayData()
  {
    cout << "Title: " << title << endl;
    cout << "price: " << price << endl;
  }
};
class Sales
{
private:
  float salesfig[3];

public:
  Sales()
  {
    for (int i = 0; i < 3; i++)
      salesfig[i] = 0;
  }
  void getData()
  {
    cout << "Enter sales figure for 3 months: " << endl;
    for (int i = 0; i < 3; i++)
      cin >> salesfig[i];
  }

  void displayData()
  {
    cout << "Sales figure for 3 months: " << endl;
    for (int i = 0; i < 3; i++)
    {
      cout << salesfig[i] << " ";
    }
  }
};

class hwitem : private item, private Sales // for hardware items this  are caorder of declartion decides the order in which the constructorlled destructors are called exactly in teh reverse order
{

private:
  char category[10];
  char oem[10];

public:
  hwitem() : item(), Sales()
  {
    strnset(category, 0, 10);
    strnset(oem, 0, 10);
  }

  // arguments constructor
  hwitem(float a, float v, float c, char *t, float p, char *cat, char *o) : item(t, p), Sales(a, b, c)
  {
    strcpy(category, cat);
    strcpy(oem, o);
  }
  void getData()
  {
    item::getData(); // when calling funcitons with same name it is import ant that we specify the class using scope resolution

    cout
        << "Enter category and oem: " << endl;
    cin >> category >> oem;
    Sales::getData();
  }

  void displayData()
  {
    item::displayData();
    cout << "category and oem: " << endl;
    cout << category << " " << oem << endl;
    Sales::
        displayData();
  }
};

class switem : private item, private Sales // for software items
{
private:
  char category[10];
  char os[10];

public:
  void getData()
  {
    item::getData();
    cout << "category and os: " << endl;
    cin >> category >> os;
    Sales::getData();
  }

  void displayData()
  {
    item::displayData();
    cout << "category: " << category << endl;
    cout << "os: " << os << endl;
    Sales::displayData();
  }
};

int main()
{
  hwitem it1;
  it1.getData();
  it1.displayData();
  return 0;
}

// mutiple inheritance many class into 1

// how are constructors handled here

// private inheritance

#include <iostream>
using namespace std;

class base
{
public:
  void display()
  {
    cout << "display base " << endl;
  }

  void show()
  {
    cout << "show base " << endl;
  }
};
class derived : private base
{
public:
  base::display();
};

int main()
{
  derived d;
  d.display(); // accessible because we put the name in derived public:
  d.show();    // not accessible
}

// protected inheritance

// class derived public form class a :
// public and protected var are visible

// derived privately from base
// protected and public members become protected members form class derived

// derived protectively from base
// protected and public members become protected members form class derived

// functions that dont get inherited
// constructors and destructors
// = operator is not inherited copy constructor as well
// classes allow incremental developement
//

// /////////////////////////////////////
// /////////////////////////////////////
// /////////////////////////////////////
// /////////////////////////////////////
// /////////////////////////////////////
// /////////////////////////////////////
// /////////////////////////////////////
// /////////////////////////////////////
// /////////////////////////////////////
// /////////////////////////////////////
// /////////////////////////////////////
// /////////////////////////////////////

// virtual functions
// polymorphism one thing with different forms

// function overloading is one such thing
// poymorphism by using virtual functions
// virtual functions from design point of view

// three classes line circle triangle
// all three have draw()

// shape *arr[50];array if all 3 three classes array of pointers
// now for drawing the shapes

for (i = 0; i < 50; i++)
  arr->draw();

// functions from different class are executed from the same class call
// the array constians shape pointer not line or circle pointers

// the concept is poly morhpism
// for this to work
// we need
// first line circle triangle must be derived from the same class shape

// the shape must contain the draw function declared as virtual
#include <iostream>
using namespace std;

class one
{
public:
  void display()
  {
    cout << "In base" << endl;
  }
};
class oneofone : public one
{
public:
  void display()
  {
    cout << "in oneofone class" << endl;
  }
};
class twoofone : public one
{
public:
  void display()
  {
    cout << "in twoof two" << endl;
  }
};

int main()
{
  one *ptr;
  oneofone o1;
  twoofone o2;

  ptr = &o1;
  ptr->display(); // out:in base
  ptr = &o2;
  ptr->display(); // upcasting out:in base
}

// the pointer of base class are compatible with pointing to derived class
// display() call which one the one whose type matches the pointer declaration(base class is called )
// sometimes we dont this we want the display function of that class is to be called that the object is of

#include <iostream>
using namespace std;

// what compiler does it chooses hte function to be called at the runtime depending the obj
// late binding or dynamic binding
// runtime ppolymorphsim

class one

{
public:
  virtual void display() // base class function as virtual the contents of derived class are executed
  {
    cout << "In base" << endl;
  }
};
class oneofone : public one
{
public:
  void display()
  {
    cout << "in oneofone class" << endl;
  }
};
class twoofone : public one
{
public:
  void display()
  {
    cout << "in twoof two" << endl;
  }
};

int main()
{
  one *ptr;
  oneofone o1;
  twoofone o2;

  ptr = &o1;
  ptr->display(); // out:in base
  ptr = &o2;
  ptr->display(); // upcasting out:in base
}

// the pointer of base class are compatible with pointing to derived class
// display() call which one the one whose type matches the pointer declaration(base class is called )

// pure virtual functions
class base
{
public:
  virtual void display() = 0; // pure virtual functions the functions will pure and doesnt have a body no assingment of 0 to function  we use them when we know we wont need the object of the base class anytime soon

  // such class is called abstract class
  // now how will us ensure that no obj is created from that class
  // way one document that //sloopy way
  // place atleast one pure virtual function in teh class
  // overwrite the pure virtual function if u want to create a object from that class /

  // binding
  // connection btw the function call and the actual code tha t is executed
  // static binding function call and code known at compile time (early binding)
  // dynamic binding actual function called depends ont eh content of the pointer (late binding)

  // virtual tells the compiler to do dynamic binding instead of static one
  // c only has static binding
}

#include <iostream>
using namespace std;

class sample
{
private:
  int i;

public:
  virtual void display()
  {
    cout << "In base class" << endl;
  }
  virtual void display23()
  {
    cout << "in other display" << endl;
  }
};

class example
{
private:
  int i;

public:
  void display()
  {
    cout << "in example class " << endl;
  }
};

class trial
{
public:
  void display()
  {
    cout << "in trial" << endl;
  }
};

int main()
{
  sample s;
  example e;
  trial t;

  cout << sizeof(s) << " " << sizeof(e) << " " << sizeof(t); // 8 4 1 why the sizes should have been 4 4 1
  // without virtual fucnctions the size is what u expect
  // same as single int

  // when we have a vitual function the compiler insert the VPTR (size void pointer ) even if we have multiple
  // virtuall functions only one void pointer is added

  // as for trial t having a size of 1 byte
  //  every class needs to have a memory address and the smallest possible is 1

  // ot accomplish dunamic binding the compiler create the VTABLE WHERE it places teh address for the virtual functiosn of the class

  // when objects of base or derived class are created it ninserts the VPtr which points to teh vtable and thus performing
  // dynamic binding
}

#include <iostream>
using namespace std;

class vehicle
{
public:
  virtual void speed()
  {
    cout << "speed base" << endl;
  }
  virtual void maintenance()
  {
    cout << "maintenance base " << endl;
  }

  void value()
  {
    cout << "value base " << endl;
  }
};

class fourWheeler : public vehicle
{
public:
  void speed()
  {
    cout << "in speed fourwheeler" << endl;
  }

  void maintenance()
  {
    cout << "in maintenance fourwheeler" << endl;
  }
};

class twoWheeler : public vehicle
{
public:
  void speed()
  {
    cout << "in speed two wheeler" << endl;
  }
  void maintenance()
  {
    cout << "in maintenance two wheeler" << endl;
  }

  void value()
  {
    cout << " in value two wheeler" << endl;
  }
};
class airborne : public vehicle
{
public:
  void speed()
  {
    cout << "in speed airborne" << endl;
  }
};

int main()
{
  vehicle *ptr1;
  vehicle v;

  ptr1 = &v;

  // vehicle
  ptr1->speed();
  ptr1->maintenance();
  ptr1->value();

  vehicle *ptr2, *ptr3, *ptr4;

  fourWheeler maruti;
  twoWheeler bajaj;
  airborne jumbo;

  ptr2 = &maruti;
  ptr3 = &bajaj;
  ptr4 = &jumbo;

  ptr2->speed();       // four
  ptr2->maintenance(); // four
  ptr2->value();       // vehicle

  ptr3->speed();       // two
  ptr3->maintenance(); // two
  ptr3->value();       // vehicle

  vehicle w;
  w.speed(); // vechicle

  fourWheeler f;
  f.speed(); // four

  airborne a;
  a.maintenance(); // vechicle
}

// non virutal and the pointer is of base type always ca;
// ; the functions formt the vase class

// the vptr plays an important role here so we have to make it point to correct vtable
// best place them in constructor
// we didnt had a constructor so one genereated itself default constructor

// why use virtual functions
// the mechanism of virtual functions is not the effiecient one
// vptr andvtable and mapping tehm takes time and space to execute
// if all the functions followed dynamic binding the situation wold have taken turn for worst
#include <iostream>
using namespace std;

// add new vitural functions in derived class

class base
{
public:
  virtual void fun1()
  {
    cout << "in base: fun1" << endl;
  }
};

class derived : public base
{
public:
  void fun1()
  {
    cout << "in derived: fun1" << endl;
  }

  virtual void fun2()
  {
    cout << "in derived : fun2" << endl;
  }
};

int main()
{
  base *ptr1, *ptr2;

  base b;
  derived d;
  ptr1 = &b;
  ptr2 = &d;

  ptr1->fun1();
  ptr2->fun1();
  // ptr2->fun2(); // error base class pointer has no info of the virtual functiosn of the derived class
  ((derived *)ptr2)->fun2(); // fix this this fixes the issue
  // we use virtual functions ony using ptr and refrences whithout them objetc slicing takes place
}

#include <iostream>
using namespace std;

class base
{
private:
  int i;

public:
  base(int ii)
  {
    // int i = ii;
    i = ii; // we gotta assign not declare
  }

  virtual void fun1()
  {
    cout << i << endl;
  }
};

class derived : public base
{
private:
  int j;

public:
  derived(int ii, int jj) : base(ii)
  {
    j = jj;
  }

  void fun1()
  {
    base::fun1();
    cout << j << endl;
  }
};

int main()
{
  base b(10);
  derived d(15, 29);

  base *ptr1 = &b;
  ptr1->fun1(); // 10

  base *ptr2 = &d;
  ptr2->fun1(); // 15 29

  base &ref1 = b;
  ref1.fun1(); // 10

  base &ref2 = d;
  ref2.fun1(); /// 15 29

  b = d; // 15 only base part // object sliced object is sliced till all that remains belong to the recipient
  b.fun1();
}

// virtual functions and constructors
// for next timeuu
// #ideal place tod efine constructors
// order of calling constructors
// calling virtual functions within constructor
// functions defined inside a class are inline includes cinstructors
// if u have virtual functions the vptr is inserted inside the constsructor call to point to the vtable
// constructor calls the base class constructor
// so the code size grows without speed benefit
// when looking for efficency define them outside teh class

// the base class constructor is always gets called
// because the constructor of base class has the access to the values of the base class

// the order of constructor call

// base constructor first then derived constructor

// calling virtual functions form constructors

#include <iostream>
using namespace std;
class base
{
private:
  int i;

public:
  base(int ii)
  {
    i = ii;
  }

  virtual void fun1()
  {
    cout << i << endl;
  }
};

class derived : public base
{
private:
  int j;

public:
  derived(int ii, int jj) : base(ii)
  {
    base *p;
    p = this;
    j = jj;    // shift this a line below it will give garbage value
    p->fun1(); // derived class //the member function of the derived class always
    // at this point only the base part of derived class is complete it is not complete but still virtual function call
    // calls teh functions from the inheritence heriarchy
    // when contructor called it initalizes teh vptr of teh current class to vtable  so the last constructor call decides the state of the vptr
  }

  void fun1()
  {
    cout << j << endl;
  }
};

int main()
{
  base b(10);
  derived d(15, 20);
}

// destructors and virtual destructors
// destructor is there for destroying teh class
// follow the reverse order of the constructor call

// imagine a situation in which the derived object is created using the new and assigned to the base pointer now we
// delete the obj which call the base destructor
// which cause problems soln: use virtual destructors
#include <iostream>
using namespace std;

class base
{
public:
  base()
  {
    cout << "In base constructor" << endl;
  }
  virtual ~base() // wihtout virtual only the base destructor is called
  {
    cout << "in base destructor" << endl;
  }
};

class derived : public base
{

public:
  derived()
  {
    cout << "in derived constructor" << endl;
  }
  ~derived()
  {
    cout << "in derived destructor" << endl;
  }
};
int main()
{
  base *b;
  b = new derived;
  delete b;
}

// we can have pure virtual destructor as well but we have to provid the body the destructor

// callling virtual functions from the destructor
// only local version of function is called
// similar to calling virtual functions from the base class

#include <iostream>
using namespace std;

class base
{
public:
  ~base()
  {
    cout << "in base dest" << endl;
  }
  virtual void fun1()
  {
    cout << "in base:fun1" << endl;
  }
};

class derived : public base
{
public:
  ~derived()
  {
    base *p;
    p = this;
    p->fun1(); // of the derived destructors dont have acess to the future hierarchy
  }

  void fun1()
  {
    cout << "in derived: fun1" << endl;
  }
};

int main()
{
  derived d;
}

// virtual base class

// think of a situation
// base derived 1 derived 2 and from these two we have derived 3

// now for any member of base class derived class has 2 copies from which it check for values
// to get rid of this we derive derived 1 and derived 2 as virtual

#include <iostream>
using namespace std;

class base
{
protected:
  int data;

public:
  base()
  {
    data = 500;
  }
};

class derived1 : virtual public base
{
};

class derived2 : virtual public base
{
};

class derived3 : public derived1, public derived2
{
public:
  int getdata()
  {
    return data;
  }
};

int main()
{
  derived3 ch;
  int a;

  a = ch.getdata();
  cout << a << endl;
}

// this occurs in the case of the member functions as well

/// mouse.cpp
using namespace std;
class mouse
{
private:
  union REGS i, o;

public:
  mouse()
  {
    initmouse();
    showmouseptr();
  }

  void initmouse()
  {
    i.x.ax = 0;
    int86(0x33, &i, &o);
  }

  void showmouseptr()
  {
    i.x.ax = 1;
    int86(0x33, &i, &o);
  }

  void hidemouseptr()
  {
    i.x.ax = 2;
    int86(0x33, &i, &o);
  }

  void getmousepos(int &button, int &x, int &y)
  {
    i.x.ax = 3;
    int86(0x33, &i, &o);

    button = o.x.bx;
    x = o.x.cx;
    y = o.x.dx;
  }

  void restrictmouseptr(int x1, int y1, int x2, int y2)
  {
    i.x.ax = 7;
    i.x.cx = x1;
    i.x.dx = x2;
    int86(ox33, &i, &o);
    i.x.ax = 8;
    i.x.cx = y1;
    i.x.dx = y2;
  }
};

////virtual.cpp
#include <iostream>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mouse.cpp"

#include <fstream>

class shapes
{
public:
  virtual void draw()
  {
  }

  virtual void save(ofstream &ft)
  {
  }

  virtual void open(ifstream &fs)
  {
  }
};

class myline : public shapes
{
private:
  int sx, sy, ex, ey, color;

public:
  myline()
  {
  }
  myline(int x1, int y1, int x2, int y2, int clr)
  {
    sx = x1;
    sy = y1;
    ex = x2;
    sy = y2;
    color = clr;
  }

  void draw()
  {
    setcolor(color);
    moveto(sx, sy);
    lineto(ex, ey);
  }

  void save(ofstream &ft)
  {
    ft << "L "
       << "\n";
    ft << sx << " " << sy << " " << ex << " " << ey << " " << color << "\n";
  }
  void open(ifstream &fs)
  {
    fs >> sx >> sy >> ex >> ey >> color;
  }
};

class myrectangle : public shapes
{
private:
  int sx, sy, ex, ey, color;

public:
  myrectangle() {}

  myrectangle(int x1, int y1, int x2, int y2, int clr)
  {
    sx = x1;
    sy = y1;
    ex = x2;
    ey = y2;
    color = clr;
  }

  void draw()
  {
    setcolor(color);
    rectangle(sx, sy, ex, ey);
  }

  void save(ofstream &ft)
  {
    ft << "r"
       << "\n";
    ft << sx << " " << sy << " " << ex << " " << ey << " " << color << "\n";
  }

  void open(ifstream &fs)
  {
    fs >> sx >> Sy >> ex >> ey >> color;
  }
};

class mycircle : public shapes
{
private:
  int sx, sy, radius, color;

public:
  mycircle()
  {
  }
  mycircle(int x1, int y1, int r, int clr)
  {
    sx = x1;
    sy = y1;
    radius = r;
    color = clr;
  }

  void draw()
  {
    setcolor(color);
    circle(sx, sy, radius);
  }

  void save(ofstream &ft)
  {
    ft << "C"
       << "\n";
    ft << sx << " " << sy << " " << radius << " " << color << "\n";
  }

  void open(ifstream &fs)
  {
    fs >> sx >> sy >> radius >> color;
  }
};

struct node
{
  void *obj;
  node *link;
};
class objarray()
{
private:
  node *head;

public:
  objarray()
  {
    head = NULL;
  }

  void add(void *o)
  {
    node *temp = new_node;
    temp->obj = o;
    temp->link = NULL;

    if (head == NULL)
      head = temp;
    else
    {
      node *q;
      q = head;
      while (q->link != NULL)
        q = q->link;

      q->link = temp;
    }
  }

  void *getobj(int i)
  {
    node *q;
    q = head;
    int n;
    for (i = 1; i < n; i++)
    {
      q = q->link;
    }

    return (q->obj);
  }
  int getcount()
  {
    int n = 0;
    node *q;
    q = head;
    while (q != NULL)
    {
      q = q->link;

      n++;
    }
    return n;
  }

  ~objarray()
  {
    node *q;
    q = head;
    while (q != NULL)
    {
      head = head->link;
      delete q;
      q = head;
    }
  }
};

void mainscreen()
{
  cleardevice();

  rectangle(0, 0, 629, 479);
  line(0, 30, 640, 30);

  char *names = {
      "clear",
      "open",
      "save",
      "line",
      "rect",
      "circ",
      "exit"};

  // display menu
  int x, i;
  for (x = 5, i = 0; x < 7 * 90; x += 90, i++)
  {
    setcolor(WHITE);
    rectangle(x, 5, x + 70, 25);
    floodfill(x + 1, 6, WHITE);
    settectstyle(1, 0, 3);
    setcolor(BLACK);
    outextxy(x + 10, 0, names[i]);
  }
}

int main()
{
  istream fs;
  ofstream ft;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, "c:\\tc\\bgi");

  mainscreen();

  setviewport(1, 31, 638, 1);

  mouse m;
  int button, x, y, flag = 0;
  int t, i, index;

  int strptx, strpty, endptx, endpty;

  objarray arr;

  while (true)
  {
    button = 0;
    m.getmousepos(button, x, y);

    if (((button & 1) == 1) && (flag == 0))
    {
      for (t = 5, i = 0; t < 7 * 90, t += 90, i++)
      {
        if (x >= t && x <= t + 70 && y >= 5 && y <= 25)
        {
          index = i;
          flag = 1;
          break;
        }
      }
    }

    int clrnum = random(16);
    int sx = random(638);
    int sy = random(478);
    int ex = random(638);
    int ey = random(478);
    int r = random(200);

    switch (index)
    {
    case 0:
      m.getmousepos(button, x, y);

      if (((button & 1) == 0) && (flag == 1))
      {
        clearviewport();
        flag = 0;
      }
      break;
    case 1:
      m.getmousepos(button, x, y);

      if (((button & 1) == 0) && (flag == 1))
      {
        fs.open("output.txt", ios::in);
        shapes *ptr;

        char a[2];

        while (fs)
        {
          fs >> a;

          if (strcmp(a, "L") == 0)
          {
            myline *l = new myline();
            l->open(fs);
            arr.add(l);
          }
          if (strcmp(a, "R") == 0)
          {
            myrectangle *r = new myrectangle();
            r->open(fs);
            arr.add(r);
          }
          if (strcmp(a, "C") == 0)
          {
            myrectangle *c = new myrectangle();
            r->open(fs);
            arr.add() c;
          }
        }

        fs.close();
        int count = arr.getcount();

        for (i = 1; i <= count; i++)
        {
          ptr = (shapes *)arr.getobj(i);
          ptr->draw();
        }

        flag = 0;
      }
      break;

    case 2:
      m.getmousepos(button, x, y);
      if (((button & 1) == 0) && (flag == 1))
      {
        ft.open("output.txt", ios::out);

        int count = arr.getcount();

        shapes *ptr;
        for (i = ; i <= count; i++)
        {
          ptr = (shapes *)arr.getobj(i);
          ptr->save(ft);
        }

        ft.close();
        flag = 0;
      }
      break;

    case 3:
      m.getmousepos(button, x, y);
      if (((button & 1) == 0) && (flag == 1))
      {
        setcolor(clrnum);
        moveto(sx, sy);
        lineto(ex, ey);

        myline *l = new myline(sx, sy, ex, ey, clrnum);

        if (l == NULL)
          exit(1);

        arr.add(l);
        flag = 0;
      }
      break;

    case 4:
      m.getmousepos(button, x, y);
      if (((button & 1) == 0) && (flag == 1))
      {
        setcolor(clrnum);
        rectangle *r = new myrectangle(sx, sy, ex, ey, clrnum);

        if (r == NULL)
          exit(1);

        arr.add(r);
        flag = 0;
      }
      break;

    case 5:
      m.getmousepos(button, x, y);
      if (((button & 1) == 0) && (flag == 1))
      {
        setcolor(clrnum);
        circle(sx, sy, r);

        mycircle *c = new mycircle(sx, sy, clrnum);

        if (c == NULL)
          exit(1);

        arr.add(c);
        flag = 0;
      }
      break;

    default:
      break;
    }

    if (index == 6)
      break = 6;
  }
  closegraph();
  restorecrtmode();
}

// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////
// //////////////////////////////////////////////////

// unit 10 iostreams

// unit 10 input output

#include <stdio.h>
#include <stdlib.h>
using namespace std;

class file
{
private:
  FILE *fp;

public:
  file(const char *name, const char *mode)
  {
    fp = fopen(name, mode);

    if (fp == NULL)
    {
      printf("\nCannot open file: %s", name);
      exit(1);
    }
  }

  ~file()
  {
    fclose(fp);
  }

  int fgetc()
  {
    int ch;
    ch = ::fgetc(fp);
    return ch;
  }

  void printf(const char *fmt, ...)
  {
    va_list ptr;
    char str[100];
    va_start(ptr, fmt);
    vsprintf(str, fmt, ptr);
    ::printf(str);
    va_end(ptr);
  }

  int open(const char *path, const char *mode = "r");
  int close();

  int ungetc(int c);
  int fputc(int c);
  int puts(const char *s);
  char *gets(char *s, int n);

  int printf(const char *fmt, ...);

  int eof();
  int flush();

  int fseek(long offset, int whence);

  void rewind();
  long ftell();
  // and other functions
  FILE *getfilepointer()
  {
    return fp;
  }
};
// now here comes the trouble these funtions use printf/scanf for input and output and
//  we have to remember all these specifiers which is quite hectic
//  next not all types of data have their format specifiers
//  no warning for mismatch of type specifiers

// for that we have better and cleaner approach iostream
// stream refers to the flow of the data
// standard streams are keyboard and monitor but can be redirected if needed

// cin istream_withassign
//     cout ostream_withassign

// an iostream system has three parts
// 1) buffer
// streambuf class

// 2)reporting error and control formats
// ios class

// translation system that convert classes into squence of characters
// istream, fstream, iostream;

// ios is the base of the hierachy al the classes share this data
//  has a pointer to streambuf class
// ios has members that help in manipulating the data stream as well flags for error control

int main()
{
  char filename[67], ch;

  printf("\nEnter the name of the fiel: ");
  scanf("%s", filename);
  file f(filenmae, "r");

  while (ch = fgetc(f.getfilepointer()) != EOF)
    printf("%c", ch);
}

// using classes
// file iostreams
// ofstream  out
// ifstream  in
// fstream  in | out

// modes
// in
// out
// binary
// ate
// app
// trunc

#include <iostream>
#include <fstream>
#include <ofstream>
#include <ifstream>
using namespace std;

int main()
{
  ofstream fout;
  string line;
  fout.open("sample.txt");
  while (fout)
  {
    getline(cin, line);

    if (line == "-1")
      break;

    fout << line << endl;
  }
  fout.close();

  ifstream fin;

  fin.open("sample.txt");
  while (getline(fin, line))
  {
    cout << line << endl;
  }
  fin.close();
  return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int rno, fee;
  string name;

  cout << "rno: ";
  cin >> rno;
  cout << "\nName: ";
  cin >> name;
  cout << "fee: ";
  cin >> name;

  ofstream fout("stud.doc");

  fout << rno << "\t" << name << "\t" << fee;

  fout.close();

  // ifstream fin("stud.doc");

  // fin >> rno >> name >> fee;
  // fin.close();
  // cout << endl
  //      << rno << "\n"
  //      << name << "\t" << fee;
}

#include <fstream>
using namespace std;

int main()
{
  ofstream outfile("sample.txt"); // outfile.open()
  outfile << "abcef" << endl;

  char ch = 'Z';
  int i = 25;
  float a = 473.14;
  string s = "hyper";

  outfile << ch << endl
          << i << endl
          << a << endl
          << s << endl;
  outfile.close();

  ifstream infile("sample.txt"); // set the mode

  infile >> ch >> i >> a >> s;
}

#include <fstream>

#include <iostream>
using namespace std;

int main()
{
  ofstream outfile("sample.txt");
  outfile << "line 1\n";
  outfile << "line 2\n";

  outfile.close();
  ifstream infile("sample.txt");

  string a, b;
  while (infile.eof()) // eof returns 0 if the end of file is reached
  {
    getline(infile, a);
    cout << endl
         << a;
  }
}

// binary i/o
#include <iostream>
#include <fstream>
using namespace std;
// suppose we wish to wrote special characters like class we gotta overload the operators and its gonna consume more memory each value is written as string not as binary bit
int main()
{
  struct employee
  {
    string name;
    int age;
    float basic;
    float gross;
  };
  employee e;
  char ch = 'Y';

  ofstream outfile;

  outfile.open("Emp.dat", ios::out | ios::binary);
  while (ch == 'Y')
  {
    cout << endl
         << "Enter a record: ";
    cin >> e.name >> e.age >> e.basic >> e.gross;

    outfile.write((char *)&e, sizeof(e)); // we type cast becaue write doesnot know how to write employee
    cout << "Add another record: ";
    cin >> ch;
  }

  outfile.close();
}

// error during io
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
  void report(ofstream &);
  ofstream file;
  file.open("sample.txt", noreplace);
  if (!file)
  {
    report(file);
    exit(1);
  }
  else
  {
    file << "fadad" << endl
         << "dfada";

    if (!file)
    {
      report(file);
      exit(2);
    }
  }
  file.close();
}

void report(ofstream &file)
{
  cout << "unable to opne file";
}

// program deleting a file copy the content into anohter file
// we implement pack(dele perm) adn delete(temp dele )

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
using namespace std;
class group
{
private:
  fstream file;
  struct person
  {
    char flag;
    char empcode[5];
    char name[40];
    int age;
    float sal;
  } p;

public:
  group();
  void addrec();
  void listrec();
  void modirec();
  void delrec();
  void recallrec();
  void packrec();
  void exit();
};

int main()
{
  char choice;
  group g;

  do
  {

    cout << "1.Add records: " << endl;
    cout << "2.List records: " << endl;
    cout << "3:Modify records:" << endl;
    cout << "4.delete records:  " << endl;
    cout << "5.recall records:  " << endl;
    cout << "6 pack records:  " << endl;
    cout << "7. exit: " << endl;
    cout << "Your choice?  " << endl;
    cin >> choice;

    switch (choice)
    {
    case '1':
      g.addrec();
    case '2':
      g.listrec();
      break;
    case '3':
      g.modirec();
      g.listrec();
      break;
    case '4':
      g.delrec();
      g.listrec();
      break;
    case '5':
      g.recallrec();
      g.listrec();
      break;
    case '6':
      g.packrec();
      g.listrec();

      break;
    case 7:
      g.exit(1);
      break;
    default:
      break;
    }
  } while (choice != 0);
}
group::group()
{
  file.open("./Emp", ios::binary | ios::in | ios::out);

  if (!file)
  {
    cout << "unable to open" << endl;
    exit(1);
  }
}

void group::addrec()
{
  char ch;
  file.seekp(0L, ios::end);

  do
  {
    cout << "enter emp code,name,age & sal: " << endl;
    cin >> p.empcode >> p.name >> p.age >> p.sal;

    p.flag = ' ';

    file.write((char *)&p, sizeof(p));
    cout << "Add another record?(Y/n): ";
    cin >> ch;
  } while (ch == 'y' || ch == 'Y');
}

void group::listrec()
{
  int j = 0, a;

  file.seekg(0L, ios::beg);

  while (file.read((char *)&p, sizeof(p)))
  {
    if (p.flag != '*')
    {
      cout << "REcord #" << ++j << setw(6) << p.empcode
           << setw(20) << p.name
           << setw(4) << p.age
           << setw(9) << p.sal;
      cout << endl;
    }
  }

  file.clear();
  cout << endl
       << "press any key..";
}

void group::modirec()
{
  char code[5];
  int count = 0;
  long int pos;
  cout << "Enter emp code : ";
  cin >> code;

  file.seekg(0L, ios::beg);

  while (file.read((char *)&p, sizeof(p)))
  {
    if (strcmp(p.empcode, code) == 0)
    {
      // ask for new data
      cout << "Enter new record: " << endl;
      cin >> p.empcode >> p.name >> p.age >> p.sal;
      p.flag = ' ';

      // put the pointer such that existing record is overwritten

      pos = count * sizeof(p);
      file.seekp(pos, ios::beg);
      file.write((char *)&p, sizeof(p));
    }

    count++;
  }

  cout << "No emp details found with th code =" << code;
  cout < endl << "press any key..";
  getch();
  file.clear();
}

void group::delrec()
{
  char code[5];
  long int pos;
  int count = 0;

  cout << "Employee code : ";
  cin >> code;

  file.seekg(0l, ios::beg);

  while (file.read((char *)&p, sizeof(p)))
  {
    if (strcmp(p.empcode, code))
    {
      p.flag = '*';

      pos = count * sizeof(p);

      file.seekp(pos, ios::beg);

      file.write((char *)&p, sizeof(p));
      return;
    }
    count++;
  }

  cout << "No record of the employee";
  cout << endl
       << "press any key to escape...";
  getch();
  file.clear();
}

void group::recallrec()
{
  char code[5];

  cout << "Enter emp code ";
  cin >> code;

  file.seekg(0l, ios::beg);

  while (file.read((char *)&p, sizeof(p)))
  {
    p.flag = ' ';

    ppos = count * sizeof(p);
    file.seekp(pos, ios::beg);
    file.write((char *)&p, sizeof(p));
    return;
  }
  count++;

  cout << "no employee found with teh code = " << code;
  cout << endl
       << "press any key to escape: ";
  getch();
  file.clear();
}

void group::packrec()
{
  ofstream outfile;
  outfile.open("temp", ios::out);

  file.seekg(0, ios::beg);

  while (file.read((char *)&p, sizeof(p)))
  {
    if (p.flag != '*')
      outfile.write((char *)&p, sizeof(p));
  }

  outfile.close();
  file.close();
  remove("Emp.dat");
  rename("temp", "Emp.dat");
  file.open("emp.dat", ios::binary | ios::in | ios::out | ios::_Nocreate);
}
void group::exit()
{
  file.close();
}
// each stream has two pointer get and put
// the value of get tell where the character are to be read
// and put pointer tell us where to put the value
// seekp,seekg and we also have tellg and tellp for current pos

// when we reach the end of file we get ios::state set
// even repositioning the get pointer change the fact
// we use file.clear()

// command line arguments
// int main(int argc,char * argv)

// ios has state var which specifies the various states of teh program
// eofbit
// failbit
// badbit
// hardbit /

// various functions available for that
// if (!file) or if(file.is_open()) ///both work

// streambuf class to use buffers

#include <iostream>
#include <fstream>

int main()
{
  char source[67].target[67];
  char ch;

  cout << endl
       << "Enter source file name: ";
  cin >> source;

  cout << "enter target name:  ";
  cin >> target;
  // rdbuf() pointer every stream has this pointer that points to teh streambuf class
  outfile << infile.rdbuf(); // all the content of infile is transferred in one step //one line copy
}
// cstyle file handling

// fopen(filenmae,modeof operation )
// r w a r+ w+ a+ rb wb ab rb+ wb+ ab+
// returns a pointer to file else null
// Type *File
// fclose(fp)
// fgetc(demo)//read
// feof(demo) end of file
// getc(demo) return eof at end and when fails
// fgets(str,max,filestream)
// gets(str)

// fprintf(fptr, format, vars);
// fscanf(ptr,format,storage)
// fread(add,sizeof,1,fileptr)
// fseek(filestream,longoffset,int orging)
// SEEK_SET
// SEEK_CUR
// SEEK_END

// rewind(File *stream)
// vector of pair sort sorts them on the basis of first element

// overload << >>
#include <strstream> //for io in mem

// classes inside classes
// container ship or inheritance
// kind of  // inheritance
// has of // cs

class carburettor
{
};
class car
{
  carburettor c;
}

////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
// special features of cpp
#include <iostream>
#include <string>

using namespace std;

class carburetor
{
private:
  char type;
  float const;
  string mfr;

public:
  void setData(char t, float c, string s)
  {
    type = t;
    cost = c;
    mfr = s;
  }

  void displayData()
  {
    cout << type << endl;
  }
};
class car
{
private:
  string model;
  string driverType;

public:
  void setData(string a, string b)
  {
    model = a;
    driverType = b;
  }

  void displayData()
  {
    cout << model << driverType << endl;
  }
  carburetor c; // embedded obj keep it private and make the change in the class
}

int
main()
{
  car myCar;
  myCar.c.setData('a', 89, "mico");
  myCar.setData("sports", "4-w");

  myCar.c.displayData();
  myCar.displayData();
}

// friend functions
// some type we wish to modify the private functions outside the class
// two unreleated class it is where we use friend functions

#include <iostream>
using namespace std;
class two; // class cannot be refereed until declared
class one
{
private:
  int data1;

public:
  one()
  {
    data1 = 10;
  }

  friend int accessboth(one, two);
};
class two
{
private:
  int data2;

public:
  two()
  {
    data2 = 12;
  }
  friend int acessboth(one, two);
};

int acessnoth(one a, two b)
{
  return (a.data1 + b.data2);
}

// write driver

// overload << >>
#include <iostream>
class complex
{
private:
  double real, imag;

public:
  complex()
  {
  }

  complex(double r, double i)
  {
    real = r;
    imag = i;
  }

  friend ostream &operator<<(ostream &s, complex &c);
  friend istream &operator>>(istream &s, complex &c);
};

ostream &operator<<(ostream &s, complex &c)
{
  s << "{" << c.real << ", " << c.imag << " )";
  return s;
}

istream &operator>>(istream &s, complex c)
{
  s >> c.real >> c.imag;
  return s;
}

// uses of friend
// friend classes
// class two;
// class one
// {
//   friend two;
// }

// smart pointers
