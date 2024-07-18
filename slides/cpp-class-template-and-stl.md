# C++ 类、模板和 STL

1. C++ 类和对象
1. 重载
1. 构建类的层次结构
1. C++ 模板
1. C++ STL（标准模板库）
1. 实用技巧

		
## C++ 类和对象

- 类（class）是结构体（structure）的一个扩展，其中不仅仅包括数据，同时也包括基于这些数据完成特定功能的函数。
- 类中定义的数据称作“数据成员”，也称为“属性（property）”。
- 类中定义的函数称作“函数成员”；根据用途的不同，可进一步区分为构造器（constructor）、析构器（destructor）、设置器（setter）、获取器（getter）或者方法（method）。
- 对象（object）是类的一个实例（instance），每个类的对象有自己的实例数据。类的对象在实例化时，会自动调用其构造器。
- C++ 中，`class` 关键词定义一个类；
- 在正式项目中，C++ 类的定义通常置于独立的头文件中，以方便其他模块引用。

	
```cpp
class Rectangle {
    double width, height;

  public:
    // Rectangle 类的构造器（constructor)
    Rectangle(double w, double h) {
        width = w; height = h;
    }

    // Rectangle 类的 perimeter 方法（method)，用于计算周长。
    double perimeter(void) {
        return (width + height) * 2.0;
    }

    // Rectangle 类的 area 方法，用于计算面积。
    double area(void) {
        return width * height;
    }
};

    Rectangle rc_a {20.0, 20.0};
    Rectangle rc_b {20.0, 10.0};
    cout << rc_a.perimeter() << endl;
    cout << rc_b.area() << endl;
```

	
### 课堂练习

（十分钟内完成）

1) 基于上面的示例代码，实现 `Circle` 类。
2) 保存为 `circle.cpp`，调试通过后提交到自己的作业仓库。

	
### 补充属性获取器和设置器

```cpp
class Rectangle {
    double _w, _h;

  public:
    // Rectangle 的默认构造器
    Rectangle() {
        _w = 0; _h = 0;
    }

    Rectangle(double w, double h) {
        _w = w; _h = h;
    }

    // Rectangle 的属性设置器（setter），用于设置 width 属性
    void setWidth(double w) {
        _w = w;
    }

    // Rectangle 的属性设置器（setter），用于设置 height 属性
    void setHeight(double h) {
        _h = h;
    }

    // Rectangle 的属性获取器（getter），用于获取 width 属性
    double width() const {
        return _w;
    }

    // Rectangle 的属性获取器（getter），用于获取 height 属性
    double height() const {
        return _h;
    }

    double perimeter(void) {
        return (_w + _h) * 2.0;
    }

    double area(void) {
        return _w * _h;
    }
};

    Rectangle rc;
    double w, h;
    cin >> w >> h;
    rc.setWidth(w);
    rc.setHeight(h);

    cout << "Perimter: " << rc.perimeter() << endl;
    cout << "Area: " << rc.area() << endl;
```

	
### 类对象的生命周期

- 在局部范围（scope）内定义的类对象，其生命周期在程序执行跳出对应范围时终止。
- 在全局范围内定义的类对象，其生命周期在整个程序执行结束时终止。
- 当类对象的生命周期结束时，将自动调用其析构器。

```cpp
#include <iostream>

class Rectangle {
    double width, height;

  public:
    // Rectangle 类的默认构造器（constructor)
    Rectangle(): width(0), height(0) {
        std::cout << "Constructor called" << std::endl;
    }

    // Rectangle 类的构造器（constructor)
    Rectangle(double w, double h) {
        width = w; height = h;
    }

    // Rectangle 类的析构器（destructor)
    ~Rectangle() {
        std::cout << "Destructor called" << std::endl;
    }
    ...
};

// global_rc 对象生命周期在整个程序运行时有效。
Rectangle global_rc;

int foo()
{
    Rectangle rc;       // rc 对象生命周期在整个 foo 函数中有效。
                        // 每进入一次 foo() 函数，将新构造一个 rc 对象。

    {                           // 花括号定义了一个新的（匿名）名字空间
        Rectangle another_rc;   // another_rc 甚至可以用 rc 这个名称。
        ...
                                // 名字空间结束，another_rc 对象的生命周期结束。
    }

    return 0;           // 函数返回时，rc 对象的生命周期结束。
                        // 析构器将被调用。
}
```

		
## 类的其他特性

