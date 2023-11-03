#include <iostream>
#include <cmath>
using namespace std;

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
};

int main()
{
    CartasianPlane cp(8, 7);
    
    cp.plot(3, 6);
    
    return 0;
}