#include "TXLib.h"

bool checkFocus(int MinX, int MaxX, int MinY, int MaxY);
void checkMenuFocus();
void drawMenu (int screenW, int screenH, HDC fon_menu);

bool checkFocus(int MinX, int MaxX, int MinY, int MaxY)
{
    if (
        txMouseX() >= MinX && //  ���� ��������� �� ������
        txMouseX() <= MaxX &&
        txMouseY() <= MaxY &&
        txMouseY() >= MinY
        )
    {
        return true;
    }

    return false;
}

void checkMenuFocus()
{
    if (checkFocus(40, 560, 810, 850))
    {
        txTextOut(txMouseX(), txMouseY() - 20, "��������� ���������" );
    }

    else if (checkFocus(40, 560, 880, 920))
    {
        txTextOut(txMouseX(), txMouseY() - 20, "���������� ����-��" );
    }

    else if (checkFocus(40, 560, 940, 980))
    {
        txTextOut(txMouseX(), txMouseY() - 20, "�������� ��������� ����������" );
    }

    else if (checkFocus(40, 560, 1000, 1040))
    {
        txTextOut(txMouseX(), txMouseY() - 20, "��� �� �������, �� ��� ���������" );
    }
}

void drawMenu (int screenW, int screenH, HDC fon_menu)
{
    txSetColor(TX_BLACK);
    txClear();
    txBitBlt (txDC(), 0, 0, screenW, screenH, fon_menu, 0, 0);


//txDeleteDC (background_FromTXLibHelp);
txTextOut (40, 810, "����� ����������");
txTextOut (40, 940, "���������");
txTextOut (40, 1000, "���������");
txTextOut (40, 1050, "�����");
}
