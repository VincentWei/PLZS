# C++ 类、模板和 STL

1. C++ 类和对象
1. C++ 模板
1. C++ STL（标准模板库）

		
## C++ 类和对象

- 类（class）是结构体（structure）的一个扩展，其中不仅仅包括数据，同时也包括基于这些数据完成特定功能的函数。
- 类中定义的数据称作“数据成员”，也称为“属性（property）”。
- 类中定义的函数称作“函数成员”；根据用途的不同，可进一步区分为设置器（setter）、获取器（getter）或者方法（method）。
- 对象（object）是类的一个实例（instance），每个类的对象有自己的实例数据。
- C++ 中，可使用 `struct` 或者 `class` 关键词定义一个类。
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
2) 保存为 `circle.cpp` 并提交到自己的作业仓库。

	
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

	
### 重载 `<<` 运算符

- 自定义左值类型为 `ostream` 右值类型为 `Rectangle` 的 `<<` 运算符，可实现 `Rectangle` 类的定制输出。
- `ostream` 是全局对象 `cout` 的类名称。

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

- 类似地，自定义左值类型为 `istream`，右值类型为 `Rectangle` 的 `>>` 运算符，可实现 `Rectangle` 类的定制输入。
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

	
### 课堂练习

（十五分钟内完成）

1) 照猫画虎，继续完善自己的 `Circle` 类，实现默认构造器、属性获取器和设置器，以及两个运算符重载函数。
2) 将增强版本提交到自己的作业仓库。

	
### 构建类的层次结构

- 将不同的公共接口归纳到基类中定义，并在子类中按需要重载。
- C++ 中可被子类重载的成员函数称为“虚函数”。
- 在子类中重载虚函数，实现面向对象当中的多态（polymorphism）。

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

	
- 基于基类实现 `Rectangle` 类

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

    virtual double perimeter(void) {
        return (_w + _h) * 2.0;
    }

    virtual double area(void) {
        return _w * _h;
    }

    virtual void write(ostream &os) {
        os << "Rectangle (" << _w << " x " << _h << ")";
    }

    virtual void read(istream &is) {
        is >> _w >> _h;
    }
};
```

	
- 基于基类实现 `Circle` 类

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

    virtual double perimeter(void) {
        return 2.0 * M_PI * _r;
    }

    virtual double area(void) {
        return M_PI * _r * _r;
    }

    virtual void write(ostream &os) {
        os << "Circle (" << _r << ")";
    }

    virtual void read(istream &is) {
        is >> _r;
    }
};
```

		
## C++ 模板

- C++ 引入的模板，可用来实现代码的类型无关（泛型编程），从而大幅提高开发效率。
- 在 C++ 中，可使用模板定义函数、类等。

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
    auto z = summary<long double>(10.00003l, 20.00009l);
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

1) 基于上面的示例代码，实现一个 `Triple` 模板类。
2) 保存为 `template-triple.cpp` 并提交到自己的作业仓库。

		
## C++ STL（标准模板库）

- C++ STL（standard template library，标准模板库）是 C++ 的标准库。
- C++ STL 通过类模板和函数模板实现了大量的基础数据结构、算法和功能，如输入输出、字符串、容器、迭代器等。
- 标准对象 `cout` 和 `cin` 分别是 `ostream` 和 `istream` 类的实例，而 `ostream` 和 `istream` 分别是 `basic_ostream` 和 `basic_istream` 类模板的实例。
- `string` 类是 `basic_string` 类模板的一个实例，其中的字符类型为 `char`，也就是 8 位字符。
- `u16string` 类是 `basic_string` 类模板的一个实例，其中的字符类型为 `char16_t`，也就是 16 位字符。
- `u32string` 类是 `basic_string` 类模板的一个实例，其中的字符类型为 `char32_t`，也就是 32 位字符。

	
- 基于函数模板以及 `string` 等类，STL 提供了 `stoi()`、`stoull()`、`stod()` 等函数，可将字符串对象分别转换为整数、无符号长整数或者双精度浮点数等。
- `array` 类模板可用于定义任意数据类型和类的固定大小的序列容器。
- `vector` 类模板可用于定义任意数据类型和类的可变大小的序列容器。
- STL 为容器类提供了用于迭代器的模板函数：`begin()` 和 `end()`。
- 基于迭代器，STL 以函数模板的形式提供了针对容器中元素的各种操作或功能，如 `transform()`、`sort()` 等。

	
### `string` 类


	
### `array` 模板类


	
### `vector` 模板类

	
### 迭代器

	
### 基于迭代器的常用算法函数模板


		
## 作业

1) 使用层次化的类重构上一讲中的 `calc-areas.cpp` 程序。运行效果不变。

	
2) 

	
### 作业回顾

