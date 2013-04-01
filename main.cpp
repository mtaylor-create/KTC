#include "mbed.h"
#include "SDFileSystem.h"
#include "string"
#include "Thermal.h"
using namespace std;

SDFileSystem sd(p5, p6, p7, p8, "sd"); // the pinout on the mbed Cool Components workshop board

char c[50];                          // a single byte buffer

unsigned int size;

Thermal printer(p13, p14, 19200);
DigitalIn pb(p20);

int main()
{
    printf("Hello World!\n");

    char snippet [50];

    FILE *fp;

    pb.mode(PullUp);

    int f;
    
    //printer.doubleHeightOn();
    //for (int f=1; f<3; f++) {
    while(1) {
        f = rand() % 166 + 1;
        if (!pb) {
            wait(.05);
            if (!pb) {

                sprintf(snippet, "/sd/%d.txt",f);

                //printf(snippet);

                while ((fp = fopen(snippet, "r")) == NULL) {
                    //printf("Could not open file for read\n");
                    f = rand() % 166 + 1;
                    sprintf(snippet, "/sd/%d.txt",f);
                }
//                } else {

                while (fgets(c, 50, fp) != NULL) {
                    printf("%s", c);
                    printer.printf("%s", c);

                }
                printer.printf("\n");

                for (int lspace = 1; lspace<5; lspace++) {
                    printer.printf("\n");
                }
                wait(5);
//                }

            }
        }

//       f++;
//       if (f>166) {
//           f=1;
//       }
    }



}


//int printfile()
//{

//}