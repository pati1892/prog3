#include <fstream>
#include <string>
#include <vector>
#include "Position.cpp"
#include <sstream>

class WorldWealthListLoader {

public:
	WorldWealthListLoader(std::string filename):filename(filename) {
		open();
		ignoreHeader();
	}

	// Geerbt über DataLoader
	std::vector<Position> getPosition()
	{
		std::string line;
		std::vector<Position> position;		
		while (std::getline(input, line)) {
			if (static_cast<int>(line.at(0)) > 47 && static_cast<int>(line.at(0)) < 58) {
				std::vector<std::string> pos = split(line, '\t');
				if (pos.size() == 6) {

					position.push_back(*new Position(pos.at(0), pos.at(1), pos.at(2), pos.at(3), pos.at(4), pos.at(5)));
				}	
			}
				
		}
		close();
		return position;
		
	}

	void close(){
		input.close();
	}

private:
	std::string filename;
	std::ifstream input;

	std::vector<std::string> split(const std::string& str, char delimiter)
	{
		std::istringstream is(str);
		std::vector<std::string> result;
		for (std::string cur; std::getline(is, cur, delimiter); 
		result.push_back(cur));
		return result;
	}

	int open() {
		input = std::ifstream(filename, std::ifstream::in);
		if (!input) {
			std::cerr << "Fehler beim Oeffnen der Datei " << filename << std::endl;
			return 0;
		}
		
		return 1;
	}
	void ignoreHeader() {
		std::string line;
		std::getline(input, line);
		std::getline(input, line);
	}
};

int main() {
	WorldWealthListLoader* wwl = new WorldWealthListLoader("WorldWealthList.txt");
	WorldWealthListLoader& wwlRef = *wwl;
	std::cout << "hallo 1" << std::endl;

	std::vector<Position> positions;
	Position* currentPosition;

	/*while ((currentPosition = wwlRef.getNextPosition()) != nullptr) {
		positions.push_back(*currentPosition);
	}
	wwlRef.close();*/
	positions = wwlRef.getPosition();

	for (Position position : positions) {
		std::cout << position.rank << " " << position.name << " " << position.country << " " << position.age << " "
			<< position.wealth << " " << position.sourceOfWealth << "\n";
		
	}
	std::cout << "hallo" << std::endl;
	return 0;
	


}