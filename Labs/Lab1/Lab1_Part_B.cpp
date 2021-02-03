#include <iostream>
#include <string>
using namespace std;
class Point
{
private:
  double array[2];

public:
  Point()
  {
    for (int i = 0; i < 2; i++)
    {
      array[i] = 0;
    }
  }
  Point(const Point &obj)
  {
    x = obj.x;
    y = obj.y;
  }
  Point &operator(const Point &obj)
  {
  }
  ~Point()
  {
  }
  double GetX const()
  {
    return x;
  }
  double GetY const()
  {
    return y;
  }
  void SetX()
  {
    array[0] = x;
  }
  void SetY()
  {
    array[1] = y;
  }
  string ToString() const
  {
    stringstream out;
    out << x.setprecision(2) << ", " << y.setprecision(2) << endl;
    return out.str();
  }
  friend ostream &Operator << (ostream &const Point3D &obj)
  {
    cut << obj.ToString();
    return cut;
  }
};