#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;
int main(int argc, char *argv[])
{


    ifstream file1,file2;
    file1.open("./main/test.txt", ios_base::in);
    file2.open("./main/archivo.txt",ios_base:: in);
    ofstream fileOut;
    fileOut.open("./final.txt");

    string linea,linea2;
    int contador = 0;
    int lenght1 =0;
    int lenght2=0;
    

  

    for(string line1; getline(file1, line1); ){
        istringstream in(line1); 
        float numFila;
        in>>numFila;
        for(string line2; getline(file2, line2);){
            contador++;
            if(numFila==contador){
                istringstream in2(line2);
                float x,y;
                in2>> x >> y ;
                fileOut<<x<<" "<<y<<endl;
                break;
            }
        }

    }

    
    file1.close();
    file2.close();
    fileOut.close();
    return EXIT_SUCCESS;
}