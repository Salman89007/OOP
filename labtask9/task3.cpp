#include <iostream>
#include <string>
using namespace std;

class RadarSystem{
	protected:
	double targetDistance;
	double targetAzimuth;
	public:
	RadarSystem(double targetDistance,double targetAzimuth): targetDistance(targetDistance),targetAzimuth(targetAzimuth){
	}
	void renderDisplay()const {
		cout<<"radar sweep -> distance : "<<targetDistance<<" , azimuth : "<<targetAzimuth<<endl;
	}
};
class NavigationSystem{
	protected:
	double gpsLatitude;
	double gpsLongitude;
	public:
	NavigationSystem(double gpsLatitude,double gpsLongitude): gpsLatitude(gpsLatitude),gpsLongitude(gpsLongitude){
	}
	void renderDisplay()const {
		cout<<"terrain map grid -> latitude : "<<gpsLatitude<<" , longitude : "<<gpsLongitude<<endl;
	}
};
class HeadsUpDisplay : public RadarSystem, public NavigationSystem{
	private:
	bool nightVisionActive;
	public:
	HeadsUpDisplay(double targetDistance,double targetAzimuth,double gpsLatitude,double gpsLongitude,bool nightVisionActive) :
	RadarSystem(targetDistance,targetAzimuth),NavigationSystem(gpsLatitude,gpsLongitude),nightVisionActive(nightVisionActive){
	}
	void renderDisplay()const {
		cout<<"night vision : "<<(nightVisionActive ? "ON" : "OFF")<<endl;
		RadarSystem::renderDisplay();
		NavigationSystem::renderDisplay();
	}
	void renderTacticalOverlay(bool radarMode,bool navMode)const {
		if(!radarMode && !navMode){
			cout<<"no mode selected"<<endl;
			return;
		}
		if(radarMode){
			RadarSystem::renderDisplay();
		}
		if(navMode){
			NavigationSystem::renderDisplay();
		}
	}
};
int main(){
	HeadsUpDisplay hud(12.5,45.0,33.6844,73.0479,true);

	cout<<"--- full display ---"<<endl;
	hud.renderDisplay();

	cout<<"--- radar only ---"<<endl;
	hud.renderTacticalOverlay(true,false);

	cout<<"--- navigation only ---"<<endl;
	hud.renderTacticalOverlay(false,true);

	cout<<"--- both modes ---"<<endl;
	hud.renderTacticalOverlay(true,true);

	cout<<"--- no mode ---"<<endl;
	hud.renderTacticalOverlay(false,false);

	cout<<"--- explicit base calls ---"<<endl;
	hud.RadarSystem::renderDisplay();
	hud.NavigationSystem::renderDisplay();

	return 0;
}