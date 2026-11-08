#include <iostream>
#include <string>
using namespace std;

class VehicleNode{
	protected:
	string vehicleVIN;
	double operationalHours;
	public:
	VehicleNode(string vehicleVIN,double operationalHours): vehicleVIN(vehicleVIN),operationalHours(operationalHours){
	}
};
class ElectricVehicle : virtual public VehicleNode{
	protected:
	double batteryLevelCapacity;
	public:
	ElectricVehicle(string vehicleVIN,double operationalHours,double batteryLevelCapacity) :
	VehicleNode(vehicleVIN,operationalHours),batteryLevelCapacity(batteryLevelCapacity){
	}
};
class AutonomousVehicle : virtual public VehicleNode{
	protected:
	string sensorSuiteVersion;
	public:
	AutonomousVehicle(string vehicleVIN,double operationalHours,string sensorSuiteVersion) :
	VehicleNode(vehicleVIN,operationalHours),sensorSuiteVersion(sensorSuiteVersion){
	}
};
class AutonomousElectricTruck : public ElectricVehicle, public AutonomousVehicle{
	public:
	AutonomousElectricTruck(string vehicleVIN,double operationalHours,double batteryLevelCapacity,string sensorSuiteVersion) :
	VehicleNode(vehicleVIN,operationalHours),
	ElectricVehicle(vehicleVIN,operationalHours,batteryLevelCapacity),
	AutonomousVehicle(vehicleVIN,operationalHours,sensorSuiteVersion){
	}
	void generateFleetReport()const {
		cout<<"VIN : "<<vehicleVIN<<endl;
		cout<<"operational hours : "<<operationalHours<<endl;
		cout<<"battery capacity : "<<batteryLevelCapacity<<endl;
		cout<<"sensor version : "<<sensorSuiteVersion<<endl;
	}
};
int main(){
	AutonomousElectricTruck truck("VIN12345",1500.5,85.0,"v2.1");
	truck.generateFleetReport();

	cout<<"size of VehicleNode : "<<sizeof(VehicleNode)<<endl;
	cout<<"size of ElectricVehicle : "<<sizeof(ElectricVehicle)<<endl;
	cout<<"size of AutonomousVehicle : "<<sizeof(AutonomousVehicle)<<endl;
	cout<<"size of AutonomousElectricTruck : "<<sizeof(truck)<<endl;

	return 0;
}