#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

int main()
{

    double pi = 3.14159;
    float delta_t = 0.1;  // odstep miedzy kolejnymi probkami

    // ======== [ DYSKRETYZACJA ] =========

    double x = 0;  // aktualna wartosc probki
    int iter = 0;  // numer kroku

    vector <long double> y;

    while (x <= (2 * pi))
    {
        y.push_back(sin(x));

        //cout << "wartosc sin dla x = " << x << " to: " << y[iter] << endl;

        x += delta_t;
        iter++;
    }

    // ======== [ POCHODNA ] =========

    vector <double> pochodna;

    x = 0;
    iter = 0;

    while (x <= 2 * pi)
    {

        pochodna.push_back((sin(x + delta_t) - sin(x)) / delta_t);

        //cout << "pochodna w punkcie " << x << " wynosi: " << pochodna[iter] << endl;

        x += delta_t;
        iter++;

    }

    // ======== [ CALKA ] =========

    delta_t = 0.000001;
    x = 0;

    // METODA PROSTOKATOW

    double calka = 0;

    while (x <= pi)
    {

        calka += delta_t * x;

        x += delta_t;

    }

    cout << "[metoda prostokatow] wartosc calki: " << calka << endl;

    // METODA TRAPEZOW

    calka = 0;
    x = 0;

    while (x <= pi)
    {

        calka += 0.5 * (x + (x + delta_t)) * delta_t; // 1/2 * (a+b) * h

        x += delta_t;

    }

    cout << "[metoda trapezow] wartosc calki: " << calka << endl;

    // ================= [ LAB 4 ] ================= //

    float liczba;
    double pierwiastek;

    cout << "Podaj liczbe do pierwiastkowania: ";

    cin >> liczba;

    if (liczba >= 1)
    {

        // MATH

        pierwiastek = sqrt(liczba);

        cout << "[MATH] Pierwiastek liczby " << liczba << " jest rowny: " << pierwiastek << endl;

        // ZGADYWANIE

        long double eps = 0.00000000000000001;

        long double granica_l = 0;
        long double granica_p = liczba;

        long double srodek = liczba / 2;

        long double obliczona_liczba = srodek * srodek;

        while (abs(obliczona_liczba - liczba) > eps)
        {
            if (obliczona_liczba > liczba)
            {
                granica_p = srodek;
            }
            else if (obliczona_liczba < liczba)
            {
                granica_l = srodek;
            }
            srodek = granica_l + ((granica_p - granica_l) / 2);
            obliczona_liczba = srodek * srodek;

            cout << srodek << endl;

        }

        cout << "[ZGADYWANIE] Pierwiastek liczby " << liczba << " jest rowny: " << srodek << endl;

        // METODA NEWTONA

        double a = 1;
        double b = liczba;

        while (abs(a - b) >= eps)
        {

            a = (a + b) / 2.;
            b = liczba / a;

        }

        cout << "[NEWTON] Pierwiastek liczby " << liczba << " jest rowny: " << a << endl;

    }

    else
    {
        cout << "Liczba musi byc wieksza niz 1!" << endl;
    }

    return 0;

}