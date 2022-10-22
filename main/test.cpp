#include "CImg.h"
#include <iostream>
#include <fstream>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cimg_library;
int main(int argc, char *argv[])
{

    if(argc != 2){
	cout<<"usage: "<<argv[0]<<" img1 img2 "<<endl;
	return 1;
    }
    CImg<float> src1;
    src1.load_tiff(argv[1]);
    src1.crop(1000,1000,0,0,3700,3700,0,0,3);
    const unsigned char color[] = { 255,0,0 };
    src1.draw_point(3,1,color);
    cout<<src1.size()<<endl;

    src1.display();
    int w1 = src1.width();
    int h1 = src1.height();
    cout<<src1.atXY(3,1,0,0)<<endl;
    
   
    /*
     ofstream file;
    file.open("./archivo.txt");
    for(int i=0; i<h1; i++){
        for(int j=0; j<w1 ; j++){
            if(src1.atXY(j,i,0,0)!=0){
                file<<float(j)<<" "<<float(i)<<" "<<src1.atXY(j,i,0,0)<<endl;
            }
            

        }
    }
    file.close();
    
    
    */
    
    
    
   
    
   
    
    
    return 0;
}