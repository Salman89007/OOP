#include <iostream>
#include <vector>
using namespace std;

class DrawableShape{
	public:
	DrawableShape(){
	}
	virtual double area() = 0;
	virtual void draw() = 0;
	virtual ~DrawableShape(){
		cout<<"DrawableShape Destroyed "<<endl;
	}
};

class CircleShape : public DrawableShape{
	double radius;
	public:
	CircleShape(double radius) : DrawableShape(), radius(radius){
	}
	double area(){
		return 3.14159 * radius * radius;
	}
	void draw(){
		cout<<"Drawing Circle with radius "<<radius<<endl;
	}
	virtual ~CircleShape(){
		cout<<"CircleShape Destroyed "<<endl;
	}
};

class RectangleShape : public DrawableShape{
	double width;
	double height;
	public:
	RectangleShape(double width, double height) : DrawableShape(), width(width), height(height){
	}
	double area(){
		return width * height;
	}
	void draw(){
		cout<<"Drawing Rectangle "<<width<<" x "<<height<<endl;
	}
	virtual ~RectangleShape(){
		cout<<"RectangleShape Destroyed "<<endl;
	}
};

int main(){
	vector<DrawableShape*> shapes;
	shapes.push_back(new CircleShape(5));
	shapes.push_back(new RectangleShape(4, 6));
	shapes.push_back(new CircleShape(2.5));
	shapes.push_back(new RectangleShape(10, 3));
	for(int i = 0; i < shapes.size(); i++){
		shapes[i]->draw();
		cout<<"Area : "<<shapes[i]->area()<<endl;
	}
	for(int i = 0; i < shapes.size(); i++){
		delete shapes[i];
	}
	shapes.clear();
	return 0;
}