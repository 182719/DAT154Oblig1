#include "framework.h"
#include "DAT154Oblig1.h"

void drawTrafficLight(HDC hdc, int x, int y)
{
	// GDI logic for creating a brush
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
	HGDIOBJ hOrg = SelectObject(hdc, hBrush);
	// Red ellipse (circle)
	Rectangle(hdc, x, y, x + 100, y + 270);
	
	//øverste lys
	hBrush = CreateSolidBrush(RGB(192, 192, 192));
	hOrg = SelectObject(hdc, hBrush);
	Ellipse(hdc, x + 10, y + 10, x + 90, y + 80);

	//Midt lys
	Ellipse(hdc, x + 10, y + 100, x + 90, y + 170);

	//Nederste lys

	Ellipse(hdc, x + 10, y + 190, x + 90, y + 260);
	
	// Cleanup, set back original brush
	SelectObject(hdc, hOrg);
	DeleteObject(hBrush);
}
