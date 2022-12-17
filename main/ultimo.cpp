#include "CImg.h"
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;
using namespace cimg_library;
int main(int argc, char *argv[])
{

    if(argc != 2){
	cout<<"usage: "<<argv[0]<<" img1  "<<endl;
	return 1;
    }

    // se carga la imagen con la biblioteca CImg y se cortan los borden en negro de la imagen original
    CImg<float> src1;                           
    src1.load_tiff(argv[1]);
    src1.crop(1000,1000,0,0,3700,3700,0,0,3);

    // Alta y Ancho de la imagen cortada
    int w1 = src1.width();
    int h1 = src1.height();
    ifstream file1;
   

     CImg<float> tar(w1,h1,1,3,0);

        file1.open("./final.txt", ios_base::in);        // se lee el archivo que contiene los clusters
        for(string line1; getline(file1, line1); ){
            istringstream in(line1); 
            float x,y,id;
            in>>x>>y>>id;
            // variable de color para pintar los clusters encontrados de distintos colores.
            unsigned char color[3];   
            color[0]= int(id) % 256;
            color[1]= int(id*2) % 256;
            color[2]= int(id*3) % 256;
            tar.draw_point(x,y,color); //Funcion de CImg para dibujar un punto en la coordenada x,y con el color determinado anteriormente
        }
        file1.close();
        (src1,tar).save("result.tiff"); 
    return 0;
}