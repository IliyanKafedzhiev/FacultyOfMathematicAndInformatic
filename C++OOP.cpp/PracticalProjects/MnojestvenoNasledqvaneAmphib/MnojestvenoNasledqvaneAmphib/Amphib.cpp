#include "Amphib.h"
#include <iostream>
#include <string>

using namespace std;





/***************************************/

/*Vehicle*/

/***************************************/

Vehicle::Vehicle(char * model,double hight,  double weight)
{
	this->hight=(hight>0)?hight:0;
	this->weight=(weight>0)?weight:0;
	setModel(model);
}

Vehicle& Vehicle::operator=(const Vehicle&v)
{
	if(this!=&v)
	{
		delete [] model;
		setModel(v.model);
		hight=v.hight;
		weight=v.weight;
	}
	return *this;
}

Vehicle::Vehicle(const Vehicle&v):hight(v.hight),weight(v.weight)
{
	setModel(v.model);
}

Vehicle::~Vehicle()
{
	delete[] model;
}

void Vehicle::setModel(char* text)
{
	this->model=new char[strlen(text)+1];
	for (int i = 0; i <= strlen(text); i++)
	{
		model[i]=text[i];
	}
}

void Vehicle::printVehicle(const Vehicle &v)
{
	cout<<"Model :"<<v.model<<endl;
	cout<<"Hight :"<<v.hight<<endl;
	cout<<"Weight:"<<v.weight<<endl;

}

bool Vehicle::canPassOverBridge(float testWeight)
{
	return this->weight <= testWeight;
}

bool Vehicle::canPassUnderBridge(float testHight)
{
	return testHight >=  this->hight ;
}
/***************************************/

/*LandVehicle*/

/***************************************/
LandVehicle::LandVehicle(char * model , double height,  double weight,double maxSpeed ,double powerHP)
	:Vehicle(model,height,weight),maxSpeed((maxSpeed>0)?maxSpeed:0),powerHP((powerHP>0)?powerHP:0)
{
}

LandVehicle::LandVehicle(const LandVehicle&l):Vehicle(l)
{
	maxSpeed=l.maxSpeed;
	powerHP=l.maxSpeed;
}

LandVehicle& LandVehicle::operator=(const LandVehicle&l)
{
	if (this!=&l)
	{
		Vehicle::operator=(l);
		this->maxSpeed=l.maxSpeed;
		this->powerHP=l.powerHP;
	}
	return *this;
}

void LandVehicle::printVehicle(const LandVehicle&l)
{
	Vehicle::printVehicle(l);
	cout<<"MaxSpeed:"<<maxSpeed<<endl;
	cout<<"Power in HP:"<<powerHP<<endl;
}

float LandVehicle::getTime(float way)const
{
	return way/maxSpeed;
}

/***************************************/

/*WaterVehicle*/

/***************************************/
WaterVehicle::WaterVehicle(char * model,double height,  double weight,double maxSpeed):Vehicle(model,height,weight)
{
	this->maxSpeed=(maxSpeed>0)?maxSpeed:0;
}

WaterVehicle::WaterVehicle(const WaterVehicle&W):Vehicle(W)
{
	this->maxSpeed=W.maxSpeed;
}

WaterVehicle& WaterVehicle::operator=(const WaterVehicle&W)
{
	if (this!=&W)
	{
		Vehicle::operator=(W);
		this->maxSpeed=W.maxSpeed;
	}
	return *this;
}

float WaterVehicle::getSpeedUpStream(float speedStream)const
{
	return maxSpeed-speedStream;
}

float WaterVehicle::getSpeedDownStream(float speedStream)const
{
	return maxSpeed+speedStream;
}

float WaterVehicle:: getTimeDownStream(float speedStream,float miles)const
{
	float maxS=this->getSpeedDownStream(speedStream);
	return miles/maxS;
}

float WaterVehicle:: getTimeUpStream(float speedStream,float miles)const
{
	float maxS=this->getSpeedUpStream(speedStream);
	return miles/maxS;
}

void WaterVehicle::printVehicle(const WaterVehicle&W)
{
	Vehicle::printVehicle(W);
	cout<<"SpeedMV: "<<W.maxSpeed<<endl;
}
/***************************************/

/*Amphib*/

/***************************************/
Amphib::Amphib(char * model,double height,  double weight,double maxSpeedMV,double maxSpeedKH ,double powerHP)
	:Vehicle(model,height,weight)
	,WaterVehicle(model,height,weight,maxSpeedMV)
	,LandVehicle(model ,height,weight,maxSpeedKH ,powerHP)
{
}

Amphib::~Amphib(void)
{
}

void Amphib::printVehicle(const Amphib&A)
{
	LandVehicle::printVehicle(A);
	cout<<"MaxSpeedMV: "<<WaterVehicle::maxSpeed<<endl;

}

bool Amphib::isAmphibCanPasWayBeforeOneHour()
{
	double time=0;
	time=5/LandVehicle::maxSpeed;
	if(!Vehicle::canPassUnderBridge(5))
		return 0;
	time+=WaterVehicle::getTimeUpStream(10,3.1009);
	if (time<=1)
	{
		return 1;
	}
	return 0;
}