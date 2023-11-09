//Author: Saiyam Jain
//License: MIT LICENSE

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    public:
        int x_coord, y_coord;

        Point(int x = 0, int y = 0)
        {
            x_coord = x;
            y_coord = y;
        }

        Point(Point& p)
        {
            x_coord = p.x_coord;
            y_coord = p.y_coord;
        }

        double operator |(Point const& obj) //Distance formula
        {
            double distance;

            distance = sqrt(pow(obj.x_coord - x_coord, 2) + pow(obj.y_coord - y_coord, 2));
        
            return distance;
        }

        Point operator ^(Point const& obj) //Midpoint formula
        {
            Point res;

            res.x_coord = (x_coord + obj.x_coord) / 2;
            res.y_coord = (y_coord + obj.y_coord) / 2;

            return res;
        }
};

class Line
{
    public:
        Point point1, point2;

        Line(Point a, Point b)
        {
            point1 = a;
            point2 = b;
        }

        Line(Line& l)
        {
            point1 = l.point1;
            point2 = l.point2;
        }

        bool check_for_point(Point p)
        {
            if(p.y_coord - point1.y_coord == ((point2.y_coord - point1.y_coord)/(point2.x_coord - point1.x_coord)*(p.x_coord - point1.x_coord)))
            {
                return true;
            }
            
            return false;
        }

        bool check_for_point(int x, int y)
        {
            Point p(x, y);
            return check_for_point(p);
        }
};

class CartasianPlane
{
    private:
        int x_axis, y_axis;

    public:
        CartasianPlane(int x_len = 0, int y_len = 0)
        {
            x_axis = x_len;
            y_axis = y_len;
        }

        void plot(int x = 0, int y = 0) //Plot from given coordinates
        {
            for(int i = y_axis; i >= -y_axis; i--)
            {
                for(int j = -x_axis; j <= x_axis; j++)
                {
                    if(i == y && j == x)
                    {
                        cout << " @ ";
                    }
                    else if(i == 0 && j == 0)
                    {
                        cout << " + ";
                    }
                    else if(j == 0)
                    {
                        cout << " | ";
                    }
                    else if(i == 0)
                    {
                        cout << " - ";
                    }
                    else
                    {
                        cout << "   ";
                    }
                }
                cout << endl;
            }
        
        }

        void plot(Point p) //Plot from given point object
        {
            plot(p.x_coord, p.y_coord);
        }

        void plot(Line l) //Plot from given line object
        {
            for(int i = y_axis; i >= -y_axis; i--)
            {
                for(int j = -x_axis; j <= x_axis; j++)
                {
                    if(l.check_for_point(i, j))
                    {
                        cout << " @ ";
                    }
                    else if(i == 0 && j == 0)
                    {
                        cout << " + ";
                    }
                    else if(j == 0)
                    {
                        cout << " | ";
                    }
                    else if(i == 0)
                    {
                        cout << " - ";
                    }
                    else
                    {
                        cout << "   ";
                    }
                }
                cout << endl;
            }
        }

        void plot(Point a, Point b) //Plot a line from two given points
        {
            Line l(a, b);
            plot(l);
        }
};

int main()
{
    CartasianPlane cp(12, 12);
    Point a(-2, 3), b(-5, 0), c;
    Line l(a, b);
\
    c = a^b;
    cp.plot(a);
    cout << endl;
    cp.plot(b);
    cout << endl;
    cp.plot(c);
    cout << endl;
    cout << (a|b);
    cout << endl;
    cp.plot(l);

    return 0;
}