### 成员的可访问性

- 为什么要定义类成员的可访问性（accessibility）？
- C++ 通过声明符（declarator） `public`、`private` 等定义类成员的可访问性；默认为 `private`。
- 类成员的默认可访问性为 `private`，表示该等成员数据或者成员函数，只能在该类的成员函数中访问。
- 可访问性为 `public` 的成员，可在非该类的成员函数中访问。通常，不降成员数据设定为 `public`。
- 在 C++ 中，也可以使用 `struct` 定义类，但其成员函数和成员数据默认均具有 `public` 的可访问性。
- 在 C++ 中，也可以针对 `enum union` 定义成员函数，所有成员函数默认具有 `public` 的可访问性。

	
### 成员函数的说明符

- 成员函数的说明符（specifier）用于修改函数的某些特性，置于函数参数列表之后，函数体之前。
- `const` 说明符：表示该成员函数不会修改该类对象的成员数据；类的获取器通常具有 `const` 属性。
- 不包含 `const` 说明符的成员函数，被认为可能修改类对象的成员数据，故而不能被具有 `const` 修饰词的类指针使用。

```cpp
Rectangle rc;
const Rectangle *p = &rc;

p->width();             // width() 获取器具有 const 说明符
p->setWidth(10);        // 报编译错误
```

		
## 重载

- 重载（overload）是面向对象编程中一个重要的方法。
- 在 C++ 中，运算符、普通函数、类的虚拟（virtual）成员函数，均可以被重载。
- 编译器根据运算符左右操作数（operand）的类型、普通函数的参数类型、真实的类名称确定真正调用的函数。

	
### 普通函数的重载

```cpp
#include <cmath>

long int rounded_addition(long a, long b = 0)
{
    int r;
    r = a + b;
    return r;
}

long int rounded_addition(double a, double b = 0)
{
    return lround(a) + lround(b);
}

    auto rz = rounded_addition(5, 3);
    cout << "The result is " << rz << endl;

    auto rf = rounded_addition(5.4, 3.6);
    cout << "The result is " << rf << endl;
```

	
### 运算符重载

