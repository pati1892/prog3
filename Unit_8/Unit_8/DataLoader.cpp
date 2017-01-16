#include "Position.cpp"

class DataLoader {

public:

	virtual Position getNextPosition() = 0;
	virtual int hasNextPosition() = 0;

private:

};