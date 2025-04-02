// Diamond Inheritance

#include <iostream>

class Component
{
public:
	Component(std::string companyName) :
		companyName(companyName)
	{
		std::cout << "Constructor Component\n";
	}
	std::string companyName;
};

class GPU : public Component
{
public:
	GPU(std::string companyName) :
		Component(companyName)
	{
		std::cout << "Constructor GPU\n";
	}
};

class Memory : public Component
{
public:
	Memory(std::string companyName) :
		Component(companyName)
	{
		std::cout << "Constructor Memory\n";
	}
};

class GraphicCard : public GPU, public Memory
{
public:
	GraphicCard(std::string gpuCompanyName, std::string memoryCompanyName) :
		GPU(gpuCompanyName),
		Memory(memoryCompanyName)
	{
		std::cout << "Constructor GraphicCard\n";
	}
};

////////////////////////////////////////////////////////////////////////////

class Character
{
public:
	Character()
	{
		std::cout << "Constructor Character\n";
	}
	int HP;
};

class Orc : virtual public Character
{
public:
	Orc()
	{
		std::cout << "Constructor Orc\n";
	}
};

class Warrior : virtual public Character
{
public:
	Warrior()
	{
		std::cout << "Constructor Warrior\n";
	}
};

class OrcWarrior : public Orc, public Warrior
{
public:
	OrcWarrior()
	{
		std::cout << "Constructor OrcWarrior\n";
	}
};

int main()
{
	GraphicCard graphicCard("AMD", "Samsung");
	std::cout << '\n';
	OrcWarrior orcWarrior;
}