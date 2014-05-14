#include "Record.h"
#include <stdexcept>
#include <cstring>
#include <iostream>
using namespace std;
int Record::counterOfObject=0;
/**************************************************************************/
//constructors destructors and operators 
/**************************************************************************/
Record::Record():ID(counterOfObject++),type(UnknownType),genre(Unknown),year(1),price(1)
{
	this->setAlbumInConstructor("");
	this->setArtistInConstructor("");
}

Record::Record(const char*album,const char* artist,const unsigned int year
		,const double price,const Genre genre,const kindType type)
		:ID(counterOfObject),type(type),genre(genre),price((price>0)?price:0)
{
	if(year>0 && year<3000)
	{
		this->year=year;
	}
	else
	{
		throw invalid_argument("invalid year");
	}
	this->setAlbumInConstructor(album);
	this->setArtistInConstructor(artist);
	setPrice(price);
	counterOfObject++;
}

Record::Record(const Record&tmp):ID(counterOfObject++),year(tmp.year),type(tmp.type),
	price(tmp.price),genre(tmp.genre)
{
	this->setAlbum(tmp.album);
	this->setArtist(tmp.artist);
}

Record::~Record(void)
{
	delete []this->album;
	delete []this->artist;
}

Record& Record::operator=(const Record&tmp)
{
	if (this!=&tmp)
	{
		this->setAlbum(tmp.album);
		this->setArtist(tmp.artist);
		this->year=tmp.year;
		this->setPrice(tmp.price);
		this->setGenre(tmp.genre);
		this->type=tmp.type;
	}
		
	return *this;
}

std::ostream &operator<<(std::ostream& stream,const Record&tmp)
{
	stream<<"Album : "<<tmp.getAlbum()<<endl;
	stream<<"Artist : "<<tmp.getArtist()<<endl;
	stream<<"year : "<<tmp.getYear()<<endl;
	stream<<"Price: "<<tmp.getPrice()<<endl;
	stream<<"ID: "<<tmp.getID()<<endl;
	stream<<"Genre : ";
	switch (tmp.getGenre())
	{
	case 7:
		stream<<"Metal"<<endl;
		break;
	case 6:
		stream<<"Popfolk"<<endl;
		break;
	case 5:
		stream<<"Rap"<<endl;
		break;
	case 4:
		stream<<"Dance"<<endl;
		break;
	case 3:
		stream<<"Rock"<<endl;
		break;
	case 2:
		stream<<"Disco"<<endl;
		break;
	case 1:
		stream<<"Pop"<<endl;
		break;
	case 0:
		stream<<"unknown"<<endl;
		break;
	default:
		stream<<"unknown"<<endl;
		break;
	}
	stream<<"Type : ";
	switch (tmp.getType())
	{
	case 3:
		stream<<"vinyl"<<endl;
		break;
	case 2:
		stream<<"Type"<<endl;
		break;
	case 1:
		stream<<"CD"<<endl;
		break;
	case 0:
		stream<<"unknown"<<endl;
		break;
	default:
		stream<<"unknown"<<endl;
		break;
	}
	stream<<endl;
	return stream;

}
/**************************************************************************/
//Setters
/**************************************************************************/
void Record::setAlbumInConstructor(const char* tmp)
{
	if (tmp==NULL)
	{
		throw invalid_argument("invalid album");
	}
	int len= strlen(tmp);
	album=new char [len+1];
	for (int i = 0; i <= len; i++)
	{
		album[i]=tmp[i];
	}
}

void Record::setArtistInConstructor(const char*tmp)
{
	if (tmp==NULL)
	{
		throw invalid_argument("invalid artist");
	}
	int len= strlen(tmp);
	artist=new char [len+1];
	for (int i = 0; i <= len; i++)
	{
		artist[i]=tmp[i];
	}
}

void Record::setAlbum(const char*tmp)
{
	if (tmp==NULL)
	{
		throw invalid_argument("invalid album");
	}
	delete [] album;
	int len= strlen(tmp);
	album=new char [len+1];
	for (int i = 0; i <= len; i++)
	{
		album[i]=tmp[i];
	}
	//strncpy_s()
}

void Record::setArtist(const char*tmp)
{
	if (tmp==NULL)
	{
		throw invalid_argument("invalid artist");
	}
	delete [] artist;
	int len= strlen(tmp);
	artist=new char [len+1];
	for (int i = 0; i <= len; i++)
	{
		artist[i]=tmp[i];
	}
}

//void Record::setYear(const unsigned int tmp)
//{
//	year=(tmp>1)?tmp:2000;
//}

void Record::setPrice(const double tmp)
{
	if (tmp<0)
	{
		throw invalid_argument("invalid price");
	}
	price=tmp;
}

void Record::setGenre(const Genre tmp)
{
	genre=tmp;
}

//void Record::setType(const kindType tmp)
//{
//	type=(tmp>unknownType && tmp<=vinyl)?tmp:unknownType;
//}
/**************************************************************************/
//Getters
/**************************************************************************/

unsigned Record::getCounterOfObject()const
{
	return Record::counterOfObject;
}

const char* Record::getAlbum()const
{
	return this->album;
}

const char* Record::getArtist()const
{
	return this->artist;
}

unsigned int Record::getYear()const
{
	return this->year;
}

double Record::getPrice()const
{
	return this->price;
}

Genre Record::getGenre()const
{
	return this->genre;
}

kindType Record::getType()const
{
	return this->type;
}

unsigned int Record::getID()const
{
	return this->ID;
}

/******************************************************************************/
void Record::recordInformation()const
{
	cout<<"Album : "<<getAlbum()<<endl;
	cout<<"Artist : "<<getArtist()<<endl;
	cout<<"year : "<<getYear()<<endl;
	cout<<"Price: "<<getPrice()<<endl;
	cout<<"ID: "<<getID()<<endl;
	cout<<"Genre : ";
	switch (getGenre())
	{
	case 7:
		cout<<"Metal"<<endl;
		break;
	case 6:
		cout<<"Popfolk"<<endl;
		break;
	case 5:
		cout<<"Rap"<<endl;
		break;
	case 4:
		cout<<"Dance"<<endl;
		break;
	case 3:
		cout<<"Rock"<<endl;
		break;
	case 2:
		cout<<"Disco"<<endl;
		break;
	case 1:
		cout<<"Pop"<<endl;
		break;
	case 0:
		cout<<"unknown"<<endl;
		break;
	default:
		cout<<"unknown"<<endl;
		break;
	}
	cout<<"Type : ";
	switch (getType())
	{
	case 3:
		cout<<"vinyl"<<endl;
		break;
	case 2:
		cout<<"Type"<<endl;
		break;
	case 1:
		cout<<"CD"<<endl;
		break;
	case 0:
		cout<<"unknown"<<endl;
		break;
	default:
		cout<<"unknown"<<endl;
		break;
	}
	cout<<endl;
	
}