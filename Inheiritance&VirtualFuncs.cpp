#include <iostream>
#include <string>

class Landmark
{
private:
	std::string sName;
public:
	Landmark(std::string pName)
	{
		sName = pName;
	}
	virtual const std::string color() = 0;
	
	virtual const std::string icon() = 0;

	const std::string name()
	{
		return sName;
	}

	virtual ~Landmark() {};
};

class Hotel : public Landmark
{
private:
public:
	Hotel(std::string pName) :Landmark(pName) {};
	const std::string color()
	{
		return "yellow";
	}
	const std::string icon()
	{
		return "bed";
	}

	~Hotel()
	{
		std::cout << "Deleting hotel " << name() << std::endl;
	}
};

class Restaurant : public Landmark
{
private:
	int size;
public:
	Restaurant(std::string pName, int psize) :Landmark(pName), size(psize) {};
	const std::string color()
	{
		return "yellow";
	}
	const std::string icon()
	{
		return size < 40 ? "small knife/fork" : "large knife/fork";
	}

	~Restaurant()
	{
		std::cout << "Deleting restaurant " << name() << std::endl;
	}
};


class Hospital : public Landmark
{
private:
public:
	Hospital(std::string pName) :Landmark(pName) {};
	const std::string color()
	{
		return "blue";
	}
	const std::string icon()
	{
		return "H";
	}	
	~Hospital()
	{
		std::cout << "Deleting hospital " << name() <<std::endl;
	}
};




void display(Landmark* lm)
{
	std::cout << "Display a " << lm->color() << " " << lm->icon() << " icon for "
		<< lm->name() << "." << std::endl;
}

int main()
{
	Landmark* landmarks[4];


	landmarks[0] = new Hotel("Westwood Rest Good");
	

	// Restaurants have a name and seating capacity.  Restaurants with a
	// capacity under 40 have a small knife/fork icon; those with a capacity
	// 40 or over have a large knife/fork icon.


	landmarks[1] = new Restaurant("Bruin Bite", 30);
	landmarks[2] = new Restaurant("La Morsure de l'Ours", 100);
	landmarks[3] = new Hospital("UCLA Medical Center");

	

	std::cout << "Here are the landmarks." << std::endl;

	
	for (int k = 0; k < 4; k++)
	{	
		display(landmarks[k]); 
	}

	// Clean up the landmarks before exiting
	std::cout << "Cleaning up." << std::endl;
	for (int k = 0; k < 4; k++)
		delete landmarks[k];

	system("pause");
	return 0;
}