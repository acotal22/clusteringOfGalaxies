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
	cout<<"usage: "<<argv[0]<<" img1 img2 "<<endl;
	return 1;
    }
    // se carga la imagen con la biblioteca CImg y se cortan los borden en negro de la imagen original
    CImg<float> src1;                                              
    src1.load_tiff(argv[1]);
    src1.crop(1000,1000,0,0,3700,3700,0,0,3);

    // Alta y Ancho de la imagen cortada
    int w1 = src1.width();
    int h1 = src1.height();
   
    // Se recorre la imagen y se guarda en un archivo txt las coordenadas (x,y) y el brillo del pixel
    ofstream file;
    file.open("./archivo.txt");
    file<<"dim 3"<<endl; 
    for(int i=0; i<h1; i++){
        for(int j=0; j<w1 ; j++){
            if(src1.atXY(j,i,0,0)>0){
                file<<float(j)<<" "<<float(i)<<" "<<src1.atXY(j,i,0,0)<<endl;
            }
            

        }
    }
    file.close();

    return 0;
}