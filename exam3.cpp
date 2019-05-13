#include <stdio.h>
#include <stdlib.h>
#include "../Toy/canvas.h"

int main(int, char**)
{
    Vector series("lorenz.dat");
    Canvas canvas(500, 400, "Lorenz");
    canvas.SetDomain(50, 20, 480, 340);
    canvas.SetRange(series, 100);
    canvas.DrawGrids(4, 4, 3);
    canvas.DrawXLabel("%3.f", 4, 7);
    canvas.DrawYLabel("%4.1f", 4, 5);
    canvas.DrawString(CENTER, 375, "lorenz.dat");
    canvas.DrawXLine(0.);
    canvas.SetForeground(RedColor);
    canvas.DrawYLines(series);
    canvas.Flush();
    canvas.Flush();
    getchar();
}
