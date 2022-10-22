// para instalar cimg
// sudo apt install cimg o sudo pacman -S cimg (depende de tu linux)
// para compilar 
//g++ -o ejemplo ejemplo.cpp -lX11
#include "CImg.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;
using namespace cimg_library;

int main(int argc, char *argv[])
{

    if(argc != 3){
	cout<<"usage: "<<argv[0]<<" img1 img2 "<<endl;
	return 1;
    }
    CImg<float> src1, src2, src3;
    src1.load_tiff(argv[1]);
    src3.load_tiff(argv[1]);
    src1.crop(1000,1000,0,0,3700,3700,0,0,3);
    cout<<src1.size()<<endl;
    (src1,src3).display();
    int w1 = src1.width();
    int h1 = src1.height();
    src2.load_tiff(argv[2]);
    int w2 = src2.width();
    int h2 = src2.height();
    cerr<<" w1 "<<w1<<" h1 "<<h1<<endl;
    cerr<<" w2 "<<w2<<" h2 "<<h2<<endl;
    unsigned long size1 = src1.size();
    unsigned long size2 = src2.size();
    
    float *h_src1 = src1.data();
    float *h_src2 = src2.data();
    float *h_src3 = src1.data();
    map<float, int> mm;
    map<float, int>::iterator it;
    for(int i=0; i<w1*h2; i++){
	//h_src3[i] = h_src1[i] > h_src2[i] ? h_src1[i] - h_src2[i]: h_src2[i]-h_src1[i];
	h_src3[i] = h_src1[i] > h_src2[i] ? h_src1[i] - h_src2[i]: 0;
	//h_src3[i] = h_src1[i] > h_src2[i] ? 0 : h_src2[i] - h_src1[i];
	mm[h_src3[i]]++;
    }

    cerr<<" mm size "<<mm.size()<<endl;
    for(it=mm.begin(); it!=mm.end(); it++)
	cerr<<it->first<<" "<<it->second<<endl;
    src3.assign(h_src3,w1,h1,1,1,false);
    src3.display();


    return 0;
}
