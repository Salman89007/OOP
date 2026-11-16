#include <iostream>
using namespace std;

class VehicleSensor{
	protected:
	double x;
	double y;
	public:
	VehicleSensor(double x, double y) : x(x), y(y){
		cout<<"VehicleSensor Created "<<endl;
	}
	void setCalibration(double newX, double newY){
		x = newX;
		y = newY;
	}
	virtual void show(){
		cout<<"Calibration coordinates : ("<<x<<", "<<y<<")"<<endl;
	}
	virtual ~VehicleSensor(){
		cout<<"VehicleSensor Destroyed "<<endl;
	}
};

class LidarSensor : virtual public VehicleSensor{
	protected:
	int range;
	public:
	LidarSensor(double x, double y, int range) : VehicleSensor(x, y), range(range){
		cout<<"LidarSensor Created "<<endl;
	}
	void show(){
		cout<<"Lidar range : "<<range<<endl;
	}
	virtual ~LidarSensor(){
		cout<<"LidarSensor Destroyed "<<endl;
	}
};

class CameraSensor : virtual public VehicleSensor{
	protected:
	int resolution;
	public:
	CameraSensor(double x, double y, int resolution) : VehicleSensor(x, y), resolution(resolution){
		cout<<"CameraSensor Created "<<endl;
	}
	void show(){
		cout<<"Camera resolution : "<<resolution<<endl;
	}
	virtual ~CameraSensor(){
		cout<<"CameraSensor Destroyed "<<endl;
	}
};

class FusionModule : public LidarSensor, public CameraSensor{
	public:
	FusionModule(double x, double y, int range, int resolution) : VehicleSensor(x, y), LidarSensor(x, y, range), CameraSensor(x, y, resolution){
		cout<<"FusionModule Created "<<endl;
	}
	void show(){
		cout<<"Fusion Module"<<endl;
		cout<<"Lidar range : "<<range<<endl;
		cout<<"Camera resolution : "<<resolution<<endl;
		cout<<"Calibration coordinates : ("<<x<<", "<<y<<")"<<endl;
	}
	virtual ~FusionModule(){
		cout<<"FusionModule Destroyed "<<endl;
	}
};

int main(){
	FusionModule* fm = new FusionModule(1.5, 2.5, 200, 1080);
	fm->show();
	fm->setCalibration(10.0, 20.0);
	fm->show();
	VehicleSensor* ptr = fm;
	delete ptr;
	return 0;
}