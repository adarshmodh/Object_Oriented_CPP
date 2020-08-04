#include <iostream>


using namespace std;
/*
 * Create classes Rectangle and RectangleArea

Sample Input
10 5

Sample Output
10 5
50

 */

class Rectangle{
    private:
        
    public:
        int width, height;
        virtual void display() const{
            cout<< width << " " << height << endl;
        }
};

class RectangleArea : public Rectangle{
    private:
        int area;
    public:
        void read_input(){
            cin >> width >> height ;
        }
        void display() const{
            // area = width*height;
            cout<< (width*height) << endl;
        }   
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}