#include "framework.h"
#include "DAT154Oblig1.h"
#include "TrafficLight.h"
#include "Car.h"

void drawTrafficLight(HDC hdc, int x, int y, TrafficLight trafficLight)
{
	// GDI logic for creating all brushes
	HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH greyBrush = CreateSolidBrush(RGB(192, 192, 192));
	HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH yellowBrush = CreateSolidBrush(RGB(255, 255, 0));
	HBRUSH greenBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH actualBrush = blackBrush;

	// Saving original brush to be put back later
	HGDIOBJ hOrg = SelectObject(hdc, actualBrush);
	
	// Drawing a traffic light rectangle
	Rectangle(hdc, x, y, x + 100, y + 270);
	
	// Drawing the lights in the correct color
	actualBrush = trafficLight.getCurrentState().red ? redBrush : greyBrush;
	SelectObject(hdc, actualBrush);
	Ellipse(hdc, x + 10, y + 10, x + 90, y + 80);

	actualBrush = trafficLight.getCurrentState().yellow ? yellowBrush : greyBrush;
	SelectObject(hdc, actualBrush);
	Ellipse(hdc, x + 10, y + 100, x + 90, y + 170);

	actualBrush = trafficLight.getCurrentState().green ? greenBrush : greyBrush;
	SelectObject(hdc, actualBrush);
	Ellipse(hdc, x + 10, y + 190, x + 90, y + 260);

	// Setting the original brush back, deleting all brushes 
	// TODO: Possible to persist brushes? 
	SelectObject(hdc, hOrg);
	DeleteObject(actualBrush);
	DeleteObject(blackBrush);
	DeleteObject(greyBrush);
	DeleteObject(redBrush);
	DeleteObject(yellowBrush);
	DeleteObject(greenBrush);
	DeleteObject(hOrg);

}

void drawRoad(HDC hdc)
{
	HBRUSH greyBrush = CreateSolidBrush(RGB(169, 169, 169));
	HBRUSH darkGreyBrush = CreateSolidBrush(RGB(105,105,105));
	HBRUSH yellowBrush = CreateSolidBrush(RGB(255, 255, 0));
	HBRUSH actualBrush = greyBrush;

	//Saving original brush to be put back later
	HGDIOBJ hOrg = SelectObject(hdc, actualBrush);

	Rectangle(hdc, 400, 0, 500, 900); // Vertical Road
	Rectangle(hdc, 0, 400, 900, 500); // Horizontal Road
	actualBrush = darkGreyBrush;
	SelectObject(hdc, actualBrush);
	Rectangle(hdc, 400, 400,500, 500); // Center Square

	actualBrush = yellowBrush;
	SelectObject(hdc, actualBrush);

	for (int y = 0; y < 900; y += 50) {  //Vertical middle stripes 
		if (!(y > 399 && y < 499)) {
			Rectangle(hdc, 447, y, 452, y + 25);
		}
	}

	for (int x = 0; x < 900; x += 50) { // Horizontal middle stripes
		if (!(x > 399 && x < 499)) {
			Rectangle(hdc, x, 447, x + 25, 452);
		}
	}


	SelectObject(hdc, hOrg);
	DeleteObject(actualBrush);
	DeleteObject(darkGreyBrush);
	DeleteObject(greyBrush);
	DeleteObject(yellowBrush);

}

void drawCar(HDC hdc, Car car) 
{
	Color cColor = car.getColor();
	Position cPosition = car.getPosition();

	HBRUSH carColor = CreateSolidBrush(RGB(cColor.red, cColor.green, cColor.blue));
	HGDIOBJ hOrg = SelectObject(hdc, carColor);

	Rectangle(hdc, cPosition.x, cPosition.y, cPosition.x + 25, cPosition.y + 50);


	SelectObject(hdc, hOrg);
	DeleteObject(carColor);
	DeleteObject(hOrg);
}

void drawCarI(HDC hdc, Car car)
{
	Color cColor = car.getColor();
	Position cPosition = car.getPosition();

	HBRUSH carColor = CreateSolidBrush(RGB(cColor.red, cColor.green, cColor.blue));
	HGDIOBJ hOrg = SelectObject(hdc, carColor);

	Rectangle(hdc, cPosition.x, cPosition.y, cPosition.x + 50, cPosition.y + 25);

	SelectObject(hdc, hOrg);
	DeleteObject(carColor);
	DeleteObject(hOrg);
}