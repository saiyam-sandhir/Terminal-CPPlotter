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

        double operator |(Point const& obj)
        {
            double distance;

            distance = sqrt(pow(obj.x_coord - x_coord, 2) + pow(obj.y_coord - y_coord, 2));
        
            return distance;
        }

        Point operator ^(Point const& obj)
        {
            Point res;

            res.x_coord = (x_coord + obj.x_coord) / 2;
            res.y_coord = (y_coord + obj.y_coord) / 2;

            return res;
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

        void plot(int x = 0, int y = 0)
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

        void plot(Point p)
        {
            plot(p.x_coord, p.y_coord);
        }
};

int main()
{
    CartasianPlane cp(3, 12);
    Point a(1, 0), b(1, 10), c;

    c = a^b;
    cp.plot(a);
    cout << endl;
    cp.plot(b);
    cout << endl;
    cp.plot(c);
    cout << endl;
    cout << (a|b);
    
    return 0;
}