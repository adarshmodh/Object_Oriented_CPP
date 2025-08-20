/*
Implement the Prototype design pattern.

The Prototype is a creational design pattern that allows an object to copy itself. It is particularly useful when the creation of an object is more convenient through copying an existing object than through creation from scratch.

Your are given a Shape prototype interface that supports cloning itself within the Rectangle and Square classes.

You need to implement the following:

The clone() method in the Rectangle class which returns a new instance of the Rectangle class.
The clone() method in the Square class which returns a new instance of the Square class.
The cloneShapes() method in the Test class which returns a list of cloned shapes.
*/


#include <iostream>
using namespace std;

class Shape {
public:
    virtual ~Shape() {}
    virtual Shape* clone() const = 0;
};

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    Shape* clone() const override {
        // Write your code here
        auto cloneRectangle = new Rectangle(this->width, this->height);
        return cloneRectangle;
    }
};

class Square : public Shape {
private:
    int length;

public:
    Square(int l) : length(l) {}

    int getLength() const {
        return length;
    }

    Shape* clone() const override {
        // Write your code here
        auto cloneSquare = new Square(this->length);
        return cloneSquare;
    }
};

class Test {
public:
    vector<Shape*> cloneShapes(const vector<Shape*>& shapes) {
        // Write your code here
        vector<Shape*> newClones;
        for (const auto& shape : shapes){
            newClones.push_back(shape->clone());
        }
        return newClones;         
    }
};
