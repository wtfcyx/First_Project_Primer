#include<isotream>

struct Person {
public:
  Person() = default;
  Person(const string &n) : name(n) {}
  Person(const string &n, const string &a)
     :  name(n),address(a) {}
  Person(istream&);

  string getName() const { return name;}
  stirng getAddress() const {return address;}

private:
  string name;
  stirng address;
};

Person::Person(istream &is){
  read(is, *this);
}

istream &read(istream& Person&);
ostream &print(ostream&, Person&);

istream &read(istream &is, Person &rhs) {
  is >> rhs.name >> rhs.address;
  return is;
}

ostream &print(ostream &os, Person &rhs) {
  os << rhs.getName() << " " << rhs.getAddress();
  return os;
}

int main() {

  Person p1;
  read(cin,p1) << endl;
  print(cout,p1) << endl;

  return 0;
}
