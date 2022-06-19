#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;
////////////////////////////////////////
void show_menu();
////////////////////////////////////////
class Tgame
{
private:
    string chosen_word;
    string displayed_word;
    bool win=false;
public:
    void show_status(int status);
    void find_letter();
    void guess_word();
    void reset_word();
    bool win_status_check()
    {
        return win;
    };
    void win_status_change()
    {
        if(win==true) win=false;
        if(win==false) win=true;
    };
    void word_check()
    {
        cout<<"Zgadles slowo: "<<chosen_word<<". Wygrales!"<<endl;
        cout<<"Zaraz powrocisz do glownego menu..."<<endl;
        Sleep(1500);
        win_status_change();
    }
};


