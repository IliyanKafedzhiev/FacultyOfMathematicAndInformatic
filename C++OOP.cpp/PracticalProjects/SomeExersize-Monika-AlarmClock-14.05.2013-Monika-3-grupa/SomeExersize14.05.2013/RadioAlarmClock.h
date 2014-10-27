#include "alarmClock.h"
#include "Radio.h"
class RadioAlarmClock:public alarmClock,public Radio
{
public:
	RadioAlarmClock(char* tmpModel,double tmpPrice,char* tmpColor,bool tmpb,bool tmpIsElectron,short tmpmelody,int tmpAlarmCounter);
	~RadioAlarmClock(void);
	void printSubject();
private:
	int alarmCounter;
};

