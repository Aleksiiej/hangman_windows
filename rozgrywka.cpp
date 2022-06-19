#include "rozgrywka.h"
#include "drawings.h"

using namespace std;

extern int status_number;
////////////////////////////////////////////////////////////////////
void show_menu()
{
    cout<<"WITAM W WISIELCZYKU"<<endl;
    cout<<drawing9<<endl;
    cout<<"   MENU GLOWNE"<<endl;
    cout<<"   -----------"<<endl;
    cout<<"1.Rozpoczecie gry"<<endl;
    cout<<"2.Zakonczenie gry"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"Instrukcja: aby wybrac opcje, wpisz liczbe i zatwierdz wciskajac ENTER"<<endl;
}
////////////////////////////////////////////////////////////////////
void Tgame::show_status(int status)
{
    switch(status)
    {
    case 0:
        cout<<drawing0<<endl;
        break;
    case 1:
        cout<<drawing1<<endl;
        break;
    case 2:
        cout<<drawing2<<endl;
        break;
    case 3:
        cout<<drawing3<<endl;
        break;
    case 4:
        cout<<drawing4<<endl;
        break;
    case 5:
        cout<<drawing5<<endl;
        break;
    case 6:
        cout<<drawing6<<endl;
        break;
    case 7:
        cout<<drawing7<<endl;
        break;
    case 8:
        cout<<drawing8<<endl;
        break;
    }

    cout<<"Zgadywane slowo:"<<endl;
    cout<<chosen_word<<endl;

    for (auto element:displayed_word)
    {
        cout<<element<<" ";
    }
    cout<<endl;
}
////////////////////////////////////////////////////////////////////
void Tgame::find_letter()
{
    system("cls");
    show_status(status_number);

    cout<<endl;
    cout<<"Podaj litere: "<<endl;
    char letter;
    cin>>letter;

    int pos=chosen_word.find(letter);
    if (pos==string::npos)
    {
        cout<<"W wyrazie nie ma takiej litery"<<endl;
        status_number++;
        Sleep(1200);
    }
    else
    {
        while(true)
        {
            displayed_word[pos]=letter;
            pos=chosen_word.find(letter,pos+1);
            if (pos==string::npos) break;
        }
        if(displayed_word.compare(chosen_word)==0) word_check();
    }
    system("cls");
    show_status(status_number);
}
////////////////////////////////////////////////////////////////////
void Tgame::guess_word()
{
    system("cls");
    show_status(status_number);

    cout<<endl;
    cout<<"Podaj slowo: "<<endl;
    string guessed_word;
    cin>>guessed_word;
    if(guessed_word.compare(chosen_word)==0) word_check();
    else
    {
        cout<<"Nie zgadles."<<endl;
        status_number++;
        Sleep(1200);
    }
}
///////////////////////////////////////////////////////////////////////
void Tgame::reset_word()
{
    fstream file;
    file.open("lista_slow.txt",ios::in);

    if(file.good()==false)
    {
        cout<<"Nie udalo sie otworzyc pliku";
        exit(0);
    }

    srand(time(NULL));
    int line_number=rand()%100+1;
    int counter=1;
    while(counter<=line_number)
    {
        getline(file,chosen_word);
        counter++;
    }

    file.close();

    string temp(chosen_word.size(),'_');
    displayed_word=temp;
}













