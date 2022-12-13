#include <opencv2/opencv.hpp>
#define CVUI_IMPLEMENTATION
#include "cvui.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define WINDOW1_NAME "DBScan Settings"
#define WINDOW2_NAME "Clustering of Galaxies"
using namespace std;

int main() {
  static int width=400;
  static int height=600;
  static int width2=1400;
  static int height2=900;
  static int foto=2701;
  double valueEpsilon = 9.9;
  int valueMinPts = 12;
  bool img1 = true;
  bool img2 = false;
  bool img3 = false;
  bool img4 = false;
  bool img5 = false;
  bool img6 = false;
  bool img7 = false;
  bool img8 = false;
  


  cvui::init(WINDOW1_NAME);
  cv::Mat frame = cv::Mat(cv::Size(width, height), CV_8UC3);
  string filename;
  

  while(true) {
    frame = cv::Scalar(49, 52, 49);
    // cv::Mat frame, x, y, width, height, label
    cvui::checkbox(frame, width*0.25, height*0.15, "Image 1", &img1);
    cvui::checkbox(frame, width*0.25, height*0.20, "Image 2", &img2);
    cvui::checkbox(frame, width*0.25, height*0.25, "Image 3", &img3);
    cvui::checkbox(frame, width*0.25, height*0.30, "Image 4", &img4);
    cvui::checkbox(frame, width*0.55, height*0.15, "Image 5", &img5);
    cvui::checkbox(frame, width*0.55, height*0.20, "Image 6", &img6);
    cvui::checkbox(frame, width*0.55, height*0.25, "Image 7", &img7);
    cvui::checkbox(frame, width*0.55, height*0.30, "Image 8", &img8);

    if(img1==true){
        img2 = false;
        img3 = false;
        img4 = false;
        img5 = false;
        img6 = false;
        img7 = false;
        img8 = false;
        filename="./Data/1.tiff";
    }
    if(img2==true){
        img1 = false;
        img3 = false;
        img4 = false;
        img5 = false;
        img6 = false;
        img7 = false;
        img8 = false;
        filename="./Data/2.tiff";
    }
    if(img3==true){
        img1 = false;
        img2 = false;
        img4 = false;
        img5 = false;
        img6 = false;
        img7 = false;
        img8 = false;
        filename="./Data/3.tiff";
    }
    if(img4==true){
        img1 = false;
        img2 = false;
        img3 = false;
        img5 = false;
        img6 = false;
        img7 = false;
        img8 = false;
        filename="./Data/4.tiff";
    }
    if(img5==true){
        img1 = false;
        img2 = false;
        img3 = false;
        img4 = false;
        img6 = false;
        img7 = false;
        img8 = false;
        filename="./Data/5.tiff";
    }
    if(img6==true){
        img1 = false;
        img2 = false;
        img3 = false;
        img4 = false;
        img5 = false;
        img7 = false;
        img8 = false;
        filename="./Data/6.tiff";
    }
    if(img7==true){
        img1 = false;
        img2 = false;
        img3 = false;
        img4 = false;
        img5 = false;
        img6 = false;
        img8 = false;
        filename="./Data/7.tiff";
    }
    if(img8==true){
        img1 = false;
        img2 = false;
        img3 = false;
        img4 = false;
        img5 = false;
        img6 = false;
        img7 = false;
        filename="./Data/8.tiff";
    }
    stringstream comando;
    comando << "sh script.sh " << filename << " "<< valueEpsilon << " " << valueMinPts;
    
    //texto y trackbar del epsilon
    cvui::text(frame, width*0.1, height*0.50, "Epsilon",0.7);
    cvui::trackbar(frame, width*0.35, height*0.5, width*0.55, &valueEpsilon, (double)0.0, (double)15.0);

    // texto y trackbar del minpts
    cvui::text(frame, width*0.1, height*0.65, "MinPts",0.7);
    cvui::trackbar(frame, width*0.35, height*0.65, width*0.55, &valueMinPts, (int)10, (int)50);
    // Show window content

    if (cvui::button(frame, width*0.35, height*0.85,width*0.30,height*0.10, "Start")) {
        system(comando.str().c_str());
        break;
    }
    cvui::imshow(WINDOW1_NAME, frame);

    if (cv::waitKey(20) == 27 || cv::getWindowProperty(WINDOW1_NAME, 0) < 0) {
      break;
    }
  } 
  cv::destroyAllWindows();

/////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Siguiente ventana ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

    double factor;
    cvui::init(WINDOW2_NAME);
    cv::Mat frame2 = cv::Mat(cv::Size(width2, height2), CV_8UC3);
    cv::Mat imgInput;
    cv::Mat imgOutput;
    cv::Mat imgInput_res;
    cv::Mat imgOutput_res;
    vector<string> coutData;
    string TotalPoints;
    string CorePoints;
    string BorderPoints;
    string NoisePoints;
    string TotalClusteredPoints;
    string NumClusters;

    imgInput = cv::imread("result_000000.tiff",cv::IMREAD_COLOR );
    imgOutput = cv::imread("result_000001.tiff",cv::IMREAD_COLOR );
    cv::resize(imgInput, imgInput_res, cv::Size(), 0.167, 0.167,cv::INTER_LINEAR );
    cv::resize(imgOutput, imgOutput_res, cv::Size(), 0.305, 0.305, cv::INTER_LINEAR );
    
    ifstream ifile;
    ifile.open("cout.txt",ios_base::in);
    int cont =1;
    for(string line; getline(ifile, line); ){
        
        if(cont>38){
            coutData.push_back(line);
        }        
        cont++;
    }
    while(true) {
        frame2 = cv::Scalar(49, 52, 49);
        cvui::window(frame2, width2*0.03, height2*0.02, width2*0.24, height2*0.40, "Details");
        cvui::window(frame2, width2*0.03, height2*0.43, width2*0.337 , height2*0.54, "Input");
        cvui::window(frame2, width2*0.38, height2*0.02, width2*0.6, height2*0.95, "Output");
        cvui::image(frame2, width2*0.038, height2*0.46,imgInput_res);
        cvui::image(frame2, width2*0.386, height2*0.0502,imgOutput_res);
        cvui::text(frame2, width2*0.05, height2*0.08, "Width: 2701 px");
        cvui::text(frame2, width2*0.05, height2*0.12, "Height: 2701 px");
        cvui::text(frame2, width2*0.05, height2*0.16, coutData.at(0));
        cvui::text(frame2, width2*0.05, height2*0.20, coutData.at(1));
        cvui::text(frame2, width2*0.05, height2*0.24, coutData.at(2));
        cvui::text(frame2, width2*0.05, height2*0.28, coutData.at(3));
        cvui::text(frame2, width2*0.05, height2*0.32, coutData.at(4));
        cvui::text(frame2, width2*0.05, height2*0.36, coutData.at(5));

        // Show window content
        cvui::imshow(WINDOW2_NAME, frame2);

    if (cv::waitKey(20) == 27 || cv::getWindowProperty(WINDOW2_NAME, 0) < 0) {
        break;
    }
  }
  system("rm cout.txt");
  return 0;
}
