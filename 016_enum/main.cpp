// Enum

// An enum (enumeration) assigns names to a set of integral constants,
// improving readability and maintainability

#include <iostream>

class PC
{
public:
	// Enum to represent PC states
	enum PCState
	{
		ON,
		OFF,
		SLEEP
	};
	PCState getPCState() const
	{
		return pcState;
	}
	void setPCState(const PCState& pcState)
	{
		this->pcState = pcState;
	}
private:
	PCState pcState;
};

// Enum outside class
enum Speed
{
	MIN = 150,
	RECOMMEND = 600,
	MAX = 800
};

int main()
{
	PC pc;
	pc.setPCState(PC::PCState::ON);

	if (pc.getPCState() == PC::PCState::ON)
	{
		std::cout << "PC is ON\n";
	}

	// Using switch with enum
	switch (pc.getPCState())
	{
	case PC::PCState::OFF:
		std::cout << "PC is OFF\n";
		break;
	case PC::PCState::ON:
		std::cout << "PC is ON\n";
		break;
	case PC::PCState::SLEEP:
		std::cout << "PC is SLEEP\n";
		break;
	}
}