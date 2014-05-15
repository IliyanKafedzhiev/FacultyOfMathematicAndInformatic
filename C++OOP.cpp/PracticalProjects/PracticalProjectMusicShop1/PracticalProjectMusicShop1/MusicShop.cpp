#include "MusicShop.h"
#include <iostream>
#include <stdexcept>
#include <assert.h>
#include <string>
#include <fstream>
using namespace std;

int MusicShop::countOfExistingMusicShop=0;

MusicShop::MusicShop(const char* name,const char*addres,const unsigned capacity):itemsCount(0)
{
	setNameConstructor(name);
	setAddressConstructor(addres);
	if(capacity>=0)
	{
		this->capacity=capacity;
	}
	else
	{
		throw invalid_argument("Invalid Capacity");
	}
	records=new Record[capacity];
	countOfExistingMusicShop++;
}
//tested
MusicShop::MusicShop(const MusicShop&tmp):capacity(tmp.capacity),itemsCount(tmp.itemsCount)
{
	setShopName(tmp.musicShopName);
	setAddress(tmp.address);
	setRecords(tmp.records,tmp.itemsCount);
	countOfExistingMusicShop++;
}

MusicShop& MusicShop::operator=(const MusicShop&tmp)
{
	capacity=tmp.capacity;
	itemsCount=tmp.itemsCount;
	setShopName(tmp.musicShopName);
	setAddress(tmp.address);
	setRecords(tmp.records,tmp.itemsCount);
	return *this;
}

MusicShop::~MusicShop(void)
{
	delete [] musicShopName;
	delete [] address;
	delete [] records;
	countOfExistingMusicShop--;
}

//Setters
void MusicShop::setRecords(const Record* tmp,const unsigned items)
{
	delete []this->records; // TODO copy in  records
	if (items>=capacity)
	{
		capacity=2*items;
	}
	records=new Record[capacity];
	for (unsigned i = 0; i < items; i++)
	{
		records[i]=tmp[i];
	}
	this->itemsCount=items;
}

void MusicShop::setNameConstructor(const char* name)
{
	if (name!=NULL)
	{
		musicShopName=new char[strlen(name)+1];
		for (unsigned i = 0; i <= strlen(name); i++)
		{
			musicShopName[i]=name[i];
		}
	}
	else
	{
		throw invalid_argument("Invalid musicShopName");
	}
}

void MusicShop::setAddressConstructor(const char* name)
{
	if (name)
	{
		address=new char[strlen(name)+1];
		for (unsigned i = 0; i <= strlen(name); i++)
		{
			address[i]=name[i];
		}
	}
	else
	{
		throw invalid_argument("Invalid Address");
	}
}

void MusicShop::setShopName(const char* name)
{
	delete [] musicShopName;
	if (name!=NULL)
	{
		musicShopName=new char[strlen(name)+1];
		for (unsigned i = 0; i <= strlen(name); i++)
		{
			musicShopName[i]=name[i];
		}
	}
	else
	{
		throw invalid_argument("Invalid musicShopName");
	}
}

void MusicShop::setAddress(const char* name)
{
	delete [] address;
	if (name)
	{
		address=new char[strlen(name)+1];
		for (unsigned i = 0; i <= strlen(name); i++)
		{
			address[i]=name[i];
		}
	}
	else
	{
		throw invalid_argument("Invalid Address");
	}
}

void MusicShop::setCapacity(const int n)
{
	if(n>0)
	{
		this->capacity=n;
	}
	else
	{
		throw invalid_argument("Invalid Capacity");
	}
	

}

//Getters

const char* MusicShop::getMusicShopName()const
{
	return this->musicShopName;
}

const char* MusicShop::getAddress()const
{
	return this->address;
}

int MusicShop::getItemCount()const
{
	return this->itemsCount;
}

int MusicShop::getCapacity()const
{
	return this->capacity;
}

int MusicShop::getCountOfExistingMusicShop()const
{
	return countOfExistingMusicShop;
}

const Record* MusicShop::getRecords()const
{
	return records;
}

//Methods

