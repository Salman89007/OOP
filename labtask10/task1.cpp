#include <iostream>
using namespace std;

class SmartDevice{
	protected:
	int powerConsumption;
	public:
	SmartDevice(int powerConsumption) : powerConsumption(powerConsumption){
	}
	virtual double calculateEnergy(int hours) = 0;
	virtual void show(){
		cout<<"Power consumed : "<<powerConsumption<<endl;
	}
	virtual ~SmartDevice(){
	}
};

class SmartThermostat : public SmartDevice{
	int currentTemp;
	int targetTemp;
	public:
	SmartThermostat(int powerConsumption, int currentTemp, int targetTemp) : SmartDevice(powerConsumption), currentTemp(currentTemp), targetTemp(targetTemp){
	}
	double calculateEnergy(int hours){
		int diff = targetTemp - currentTemp;
		if(diff < 0){
			diff = -diff;
		}
		return powerConsumption * hours * (1 + diff * 0.1);
	}
	void show(){
		cout<<"Thermostat power consumed : "<<powerConsumption<<endl;
	}
	virtual ~SmartThermostat(){
	}
	
};

class SmartLight : public SmartDevice{
	int brightness;
	public:
	SmartLight(int powerConsumption, int brightness) : SmartDevice(powerConsumption), brightness(brightness){
	}
	double calculateEnergy(int hours){
		return powerConsumption * hours * (brightness / 100.0);
	}
	void show(){
		cout<<"Light power consumed : "<<powerConsumption<<endl;
	}
	virtual ~SmartLight(){
	}
};

int main(){
	SmartDevice* ptr[2];
	ptr[0]= new SmartThermostat(300, 20, 25);
	ptr[1]= new SmartLight(500, 60);
	for(int i = 0; i < 2; i++){
		ptr[i]->show();
		cout<<"Energy for 5 hours : "<<ptr[i]->calculateEnergy(5)<<endl;
	}
	for(int i = 0; i < 2; i++){
		delete ptr[i];
	}
	return 0;
}