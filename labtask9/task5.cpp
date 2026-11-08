#include <iostream>
#include <string>
using namespace std;

class CloudResource{
	protected:
	string resourceID;
	double baseHourlyRate;
	string* metadata;
	public:
	CloudResource(string resourceID,double baseHourlyRate): resourceID(resourceID),baseHourlyRate(baseHourlyRate){
		this->metadata = new string("base metadata of " + resourceID);
	}
	CloudResource(const CloudResource &other): resourceID(other.resourceID),baseHourlyRate(other.baseHourlyRate){
		this->metadata = new string(*other.metadata);
	}
	CloudResource& operator=(const CloudResource &other){
		if(this != &other){
			this->resourceID = other.resourceID;
			this->baseHourlyRate = other.baseHourlyRate;
			*this->metadata = *other.metadata;
		}
		return *this;
	}
	virtual double calculateCost(double hours){
		return baseHourlyRate * hours;
	}
	virtual ~CloudResource(){
		cout<<"freeing memory of CloudResource ...."<<endl;
		delete metadata;
	}
};
class ServerInstance : public CloudResource{
	protected:
	int cpuCores;
	double ramGB;
	string* serverMetadata;
	public:
	ServerInstance(string resourceID,double baseHourlyRate,int cpuCores,double ramGB) :
	CloudResource(resourceID,baseHourlyRate),cpuCores(cpuCores),ramGB(ramGB){
		this->serverMetadata = new string("server metadata of " + resourceID);
	}
	ServerInstance(const ServerInstance &other) :
	CloudResource(other),cpuCores(other.cpuCores),ramGB(other.ramGB){
		this->serverMetadata = new string(*other.serverMetadata);
	}
	ServerInstance& operator=(const ServerInstance &other){
		if(this != &other){
			CloudResource::operator=(other);
			this->cpuCores = other.cpuCores;
			this->ramGB = other.ramGB;
			*this->serverMetadata = *other.serverMetadata;
		}
		return *this;
	}
	double calculateCost(double hours){
		return (baseHourlyRate + (cpuCores * 0.05) + (ramGB * 0.02)) * hours;
	}
	~ServerInstance(){
		cout<<"freeing memory of ServerInstance ...."<<endl;
		delete serverMetadata;
	}
};
class GPUAcceleratedServer : public ServerInstance{
	private:
	int gpuCount;
	double gpuModelTierMultiplier;
	string* gpuMetadata;
	public:
	GPUAcceleratedServer(string resourceID,double baseHourlyRate,int cpuCores,double ramGB,int gpuCount,double gpuModelTierMultiplier) :
	ServerInstance(resourceID,baseHourlyRate,cpuCores,ramGB),gpuCount(gpuCount),gpuModelTierMultiplier(gpuModelTierMultiplier){
		this->gpuMetadata = new string("gpu metadata of " + resourceID);
	}
	GPUAcceleratedServer(const GPUAcceleratedServer &other) :
	ServerInstance(other),gpuCount(other.gpuCount),gpuModelTierMultiplier(other.gpuModelTierMultiplier){
		this->gpuMetadata = new string(*other.gpuMetadata);
	}
	GPUAcceleratedServer& operator=(const GPUAcceleratedServer &other){
		if(this != &other){
			ServerInstance::operator=(other);
			this->gpuCount = other.gpuCount;
			this->gpuModelTierMultiplier = other.gpuModelTierMultiplier;
			*this->gpuMetadata = *other.gpuMetadata;
		}
		return *this;
	}
	double calculateCost(double hours){
		double serverCost = ServerInstance::calculateCost(hours);
		double gpuFee = gpuCount * gpuModelTierMultiplier * hours;
		return serverCost + gpuFee;
	}
	~GPUAcceleratedServer(){
		cout<<"freeing memory of GPUAcceleratedServer ...."<<endl;
		delete gpuMetadata;
	}
};
int main(){
	{
		GPUAcceleratedServer gpu("GPU-001",0.50,8,32.0,2,1.5);
		cout<<"cost for 24 hours : "<<gpu.calculateCost(24)<<endl;
		cout<<"end of scope, objects will be destroyed now"<<endl;
	}
	cout<<"back in main"<<endl;

	return 0;
}