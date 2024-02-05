// Author: Saiyam Jain
// License: MIT LICENSE

#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Point
{
private:
    int x_coord, y_coord;
    double r, theta;

    friend class Line;
    friend class CartesianPlane;

public:
    Point(void) : x_coord(0), y_coord(0), r(0.0), theta(0.0){};
    Point(const int x, const int y)
    {
        x_coord = x;
        y_coord = y;
        r = sqrt(static_cast<double>(x_coord * x_coord) + y_coord * y_coord);
        theta = atan2(static_cast<double>(y_coord), static_cast<double>(x_coord));
    }
    Point(const double r_, const double theta_)
    {
        r = r_;
        theta = theta_;
        x_coord = static_cast<int>(r * cos(theta));
        y_coord = static_cast<int>(r * sin(theta));
    }
    Point(const Point &a) : x_coord(a.x_coord), y_coord(a.y_coord), r(a.r), theta(a.theta){};
    Point(const int coords[2])
    {
        x_coord = coords[0];
        y_coord = coords[1];
        r = sqrt(static_cast<double>(x_coord * x_coord) + y_coord * y_coord);
        theta = atan2(static_cast<double>(y_coord), static_cast<double>(x_coord));
    }
    Point(const double coords[2])
    {
        r = coords[0];
        theta = coords[1];
        x_coord = static_cast<int>(r * cos(theta));
        y_coord = static_cast<int>(r * sin(theta));
    }

    // Distance formula
    double distance(const Point &p) const;
    friend double operator-(const Point &p1, const Point &p2);

    // Midpoint formula
    Point midpoint(const Point &p) const;
    friend Point operator%(const Point &p1, const Point &p2);

    operator Point() const
    {
        Point temp(*this);
        return temp;
    }

    vector<double> get_coords(bool polar = false) const;

    friend ostream& operator<<(ostream &out, const Point &p);
};
double Point::distance(const Point &p) const
{
    return *this - p;
}
double operator-(const Point &p1, const Point &p2)
{
    return sqrt(pow(static_cast<double>(p2.x_coord) - p1.x_coord, 2) + pow(static_cast<double>(p2.y_coord) - p1.y_coord, 2));
}
Point Point::midpoint(const Point &p) const
{
    return *this % p;
}
Point operator%(const Point &p1, const Point &p2)
{
    return Point((p2.x_coord + p1.x_coord) / 2, (p2.y_coord + p1.y_coord) / 2);
}
vector<double> Point::get_coords(bool polar) const
{
    switch(polar)
    {
    case true:
        return {r, theta};
        break;

    case false:
        return {static_cast<double>(x_coord), static_cast<double>(y_coord)};
        break;
    }
}
ostream& operator<<(ostream &out, const Point &p)
{
    out << "{" << p.x_coord << ", " << p.y_coord << "}";
    return out;
}

class Line
{
private:
    Point point1, point2;

public:
    Line(void) : point1(Point()), point2(Point()){};
    Line(const int x1, const int y1, const int x2, const int y2) : point1(Point(x1, y1)), point2(Point(x2, y2)){};
    Line(const Line &l) : point1(l.point1), point2(l.point2){};
    Line(const double r1, const double theta1, const double r2, const double theta2) : point1(Point(r1, theta1)), point2(Point(r2, theta2)){};
    Line(const Point &p1, const Point &p2) : point1(p1), point2(p2){};
    Line(const int coords1[2], const int coords2[2]) : point1(Point(coords1)), point2(Point(coords2)){};
    Line(const double coords1[2], const double coords2[2]) : point1(Point(coords1)), point2(Point(coords2)){};

    // Slope formula
    double slope(void) const;

    // Intercept formula
    double get_x_intercept() const;
    double get_y_intercept() const;

    // Check if a point lies on a line
    bool check_if_lies(const int x1, const int x2) const;
    bool check_if_lies(const double r1, const double theta) const ;
    bool check_if_lies(const Point& p) const;
    bool check_if_lies(const int coords[2]) const;
    bool check_if_lies(const double coords[2]) const;

    // Comparing lines
    bool parallel(const Line &l) const;
    bool perpendicular(const Line &l) const;

    operator Line() const
    {
        Line temp(*this);
        return temp;
    }

    vector<double> get_coords(bool polar = false) const;

