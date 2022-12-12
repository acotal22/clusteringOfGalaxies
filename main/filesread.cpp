#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;
int main(int argc, char *argv[])
{


    ifstream file1,file2;
    file1.open("./clusters8.txt", ios_base::in);
    file2.open("./archivo8.txt",ios_base:: in);

    if (!file1){
        cout<<"error al abrir archivo 1"<<endl;


    }
    if(!file2){
                cout<<"error al abrir archivo 2"<<endl;


    }
    ofstream fileOut;
    fileOut.open("./final8_8.txt");

    string linea,linea2;
    int contador = 0;
    int lenght1 =0;
    int lenght2=0;
    

  

    for(string line1; getline(file1, line1); ){
        istringstream in(line1); 
        float numFila,id;
        in>>numFila>>id;
        for(string line2; getline(file2, line2);){
            contador++;
            if(numFila==contador){
                istringstream in2(line2);
                float x,y;
                in2>> x >> y ;
                fileOut<<x<<" "<<y<<" "<<id<<endl;
                break;
            }
            
        }

    }

    
    file1.close();
    file2.close();
    fileOut.close();
    return EXIT_SUCCESS;
}