bool MusicShop::isFull()const
{
	return itemsCount>=capacity;
}
//tested
bool MusicShop::addRecord(const Record& tmp)
{
	if (this->isFull())
	{
		if (this->capacity==0)
		{
			this->capacity=5;
		}
		else
		{
			this->capacity=this->capacity*2;
		}
		Record *tmpPtr;
		
		tmpPtr= new Record[itemsCount];
		for (unsigned i = 0; i < itemsCount; i++)
		{
			tmpPtr[i]=this->records[i];
		}
		delete [] this->records;
		records=new Record[capacity];
		for (unsigned i = 0; i < itemsCount; i++)
		{
			records[i]=tmpPtr[i];
		}
		delete [] tmpPtr;
	}
	records[itemsCount]=tmp;
	itemsCount++;
	return true;
}
//tested
bool MusicShop::removeRecord(const unsigned checkID)
{
	if (checkID<0)
	{
		return false;
	}
	if ((records[capacity-1].getCounterOfObject()-capacity) > (unsigned)checkID)
	{
		return false;
	}
	Record* tmp=&binarySearchByID(checkID,0,itemsCount-1);
	if(((string)tmp->getAlbum()).compare("")==0)
	{
		return false;
	}
	else
	{
		*tmp=records[itemsCount-1];
	}
	itemsCount--;
	if (((double)itemsCount/(double)capacity) < 0.25000000001  )
	{
		capacity = capacity / 2 ;
		Record* NewPtr = new Record [capacity];
		for (unsigned i = 0; i < itemsCount; i++)
		{
			NewPtr[i]=records[i];
		}
		delete [] records;
		records = NewPtr;
	}
	return true;
}
//tested
Record& MusicShop::binarySearchByID(unsigned checkID,unsigned imin,unsigned imax)const
{
  // continue searching while [imin,imax] is not empty
  while (imax >= imin)
    {
      /* calculate the midpoint for roughly equal partition */
      int imid = (imin + imax)/2;
 
      // determine which subarray to search
	  if (records[imid].getID() < checkID)
	  {
        // change min index to search upper subarray
        imin = imid + 1;
	  }
      else
	  {
		  if (records[imid].getID() > checkID)
		  {
			// change max index to search lower subarray
			imax = imid - 1;
		  }
		  else
		  {
			// key found at index imid
			return records[imid];
		  }
	  }
    }
  // key not found
  return records[capacity-1];
}
//tested
void MusicShop::ShopInformation()const
{
	cout<<"MusicShopName: "<<musicShopName<<endl;
	cout<<"Adress: "<<address<<endl;
	for (unsigned i = 0; i < itemsCount; i++)
	{
		records[i].recordInformation();
	}
}
//tested
bool MusicShop::isAvailable(const char * checkAlbum)const 
{
	int len= strlen(checkAlbum);
	bool isAvailable=false;
	for (unsigned i = 0; i < itemsCount; i++)
	{
		if (strlen(records[i].getAlbum())==len)
		{
			for (int j = 0; j < len; j++)
			{
				if (checkAlbum[j]==records[i].getAlbum()[j])
				{
					isAvailable=true;
				}
				else
				{
					isAvailable=false;
				}
			}
			if (isAvailable==true)
			{
				return true;
			}
		}
		
	}
	return isAvailable;
} //tested
//tested
bool MusicShop::isAvailable(const int checkID)const 
{
	if (checkID<0)
	{
		return false;
	}
	if ((records[capacity-1].getCounterOfObject()-capacity) > (unsigned)checkID)
	{
		return false;
	}
	Record *tmp = &binarySearchByID(checkID,0,itemsCount-1);
	
	if (&tmp[0] == &records[capacity-1])
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool MusicShop::isAvailableByArtist(const char* checkArtist)const
{
	int len= strlen(checkArtist);
	bool isAvailable=false;
	for (unsigned i = 0; i < itemsCount; i++)
	{
		if (strlen(records[i].getArtist())==len)
		{
			for (int j = 0; j < len; j++)
			{
				if (checkArtist[j]==records[i].getArtist()[j])
				{
					isAvailable=true;
				}
				else
				{
					isAvailable=false;
				}
			}
			if (isAvailable==true)
			{
				return true;
			}
		}
	}
	return isAvailable;
}

//Operators

MusicShop& MusicShop::operator+=(const Record&tmp)
{
	addRecord(tmp);
	return *this;
}
//tested
Record* MusicShop::operator+(const MusicShop& tmp)const 
{
	MusicShop* newShop=new MusicShop(*this);
	for (unsigned i = 0; i < tmp.itemsCount; i++)
	{
		if (!isAvailable(tmp.records[i].getAlbum()) && !isAvailableByArtist(tmp.records[i].getArtist()))
		{
			newShop->addRecord(tmp.records[i]);
		}
	}
	return newShop->records;
}
//tested
Record* MusicShop::operator/(const MusicShop& tmp)const
{
	MusicShop* newShop=new MusicShop("New Music Shop","New Adress",5);
	for (unsigned i = 0; i < itemsCount; i++)
	{
		if(tmp.isAvailable(records[i].getAlbum()) && tmp.isAvailableByArtist(records[i].getArtist())
			&& !newShop->isAvailable(records[i].getAlbum()) && !newShop->isAvailableByArtist(records[i].getArtist()) )
		{
			newShop->addRecord(records[i]);
		}
	}
	return newShop->records;
}
//tested
MusicShop& MusicShop::operator-=(const char*Album)
{
	for (int i = 0; i < itemsCount; i++)
	{
		if(!strcmp(records[i].getAlbum(),Album))
		{
			removeRecord(records[i].getID());
		}
	}
	return *this;
}
//tested
MusicShop& MusicShop::operator-=(const unsigned checkID)
{
	removeRecord(checkID);
	return*this;
}
//tested
Record* MusicShop::operator-(const MusicShop&tmp)const
{
	MusicShop* newShop=new MusicShop("New Shop Razlika","New Shop Adress",5);
	for (unsigned i = 0; i < itemsCount; i++)
	{
		if (!tmp.isAvailable(records[i].getAlbum()) && !tmp.isAvailableByArtist(records[i].getArtist()) )
		{
			newShop->addRecord(records[i]);
		}
	}
	for (unsigned i = 0; i < tmp.itemsCount; i++)
	{
		if (!isAvailable(tmp.records[i].getAlbum()) && !isAvailableByArtist(tmp.records[i].getArtist()) )
		{
			newShop->addRecord(tmp.records[i]);
		}
	}
	return newShop->records;
}
//tested
Record* MusicShop::operator*(const MusicShop&tmp)const //dopalnenie ot ediniq do drugiq
{
	MusicShop* newShop=new MusicShop("New Shop Dopulnenie","New Shop Adress",5);
	for (unsigned i = 0; i < tmp.itemsCount; i++)
	{
		if (!isAvailable(tmp.records[i].getAlbum()) && !isAvailableByArtist(tmp.records[i].getArtist()) )
		{
			newShop->addRecord(tmp.records[i]);
		}
	}
	return newShop->records;
}
//tested
bool MusicShop::operator==(const MusicShop& tmp)const
{
	for (int i = 0; i < itemsCount; i++)
	{
		if ( !tmp.isAvailable(records[i].getAlbum()) && !tmp.isAvailableByArtist(records[i].getArtist()) )
		{
			return false;
		}
	}
	for (int i = 0; i < tmp.itemsCount; i++)
	{
		if ( !isAvailable(tmp.records[i].getAlbum()) && !isAvailableByArtist(tmp.records[i].getArtist()) )
		{
			return false;
		}
	}
	return true;
}
//tested
bool MusicShop::operator<(const MusicShop& tmp)const
{
	for (int i = 0; i < tmp.itemsCount; i++)
	{
		if ( !isAvailable(tmp.records[i].getAlbum()) && !isAvailableByArtist(tmp.records[i].getArtist()) )
		{
			return false;
		}
	}
	return true;
}
//tested
ostream& operator<<(ostream& out,const MusicShop& tmp)
{
	out<<"Shop Name"<<tmp.getMusicShopName()<<endl;
	out<<"Adress:"<<tmp.getAddress()<<endl;
	for (int i = 0; i < tmp.getItemCount(); i++)
	{
		out<<*(tmp.getRecords()+i);
	}
	return out;
}
//tested
bool writeInFile(const MusicShop& tmp,const char* filename)
{
	if(!filename)
	{
		return false;
	}
	ofstream newFile(filename);
	if(!newFile)
	{
		return false;
	}
	newFile<<(tmp);
	newFile.close();
}