- 不能自定义运算符。
- 不是所有的运算符均可重载。
- 运算符重载必须发生在某个操作数的类型是类或枚举类型时。
- 某些运算符只能定义为类成员。
- [参考链接：C++运算符的重载规则](https://www.cnblogs.com/summernight/p/8541079.html)

```cpp
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

long int& operator<< (long int& l, string &str)
{
    l = lround(stod(str));
    return l;
}

int main()
{
    long int a = (long int)5.6;
    long int b;
    string s("5.6");

    b << s;

    cout << a << endl;      // 5
    cout << b << endl;      // 6
}
```

	
### 重载 `<<` 运算符

- 自定义左值（lvalue）类型为 `ostream&` 右值（rvalue）类型为 `Rectangle&` 的 `<<` 运算符，可实现 `Rectangle` 类的定制输出。
- `ostream` 是全局对象 `cout` 的类名。

```cpp
ostream &operator<< (ostream &os, Rectangle &rc) {
    os << "Rectangle (" << rc.width() << " x " << rc.height() << ")";
    return os;
}

    Rectangle rc {20.0, 30.0};
    cout << "Perimter of " << rc << ": " << rc.perimeter() << endl;
    cout << "Area of " << rc << ": " << rc.area() << endl;
```

	
### 重载 `>>` 运算符

- 类似地，自定义左值类型为 `istream&`，右值类型为 `Rectangle&` 的 `>>` 运算符，可实现 `Rectangle` 类的定制输入。
- `istream` 是全局对象 `cin` 的类名称。

```cpp
istream &operator>> (istream &is, Rectangle &rc)
{
    double w, h;

    is >> w >> h;

    rc.setWidth(w);
    rc.setHeight(h);
    return is;
}

    Rectangle rc_c;
    cin >> rc_c;
    cout << "Perimter of " << rc_c << ": " << rc_c.perimeter() << endl;
    cout << "Area of " << rc_c << ": " << rc_c.area() << endl;
```

	
### `std::endl` 到底是个啥？

- `std::endl` 不是字符串字面量（`"\n"`），而是一个函数。
- `ostream` 类的 `<<` 运算符允许其右值为一个特定类型的函数指针；对应的运算符效果是调用对应的函数。
- 而 `std::endl` 和 `std::flush` 就是这类函数。

```cpp
ostream& operator<< (ostream& (*pf)(ostream&));

ostream& endl(ostream& os);
ostream& flush(ostream& os);
```

- 因此，以下两行代码的执行效果是相同的：

```cpp
    std::cout << "Hello" << std::endl;
    std::cout << "Hello"; std::cout.endl();
```

	
### 操作器

- 在 C++ 语言中，`std::endl` 等可用于运算符右值的函数，有一个特别的名字，称作 `操作器（manipulator）`。
- 操作器可方便地被内嵌于串接在一起的多个运算符中。
- `<iomanip>` 头文件中定义了大量操作器：
   - `setprecision(int n)`：设置浮点数的输出精度（小数点位数）。
   - `setbase(int base)`：设置整数的输出进制（8、10、16）。
   - `setfill(char_type c)`：设置填充字符。
   - `setw(int n)`：设置输出宽度（输出字符不足设定的宽度时，使用填充字符）。
   - [参考链接](https://cplusplus.com/reference/iomanip/)

	
### 操作器的使用

```cpp
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

  double f = 3.14159;
  std::cout << std::setprecision(2) << f << std::endl;
  // Output: 3.14

  std::cout << std::setbase(16) << std::setfill('*') << std::setw(5)
        << 255 << std::endl;
  // Output: ***ff

  return 0;
}
```

	
### 课堂练习

（十五分钟内完成）

1) 照猫画虎，继续完善自己的 `Circle` 类，实现默认构造器、属性获取器和设置器，以及两个运算符重载函数。
2) 将增强版本提交到自己的作业仓库。

		
## 构建类的层次结构

- 将不同的公共接口归纳到基类（base class）中定义，并在子类（派生类，derived class）中按需要重载。
- 虚函数是可在派生类中重新定义的成员函数；尤其是，在基类中标记为 `= 0` 的虚函数必须在派生类中定义，否则无法实例化。
- 在派生类中重载虚函数，实现面向对象当中的多态（polymorphism）。
- 当使用基类的指针或对基类的引用来引用派生的类对象时，为该对象调用虚函数时，C++ 将调用真实对象对应的派生类定义的虚函数版本。

```cpp
class Basic2DShape {
  public:
    virtual double perimeter(void) = 0;
    virtual double area(void) = 0;

    virtual void write(ostream &os) = 0;
    virtual void read(istream &is) = 0;
};

/* 通过调用基类的虚函数实现 << 运算符的重载，从而该重载只需要实现一次。 */
ostream &operator<< (ostream &os, Basic2DShape &rc)
{
    rc.write(os);
    return os;
}

/* 通过调用基类的虚函数实现 >> 运算符的重载，从而该重载只需要实现一次。 */
istream &operator>> (istream &is, Basic2DShape &rc)
{
    rc.read(is);
    return is;
}

    // 不管是 Rectangle 还是 Circle 类，均具有相同的接口和用法
    Rectangle rc;
    cin >> rc;
    cout << "Perimter of " << rc << ": " << rc.perimeter() << endl;
    cout << "Area of " << rc << ": " << rc.area() << endl;

    Circle circle;
    cin >> circle;
    cout << "Perimter of " << circle << ": " << circle.perimeter() << endl;
    cout << "Area of " << circle << ": " << circle.area() << endl;
```

	
### 基于基类实现 `Rectangle` 类

