// DAT154Oblig1.cpp : Defines the entry point for the application.

#include "framework.h"
#include "DAT154Oblig1.h"
#include "DrawController.h"
#include "TrafficLight.h"
#include "Car.h"
#include <vector>
#include <list>
#include "SirkList.h"
#include "Commctrl.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
TrafficLight trafficLight1(0);
TrafficLight trafficLight2(2);
list<Car*> verticalCarList;
list<Car*> horizontalCarList;
static bool trafficLIghtTimerStarted = false;                     //Timer boolean
static bool carTimerStarted = false;                     //Car timer
list<Car*> liste1;
double pn = 0;
double pw = 0;
double probabilitySettingN = 0;
double probabilitySettingW = 0;


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ProbabilityDialog(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
    

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DAT154OBLIG1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DAT154OBLIG1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DAT154OBLIG1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DAT154OBLIG1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:
        switch (wParam) {
        case VK_LEFT:
            if (probabilitySettingW > 0) {
                probabilitySettingW -= 0.1;
            }
      
            break;
        case VK_RIGHT:
            if (probabilitySettingW < 1.0) {
                probabilitySettingW += 0.1;
            }
            break;
        case VK_UP:
            if (probabilitySettingN < 1.0) {
                probabilitySettingN += 0.1;
            }
            break;
        case VK_DOWN:
            if (probabilitySettingN > 0) {
                probabilitySettingN -= 0.1;
            }
            break;
        
        default: 
           {
                Position p = { 410, -50 };

                Car* c1 = new Car(p, true, &trafficLight1, NULL);
                Car* c2 = new Car(p, true, &trafficLight1, NULL);
                Car* c3 = new Car(p, true, &trafficLight1, NULL);
                Car* c4 = new Car(p, true, &trafficLight1, NULL);
                Car* c5 = new Car(p, true, &trafficLight1, NULL);
                Car* c6 = new Car(p, true, &trafficLight1, NULL);


                break;
            }
        }
 
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case ID_SHOWPROB:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOGPROB), hWnd, ProbabilityDialog);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_RBUTTONDOWN:
    {
        if (!trafficLIghtTimerStarted)
        {
            SetTimer(hWnd, 0, 2000, NULL);
            trafficLIghtTimerStarted = true;

        }
        else {
            //Clean up
            //KillTimer(hWnd, 0);
            //InvalidateRect(hWnd, 0, true);
        }
        if (!carTimerStarted)
        {
            SetTimer(hWnd, 1, 100, NULL);
            carTimerStarted = true;
        }
        else
        {
            //Clean up
            //KillTimer(hWnd, 1);
            //InvalidateRect(hWnd, 0, true);
        }
        break;
    }

    case WM_LBUTTONDOWN:
        //trafficLight1.nextState();
        //trafficLight2.nextState();
        //InvalidateRect(hWnd, NULL, true);
        {
        if (!trafficLIghtTimerStarted)
        {
            SetTimer(hWnd, 0, 2000, NULL);
            trafficLIghtTimerStarted = true;

        }
        else {
            //Clean up
            //KillTimer(hWnd, 0);
            //InvalidateRect(hWnd, 0, true);
        }
        if (!carTimerStarted)
        {
            SetTimer(hWnd, 1, 33, NULL);
            carTimerStarted = true;
        }
        else 
        {
            //Clean up
            //KillTimer(hWnd, 1);
            //InvalidateRect(hWnd, 0, true);
        }
        //fTimer = !fTimer;
        }
        break;

    case WM_TIMER:
        {
        switch (wParam) {
        case 0:
            trafficLight1.nextState();
            trafficLight2.nextState();


            pn = rand() / (double)RAND_MAX;
            pw = rand() / (double)RAND_MAX;

            // Car spawning
            if (pn < probabilitySettingN) {
                Position p = { 410, -50 };

                if (verticalCarList.size() == 0)
                {
                    Car* c = new Car(p, false, &trafficLight2, NULL); //HUSK Å SLETT
                    verticalCarList.push_back(c);
                }
                else
                {
                    Car* c = new Car(p, false, &trafficLight2, verticalCarList.back()); //HUSK Å SLETT
                    verticalCarList.push_back(c);
                }
            }
            if (pw < probabilitySettingW) {
                Position p = { -50 , 460 };
                if (horizontalCarList.size() == 0)
                {
                    Car* c = new Car(p, true, &trafficLight1, NULL); //HUSK Å SLETT
                    horizontalCarList.push_back(c);
                }
                else
                {
                    Car* c = new Car(p, true, &trafficLight1, horizontalCarList.back()); //HUSK Å SLETT
                    horizontalCarList.push_back(c);
                }
            }
            break;
        case 1:
            for (auto v : verticalCarList) {
                v->move();
            }
            for (auto c : horizontalCarList) {
                c->move();
            }
            if (!verticalCarList.empty()) {
                Car* c = verticalCarList.front();
                if (c->getPosition().y >= 900) {
                    delete c;
                    verticalCarList.pop_front();
                    if (!verticalCarList.empty()) {
                        Car* d = verticalCarList.front();
                        d->setCarInFront(NULL);
                        int x = 1;
                    }
                }
            }
            if (!horizontalCarList.empty()) {
                Car* c = horizontalCarList.front();
                if (c->getPosition().x >= 900) {
                    delete c;
                    horizontalCarList.pop_front();
                    if (!horizontalCarList.empty()) {
                        Car* d = horizontalCarList.front();
                        d->setCarInFront(NULL);
                        int x = 1;
                    }


                }
            }

            break;
        }


        InvalidateRect(hWnd, NULL, true);
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // TODO: Add any drawing code that uses hdc here...
            drawTrafficLight(hdc, 250, 500, trafficLight1);
            drawTrafficLight(hdc, 300, 100, trafficLight2); 
            drawRoad(hdc);
            for (auto v : verticalCarList) {
                drawCar(hdc, v);
            }
            for (auto c : horizontalCarList) {
                drawCarI(hdc, c);
            }
            /*
            for (size_t i = 0; i < verticalCarList.size(); i++)
            {
                drawCar(hdc, (verticalCarList.at(i)));
            }
            for (size_t i = 0; i < horizontalCarList.size(); i++)
            {
                drawCarI(hdc, (horizontalCarList.at(i)));
            }
            */
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

/*
Dialog window handler and message procedure
*/
INT_PTR CALLBACK ProbabilityDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:

        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    case WM_HSCROLL:
        if (LOWORD(wParam) == SB_THUMBTRACK || LOWORD(wParam) == SB_THUMBPOSITION) {

            probabilitySettingN = HIWORD(wParam) / 100.;
            probabilitySettingW = probabilitySettingW;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
