#include "framework.h"
#include "DAT154Oblig1.h"
#include "TrafficLight.h"

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
