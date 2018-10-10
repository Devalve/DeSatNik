#include "Lib\\TXLib.h"
#include "Lib\\MENU.cpp"

bool total_exit ();
void menu_escape(HDC escape);

const int RAZMER_KNOPKI = 100;

int count_models = 10;

int main()
{
    model Mas_models[count_models];
    for (int i=0; i<count_models; i++)
    {
        Mas_models[i] = {100, 300, "sdf"};
    }

    int screenW = GetSystemMetrics (SM_CXSCREEN);
    int screenH = GetSystemMetrics (SM_CYSCREEN);
    txCreateWindow (screenW, screenH);

    bool startWS = false;

    newplanButton = {0, screenH * 80/100, 200, screenH * 85/100};
    loadButton = {0, screenH * 85/100, 200, screenH * 90/100};
    saveButton = {0, screenH * 90/100, 200, screenH * 95/100};
    exitButton = {0, screenH * 95/100, 200, screenH};

    HDC sofa = txLoadImage ("Pics\\�����.bmp");


    Button sofaButton =  {RAZMER_KNOPKI, screenH - 300, 2 * RAZMER_KNOPKI, screenH - 200, sofa, 241, 142};
    Button sofaButton2 = {4 * RAZMER_KNOPKI, screenH - 300, 5 * RAZMER_KNOPKI, screenH - 200, sofa, 241, 142};
    //Button sofaButton = {100, screenH * 80/100, 100 + screenH * 5/100, screenH * 85/100, sofa, 241, 142};
    //continueButton = {829, 447, 1065, 483};




    HDC WSpace = txLoadImage ("Pics\\Workspace.bmp");
    HDC fon_menu = txLoadImage ("Pics\\fon_menu .bmp");
    HDC escape= txLoadImage ("Pics\\menu_escape.bmp");
    bool isExit = false;

    while (!isExit)
    {
        txBegin();

		//��������
        if (startWS)
        {
            Win32::TransparentBlt (txDC(), 0, 0, screenW, screenH, WSpace, 0, 0, 1966, 1104, RGB(123,124,1));

            txSetColor(TX_WHITE);
            txRectangle(0, screenH - 300, screenW, screenH);

            menu_escape (escape);
			ikons (sofaButton);
			ikons (sofaButton2);
			if (txMouseButtons() & 2)
			{
				startWS = false;
			}



            txSetColor(TX_BLACK);
            for (int y = screenH; y >= screenH - 300; y = y - RAZMER_KNOPKI)
            {
                txLine   (0, y, RAZMER_KNOPKI * (screenW / RAZMER_KNOPKI), y);
            }

            for (int x = 0; x <= screenW; x = x + RAZMER_KNOPKI)
            {
                txLine   (x, screenH - 300, x, screenH);
            }

            txSetColor(TX_BLACK, 4);
            for (int x = 0; x <= screenW; x = x + 5 * RAZMER_KNOPKI)
            {
                txLine   (x, screenH - 300, x, screenH);
            }
        }
        //������� ����
		else
		{
            drawMenu (screenW, screenH, fon_menu);
            checkMenuFocus();
            //menu_escape(escape);
            startWS = startWorkspace(startWS);
            testova(Mas_models, count_models);
        }

        if (total_exit ())
        {
            txDisableAutoPause();
            isExit = true;
        };

        txSleep(10);
        txEnd();
    }

    txDeleteDC(fon_menu);
    txDeleteDC(escape);
    txDeleteDC(WSpace);

    return 0;
}

bool total_exit ()
{
    if (txMouseX() > exitButton.x  &&
        txMouseX() < exitButton.x1 &&
        txMouseY() > exitButton.y  &&
        txMouseY() < exitButton.y1 &&
        txMouseButtons() & 1)
    {
        return true;
    }

    return false;
}

void menu_escape(HDC escape)
{
    int screenW = GetSystemMetrics (SM_CXSCREEN);
    int screenH = GetSystemMetrics (SM_CYSCREEN);

    bool isreturn = false;
    if (GetAsyncKeyState(VK_ESCAPE))
    {
        txSleep(1000);

        while (!isreturn)
        {                     //x   y    ï¿½ï¿½ï¿½  ï¿½ï¿½ï¿½        x    y
            txBitBlt (txDC(), screenH/2, screenW/2 - 300, 215, 291, escape, 0, 0);

            if ((txMouseButtons() & 1 &&
                txMouseX() > 0 && txMouseX() < 800
            &&  txMouseY() > 0 && txMouseY() < 321) or GetAsyncKeyState(VK_ESCAPE))
            {
                isreturn = true;
            }

            txSleep(10);
        }
    }
}
