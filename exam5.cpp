#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Toy/NRC/rk4.h"
#include "../Toy/canvas.h"

void derivs(double x, double y[], double dydx[])
{
    double SIGMA = 10.;
    double B = 8./3.;
    double R = 28.;
    dydx[1] = SIGMA*(-y[1]+y[2]);
    dydx[2] = -y[1]*y[3] + R*y[1] - y[2];
    dydx[3] = y[1]*y[2] - B*y[3];
}

int main(int, char **)
{
    Canvas canvas(500, 510, "NRC rk4()");
    canvas.SetDomain(40, 20, 480, 460);
    canvas.SetRange(-30., -30., 30., 30.);
    canvas.DrawGrids(6, 6, 3);
    canvas.DrawXLabel("%3.f", 6, 5);
    canvas.DrawYLabel("%3.f", 6, 5);
    canvas.DrawString(CENTER, 495, "Lorenz Map");

    Vector y(1, 3), dydx(1, 3), yout(1, 3);

    y[1] = 1.;  y[2] = 1.;  y[3] = 20.;

    double h = 0.0025;
    canvas.SetPenColor(RedColor);
    for (double x = 0.;  x <= 30;  x += h) {
	rk4(y(), dydx(), 3, x, h, yout(), derivs);
	canvas.DrawLine(y[1], y[2], yout[1], yout[2]);
	y = yout;
	canvas.Flush();
        canvas.Flush();
    }

    canvas.Flush();
    canvas.Flush();
    getchar();
}
