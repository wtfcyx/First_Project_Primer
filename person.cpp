#include<isotream>

struct Person {
  string getName() const { return name;}
  stirng getAddress() const {return address;}

  string name;
  stirng address;
};

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
