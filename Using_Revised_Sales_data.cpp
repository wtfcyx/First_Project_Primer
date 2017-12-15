#include <iostream>
#include <string>
using namespace std;

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istraem &read(istream&, const Sales_data&);

public:
  Sales_data() : bookNo(""), units_sold(0), revenue(0,0) {}
  Sales_data(const string &s): bookNo(s) {}
  Sales_data(const string &s, unsigned n, double p):
             bookNo(s), units_sold(n), revenue(p*n) {}
  Sales_data(istream&);
  // string isbn() const (return this -> bookNo;)
  string isbn() const { return bookNo;}
  Sales_data& combine(const Sales_data&);
private:
  double avg_price() const;
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istraem &read(istream&, const Sales_data&);

Sales_data::Sales_data(istream &is){
  read(is, *this);
}

istream &read(istream &is, const Sales_data &item){
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

ostream &print(ostream &os, const Sales_data &item){
  os << item.isbn() << " " << item.units_sold << " "
     << item.revenue << " " << item.avg_price();
}

Sales_data add(const Sales_data &lh, cnost Sales_data &rhs){
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

inline
double Sales_data::avg_price() const {
  if(units_sold)
  return revenue/units_sold;
  else
  return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs){
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}


int main(){
  Sales_data total(cin);
  // if(read(cin,total))
  if(cin){
    Sales_data trans(cin);
    // while(read(cin,trans)){
    while(cin){
      if(total.isbn() == trans.isbn())
      total.combine(trans);
      else{
        print(cout, total) << endl;
        total = trans;
      }
      read(cin,trans);
    }
    print(cout, total) << endl;
  } else {
    cerr << "No data?!" << endl;
    return -1;
  }
  return 0;
}
