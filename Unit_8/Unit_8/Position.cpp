#include <iostream>
#include <string>

class Position {

public:
	Position(std::string rank, std::string name, std::string country, std::string age, std::string wealth, std::string sourceOfWealth) :
		name(name), country(country), sourceOfWealth(sourceOfWealth) {

		setRank(rank);
		setAge(age);
		setWealth(wealth);
	}

	friend std::ostream& operator<<(std::ostream&, const Position&);

private:
	void setRank(std::string rankVal) {
		try {
			rank = std::stoi(rankVal);
		}
		catch (const std::invalid_argument &ia) {
			rank = -1;
		}
	}
	void setAge(std::string ageVal) {
		try {
			age = std::stoi(ageVal);
		}
		catch (const std::invalid_argument &ia) {
			age = -1;
		}
	}
	void setWealth(std::string wealthVal) {
		try {
			wealth = std::stof(wealthVal);
		}
		catch (const std::invalid_argument &ia) {
			wealthVal = -1;
		}
	}
public:
	int rank;
	std::string name;
	std::string country;
	int age;
	float wealth;
	std::string sourceOfWealth;
};

/*std::ostream& operator<<(std::ostream& out, const Position &position)
{
	out << position.rank << " " << position.name << " " << position.country << " " << position.age << " "
		<< position.averageWealth << " " << position.sourceOfWealth << "\n";
	return out;
}*/