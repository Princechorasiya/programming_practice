class Human
{
public:
  int height;
  int weight;
  int age;

  void setWright(int w)
  {
    weight = w;
  }
};

class Male : public Human
{
public:
  string color;
  void sleep()
  {
    cout << "lets fuck" << endl;
  }
};

class Animal
{
public:
  string sound;
  void bark()
  {
    cout << "animal speaking" << endl;
  }
};

class Human
{
public:
  string color;
  void speak()
  {
    cout << "human speaking" << endl;
  }
};

class hybrid : public Animal, public Human
{
};
class Dog : public Animal
{
  /// inherit in single mode
public:
  void bark()
  {
    cout << "Dog speaking" << endl;
  }
};

class German : public Dog
{
};