#include "rozgrywka.h"

using namespace std;

int status_number;
extern string drawing8;
extern string drawing9;

int main()
{
    Tgame game;
    int choose;
    while(true)
    {
        show_menu();

        while(true)
        {
            cin>>choose;
            if(choose==1) break;
            else if(choose==2)
            {
                cout<<"Aby wyjsc nacisnij dowolny klawisz i zatwierdz enterem"<<endl;
                int numb;
                cin>>numb;
                return 0;
            }
            else cout<<"Nieprawidlowy wybor. Sproboj ponownie."<<endl;
            Sleep(1500);
            cin.clear();
            cin.ignore(1000,'\n');
        }

        game.reset_word();
        status_number=0;

        while(true)
        {
            if (status_number==8)
            {
                system("cls");
                cout<<drawing8<<endl;
                cout<<endl<<"Przegrales"<<endl;
                cout<<endl<<"Zaraz powrocisz do menu..."<<endl;
                Sleep(1500);
                game.win_status_change();
                break;
            }
            system("cls");
            game.show_status(status_number);
            cout<<endl;
            cout<<"Wybierz opcje i zatwierdz enterem:"<<endl;
            cout<<"1.Zgadnij litere"<<endl;
            cout<<"2.Zgadnij slowo"<<endl;

            cin>>choose;

            switch (choose)
            {
            case 1:
                game.find_letter();
                break;
            case 2:
                game.guess_word();
                break;
            default:
                cout<<"Nieprawidlowy wybor. Sproboj ponownie."<<endl;
                Sleep(1500);
                cin.clear();
                cin.ignore(1000,'\n');
                break;
            }
            if(game.win_status_check()) break;
        }
        game.win_status_change();
        Sleep(1500);
        system("cls");
    }
}




