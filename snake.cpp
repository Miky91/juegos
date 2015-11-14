#include "miniwin.h"
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace miniwin;

const int i = 600;
const int j = 600;

int main() {

    vredimensiona(600,600);
    //linea(0,0,200,200);

    float x, y, rx, ry;
    x = 250;
    y = 300;
    rectangulo(x-15, y - 15, x +15, y +15);
    color(ROJO);
    refresca();
    int t = tecla();
    while(t != ESCAPE){
        if(raton(rx,ry)){
            if(fabs(rx - x) - 15 && fabs(ry - y) < 15 ){
                if ((x +15 <i) && (y+15 < j)){
                    x+= rand() %15;
                    y+= rand() %15;
                }
                else if(x+15 <i){
                    x+= rand() %15;
                }
                else if (y+15 <j){
                    y+=rand() %15;
                }
                else{
                    x=rand() %200;
                    y=rand() %250;
                }

                borra();
                rectangulo(x-15, y - 15, x +15, y +15);
                color(ROJO);
                refresca();
            }
        }
        t = tecla();
    }
    vcierra();
    return 0;
}
