#include "Record.h"
#ifndef MUSICSHOP_H
#define MUSICSHOP_H
class MusicShop
{
public:
	MusicShop(const char* name,const char*addres,const unsigned capacity=0);
	MusicShop(const MusicShop&tmp);
	MusicShop& operator=(const MusicShop&tmp);
	~MusicShop(void);
	//Getters
	inline const char* getMusicShopName()const;
	inline const char* getAddress()const;
	inline int getItemCount()const;
	inline int getCapacity()const;
	inline int getCountOfExistingMusicShop()const;
	inline const Record* getRecords()const;
	//Setters
	inline void setShopName (const char*);
	inline void setAddress(const char*);
	inline void setCapacity(const int);
	void setRecords(const Record*,const unsigned items);
	//Methods
	inline bool isFull()const;
	bool addRecord(const Record&);
	bool removeRecord(const unsigned);
	void ShopInformation()const;
	bool isAvailable(const char*)const ;
	bool isAvailable(const int)const ;
	bool isAvailableByArtist(const char*)const;

	//Operators
	MusicShop& operator+=(const Record&);
	Record* operator+(const MusicShop&)const;
	MusicShop& operator-=(const char*);
	MusicShop& operator-=(const unsigned);
	Record* operator/(const MusicShop&)const;
	Record* operator-(const MusicShop&)const;
	Record* operator*(const MusicShop&)const;
	bool operator==(const MusicShop&)const;
	bool operator<(const MusicShop&)const;
	friend std::ostream& operator<<(std::ostream&,const MusicShop&);
	
	friend bool writeInFile (const MusicShop&,const char*);

private:
	Record& binarySearchByID(unsigned checkID,unsigned imin,unsigned imax )const;
	void setNameConstructor(const char*);
	void setAddressConstructor(const char*);

	//data

	char*musicShopName;
	char*address;
	unsigned itemsCount;
	unsigned capacity;
	Record* records;
	static int countOfExistingMusicShop;
};
#endif

