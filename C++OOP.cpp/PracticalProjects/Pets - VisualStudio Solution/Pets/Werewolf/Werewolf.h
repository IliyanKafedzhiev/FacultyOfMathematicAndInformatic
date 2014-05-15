class Pets
{
    protected:
	const char gender;
	char* Name;
public:
	Pets(const char* name,bool male);
	Pets(const Pets&);
	virtual ~Pets(void);
	void setName(const char* newName);
	char* getName()const ;
	void printPet(const Pets&);
	virtual void speak()const=0;
	Pets& operator=(const Pets&);
	Pets* createPets();
	char getGender();
};

class Cat:public Pets
{
public:
	Cat(const char* name,bool male);
	~Cat(void);
	void speak()const;
	void climb()const;
};

class Dog:public Pets
{
protected:
	char* breed;
	void setBreed(const char*);
public:
	Dog(const char* name,bool male,const char*breed=nullptr);
	Dog(const Dog&);
	Dog& operator=(const Dog&);
	~Dog(void);
	void speak()const;
	char* getBreed();
};