```cpp
class Rectangle: public Basic2DShape {
    double _w, _h;

  public:
    Rectangle() {
        _w = 0; _h = 0;
    }

    Rectangle(double w, double h) {
        _w = w; _h = h;
    }

    ...

    virtual double perimeter(void) override {
        return (_w + _h) * 2.0;
    }

    virtual double area(void) override {
        return _w * _h;
    }

    virtual void write(ostream &os) override {
        os << "Rectangle (" << _w << " x " << _h << ")";
    }

    virtual void read(istream &is) override {
        is >> _w >> _h;
    }
};
```

	
### 基于基类实现 `Circle` 类

```cpp
class Circle: public Basic2DShape {
    double _r;

  public:
    Circle() {
        _r = 0;
    }

    Circle(double r) {
        _r = r;
    }

    void setRadius(double r) {
        _r = r;
    }

    double radius() const {
        return _r;
    }

    virtual double perimeter(void) override {
        return 2.0 * M_PI * _r;
    }

    virtual double area(void) override {
        return M_PI * _r * _r;
    }

    virtual void write(ostream &os) override {
        os << "Circle (" << _r << ")";
    }

    virtual void read(istream &is) override {
        is >> _r;
    }
};
```

		
## C++ 模板

- C++ 引入的模板，可用来实现代码的类型无关（泛型编程），从而大幅提高开发效率。
- 在 C++ 中，可使用模板定义函数、类，分别称为函数模板、类模板。

```cpp
int summary(int a, int b)
{
    return a+b;
}

double summary(double a, double b)
{
    return a+b;
}

float summary(float a, float b)
{
    return a+b;
}

long double summary(long double a, long double b)
{
    return a+b;
}
```

	
### 函数模板

```cpp
template <class T>
T summary(T a, T b)
{
  return a+b;
}

    auto x = summary<int>(10, 20);
    auto y = summary<double>(10.03, 20.01);
    auto z = summary<long double>(10.00003L, 20.00009L);
```

	
### 类模板

```cpp
template <class T>
class Pair {
    T values[2];

  public:
    Pair(T first, T second)  {
      values[0] = first; values[1] = second;
    }

    T max();
    T min();
};

template <class T>
T Pair<T>::max()
{
    T retval;
    retval = values[0] > values[1] ? values[0] : values[1];
    return retval;
}

template <class T>
T Pair<T>::min()
{
    T retval;
    retval = values[0] > values[1] ? values[1] : values[0];
    return retval;
}

    Pair<double> coordinates(100.0, 75.0);
    cout << coordinates.max() << endl;
```

	
### 课堂练习

（十五分钟内完成）

1) 基于上面的示例代码，实现一个 `Triple` 类模板，并增加一个 `average()` 方法。
2) 保存为 `template-triple.cpp`，调试通过后提交到自己的作业仓库。

		
## C++ STL（标准模板库）

- C++ STL（standard template library，标准模板库）是 C++ 的标准库。
- C++ STL 通过类模板和函数模板实现了大量的基础数据结构、算法和功能，如输入输出、字符串、容器、迭代器等。

	
### 输入输出模块类的层次结构

<img class="r-frame" style="height:auto;width:100%;" src="assets/cpp-iostream.gif" />

	
### `cin`、`cout`、`cerr`、`clog` 对象

