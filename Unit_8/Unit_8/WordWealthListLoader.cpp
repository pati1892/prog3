#include <fstream>
#include <iostream>
#include <string>
#include "DataLoader.cpp"

class WorldWealthListLoader:DataLoader {

public:
	WorldWealthListLoader(std::string filename):filename(filename) {}

	// Geerbt über DataLoader
	Position getNextPosition() override
	{
		return Position();
	}

	int hasNextPosition() override
	{
		return 0;
	}

private:
	std::string filename;
	std::ifstream input;

	int open() {
		input = std::ifstream(filename);
		if (!input) {
			std::cerr << "Fehler beim Oeffnen der Date " << filename << std::endl;
			return 0;
		}
		
		return 1;
	}
};

int main() {
	std::ifstream input("WorldWealthList.txt");

	if (!input)
	{
		std::cerr << "Fehler beim Oeffnen der Datei " << "  sdf"<< "\n";
		return 1;
	}



	std::string line;
	while (std::getline(input, line)) {
		std::cout << line << "\n";
	}
	return 0;
}