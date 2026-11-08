#include <iostream>
#include <string>
using namespace std;

class CoreTradingEngine{
	protected:
	double orderVolume;
	string assetSymbol;
	public:
	CoreTradingEngine(double orderVolume,string assetSymbol): orderVolume(orderVolume),assetSymbol(assetSymbol){
	}
	void executeOrder(double price){
		cout<<"order executed : "<<orderVolume<<" units of "<<assetSymbol<<" at "<<price<<endl;
	}
};
class EncryptedRiskEngine : private CoreTradingEngine{
	private:
	double maxExposure;
	protected:
	bool validateRiskThreshold(double price){
		if(price * orderVolume > maxExposure){
			cout<<"risk check failed : exposure too high"<<endl;
			return false;
		}
		return true;
	}
	public:
	EncryptedRiskEngine(double orderVolume,string assetSymbol,double maxExposure) :
	CoreTradingEngine(orderVolume,assetSymbol),maxExposure(maxExposure){
	}
	void processSecureTrade(double price,double volatilityScore){
		if(volatilityScore > 0.8){
			cout<<"trade rejected : volatility too high"<<endl;
			return;
		}
		if(validateRiskThreshold(price)){
			//executeOrder is private here but this class can still call it, so we call it only after risk check passes
			CoreTradingEngine::executeOrder(price);
		}
	}
	//if we write "using CoreTradingEngine::executeOrder;" in public, it will be public again but then risk check can be skipped
};
class HighFrequencyBot : public EncryptedRiskEngine{
	public:
	HighFrequencyBot(double orderVolume,string assetSymbol,double maxExposure) :
	EncryptedRiskEngine(orderVolume,assetSymbol,maxExposure){
	}
	void runBot(double price){
		//executeOrder(price);  error, because of private inheritance executeOrder became private in EncryptedRiskEngine so child cant use it
		//CoreTradingEngine::executeOrder(price);  error, same reason, the base class is not accessible here
		//cout<<orderVolume;  error, orderVolume also became private in EncryptedRiskEngine
		if(validateRiskThreshold(price)){
			cout<<"bot : risk check passed"<<endl;
		}
		processSecureTrade(price,0.3);
	}
};
int main(){
	HighFrequencyBot bot(100,"AAPL",50000);

	cout<<"--- direct calls ---"<<endl;
	//bot.executeOrder(150);  error, private
	//bot.CoreTradingEngine::executeOrder(150);  error, base not accessible
	cout<<"direct calls dont work, compiler blocks them"<<endl;

	cout<<"--- secure workflow ---"<<endl;
	bot.processSecureTrade(300,0.4);
	bot.processSecureTrade(600,0.4);
	bot.processSecureTrade(300,0.9);

	cout<<"--- bot workflow ---"<<endl;
	bot.runBot(200);

	return 0;
}