    friend ostream& operator<<(ostream &out, const Line &l);
};
double Line::slope(void) const
{
    return static_cast<double>(point2.y_coord - point1.y_coord) / static_cast<double>(point2.x_coord - point1.x_coord);
}
double Line::get_x_intercept() const
{
    return -point1.y_coord / slope() + point1.x_coord;
}
double Line::get_y_intercept() const
{
    return slope() * (-point1.x_coord) + point1.y_coord;
}
bool Line::check_if_lies(const int x, const int y) const
{
    if(point1.x_coord / point2.y_coord == x / y && (x - point1.x_coord) / (point2.x_coord - point1.x_coord) == (y - point1.y_coord) / (point2.y_coord - point1.y_coord))
    {
        return true;
    }
    else 
    {
        return false;
    }
}
bool Line::check_if_lies(const double r, const double theta) const
{
    int x = static_cast<int>(r * cos(theta));
    int y = static_cast<int>(r * sin(theta));

    if(point1.x_coord / point2.y_coord == x / y && (x - point1.x_coord) / (point2.x_coord - point1.x_coord) == (y - point1.y_coord) / (point2.y_coord - point1.y_coord))
    {
        return true;
    }
    else 
    {
        return false;
    }
}
bool Line::check_if_lies(const Point& p) const
{
    if(p.x_coord / p.y_coord == p.x_coord / p.y_coord && (p.x_coord - point1.x_coord) / (point2.x_coord - point1.x_coord) == (p.y_coord - point1.y_coord) / (point2.y_coord - point1.y_coord))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Line::check_if_lies(const int coords[2]) const
{
    return check_if_lies(coords[0], coords[1]);
}
bool Line::check_if_lies(const double coords[2]) const
{
    return check_if_lies(coords[0], coords[1]);
}
bool Line::parallel(const Line &l) const
{
    return slope() == l.slope();
}
bool Line::perpendicular(const Line &l) const
{
    return slope() * l.slope() == -1.0;
}
vector<double> Line::get_coords(bool polar) const
{
    vector<double> coords1 = point1.get_coords(polar);
    vector<double> coords2 = point2.get_coords(polar);

    return {coords1[0], coords1[1], coords2[0], coords2[1]};
}
ostream& operator<<(ostream &out, const Line &l)
{
    out << "[" << l.point1 << ", " << l.point2 << "]";
    return out;
}

class CartesianPlane
{
private:
    map<string, Point> points;
    map<string, Line> lines;

public:
    CartesianPlane(void){};
    CartesianPlane(const vector<pair<string, Point>> &points, const vector<pair<string, Line>> &lines)
    {
        for (const auto &point : points)
        {
            this->points.insert(point);
        }

        for (const auto &line : lines)
        {
            this->lines.insert(line);
        }
    }

    void add_point(const string &name, const Point &p)
    {
        points.insert({name, p});
    }

    void add_line(const string &name, const Line &l)
    {
        lines.insert({name, l});
    }

    Point get_point(const string &name) const
    {
        auto it = points.find(name);
        if (it != points.end())
        {
            return it->second;
        }
        else
        {
            throw invalid_argument("Point not found");
        }
    }

    Line get_line(const string &name) const
    {
        auto it = lines.find(name);
        if (it != lines.end())
        {
            return it->second;
        }
        else
        {
            throw invalid_argument("Line not found");
        }
    }

    vector<vector<double>> get_lines(void) const
    {
        vector<vector<double>> line_coords;
        for (const auto &pair : lines)
        {
            vector<double> coords = pair.second.get_coords();
            line_coords.push_back(coords);
        }
        return line_coords;
    }

    vector<string> get_point_names(void) const
    {
        vector<string> names;
        for (const auto &pair : points)
        {
            names.push_back(pair.first + " {" + to_string(pair.second.get_coords()[0]) + ", " + to_string(pair.second.get_coords()[1]) + '}');
        }
        return names;
    }

    vector<string> get_line_names(void) const
    {
        vector<string> names;
        for (const auto &pair : lines)
        {
            vector<double> coords = pair.second.get_coords();
            names.push_back(pair.first + " {" + to_string(coords[0]) + ", " + to_string(coords[1]) + ", " + to_string(coords[2]) + ", " + to_string(coords[3]) + '}');
        }
        return names;
    }
};

int main()
{
    Point p1;
    const Point p2(5, 6);
    Point p3(7.81025, 0.8761);
    Point p4(p3);
    Point p5({5, 6});
    Point p6({7.81025, 0.8761});
    cout << p1.distance(p2) << endl;
    cout << p1 - p2 << endl;
    cout << p1.midpoint(p2) << endl;
    cout << p1 % p2 << endl;
    p1 = p4;
    cout << p1 << endl;
    vector<double> coordsp5 = p5.get_coords(true);
    vector<double> coordsp6 = p6.get_coords();
    for(vector<double>::iterator itr = coordsp5.begin(); itr != coordsp5.end(); ++itr)
    {
        cout << *itr << ' ';
    }
    cout << endl;
    for(vector<double>::iterator itr = coordsp6.begin(); itr != coordsp6.end(); ++itr)
    {
        cout << *itr << ' ';
    }
    cout << endl;
    
    Line l1;
    Line l2(1, 2, 3, 8);
    Line l3(l1);
    Line l4(5.5, 6.0, 3.678, 43.56);
    Line l5(p1, p2);
    Line l6({1, 2}, {6, 8});
    Line l7({5.5, 6.0}, {3.679, 43.65});

    Line l_a(0, 1, 2, 1), l_b(0, 2, 2, 2);
    Line l_A(1, 0, 1, 3), l_B(3, 1, 3, 4);
    cout << l4.slope() << endl;
    cout << l2.get_x_intercept() << endl;
    cout << l2.get_y_intercept() << endl;
    cout << l2.perpendicular(l2) << endl;
    cout << l2.parallel(l2) << endl;
    l1 = l5;
    cout << l1 << endl;
    cout << l_a.slope() << " " << l_b.slope() << " " << l_A.slope() << " " << l_B.slope() << " " << l4.slope() << endl;
    vector<double> coordsl6 = l6.get_coords(true);
    vector<double> coordsl7 = l7.get_coords();
    for(vector<double>::iterator itr = coordsl6.begin(); itr != coordsl6.end(); ++itr)
    {
        cout << *itr << ' ';
    }
    cout << endl;
    for(vector<double>::iterator itr = coordsl7.begin(); itr != coordsl7.end(); ++itr)
    {
        cout << *itr << ' ';
    }
    
    return 0;
}


// class CartesianPlane
// {
//     private:
//         int x_axis, y_axis;

//     public:
//         CartesianPlane(int x_len = 0, int y_len = 0)
//         {
//             x_axis = x_len;
//             y_axis = y_len;
//         }

//         // Plotting functions for points and lines
//         void plot(int x = 0, int y = 0)
//         {
//             for(int i = y_axis; i >= -y_axis; i--)
//             {
//                 for(int j = -x_axis; j <= x_axis; j++)
//                 {
//                     if(i == y && j == x)
//                     {
//                         cout << " @ ";
//                     }
//                     else if(i == 0 && j == 0)
//                     {
//                         cout << " + ";
//                     }
//                     else if(j == 0)
//                     {
//                         cout << " | ";
//                     }
//                     else if(i == 0)
//                     {
//                         cout << " - ";
//                     }
//                     else
//                     {
//                         cout << "   ";
//                     }
//                 }
//                 cout << endl;
//             }
        
//         }

//         void plot(Point p)
//         {
//             plot(p.x_coord, p.y_coord);
//         }

//         void plot(Line l)
//         {
//             for(int i = y_axis; i >= -y_axis; i--)
//             {
//                 for(int j = -x_axis; j <= x_axis; j++)
//                 {
//                     if(l.check_for_point(i, j))
//                     {
//                         cout << " @ ";
//                     }
//                     else if(i == 0 && j == 0)
//                     {
//                         cout << " + ";
//                     }
//                     else if(j == 0)
//                     {
//                         cout << " | ";
//                     }
//                     else if(i == 0)
//                     {
//                         cout << " - ";
//                     }
//                     else
//                     {
//                         cout << "   ";
//                     }
//                 }
//                 cout << endl;
//             }
//         }

//         void plot(Point a, Point b) //Plot a line from two given points
//         {
//             Line l(a, b);
//             plot(l);
//         }
// };

// int main()
// {

//     return 0;
// }