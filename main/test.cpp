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
    CImg<float> src1;
    src1.load_tiff(argv[1]);
    src1.crop(1000,1000,0,0,3700,3700,0,0,3);

    float idAux = 2;
   
    //src1.display();


    

    
    int w1 = src1.width();
    int h1 = src1.height();
    ifstream file1;
    vector<pair<float,float>> v; 

    map<float,vector<pair<float,float>>> mapa;

    file1.open("./final1_1.txt",ios_base::in);
    for(string line1; getline(file1,line1); ){
        istringstream in(line1);
        float id,x,y;
        in>>x>>y>>id;
        
        //cout<<color[0]<<","<<color[1]<<","<<color[2]<<endl;
        //mapa.insert({id,{x,y}});

    }
    file1.close();

     CImg<float> tar(w1,h1,1,3,0);
    
    
      
        file1.open("./final1_1.txt", ios_base::in);
        for(string line1; getline(file1, line1); ){
            istringstream in(line1); 
            float x,y,id;
            in>>x>>y>>id;
            unsigned char color[3];
            color[0]= int(id) % 256;
            color[1]= int(id*2) % 256;
            color[2]= int(id*3) % 256;
            tar.draw_point(x,y,color);
        }
        file1.close();
        (src1,tar).save("r1_1.tiff");

    
    
    
   
    
    
        
    
    /*
    ofstream file;
    file.open("./archivo.txt");
    for(int i=0; i<h1; i++){
        for(int j=0; j<w1 ; j++){
            if(src1.atXY(j,i,0,0)>0){
                file<<float(j)<<" "<<float(i)<<" "<<src1.atXY(j,i,0,0)<<endl;
            }
            

        }
    }
    file.close();
    
    */
    
    
    
   
    
        

    
    return 0;
}