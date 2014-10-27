#ifndef RECORD_H
#define RECORD_H

#include "Type.h"
#include "Genre.h"
#include <iostream>

class Record
{
public:
	/**************************************************************************/
	//constructors destructors and operators
	/**************************************************************************/
	Record(const char*album,const char* artist,const unsigned int year
		,const double price,const Genre genre=Unknown
		,const kindType type=UnknownType);
	Record();
	Record(const Record&);
	Record&operator=(const Record&);
	~Record(void);
	friend std::ostream& operator<<(std::ostream&,const Record&);
	/**************************************************************************/
	//Setters
	/**************************************************************************/
	inline void setAlbum (const char*);
	inline void setArtist (const char*);
	//inline void setYear(const unsigned int);
	inline void setPrice(const double);
	inline void setGenre(const Genre);
	//inline void setType(const kindType);
	/**************************************************************************/
		//Getters
	/**************************************************************************/
	inline const char* getAlbum ()const;
	inline const char* getArtist ()const;
	inline unsigned int getYear()const;
	inline double getPrice()const;
	inline Genre getGenre()const;
	inline kindType getType()const;
	inline unsigned int getID ()const;
	unsigned getCounterOfObject()const;

	void recordInformation ()const;
private: 
	void setAlbumInConstructor(const char*);
	void setArtistInConstructor(const char*);


	char*album;
	char*artist;
	unsigned int year;
	double price;
	Genre genre;
	kindType type;
	const unsigned int ID;
	static int counterOfObject;
};
#endif

