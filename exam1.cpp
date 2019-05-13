#include <stdio.h>
#include <stdlib.h>
#include "../Toy/canvas.h"

int main(int argc, char *argv[])
{
    Canvas canvas(200, 200, "Hello World!");
    canvas.SetForeground(BlueColor);
    canvas.DrawLine(10, 10, 90, 50);
    canvas.SetForeground(GreenColor);
    canvas.DrawRectangle(30, 30, 70, 90);
    canvas.SetForeground(RedColor);
    canvas.DrawEllipse(50, 50, 40, 40);
    canvas.SetForeground(YelloColor);
    canvas.DrawString(100, 100, "Hello World!");
    canvas.Flush();
    canvas.Flush();
    getchar();
}
