#include <iostream>
#include <string>
using namespace std;

class Screen {
public:
  using pos = string::size_type;
  using content_type = char;

  Screen &set(char);
  Screen &set(pos, pos, char);

  Screen &display(ostream &os){
    do_display(os); return *this;
  }

  const Screen &display(ostream &os) const {
    do_display(os); return *this; }
  }

  Screen() = default;
  Screen(pos ht, pos wd)
      :  height(ht), width(wd), contents(ht*wd, ' ') {}
  Screen(pos ht, pos wd, content_type c)
      :  height(ht), width(wd), contents(ht*wd, c) {}

  const content_type &get() const { return contents[cursor];}
  content_type &get() { return contents[cursor]; }
  const content_type &get(pos row, pos col) const;
  content_type &get(pos row, pos col);

  Screen &move(pos row, pos col);

private:
  pos cursor = 0;
  pos width = 0;
  pos height = 0;
  string contents;

  void do_display(ostream &os) const {os << contents;}
};

inline
Screen &Screen::set(char c){
  contents[cursor] = c;
  return *this;
}

inline
Screen &Screen::set(pos r, pos col, char ch){
  contents[r*width + col] = ch;
  return *this;
}

inline
const Screen::content_type &Screen::get(pos row, pos col) const {
  return contents[row*width + col];
}

inline
Screen::content_type &Screen:get(pos row, pos col){
  return contents[row*width + col];
}

inline
Screen &Screen::move(pos row, pos col) {
  cursor = row*width + col;
  return *this;
}

int main() {
  return 0;
}
