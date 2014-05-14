class Vehicle

{
public:
	Vehicle(char * model,double height,  double weight);
	Vehicle(const Vehicle&);
	Vehicle&operator=(const Vehicle&);
	~Vehicle();
	void setModel(char*);
	virtual void printVehicle (const Vehicle&);
	bool canPassUnderBridge(float);
	bool canPassOverBridge(float);
private:
	
	char * model;
	double hight;
	double weight;

};

class LandVehicle:public virtual Vehicle
{
public:
	LandVehicle(char * model,double height,  double weight,double maxSpeed ,double powerHP);
	LandVehicle(const LandVehicle&);
	LandVehicle& operator=(const LandVehicle &);
	~LandVehicle(){}
	float getTime(float)const;
	void printVehicle(const LandVehicle&);

protected:
	double maxSpeed;
	int powerHP;
};

class WaterVehicle :public virtual Vehicle
{
public:
	WaterVehicle(char * model,double height,  double weight,double maxSpeed);
	WaterVehicle(const WaterVehicle&);
	WaterVehicle& operator=(const WaterVehicle&);
	~WaterVehicle(){}

	void printVehicle(const WaterVehicle&);

	float getSpeedUpStream(float speedStream)const;
	float getSpeedDownStream(float SpeedStream)const;

	float getTimeDownStream(float,float)const;
	float getTimeUpStream(float,float)const;
protected:
	double maxSpeed;
};

class Amphib:public LandVehicle,public WaterVehicle
{
public:
	Amphib(char * model,double height,  double weight,double maxSpeedMV,double maxSpeedKH ,double powerHP);
	void printVehicle(const Amphib&);
	bool isAmphibCanPasWayBeforeOneHour();
	~Amphib(void);
};







