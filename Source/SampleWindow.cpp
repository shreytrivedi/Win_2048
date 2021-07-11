// SampleWindow.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "SampleWindow.h"

#define MAX_LOADSTRING 100

#define WND_WIDTH  550
#define WND_HEIGHT 600

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_SAMPLEWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SAMPLEWINDOW));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SAMPLEWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SAMPLEWINDOW);
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
      CW_USEDEFAULT, 0, WND_WIDTH, WND_HEIGHT, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


//void GamePaint(HDC hDC)
//{
//    //MoveToEx(hDC, 0, 0, NULL);
//    //LineTo(hDC, 50, 50);
//
//    HPEN hBluePen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
//    auto hPen = SelectObject(hDC, hBluePen);
//    //HBRUSH hPurpleBrush = CreateSolidBrush(RGB(255, 0, 255));
//    //auto hbrush = SelectObject(hDC, hPurpleBrush);
//    
//    //TextOut(hDC, 10, 10, TEXT("Michael Morrison"), 16);
//    //Rectangle(hDC, 16, 36, 72, 70);
//    
//    Rectangle(hDC, GRID_TOP_LEFT_X
//        , GRID_TOP_LEFT_Y
//        , GRID_TOP_LEFT_X + ROWS*CELL_HEIGHT
//        , GRID_TOP_LEFT_Y + COLS * CELL_WIDTH);
//
//    //Draw the Horizontal Lines
//    MoveToEx(hDC, GRID_TOP_LEFT_X, GRID_TOP_LEFT_Y + 1 * CELL_HEIGHT, NULL);
//    LineTo(hDC, GRID_TOP_LEFT_X + 4 * CELL_WIDTH, GRID_TOP_LEFT_Y + 1 * CELL_HEIGHT);
//
//    MoveToEx(hDC, GRID_TOP_LEFT_X, GRID_TOP_LEFT_Y + 2 * CELL_HEIGHT, NULL);
//    LineTo(hDC, GRID_TOP_LEFT_X + 4 * CELL_WIDTH, GRID_TOP_LEFT_Y + 2 * CELL_HEIGHT);
//
//    MoveToEx(hDC, GRID_TOP_LEFT_X, GRID_TOP_LEFT_Y + 3 * CELL_HEIGHT, NULL);
//    LineTo(hDC, GRID_TOP_LEFT_X + 4 * CELL_WIDTH, GRID_TOP_LEFT_Y + 3 * CELL_HEIGHT);
//
//    //Draw the Vertical Lines
//    MoveToEx(hDC, GRID_TOP_LEFT_X + 1 * CELL_WIDTH, GRID_TOP_LEFT_Y, NULL);
//    LineTo(hDC, GRID_TOP_LEFT_X + 1 * CELL_WIDTH, GRID_TOP_LEFT_Y + 4 * CELL_HEIGHT);
//
//    MoveToEx(hDC, GRID_TOP_LEFT_X + 2 * CELL_WIDTH, GRID_TOP_LEFT_Y, NULL);
//    LineTo(hDC, GRID_TOP_LEFT_X + 2 * CELL_WIDTH, GRID_TOP_LEFT_Y + 4 * CELL_HEIGHT);
//
//    MoveToEx(hDC, GRID_TOP_LEFT_X + 3 * CELL_WIDTH, GRID_TOP_LEFT_Y, NULL);
//    LineTo(hDC, GRID_TOP_LEFT_X + 3 * CELL_WIDTH, GRID_TOP_LEFT_Y + 4* CELL_HEIGHT);
//
//    //TextOut(hDC, 100, 100, TEXT("16"), 2);
//
//    RECT r = { 50, 50, 150, 150 };
//    DrawText(hDC, TEXT("16"), -1, &r,
//        DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//
//    //RECT r = { 34, 50, 54, 70 };
//    //FrameRect(hDC, &r, hBluePen);
//}


#include "GameRenderer.h"
#include "GameManager.h"
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
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            //GamePaint(hdc);
            RenderBoard(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
            case VK_LEFT:

                // Process the LEFT ARROW key. 
                GameManager::GetInstance()->OnHandleLeft();
                InvalidateRect(hWnd, NULL, FALSE);
                break;

            case VK_RIGHT:

                // Process the RIGHT ARROW key. 
                GameManager::GetInstance()->OnHandleRight();
                InvalidateRect(hWnd, NULL, FALSE);
                break;

            case VK_UP:

                // Process the UP ARROW key. 
                GameManager::GetInstance()->OnHandleUp();
                InvalidateRect(hWnd, NULL, FALSE);
                break;

            case VK_DOWN:

                // Process the DOWN ARROW key. 
                GameManager::GetInstance()->OnHandleDown();
                InvalidateRect(hWnd, NULL, FALSE);
                break;
        }
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
