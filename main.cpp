#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Shape {
protected:
  double x, y;

public:
  Shape(double x, double y) : x(x), y(y) {}
  virtual double area() const = 0;
  virtual ~Shape() {};
};

class Circle : public Shape {
protected:
  double rad;

public:
  Circle(double x, double y, double rad) : Shape(x, y) { this->rad = rad; }
  virtual double area() const { return M_PI * rad * rad; }
  virtual ~Circle() {};
};

class Rectangle : public Shape {
protected:
  double a, b;

public:
  Rectangle(double x, double y, double a, double b) : Shape(x, y) {
    this->a = a;
    this->b = b;
  }
  virtual double area() const { return a * b; }
  virtual ~Rectangle() {};
};

vector<Shape *> V;

int main() {
  Circle x1(1, 3, 5);
  Circle x2(2, 3, 6);
  Circle x3(1, 3, 7);
  Rectangle y1(2, 5, 7, 8);

  V.push_back(&x1);
  V.push_back(&x2);
  V.push_back(&x3);
  V.push_back(&y1);

  for (int i = 0; i < V.size(); ++i) {
    double d = V[i]->area();
    cout << d << "\n";
  }
  return 0;
}