#include <iostream>
#include <string>

using namespace std;

class Animal // BASE CLASS
{
	private: // attributes from this section can not be inherited
		string name;
		float weight;
		
		static int numberOfAnimals; // shared value between all objects in class
		
	public:
		string getName()
		{
			return name;
		}
		void setName(string name)
		{
			this->name = name; // -> arrow pointer, it is used to access object's fields
		}
		float getWeight()
		{
			return weight;
		}
		void setWeight(float weight)
		{
			this->weight = weight;
		}
		void setAll(string, float);
		Animal(string, float); // constructor that allows to set values while creating the object
		Animal(); // constructor
		~Animal(); // deconstructor 
		static int getNumberOfAnimals()
		{
			return numberOfAnimals;
		}
		void ToString();
};

int Animal::numberOfAnimals = 0;

void Animal::setAll(string name, float weight)
{
	this->name = name;
	this->weight = weight;
}

Animal::Animal(string name, float weight)
{
	this->name = name;
	this->weight = weight;
	Animal::numberOfAnimals++;
}

Animal::Animal()
{
	this->name = " ";
	this->weight = 0;
	Animal::numberOfAnimals++;
}

Animal::~Animal()
{
	cout << "Animal " << this->name << " destroyed." << endl;
}

void Animal::ToString()
{
	cout << "This animal's name is " << this->name << " and it weighs " << this->weight << " kgs." << endl;
}

class Dog : public Animal // SUBCLASS inherits from the PUBLIC section of the BASE CLASS
{
	private:
		string sound = "WOOOF!";
	
	public:
		void Speak()
		{
			cout << "This dog's name is " << this->getName() << ", it weighs " << this->getWeight() << " kgs and says: " << this->sound << endl;
		}
		Dog(string, float, string);
		Dog():Animal()
		{
			
		};
		void ToString();	
};

Dog::Dog(string name, float weight, string sound) : Animal(name, weight)
{
	this->sound = sound;
}

void Dog::ToString()
{
	cout << "This dog's name is " << this->getName() << ", it weighs " << this->getWeight() << " kgs and says: " << this->sound << endl;
}

int main()
{
	Animal dog1;
	dog1.setName("Fluffy");
	dog1.setWeight(25);
	dog1.ToString();
	
	Animal cat1("Garfield", 10);
	cat1.ToString();
	
	Animal mouse1;
	mouse1.setAll("Stuart", 0.25);
	mouse1.ToString();
	
	Dog dog2;
	dog2.setWeight(40);
	dog2.setName("Pluto");
	dog2.Speak();
	
	Dog dog3("Hooch", 60, "WOOOOOOF!");
	dog3.ToString();
	
	cout << endl;
	cout << "Number of animals: " << Animal::getNumberOfAnimals() << endl;
	cout << endl;
	
	return 0;
	system("pause");
}

