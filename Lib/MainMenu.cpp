//áèáëèîòåêè
#include "TXLib.h"
#include <fstream>
#include <string>
#include <iostream>

//Îáúÿâëåíèå ôóíêöèé:
void chooseVoid (HDC menuPic ,HDC choose, int red, int green, int blue, bool game_over, int* level, bool* nachalo_igry, HDC user, int x, int y, HDC about);
bool menu (HDC choose, HDC menuPic, bool* nachalo_igry, int red, int green, int blue, HDC user, int x, int y, HDC* about );
void aboutVoid (HDC menuPic ,HDC choose, int red, int green, int blue, bool game_over, int* level, bool* nachalo_igry, HDC user, int x, int y, HDC about);

using namespace std;

//ïðèñâîåíèå level çíà÷åíèå 1
int level = 1;




bool menu (HDC choose, HDC menuPic, bool* nachalo_igry, int red, int green, int blue,HDC user, int x, int y, HDC about ) {

    bool game_over = false;
    txTransparentBlt (txDC(), 0, 0, 1440, 900, menuPic, 0, 0, TX_WHITE);

    if (txMouseX() > 300 and   //íà÷àòü âûáðàííûé óðîâåíü
        txMouseY() > 385 and
        txMouseY() < 397 and
        txMouseX() < 447 and
        txMouseButtons() & 1)
    {
        *nachalo_igry = true;

    }
    else if (txMouseX() > 283 and   //âûõîä èç èãðû
        txMouseY() > 485 and
        txMouseY() < 503 and
        txMouseX() < 482 and
        txMouseButtons() & 1)
    {
        game_over = true;
    }

    else if (txMouseX() > 262 and  //âûáîð óðîâíåé
        txMouseY() > 306 and
        txMouseY() < 415 and
        txMouseX() < 708 and
        txMouseButtons() & 1)
    {
        *nachalo_igry = false;
        txClear();
        chooseVoid ( menuPic, choose, red, green, blue, game_over, &level, nachalo_igry, user, x, y, about);
    }

    else if (txMouseX() > 289 and    //about - äîïîëíèòåëüíî
        txMouseY() > 526 and
        txMouseY() < 536 and
        txMouseX() < 486 and
        txMouseButtons() & 1)
    {
       *nachalo_igry = false;
        txClear();
        aboutVoid ( menuPic, choose, red, green, blue, game_over, &level, nachalo_igry, user, x, y, about);
    }

    else if (txMouseX() > 300 and       //Âûáîð óðîâíåé
        txMouseY() > 437 and
        txMouseY() < 448 and
        txMouseX() < 438 and
        txMouseButtons() & 1)
    {
        *nachalo_igry = false;
        chooseVoid ( menuPic, choose, red, green, blue, game_over, &level, nachalo_igry, user, x, y, about);
    }

    return game_over;
}

void chooseVoid (HDC menuPic ,HDC choose, int red, int green, int blue, bool game_over, int* level, bool* nachalo_igry, HDC user, int x, int y, HDC about) 
{ //ôóíêöèÿ âûáîðà óðîâíåé



    txSleep(1000);
    while (*nachalo_igry == false) {
        txTransparentBlt (txDC(), 0, 0, 1440, 900, choose, 0, 0, TX_WHITE);

        if (txMouseX() > 93 and          //çàãðóçèòü óðîâåíü ¹1
            txMouseY() > 90 and
            txMouseY() < 330 and
            txMouseX() < 477 and
            txMouseButtons() & 1)
        {
                    *level = 1;
                    *nachalo_igry = true;

        } else
       if (txMouseX() >533 and    //çàãðóçèòü óðîâåíü ¹2
            txMouseY() > 90 and
            txMouseY() < 329 and
            txMouseX() < 917 and
            txMouseButtons() & 1)
        {
                    *level = 2;
                    *nachalo_igry = true;

        } else
        if (txMouseX() > 970 and           //çàãðóçèòü óðîâåíü ¹3
            txMouseY() > 90 and
            txMouseY() < 332 and
            txMouseX() < 1359 and
            txMouseButtons() & 1)
        {
                    *level = 3;
                    *nachalo_igry = true;

        }  else

        if (txMouseX() > 530 and    //çàãðóçèòü ïîëüçîâàòåëüñêèé óðîâåíü
            txMouseY() > 521 and
            txMouseY() < 761 and
            txMouseX() < 917 and
            txMouseButtons() & 1)
        {
            *level = 0;
            *nachalo_igry = true;


        }
        if (txMouseX() > 29 and      //âîçâðàò â ìåíþ
            txMouseY() > 830 and
            txMouseY() < 874 and
            txMouseX() < 90 and
            txMouseButtons() & 1)
        {

              return;

        }


        txSleep(10);
    }
}


void aboutVoid (HDC menuPic ,HDC choose, int red, int green, int blue, bool game_over, int* level,
 bool* nachalo_igry, HDC user, int x, int y, HDC about) 
{  //äîêóìåíòàöèÿ

    bool fileRead = false;

    while (true) 
    {

    
          if (txMouseX() > 34 and
            txMouseY() > 15 and
            txMouseY() < 70 and
            txMouseX() < 132 and
            txMouseButtons() & 1)
          { return; }
      txSleep(10);
     }
   }




