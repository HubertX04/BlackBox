/*
Hubert Kowalski
Black Box
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct historia
{
    char tab_h[50][50];
    int x_h, y_h;
    int zaznaczone_h;
    int liczba_strzalu_h;
};

void menu(char tab[50][50], int ukryte[50][50], int& liczba_strzalu, int& zapis, int czy_historia[210], historia his[210]);
void menu_u(int rozmiar, int atomy, int ukryte[50][50], int& liczba_strzalu, char tab[50][50], int zapis, int czy_historia[210], historia his[210]);

void clear_cls()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}

void powrot(char tab[50][50], int ukryte[50][50], int& liczba_strzalu, int& zapis, int czy_historia[210], historia his[210])
{
    cout << "Jesli chcesz wrocic do menu wpisz Y i zatwierdz klawiszem enter..." << endl;

    char a;

    while (cin >> a)
    {
        if (a == 'y' || a == 'Y')
        {
            clear_cls();
            menu(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);
            break;

        }
        else
        {
            cout << "Podany znak nie jest Y!!! Czy probojesz mnie oszukac?" << endl;
        }
    }
}

void black_box()
{
    cout << "                     %@@@@@@@@(     .@@@/                          #@@@                @@@@@@@@&*" << endl;
    cout << "                    .@@@ / , @@@@   (@@@                           @@@/               (@@@. / @@@#" << endl;
    cout << "                    %@@@   /@@@/   @@@/   .%@@@@@@@@%   /@@@@@@&  %@@&  /@@@#        .@@@(  .#@@&.  .&@@@@@@@/   %@@@.  &@@&" << endl;
    cout << "                   ,@@@@@@@@@%.   %@@&   %@@@.  ,@@@, ,@@@(      .@@@*%@@@,          #@@@@@@@@@(   %@@@.  .@@@/   #@@&%@@#" << endl;
    cout << "                   &@@@    #@@@, .@@@*  /@@@    &@@%  &@@#       %@@&#@@&           .@@@/    @@@& ,@@@*   ,@@@*   *@@@@@." << endl;
    cout << "                  *@@@#((#@@@@#  #@@@.  /@@@/ /@@@@,  %@@@/ .(, *@@@, #@@@.         #@@@(((%@@@@*  @@@&..%@@@/  (@@@,*@@@," << endl;
    cout << "                  #&&&&&&%(,      %@@@(  .%@@%./&&%    .%@@@&/  #&&#   /&&&,       .%&&&&&&#/.      .%@@@&(.  (&&&*   /&&&," << endl;
}

void powitanie()
{
    cout << "UWAGA! Aby cala gra byla wyswietlana poprawnie zaleca sie," << endl << "aby konsola byla wlaczona W PELNYM OKNIE." << endl;
    cout << "Jesli to zrobiles, wpisz Y i zatwierdz klawiszem enter..." << endl;

    char a;

    while (cin >> a)
    {
        if (a == 'y' || a == 'Y')
        {
            clear_cls();
            break;

        }
        else
        {
            cout << "Podany znak nie jest Y!!! Czy probojesz mnie oszukac?" << endl;
        }
    }
}

void instrukcja(char tab[50][50], int ukryte[50][50], int& liczba_strzalu, int& zapis, int czy_historia[210], historia his[210])
{
    black_box();
    cout << endl << endl;
    cout << "#####################################" << endl << endl;
    cout << "- (w, s, a, d) i (W, S, A, D) - poruszanie sie po planszy odpowiednio : w gore, w dol, w lewo i prawo." << endl;
    cout << "- q, Q - wyjscie do menu glownego." << endl;
    cout << "- u, U - undo(cofnij ruch)." << endl;
    cout << "- r, R - redo(powtorz cofniety ruch)." << endl;
    cout << "- spacja oddanie strzalu(gdy kursor jest na dowolnej scianie)." << endl;
    cout << "- o, O - na planszy umozliwia zaznaczenie przypuszczalnego polozenia atomu." << endl;
    cout << "- k, K - konczy rozgrywke i umozliwia wyswietlenie rozwiazania i liczby uzyskanych punktow" << endl << "(poprawnie znalezionych atomow)." << endl;
    cout << "- p, P - umozliwia wyswietlenie rozwiazania(przerywa etap gry, brak mozliwosci kontynuowania tego etapu gry)." << endl;
    cout << "- h, H - Help / Pomoc - pokazuje na chwile umieszczenie atomow na planszy." << endl << endl;
    cout << "---> Klawisze sterujace powinny byc zatwierdzane klawiszem enter." << endl << endl;
    cout << "Gracz porusza sie na planszy kursorem `G`." << endl;
    cout << "Po skonczeniu rozgrywki dany znak okresla: O - trafiony atom, X - nie trafiony atom, 0 - poprawne polozenie atomu" << endl;
    cout << "Jesli liczba ruchow przekroczy 9, nastepne ruchy zaczna byc liczone od 0 ( kazda kolejna liczba modulo 10)" << endl;
    cout << "Gracz moze wykonac maksymalnie 200 ruchow!!!" << endl << endl;

    powrot(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);
}

void o_autorze(char tab[50][50], int ukryte[50][50], int& liczba_strzalu, int& zapis, int czy_historia[210], historia his[210])
{
    black_box();
    cout << endl << endl;
    cout << "#####################################" << endl << endl;
    cout << "O autorze:" << endl;
    cout << "- Imie i nazwisko -> Hubert Kowalski" << endl;
    cout << "- adres e-mail -> hubert.kowzsnr@gmail.com" << endl << endl;

    powrot(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);
}

void tworzenie_planszy(int wymiar, char tab[50][50])
{
    for (int i = 1; i <= wymiar; i++)
    {
        if (i == 1)
        {
            tab[1][i] = char(201);
        }
        else
        {
            if (i == wymiar)
            {
                tab[1][i] = char(187);
            }
            else
            {
                if (i % 2 == 0)
                {
                    tab[1][i] = char(205);
                }
                else
                {
                    tab[1][i] = char(203);
                }
            }
        }
    }

    for (int i = 2; i < wymiar; i++)
    {
        for (int j = 1; j <= wymiar; j++)
        {
            if (j == 1)
            {
                if (i % 2 == 0)
                {
                    tab[i][j] = char(186);
                }
                else
                {
                    tab[i][j] = char(204);
                }
            }
            else
            {
                if (j == wymiar)
                {
                    if (i % 2 == 0)
                    {
                        tab[i][j] = char(186);
                    }
                    else
                    {
                        tab[i][j] = char(185);
                    }
                }
                else
                {
                    if (i % 2 == 0)
                    {
                        if (j % 2 == 0)
                        {
                            tab[i][j] = char(32);
                        }
                        else
                        {
                            tab[i][j] = char(186);
                        }
                    }
                    else
                    {
                        if (j % 2 == 0)
                        {
                            tab[i][j] = char(205);
                        }
                        else
                        {
                            tab[i][j] = char(206);
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= wymiar; i++)
        {
            if (i == 1)
            {
                tab[1][i] = char(201);
            }
            else
            {
                if (i == wymiar)
                {
                    tab[1][i] = char(187);
                }
                else
                {
                    if (i % 2 == 0)
                    {
                        tab[1][i] = char(205);
                    }
                    else
                    {
                        tab[1][i] = char(203);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= wymiar; i++)
    {
        if (i == 1)
        {
            tab[wymiar][i] = char(200);
        }
        else
        {
            if (i == wymiar)
            {
                tab[wymiar][i] = char(188);
            }
            else
            {
                if (i % 2 == 0)
                {
                    tab[wymiar][i] = char(205);
                }
                else
                {
                    tab[wymiar][i] = char(202);
                }
            }
        }
    }

    for (int i = 1; i <= wymiar; i++)
    {
        if (i % 2 != 0)
        {
            tab[0][i] = char(179);
            tab[wymiar + 1][i] = char(179);
        }
        else
        {
            tab[0][i] = char(32);
            tab[wymiar + 1][i] = char(32);
        }
    }

    for (int i = 1; i <= wymiar; i++)
    {
        if (i % 2 != 0)
        {
            tab[i][0] = char(196);
            tab[i][wymiar + 1] = char(196);
        }
        else
        {
            tab[i][0] = char(32);
            tab[i][wymiar + 1] = char(32);
        }
    }

    tab[0][0] = char(219);
    tab[0][wymiar + 1] = char(219);
    tab[wymiar + 1][0] = char(219);
    tab[wymiar + 1][wymiar + 1] = char(219);

}

void czyszczenie(int ukryte[50][50], char tab[50][50])
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            ukryte[i][j] = 0;
            tab[i][j] = ' ';
        }
    }
}

void losowanie_atomow(int wymiar, int atomy, int ukryte[50][50])
{
    int wylosowane = 0;
    int x, y;
    while (wylosowane != atomy)
    {
        x = rand() % (wymiar - 2) + 2;
        y = rand() % (wymiar - 2) + 2;
        if (x % 2 != 0)
        {
            x -= 1;
        }
        if (y % 2 != 0)
        {
            y -= 1;
        }

        if (ukryte[y][x] == 0)
        {
            ukryte[y][x] = 1;
            wylosowane++;
        }

    }


}

void pierwsze_wypisanie(int wymiar, int atomy, int& zaznaczone, char kursor, int x, int y, int& zapis, char tab[50][50], historia his[210], int czy_historia[210], int& liczba_strzalu)
{
    black_box();
    cout << endl << endl;
    cout << "#####################################" << endl << endl;

    cout << "Liczba atomow: " << atomy << endl;
    cout << "Liczba zaznaczonych atomow: " << zaznaczone << endl << endl;

    for (int i = 0; i <= wymiar + 1; i++)
    {
        for (int j = 0; j <= wymiar + 1; j++)
        {
            his[zapis].tab_h[i][j] = tab[i][j];
            if (y == i && x == j)
            {
                cout << kursor;
            }
            else
            {
                cout << tab[i][j];
            }
        }
        cout << endl;
    }
    his[zapis].zaznaczone_h = zaznaczone;
    his[zapis].x_h = x;
    his[zapis].y_h = y;
    czy_historia[zapis] = 1;
    his[zapis].liczba_strzalu_h = liczba_strzalu;
}

void wypisywanie_planszy(int atomy, int& zaznaczone, int wymiar, char kursor, int x, int y, int& zapis, char tab[50][50], historia his[210], int czy_historia[210], int& liczba_strzalu)
{

    zapis += 1;

    cout << "Liczba atomow: " << atomy << endl;
    cout << "Liczba zaznaczonych atomow: " << zaznaczone << endl << endl;

    for (int i = 0; i <= wymiar + 1; i++)
    {
        for (int j = 0; j <= wymiar + 1; j++)
        {
            his[zapis].tab_h[i][j] = tab[i][j];

            if (y == i && x == j)
            {
                cout << kursor;

            }
            else
            {
                cout << tab[i][j];
            }
        }
        cout << endl;
    }
    his[zapis].zaznaczone_h = zaznaczone;
    his[zapis].x_h = x;
    his[zapis].y_h = y;
    czy_historia[zapis] = 1;
    his[zapis].liczba_strzalu_h = liczba_strzalu;
    for (int i = zapis + 1; i < 205; i++)
    {
        czy_historia[i] = 0;
    }
}

void wypisywanie_planszy_bez_kopii(int atomy, int& zaznaczone, int wymiar, char kursor, int x, int y, char tab[50][50])
{
    cout << "Liczba atomow: " << atomy << endl;
    cout << "Liczba zaznaczonych atomow: " << zaznaczone << endl << endl;

    for (int i = 0; i <= wymiar + 1; i++)
    {
        for (int j = 0; j <= wymiar + 1; j++)
        {

            if (y == i && x == j)
            {
                cout << kursor;

            }
            else
            {
                cout << tab[i][j];
            }
        }
        cout << endl;
    }
}

void laser(int x, int y, int kierunek, int pomx, int pomy, int wymiar, char tab[50][50], int& liczba_strzalu, int ukryte[50][50])
{
    int krawedz = 0;
    while (krawedz != 2)
    {
        if (x == 0 || y == 0 || x == wymiar + 1 || y == wymiar + 1)
        {
            if (krawedz == 1)
            {
                tab[y][x] = char(((liczba_strzalu % 10) + 48));
                tab[pomy][pomx] = char(((liczba_strzalu % 10) + 48));
                break;
            }
            krawedz++;
        }

        if (kierunek == 2)
        {
            if (ukryte[y + 2][x] == 1)
            {
                tab[pomy][pomx] = 'H';
                break;
            }
            else if (ukryte[y + 2][x + 2] == 1 && ukryte[y + 2][x - 2] == 1)
            {
                tab[pomy][pomx] = 'R';
                break;
            }
            else if (ukryte[y + 2][x + 2] == 1)
            {
                if (x == 0 || y == 0 || x == wymiar + 1 || y == wymiar + 1)
                {
                    tab[pomy][pomx] = 'R';
                    break;
                }
                else
                {
                    kierunek = 4;
                    continue;
                }
            }
            else if (ukryte[y + 2][x - 2] == 1)
            {
                if (x == 0 || y == 0 || x == wymiar + 1 || y == wymiar + 1)
                {
                    tab[pomy][pomx] = 'R';
                    break;
                }
                else
                {
                    kierunek = 6;
                    continue;
                }
            }
            else
            {
                y += 2;
                continue;
            }
        }
        else if (kierunek == 6)
        {
            if (ukryte[y][x + 2] == 1)
            {
                tab[pomy][pomx] = 'H';
                break;
            }
            else if (ukryte[y + 2][x + 2] == 1 && ukryte[y - 2][x + 2] == 1)
            {
                tab[pomy][pomx] = 'R';
                break;
            }
            else if (ukryte[y + 2][x + 2] == 1)
            {
                if (x == 0 || y == 0 || x == wymiar + 1 || y == wymiar + 1)
                {
                    tab[pomy][pomx] = 'R';
                    break;
                }
                else
                {
                    kierunek = 8;
                    continue;
                }
            }
            else if (ukryte[y - 2][x + 2] == 1)
            {
                if (x == 0 || y == 0 || x == wymiar + 1 || y == wymiar + 1)
                {
                    tab[pomy][pomx] = 'R';
                    break;
                }
                else
                {
                    kierunek = 2;
                    continue;
                }
            }
            else
            {
                x += 2;
                continue;
            }
        }
        else if (kierunek == 8)
        {
            if (ukryte[y - 2][x] == 1)
            {
                tab[pomy][pomx] = 'H';
                break;
            }
            else if (ukryte[y - 2][x + 2] == 1 && ukryte[y - 2][x - 2] == 1)
            {
                tab[pomy][pomx] = 'R';
                break;
            }
            else if (ukryte[y - 2][x + 2] == 1)
            {
                if (x == 0 || y == 0 || x == wymiar + 1 || y == wymiar + 1)
                {
                    tab[pomy][pomx] = 'R';
                    break;
                }
                else
                {
                    kierunek = 4;
                    continue;
                }
            }
            else if (ukryte[y - 2][x - 2] == 1)
            {
                if (x == 0 || y == 0 || x == wymiar + 1 || y == wymiar + 1)
                {
                    tab[pomy][pomx] = 'R';
                    break;
                }
                else
                {
                    kierunek = 6;
                    continue;
                }
            }
            else
            {
                y -= 2;
                continue;
            }
        }
        else if (kierunek == 4)
        {
            if (ukryte[y][x - 2] == 1)
            {
                tab[pomy][pomx] = 'H';
                break;
            }
            else if (ukryte[y + 2][x - 2] == 1 && ukryte[y - 2][x - 2] == 1)
            {
                tab[pomy][pomx] = 'R';
                break;
            }
            else if (ukryte[y + 2][x - 2] == 1)
            {
                if (x == 0 || y == 0 || x == wymiar + 1 || y == wymiar + 1)
                {
                    tab[pomy][pomx] = 'R';
                    break;
                }
                else
                {
                    kierunek = 8;
                    continue;
                }
            }
            else if (ukryte[y - 2][x - 2] == 1)
            {
                if (x == 0 || y == 0 || x == wymiar + 1 || y == wymiar + 1)
                {
                    tab[pomy][pomx] = 'R';
                    break;
                }
                else
                {
                    kierunek = 2;
                    continue;
                }
            }
            else
            {
                x -= 2;
                continue;
            }
        }
    }
}

void plansza(int rozmiar, int atomy, int ukryte[50][50], int& liczba_strzalu, char tab[50][50], int& zapis, int czy_historia[210], historia his[210])
{
    czyszczenie(ukryte, tab);

    liczba_strzalu = 1;
    int wymiar = rozmiar * 2 + 1;

    tworzenie_planszy(wymiar, tab);

    char znak, kursor = 'G';
    int x = 2, y = 0, zaznaczone = 0, pomx, pomy, trafione = 0, koniec = 0, ile_ruchow = 0;

    losowanie_atomow(wymiar, atomy, ukryte);
    pierwsze_wypisanie(wymiar, atomy, zaznaczone, kursor, x, y, zapis, tab, his, czy_historia, liczba_strzalu);

    while (koniec == 0)
    {
        cin.ignore();
        cin.get(znak);
        clear_cls();

        black_box();
        cout << endl << endl;
        cout << "#####################################" << endl << endl;
        if (zapis <= 200)
        {
            if (znak == 'w' || znak == 'W')
            {
                if (y != 0)
                {
                    if (!((x == 0 && y == 2) || (y == 2 && x == wymiar + 1)))
                    {
                        y -= 2;
                    }
                }
            }
            else if (znak == 'a' || znak == 'A')
            {
                if (x != 0)
                {
                    if (!((y == 0 && x == 2) || (y == wymiar + 1 && x == 2)))
                    {
                        x -= 2;
                    }
                }
            }
            else if (znak == 's' || znak == 'S')
            {
                if (y != wymiar + 1)
                {
                    if (!((x == 0 && y == wymiar - 1) || (x == wymiar + 1 && y == wymiar - 1)))
                    {
                        y += 2;
                    }
                }
            }
            else if (znak == 'd' || znak == 'D')
            {
                if (x != wymiar + 1)
                {
                    if (!((x == wymiar - 1 && y == 0) || (x == wymiar - 1 && y == wymiar + 1)))
                    {
                        x += 2;
                    }
                }
            }

            else if (znak == 'u' || znak == 'U')
            {
                if (zapis > 0)
                {
                    zapis -= 1;

                    zaznaczone = his[zapis].zaznaczone_h;
                    liczba_strzalu = his[zapis].liczba_strzalu_h;
                    x = his[zapis].x_h;
                    y = his[zapis].y_h;

                    for (int i = 0; i <= wymiar + 1; i++)
                    {
                        for (int j = 0; j <= wymiar + 1; j++)
                        {
                            tab[i][j] = his[zapis].tab_h[i][j];
                        }
                    }
                    wypisywanie_planszy_bez_kopii(atomy, zaznaczone, wymiar, kursor, x, y, tab);

                }
                else
                {
                    zapis = 0;
                    cout << "Nie mozna sie cofnac!!! Znajdujesz sie na poczatku gry!" << endl;
                    wypisywanie_planszy_bez_kopii(atomy, zaznaczone, wymiar, kursor, x, y, tab);
                }
                continue;
            }
            else if (znak == 'r' || znak == 'R')
            {
                if (czy_historia[zapis + 1] == 1)
                {
                    zapis += 1;

                    zaznaczone = his[zapis].zaznaczone_h;
                    liczba_strzalu = his[zapis].liczba_strzalu_h;
                    x = his[zapis].x_h;
                    y = his[zapis].y_h;

                    for (int i = 0; i <= wymiar + 1; i++)
                    {
                        for (int j = 0; j <= wymiar + 1; j++)
                        {
                            tab[i][j] = his[zapis].tab_h[i][j];
                        }
                    }

                    wypisywanie_planszy_bez_kopii(atomy, zaznaczone, wymiar, kursor, x, y, tab);
                }
                else
                {
                    cout << "To jest twoj ostatni ruch!!!" << endl;
                    wypisywanie_planszy_bez_kopii(atomy, zaznaczone, wymiar, kursor, x, y, tab);
                }
                continue;
            }
            else if (znak == 'q' || znak == 'Q')
            {
                menu_u(rozmiar, atomy, ukryte, liczba_strzalu, tab, zapis, czy_historia, his);
            }
            else if (znak == ' ')
            {
                if (tab[y][x] == 32)
                {
                    if (!(x == 0 || x == wymiar + 1 || y == 0 || y == wymiar + 1))
                    {
                        cout << "Nie mozesz strzelac w srodku planszy!!!" << endl << endl;
                    }
                    else
                    {
                        ile_ruchow += 1;
                        pomx = x;
                        pomy = y;

                        if (x == 0)
                        {
                            laser(x, y, 6, pomx, pomy, wymiar, tab, liczba_strzalu, ukryte);
                        }
                        if (x == wymiar + 1)
                        {
                            laser(x, y, 4, pomx, pomy, wymiar, tab, liczba_strzalu, ukryte);
                        }
                        if (y == 0)
                        {
                            laser(x, y, 2, pomx, pomy, wymiar, tab, liczba_strzalu, ukryte);
                        }
                        if (y == wymiar + 1)
                        {
                            laser(x, y, 8, pomx, pomy, wymiar, tab, liczba_strzalu, ukryte);
                        }
                        liczba_strzalu += 1;
                    }
                }
                else
                {
                    cout << "Laser w tym miejscu zostal wystrzelony, lub do niego dotarl!!!" << endl << endl;
                }
            }

            else if (znak == 'h' || znak == 'H')
            {
                cout << "Liczba atomow: " << atomy << endl;
                cout << "Liczba zaznaczonych atomow: " << zaznaczone << endl << endl;

                for (int i = 0; i <= wymiar + 1; i++)
                {
                    for (int j = 0; j <= wymiar + 1; j++)
                    {
                        if (y == i && x == j)
                        {
                            cout << kursor;
                        }
                        else
                        {
                            if (ukryte[i][j] == 1)
                            {
                                cout << 'O';
                            }
                            else
                            {
                                cout << tab[i][j];
                            }
                        }
                    }
                    cout << endl;
                }
                continue;
            }
            else if (znak == 'o' || znak == 'O')
            {
                if (!(x == 0 || x == wymiar + 1 || y == 0 || y == wymiar + 1))
                {
                    if (zaznaczone < atomy || (tab[y][x] == 'o'))
                    {
                        if (tab[y][x] == 'o')
                        {
                            tab[y][x] = 32;
                            zaznaczone -= 1;
                        }
                        else
                        {
                            tab[y][x] = 'o';
                            zaznaczone += 1;
                        }
                    }
                    else
                    {
                        cout << "Zaznaczono maksymalna ilosc atomow!!!" << endl << endl;
                    }
                }
                else
                {
                    cout << "Nie mozesz tu zaznaczyc atomu!!!" << endl << endl;
                }

            }
            else if (znak == 'k' || znak == 'K')
            {
                if (zaznaczone == atomy)
                {
                    cout << "Liczba atomow: " << atomy << endl;
                    cout << "Liczba zaznaczonych atomow: " << zaznaczone << endl << endl;

                    for (int i = 0; i <= wymiar + 1; i++)
                    {
                        for (int j = 0; j <= wymiar + 1; j++)
                        {
                            if (y == i && x == j)
                            {
                                cout << kursor;
                            }
                            else
                            {
                                if (ukryte[i][j] == 1)
                                {
                                    if (tab[i][j] == 'o')
                                    {
                                        cout << 'O';
                                        trafione += 1;
                                    }
                                    else
                                    {
                                        cout << '0';
                                    }
                                }
                                else
                                {
                                    if (tab[i][j] == 'o')
                                    {
                                        cout << 'X';
                                    }
                                    else
                                    {
                                        cout << tab[i][j];
                                    }
                                }
                            }
                        }
                        cout << endl;
                    }

                    cout << "Zakonczyles rozgrywke w " << ile_ruchow << " ruchach! Trafiles " << trafione << " pkt.na " << atomy << "!!!" << endl << endl;
                    cout << "Wpisz y, aby wrocic do menu glownego." << endl;
                    while (cin >> znak)
                    {
                        if (znak == 'y' || znak == 'Y')
                        {
                            koniec = 1;
                            menu(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);
                            break;
                        }
                        else
                        {
                            cout << "Wpisano niepoprawny znak!!! Sproboj ponownie." << endl;
                        }
                    }
                }
                else
                {
                    cout << "Nie wszystkie atomy zostaly zaznaczone!!!" << endl << "Zaznacz wszystkie i sproboj ponownie" << endl;
                }
            }
            else if (znak == 'p' || znak == 'P')
            {
                cout << "Liczba atomow: " << atomy << endl;
                cout << "Liczba zaznaczonych atomow: " << zaznaczone << endl << endl;

                for (int i = 0; i <= wymiar + 1; i++)
                {
                    for (int j = 0; j <= wymiar + 1; j++)
                    {
                        if (y == i && x == j)
                        {
                            cout << kursor;
                        }
                        else
                        {
                            if (ukryte[i][j] == 1)
                            {
                                if (tab[i][j] == 'o')
                                {
                                    cout << 'O';
                                    trafione += 1;
                                }
                                else
                                {
                                    cout << '0';
                                }
                            }
                            else
                            {
                                if (tab[i][j] == 'o')
                                {
                                    cout << 'X';
                                }
                                else
                                {
                                    cout << tab[i][j];
                                }
                            }
                        }
                    }
                    cout << endl;
                }

                cout << "Przerwales rozgrywke! Trafiles " << trafione << " pkt. na " << atomy << "!!!" << endl << endl;
                cout << "Wpisz y, aby wrocic do menu glownego." << endl;
                while (cin >> znak)
                {
                    if (znak == 'y' || znak == 'Y')
                    {
                        koniec = 1;
                        menu(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);
                        break;
                    }
                    else
                    {
                        cout << "Wpisano niepoprawny znak!!! Sproboj ponownie." << endl;
                    }
                }
            }
            else
            {
                cout << "Podany znak jest nieprawidlowy, lub wpisales wiecej niz raz pojedyczny znak!" << endl;
                cout << "Jesli wpisales wiecej niz jeden znak, wcisnij przycisk enter!" << endl << endl;
            }

            if (koniec == 0)
            {
                wypisywanie_planszy(atomy, zaznaczone, wymiar, kursor, x, y, zapis, tab, his, czy_historia, liczba_strzalu);
            }
        }
        else
        {
            cout << "Przekroczono ponad 200 RUCHOW!!!" << endl;
            cout << "Zostaniesz przekierowany do menu! Wpisz znak y i zatwierdz enterem:" << endl;
            while (cin >> znak)
            {
                if (znak == 'y' || znak == 'Y')
                {
                    clear_cls();
                    menu(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);
                }
                else
                {
                    cout << "Podaj poprawny znak!!!" << endl;
                }
            }
            break;
        }
    }
}

void gra(char tab[50][50], int ukryte[50][50], int& liczba_strzalu, int& zapis, int czy_historia[210], historia his[210])
{
    int t = 0;
    zapis = 0;

    for (int i = 0; i < 210; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            for (int k = 0; k < 50; k++)
            {
                his[i].tab_h[j][k] = 0;
            }
        }
        his[i].zaznaczone_h = 0;
        his[i].x_h = 0;
        his[i].y_h = 0;
        czy_historia[i] = 0;
        his[i].liczba_strzalu_h = 0;
    }

    clear_cls();

    black_box();
    cout << endl << endl;
    cout << "#####################################" << endl << endl;
    cout << "Wybierz wielkosc planszy:" << endl;
    cout << "1. 5x5 (3 atomy) - latwe" << endl;
    cout << "2. 8x8 (5 atomow) - srednie" << endl;
    cout << "3. 10x10 (8 atomow) - trudne" << endl;
    cout << "4. Wroc do menu!" << endl;

    while (cin >> t)
    {
        if (t >= 1 && t <= 4)
        {
            clear_cls();
            if (t == 1)
            {
                plansza(5, 3, ukryte, liczba_strzalu, tab, zapis, czy_historia, his);
            }
            if (t == 2)
            {
                plansza(8, 5, ukryte, liczba_strzalu, tab, zapis, czy_historia, his);
            }
            if (t == 3)
            {
                plansza(10, 8, ukryte, liczba_strzalu, tab, zapis, czy_historia, his);
            }
            if (t == 4)
            {
                menu(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);
            }
            break;
        }
        else
        {
            cout << "Podana cyfra jest nieprawidlowa! Sproboj ponownie." << endl;
        }
    }

}

void menu_u(int rozmiar, int atomy, int ukryte[50][50], int& liczba_strzalu, char tab[50][50], int zapis, int czy_historia[210], historia his[210])
{
    clear_cls();
    char option;
    black_box();
    cout << endl << endl;
    cout << "#####################################" << endl << endl;
    cout << "Wybierz opcje:" << endl;
    cout << "1. Graj dalej!" << endl;
    cout << "2. Rozpocznij etap od nowa" << endl;
    cout << "3. Wyjdz do menu" << endl;

    while (cin >> option)
    {
        if (option == '1')
        {
            clear_cls();
            black_box();
            cout << endl << endl;
            cout << "#####################################" << endl << endl;
            break;
        }
        else if (option == '2')
        {
            clear_cls();
            plansza(rozmiar, atomy, ukryte, liczba_strzalu, tab, zapis, czy_historia, his);
            break;
        }
        else if (option == '3')
        {
            menu(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);
            break;
        }
        else
        {
            cout << "Podany numer jest niepoprawny!" << endl;
        }
    }
}

void menu(char tab[50][50], int ukryte[50][50], int& liczba_strzalu, int& zapis, int czy_historia[210], historia his[210])
{
    clear_cls();
    int option;
    black_box();
    cout << endl << endl;
    cout << "#####################################" << endl << endl;
    cout << "Black Box - Hubert Kowalski" << endl << endl;
    cout << "Wybierz opcje:" << endl;
    cout << "1. Graj!" << endl;
    cout << "2. Instrukcja" << endl;
    cout << "3. O autorze" << endl;
    cout << "4. Wyjscie" << endl;
    cout << endl << "#####################################" << endl;

    while (cin >> option)
    {
        if (option >= 1 && option <= 4)
        {
            clear_cls();
            if (option == 1)
            {
                gra(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);
            }
            if (option == 2)
            {
                instrukcja(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);
            }
            if (option == 3)
            {
                o_autorze(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);
            }
            if (option == 4)
            {
                exit(0);
            }
            break;
        }
        else
        {
            cout << "Wybrany numer jest nieprawidlowy!!! Sproboj ponownie:" << endl;
        }
    }
}

int main()
{
    char tab[50][50] = {};
    int ukryte[50][50] = {};
    int liczba_strzalu = 0, zapis = 0;
    int czy_historia[210] = {};
    historia his[210] = {};

    srand(time(NULL));

    powitanie();
    menu(tab, ukryte, liczba_strzalu, zapis, czy_historia, his);

    return 0;
}
