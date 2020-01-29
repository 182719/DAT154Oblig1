#pragma once
typedef struct {
	int red;
	int green;
	int blue;
} Color;

typedef struct {
	int x;
	int y;
} Position;

class Car {
	Color color;
	Position position;
public:
	Car();
	Car(Position p);
	Color getColor();
	Position getPosition();
	void setPosition(Position p);
};

