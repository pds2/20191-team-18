#ifndef UIMANAGER_H
#define UIMANAGER_H

#define SCR_MODE_BLANK 0
#define SCR_MODE_MENU 1
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
        int _screenMode;
        bool _initializedScreen;
        
        int _menuEntryPos;
        int _menuStartDrawPos;
        vector<string> curMenu;
        void drawBorders(char vChar, char hChar);
        void getMenuDrawPosition(int &y, int &x);
        void menuNavigate(int pressedKey);
        void menuNavigateUp();
        void menuNavigateDown();
        void highlightMenuEntry(int entry);
        void unhighlightMenuEntry(int entry);
        void drawMenu(vector<string> menu, int startingAt);

        bool _stopListener;
        void startListener();
        void stopListener();
    public:
        UIManager(bool shouldInitScr);
        virtual ~UIManager();
        
        void initScreen();
        int getX_Size();
        int getY_Size();
        int getX_Position();
        int getY_Position();

        void drawMenu(vector<string> menu, int startingAt, bool forceStartListener);
        int getSelectedMenuItem();
        
        void initScreenActionListener();
};

#endif