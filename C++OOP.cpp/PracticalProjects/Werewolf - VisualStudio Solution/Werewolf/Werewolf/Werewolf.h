enum FurColors {HAIRLESS, BLACK, BROWN, WHITE, GREY};
enum Sex {MALE, FEMALE};

class Animal
{
protected:
	char* breed;
	bool fur;
	FurColors furColor;
	bool legs;
	int legsCount;
	bool tail;
	double tailLength;

	void Delete();   //trie 
	void Copy(const Animal& animal); //kopira

public:
	Animal(const char* breed, bool fur, bool legs, bool tail,
		FurColors furColor = HAIRLESS, int legsCount = 0, double tailLength = 0.0);
	Animal(const Animal& animal);
	Animal& operator = (const Animal& animal);
	~Animal();
};

class Person
{
protected:
	char* name;
	unsigned int age;
	Sex sex;

	void Delete();
	void Copy(const Person& person);

public:
	Person(const char* name, unsigned int age, Sex sex);
	Person(const Person& person);
	Person& operator = (const Person& person);
	~Person();
};

class Wolf :public Animal
{
protected:
	double toothsLenght;
	bool packMember;
	unsigned int packSize;

	void Delete();
	void Copy(const Wolf& wolf);
public:
	Wolf(const char* breed, bool fur, bool legs, bool tail,double toothsLenght,bool packMember,
		FurColors furColor = HAIRLESS , int legsCount = 0, double tailLength = 0.0,unsigned int packSize = 0
		);
	Wolf(const Wolf& wolf);
	Wolf& operator=(const Wolf& wolf);
};

class Werewolf : public Wolf,public Person
{
	char firstChange[11];
	void Copy(const Werewolf& werewolf);
public:

	Werewolf(const char* breed, bool fur, bool legs, bool tail,double toothsLenght,bool packMember,
		const char* name, unsigned int age, Sex sex,char* firstChange,
		FurColors furColor = HAIRLESS , int legsCount = 0, double tailLength = 0.0,unsigned int packSize = 0);
	Werewolf(const Werewolf& werewolf);
	Werewolf& operator=(const Werewolf& werewolf);

};