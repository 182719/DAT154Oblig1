#include "framework.h"
#include "DAT154Oblig1.h"
#include "TrafficLight.h"

void drawTrafficLight(HDC hdc, int x, int y, TrafficLight trafficLight)
{
	// GDI logic for creating a brush
	HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH greyBrush = CreateSolidBrush(RGB(192, 192, 192));
	HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH yellowBrush = CreateSolidBrush(RGB(255, 255, 0));
	HBRUSH greenBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH actualBrush = blackBrush;

	HGDIOBJ hOrg = SelectObject(hdc, actualBrush);
	

	// Red ellipse (circle)
	Rectangle(hdc, x, y, x + 100, y + 270);
	
	//øverste lys
	actualBrush = trafficLight.getCurrentState().red ? redBrush : greyBrush;
	SelectObject(hdc, actualBrush);
	Ellipse(hdc, x + 10, y + 10, x + 90, y + 80);

	actualBrush = trafficLight.getCurrentState().yellow ? yellowBrush : greyBrush;
	SelectObject(hdc, actualBrush);
	Ellipse(hdc, x + 10, y + 100, x + 90, y + 170);

	actualBrush = trafficLight.getCurrentState().green ? greenBrush : greyBrush;
	SelectObject(hdc, actualBrush);
	Ellipse(hdc, x + 10, y + 190, x + 90, y + 260);

	// Cleanup, set back original brush
	SelectObject(hdc, hOrg);
	DeleteObject(actualBrush);
	DeleteObject(blackBrush);
	DeleteObject(greyBrush);
	DeleteObject(redBrush);
	DeleteObject(yellowBrush);
	DeleteObject(greenBrush);
	DeleteObject(hOrg);

}
