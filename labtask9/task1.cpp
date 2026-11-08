#include <iostream>
#include <string>
using namespace std;

class PatientRecord{
	protected:
	double* vitalsHistory;
	int logCount;
	public:
	PatientRecord(double *ptr,int logCount): vitalsHistory(ptr),logCount(logCount){
	}
	PatientRecord(const PatientRecord &other){
		this->logCount = other.logCount;
		this->vitalsHistory = new double[logCount];
		for(int i=0;i<logCount;i++){
			this->vitalsHistory[i] = other.vitalsHistory[i];
		}
	}
	PatientRecord& operator=(const PatientRecord &other){
		if(this != &other){
			delete[] vitalsHistory;
			this->logCount = other.logCount;
			this->vitalsHistory = new double[logCount];
			for(int i=0;i<logCount;i++){
				this->vitalsHistory[i] = other.vitalsHistory[i];
			}
		}
		return *this;
	}
	void show()const {
		cout<<"log count : "<<logCount<<endl;
		for(int i=0;i<logCount;i++){
			cout<<vitalsHistory[i]<<endl;
		}
	}
	virtual ~PatientRecord(){
		cout<<"freeing memory of base class ...."<<endl;
		delete[] vitalsHistory;
	}
};
class ICUPatientRecord : public PatientRecord{
	private:
	string* alertMessages;
	int alertCount;
	int severityLevel;
	public:
	ICUPatientRecord(double *ptr,int logCount,string* alertMessages,int alertCount,int severityLevel) :
	PatientRecord(ptr,logCount),alertMessages(alertMessages),alertCount(alertCount),severityLevel(severityLevel){
	}
	ICUPatientRecord(const ICUPatientRecord &other) : PatientRecord(other){
		this->alertCount = other.alertCount;
		this->severityLevel = other.severityLevel;
		this->alertMessages = new string[alertCount];
		for(int i=0;i<alertCount;i++){
			this->alertMessages[i] = other.alertMessages[i];
		}
	}
	ICUPatientRecord& operator=(const ICUPatientRecord &other){
		if(this != &other){
			PatientRecord::operator=(other);
			delete[] alertMessages;
			this->alertCount = other.alertCount;
			this->severityLevel = other.severityLevel;
			this->alertMessages = new string[alertCount];
			for(int i=0;i<alertCount;i++){
				this->alertMessages[i] = other.alertMessages[i];
			}
		}
		return *this;
	}
	void addAlert(string msg){
		string* temp = new string[alertCount+1];
		for(int i=0;i<alertCount;i++){
			temp[i] = alertMessages[i];
		}
		temp[alertCount] = msg;
		delete[] alertMessages;
		alertMessages = temp;
		alertCount++;
	}
	void evaluateEmergencyStatus(){
		for(int i=0;i<logCount;i++){
			if(vitalsHistory[i] < 60 || vitalsHistory[i] > 100){
				addAlert("Abnormal heart rate at log " + to_string(i) + " : " + to_string(vitalsHistory[i]) + " bpm");
				severityLevel++;
			}
		}
	}
	void show()const {
		PatientRecord::show();
		cout<<"severity level : "<<severityLevel<<endl;
		cout<<"alert count : "<<alertCount<<endl;
		for(int i=0;i<alertCount;i++){
			cout<<alertMessages[i]<<endl;
		}
	}
	~ICUPatientRecord(){
		cout<<"freeing memory of derived class ...."<<endl;
		delete[] alertMessages;
	}
};
int main(){
	int logCount = 5;
	double*ptr = new double[logCount];
	cout<<"enter values in array : "<<endl;
	for(int i=0;i<logCount;i++){
		cin>>ptr[i];
	}
	ICUPatientRecord P(ptr,logCount,nullptr,0,0);
	P.evaluateEmergencyStatus();
	cout<<"--- original ---"<<endl;
	P.show();

	ICUPatientRecord S(P);
	cout<<"--- copy ---"<<endl;
	S.show();

	S.addAlert("Extra alert on copy only");
	cout<<"--- after changing copy ---"<<endl;
	cout<<"original:"<<endl;
	P.show();
	cout<<"copy:"<<endl;
	S.show();

	return 0;
}