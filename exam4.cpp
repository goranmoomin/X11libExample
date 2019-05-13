#include <stdio.h>
#include <stdlib.h>
#include "../Toy/canvas.h"

int main(int, char**)
{
    Vector series("lorenz.dat");
    Canvas canvas(450, 450, "Recostruct map");
    canvas.SetDomain(25, 25, 400, 400);
    canvas.SetForeground(BlueColor);
    float min = series.GetMin();
    float max = series.GetMax();
    canvas.SetRange3D(min, max, min, max, min, max);
    //canvas.DrawGrid3D(10, 10, 10, 5);
    canvas.SetForeground(RedColor);
    int tau = 5, dim = 3;
    for (int i = dim*tau-1;  i < series.Size();  i++)
	canvas.DrawDot3D(series[i-tau*2], series[i-tau], series[i]);
    canvas.Flush();
    canvas.Flush();
    getchar();
}
