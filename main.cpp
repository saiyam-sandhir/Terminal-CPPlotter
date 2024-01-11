// Author: Saiyam Jain
// License: MIT LICENSE

#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Point
{
    private:
        int x_coord, y_coord;
        double r, theta;

        friend class CartasianPlane;

    public:
        Point(const int x = 0, const int y = 0)
        {
            x_coord = x;
            y_coord = y;
            r = static_cast<double>(x_coord * x_coord) + y_coord * y_coord;
            theta = acos(static_cast<double>(x_coord) / r);
        }
        Point(const double r_ = 0.0, const double theta_ = 0.0)
        {
            r = r_;
            theta = theta_;
            x_coord = static_cast<int>(r * cos(theta));
            y_coord = static_cast<int>(r * sin(theta));
        }
        Point(const Point& a):x_coord(a.x_coord), y_coord(a.y_coord), r(a.r), theta(a.theta){};
        Point(const int coords[2])
        {
            x_coord = coords[0];
            y_coord = coords[1];
            r = static_cast<double>(x_coord * x_coord) + y_coord * y_coord;
            theta = acos(static_cast<double>(x_coord) / r);
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
        friend double operator-(const Point& p1, const Point& p2);

        // Midpoint formula
        Point midpoint(const Point &p) const;
        friend Point& operator%(const Point& p1, const Point& p2);

        operator Point() const
        {
            Point temp(*this);

            return temp;
        }

        template <typename T>
        vector<T> get_coords(bool polar = false) const;

        friend ostream& operator<<(ostream& out, const Point& p);
};
double Point::distance(const Point &p) const
{
    return *this - p;
}
double operator-(const Point& p1, const Point& p2)
{
    return sqrt(pow(static_cast<double>(p2.x_coord) - p1.x_coord, 2) + pow(static_cast<double>(p2.y_coord) - p1.y_coord, 2));
}

class Line
{
    private:
        Point point1, point2;

    public:
        Line(const int x1, const int y1, const int x2, const int y2):point1(Point(x1, y1)), point2(Point(x2, y2)){};
        Line(const Line& l):point1(l.point1), point2(l.point2){};
        Line(const double r1, const double theta1, const double r2, const double theta2):point1(Point(r1, theta1)), point2(Point(r2, theta2)){};
        Line(const Point& p1, const Point& p2):point1(p1), point2(p2){};
        Line(const int coords1[2], const int coords2[2]):point1(Point(coords1)), point2(Point(coords2)){};
        Line(const double coords1[2], const double coords2[2]):point1(Point(coords1)), point2(Point(coords2)){};

        // Slope formula
        double slope() const;
        
        // Intercept formula
        double get_x_intercept() const;
        double get_y_intercept() const;

        // Comparing lines
        bool parallel(const Line &l) const;
        bool perpendicular(const Line &l) const;
        friend bool operator|(const Line& l1, const Line& l2);
        friend bool operator_(const Line& l1, const Line& l2);

        // Distance formula
        int distance(const Point &p) const;
        int distance(const Line &l) const;
        friend int operator-(const Point& p, const Line& l);
        friend int operator-(const Line& l1, const Line& l2);

        // Slope-intercept formula
        string get_formula() const;

        friend ostream& operator<<(ostream& out, const Line& l);
};

class CartasianPlane
{
    private:
        int x_axis, y_axis;

        map<char, Point> saved_points;
        map<char, Line> saved_lines;

    public:
        CartasianPlane(int x_len = 0, int y_len = 0):x_axis(x_len), y_axis(y_len){};
        CartasianPlane(const CartasianPlane& c):x_axis(c.x_axis), y_axis(c.y_axis){};

        // Functions for explicitly changing the axes length
        inline void set_x_len(const int len){ x_axis = len; }
        inline void set_y_len(const int len){ y_axis = len; }
        void set_xy_len(const int len1, const int len2)
        { 
            x_axis = len1;
            y_axis = len2;
        }

        /*---------- POINTS ----------*/

            // Functions for saving points

                // Save a point given its x and y coordinates
                void save_point(const char name, const int x, const int y);

                // Save a point object
                void save_point(const char name, const Point& a);

                // Save a point given its x and y coordinates as an array
                void save_point(const char name, const int corrds[2]);

            // Functions for plotting points

                // Plot a point given its x and y coordinates
                void plot(const int x, const int y) const;

                // Plot a point object
                void plot(const Point& a) const;

                // Plot a saved point of the Cartesian plane object
                void plot(Point, const char name) const;

                // Plot a point given its x and y coordinates as an array
                void plot(const int corrds[2]) const;

                // Plot all the saved points
                void plot_all(Point) const;

            // Functions for deleting points

                // Delete a point given its name
                void delete_point(const char name);

                // Delete all the saved points
                void delete_all(Point);

            // Other Functions

                // Search for a saved point given its name
                bool find(Point, const char name) const;

                // Get a list(vector) of saved points
                vector<Point> get_points(void) const;

                // Get a list(vector) of saved point names
                vector<string> get_point_names(bool with_coords = false) const;

        /*----------------------------*/

        /*---------- LINES ----------*/

            // Functions for saving lines

                // Save a line given any two points that lie on the line
                void save_line(const char name, const int x1, const int y1, const int x2, const int y2);

                // Save a line given any two points that lie on the line as point objects
                void save_line(const char name, const Point a1, const Point a2);

                // Save a line given any two points' coordinates that lie on the line as arrays
                void save_line(const char name, const int coords1[2], const int corrds2[2]);

                // Save a line given a Line object
                void save_line(const char name, const Line& l);

            // Functions for plotting lines

                // Plot a line given any two points' x and y coordinates that lie on the line
                void plot(const int x1, const int y1, const int x2, const int y2) const;

                // Plot a line given any two point objects that lie on the line as endpoints
                void plot(const Point a1, const Point a2) const;

                // Plot a saved line of the Cartesian plane object
                void plot(Line, const char name) const;

                // Plot a line given any two points' coordinates as arrays that lie on the line
                void plot(const int coords1[2], const int corrds2[2]) const;

                // Plot a line given a Line object
                void plot(const Line& l) const;

                // Plot all the saved lines
                void plot_all(Line) const;

            // Functions for deleting lines

                // Delete a point given its name
                void delete_line(const char name);

                // Delete all the saved lines
                void delete_all(Line);

            // Other Functions

                // Search for a saved point given its name
                bool find(Line, const char name) const;

                // Get a list(vector) of saved lines
                vector<Line> get_lines(void) const;

                // Get a list(vector) of saved line names
                vector<string> get_line_names(void) const;

        /*---------------------------*/

        /*---------- BOTH ----------*/

            // Functions for plotting
            void plot_all(void) const;

            // Functions for deleting
            void delete_all(void);

        /*--------------------------*/

        /*---------- OPERATORS ----------*/

            // For assigning one cartasian plane to another
            operator CartasianPlane() const
            {
                CartasianPlane temp(*this);
                return temp;
            }

            // Adding(merging) two cartasian planes
            friend CartasianPlane operator+(const CartasianPlane cp1, const CartasianPlane cp2);

            // Subtracting(removing commons) two cartasian planes
            friend CartasianPlane operator-(const CartasianPlane cp1, const CartasianPlane cp2);

        /*-------------------------------*/
};

// class CartasianPlane
// {
//     private:
//         int x_axis, y_axis;

//     public:
//         CartasianPlane(int x_len = 0, int y_len = 0)
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