- 标准输入输出对象在 C++ 程序启动时被自动创建。
- 标准对象 `cout` 和 `cin` 分别是 `ostream` 和 `istream` 类的实例，而 `ostream` 和 `istream` 分别是 `basic_ostream` 和 `basic_istream` 类模板的实例。
- 标准对象 `cin` 对应 C 的标准输入流（`stdin`）；未被重定向的情况下，标准输入为键盘。
- 标准对象 `cout` 对应 C 的标准输出流（`stdout`）；未被重定向的情况下，标准输出为终端（屏幕终端或者伪终端）。
- 标准对象 `cerr` 对应 C 的标准错误输出流（`stderr`）；未被重定向的情况下，同标准输出，但不带缓冲区。
- 标准对象 `clog` 是 C++ 定义的标准日志输出流，默认保持和 `cerr` 的同步。

	
### `ostream` 类的接口

- 格式化输出：通过运算符 `<<` 提供。
- 无格式化输出：通过 `put()` 方法和 `write()` 方法提供。
- 定位：通过 `tellp()` 和 `seekp()` 方法提供。
- 同步（刷新缓冲）：通过 `flush()` 方法提供。
- 控制格式化输出的行为：通过基类 `ios_base` 的方法提供，如 `flags()`、`setf()`、`precision()`、`width()` 等。
- [参考链接：ostream](https://cplusplus.com/reference/ostream/ostream/)

```cpp
#include <iostream>     // std::cout, std::ios

using namespace std;

int main() {
    cout.flags(ios::right           // 右对齐
            | ios::hex              // 十六进制
            | ios::showbase);       // 显示 `0x` 前缀
    cout.width(10);                 // 设定输出宽度，不足时添加空格为前缀或后缀
    cout << 255 << '\n';
}
```

	
### `istream` 类的接口

- 格式化输入：通过运算符 `>>` 提供。
- 无格式化输入：通过 `get()`、`getline()`、`read()` 方式提供。
- 定位：通过 `tellg()` 和 `seekg()` 方法提供。
- 同步输入缓冲区：通过 `sync()` 方法提供。
- [参考链接：istream](https://cplusplus.com/reference/istream/istream/)

```cpp
#include <iostream>     // std::cin, std::cout

using namespace std;

int main()
{
    char title[256], name[256];

    cout << "Please enter your title: ";

    // 一直读取直到 '\n' 为止；会自动追加 '\0' 字符。
    // 如果输入超过 256，则会截断；防止缓冲区溢出。
    cin.getline(title, 256);

    cout << "Please enter your name: ";
    cin.getline(name, 256);

    cout << "Hello, " << title << " " << name << endl;
}
```

	
### `ofstream` 和 `ifstream` 类

- `ofstream` 类是 `ostream` 类的子类，用于向普通文件中写入数据。
- `ifstream` 类是 `istream` 类的子类，用于从普通文件中读入数据。
- 通过 `open()` 和 `close()` 方法打开和关闭文件。
- [参考链接：fstream](https://cplusplus.com/reference/fstream/)

```cpp
#include <iostream>     // std::cout
#include <fstream>      // std::ofstream and std::ifstream

using namespace std;

int main()
{
    ofstream ofs;
    ofs.open("test.txt", ofstream::out);
    ofs << "The first line" << endl;
    ofs << "The second line" << endl;
    ofs.close();

    ifstream ifs;
    ifs.open("test.txt", ifstream::in);

    while (true) {
        char c = ifs.get();
        if (c == EOF)
            break;
        cout << c;
    }

    ifs.close();
}
```

	
### `stringstream` 类

- `stringstream` 类是 `iostream` 类的子类。
- 通过 `stringstream` 类，可对字符串中的内容执行格式化输入和输出；也就是说，`stringstream` 类支持 `<<` 和 `>>` 运算符。
- [参考链接：stringstream](https://cplusplus.com/reference/sstream/)

```cpp
#include <sstream>

    string astr("1234 5678");
    int a, b;
    stringstream(astr) >> a >> b;       // a = 1234, b = 5678
```

	
### `string`、`u16string`、`u32string` 类

- `string` 类是 `basic_string` 类模板的一个实例，其中的字符类型为 `char`，也就是 8 位字符，主要用于处理 ASCII 字符串以及兼容 ASCII 的 UTF-8 等编码字符串。
- `u16string` 类是 `basic_string` 类模板的一个实例，其中的字符类型为 `char16_t`，也就是 16 位字符，可处理常见语言的字符。
- `u32string` 类是 `basic_string` 类模板的一个实例，其中的字符类型为 `char32_t`，也就是 32 位字符，可处理所有 Unicode 标准定义的字符。
- [参考链接：string](https://cplusplus.com/reference/string/)

	
- 基于函数模板以及 `string` 等类，STL 提供了 `stoi()`、`stoull()`、`stod()` 等函数，可分别解析字符串对象并返回对应的整数、无符号长整数或者双精度浮点数等。

```cpp
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoull

using namespace std;

int main()
{
    string str = "8246821 0xffff 020 -1";
    string::size_type sz = 0;   // alias of size_t

    while (!str.empty()) {
        unsigned long long ull = stoull(str, &sz, 0);
        cout << str.substr(0, sz) << " interpreted as " << ull << '\n';
        str = str.substr(sz);
    }
}
```

	
### 课堂练习

（五分钟内完成）

1) 复制上面的示例代码，修改代码使 `cout` 以十六进制形式输出整数。
2) 保存为 `strtoull.cpp`，调试通过后提交到自己的作业仓库。

	
- STL 提供针对基础数据类型的 `to_string()` 函数，可基于整数、浮点数等构造 `string` 对象。

```cpp
string to_string(int val);
string to_string(long val);
string to_string(long long val);
string to_string(unsigned val);
string to_string(unsigned long val);
string to_string(unsigned long long val);
string to_string(float val);
string to_string(double val);
string to_string(long double val);
```

	
### `array` 类模板

- `array` 类模板可用于定义任意数据类型和类的固定大小的序列容器。
- 相比数组，使用 `array` 类可通过迭代器获得更加灵活的数据处理手段。
- [参考链接：array](https://cplusplus.com/reference/array/)

```cpp
#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 6> primes { 2, 3, 5, 7, 11, 13 };

    for (size_t i = 0; i < primes.size(); i++) {
        cout << primes[i] << endl;
    }
}
```

	
### `vector` 类模板

- `vector` 类模板可用于定义任意数据类型和类的可变大小的序列容器。
- `array` 对象的大小（单元个数）不可变，但 `vector` 类对象的大小可变。
- [参考链接：vector](https://cplusplus.com/reference/vector/)

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> primes { 2, 3, 5, 7 };

    primes.push_back(11);
    primes.push_back(13);
    primes.push_back(17);
    primes.push_back(19);

    for (size_t i = 0; i < primes.size(); i++) {
        cout << primes[i] << endl;
    }
}
```

	
### 迭代器

- 迭代器（iterator）常见于面向对象编程语言，它提供了以某种方向遍历容器或数组中特定范围内元素的抽象方法。
- 在 C++ 中，`iterator` 以类模板的形式提供，在 `<iterator>` 中定义，可在其上执行 `+=`、`-=`、`++`、`--` 等操作，表示使迭代器向前或者向后几次。
- 通过 STL 为容器类提供的 `begin()` 和 `end()` 等函数，可创建对应的迭代器对象。

	
- 迭代器示例

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int main()
{
    array<int, 4> primes_10 { 2, 3, 5, 7 };

    for (auto it = begin(primes_10); it != end(primes_10); ++it) {
        cout << *it << endl;
    }

    vector<int> primes { 2, 3, 5, 7, 11 };

    primes.push_back(13);
    primes.push_back(17);
    primes.push_back(19);

    for (auto it = begin(primes); it != end(primes); ++it) {
        cout << *it << endl;
    }

    string hexchars("0123456789ABCDEF");
    for (auto it = begin(hexchars); it != end(hexchars); ++it) {
        cout << *it << endl;
    }
}
```

	
### 基于迭代器的常用算法函数模板

- 基于迭代器，STL 以函数模板的形式提供了针对容器中元素的各种操作或功能；常用的如：
   1. `transform()`：对容器中的单元做转换。
   1. `sort()`：对容器指定范围内的单元执行排序。
   1. `reverse()`：翻转容器中指定范围内的单元顺序。
   1. `binary_search()`：在已排序的容器之指定范围内执行二分搜索。
   1. `shuffle()`：对容器内指定范围内的单元做乱序处理。

	
- `transform()` 示例

```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char my_tolower(char c)
{
    return tolower(c);
}

int main()
{
    string hexchars("0123456789ABCDEF");

    transform(hexchars.begin(), hexchars.end(), hexchars.begin(), my_tolower);

    cout << hexchars << endl;
}
```

	
- `sort()` 示例

```cpp
#include <iostream>
#include <string>
#include <algorithm>    // std::shuffle and std::sort
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

using namespace std;

bool islessthan(char c1, char c2)
{
    return c1 < c2;
}

int main()
{
    string hexchars("0123456789ABCDEF");

    // obtain a time-based seed:
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(hexchars.begin(), hexchars.end(), default_random_engine(seed));
    cout << hexchars << endl;

    sort(hexchars.begin(), hexchars.end(), islessthan);

    cout << hexchars << endl;
}
```

		
## 实用技巧

### 条件编译

利用预处理指令 `#if`、`#ifdef`、`#ifndef` 等按指定的条件过滤语句块。

- `NDEBUG` 通常由编译器定义，表明正在编译程序的发布（Release）版本。可在程序中使用这个宏包含调试用代码：

```cpp
#ifndef NDEBUG
    // 仅用于发布版本的代码。
#else
    // 包含用于调试版本的代码，比如测试用代码。
    assert(...);
#endif
```

	

- 利用 `#if 0`可以屏蔽代码块，其效果和块注释相同，但看起来更加简洁。

```cpp
    char en;

#if 0
    en = (*p + 7);
    if (en > 'z') {
        en = 'a' + en - 'z' - 1;
    }
#else
    en = *p - 'A';
    en += 7;
    en %= 26;
    en += 'A';
#endif
```

		
## 作业

1) 使用层次化的类重构上一讲中的 `calc-areas.cpp` 程序。运行效果不变。

	
2) 输入一行英文句子（最长 4096 个字符），找出其中最长的单词并输出其长度（提示：使用 `string` 类的 `.substr()` 方法分割句子中的一个个单词，并使用 `vector` 保存分割后的单词）。运行效果如下：

```console
$ ./find-longest-word
<I Love China.>
China 5
```

	
3) 编程找到尽可能多的亲和数（提示：使用 `vector` 保存某个整数的真因子）。运行效果如下：

```console
$ ./amicable-pairs
220 284
1184 1210
2620 2924
5020 5564
6232 6368
10744 10856
12285 14595
17296 18416
63020 76084
66928 66992
67095 71145
69615 87633
79750 88730
100485 124155
122265 139815
122368 123152
141664 153176
142310 168730
171856 176336
180848 176272
185368 203432
196724 202444
280540 365084
308620 389924
319550 430402
356408 399592
437456 455344
469028 486178
503056 514736
522405 525915
600392 669688
609928 686072
624184 691256
635624 712216
643336 652664
667964 783556
726104 796696
802725 863835
879712 901424
898216 980984
947835 1125765
9980104 1043096
9363544 9437056
...
```

	
4) 使用埃氏素数筛算法找出小于 `UINT64_MAX` 的所有素数，然后使用 `<algorithm>` 中的 `binary_search()` 函数快速判断给定的正整数是否为素数。运行效果如下：

```console
$ ./primes
<12 3 1979 2 5 99>
F T T T T F
```

	
5) 给定任意整数 `n`，列出用于计算 `D(n)` 和 `O(n)` 的所有可能形式（提示：使用 `vector` 保存分解后的整数）。运行效果如下：

```console
$ ./dn-on
<3>
3
2 1
---
3
1 1 1
```

	
### 参考链接

- [素数筛](https://oi-wiki.org/math/number-theory/sieve/)

