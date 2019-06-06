#ifndef UIMANAGER_H
#define UIMANAGER_H

#define MENU_STRING_ITEM_LENGTH 25
#define MENU_NUMBER_OF_ITEM 5
#define MENU_BEGIN 0

#include <ncurses.h>
#include <vector>
#include <string>

using namespace std;

class UIManager{
    private:
        WINDOW *win;
        
        int _screenSizeX;
        int _screenSizeY;
        bool _initializedScreen;
        
        int _menuEntryPos;
        vector<string> curMenu;

        void drawBorders(char vChar, char hChar);
        void getMenuDrawPosition(int &y, int &x);
        
    public:
        UIManager(bool shouldInitScr);
        virtual ~UIManager();
        void initScreen();
        void drawMenu(vector<string> menu, int startingAt);
        int getX_Size();
        int getY_Size();
        int getX_Position();
        int getY_Position();
};

#endif