#include <stdio.h>
#include <stdlib.h>
#include "../Toy/canvas.h"

int main(int argc, char *argv[])
{
    Canvas canvas(700, 400, "Bifurcation");
    canvas.SetDomain(50, 20, 680, 350);
    canvas.SetXRange(2.8, 4.);
    canvas.SetYRange(0., 1.);
    canvas.DrawGrids(6, 4, 3);
    canvas.DrawXLabel("%4.2f", 6, 10);
    canvas.DrawYLabel("%4.2f", 4, 5);
    canvas.SetForeground(RedColor);
    LOOP_WIDTH_INT(canvas.Domain(), i) {
	double g = canvas.WinToViewX(i);
	double x = .5;
	for (int j = 0;  j < 1000;  j++) x = g*x*(1.-x);
	for (int j = 0;  j < 1000;  j++) {
	    x = g*x*(1.-x);
	    canvas.DrawDot(i, canvas.V2WY(x));
	}
	canvas.Flush();
    }
    canvas.Flush();
    getchar();
}
