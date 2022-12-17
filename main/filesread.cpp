#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;
int main(int argc, char *argv[])
{


    ifstream file1,file2;
    file1.open("./clusters.txt", ios_base::in);
    file2.open("./archivo.txt",ios_base:: in);

    if (!file1){
        cout<<"error al abrir archivo 1"<<endl;


    }
    if(!file2){
                cout<<"error al abrir archivo 2"<<endl;


    }
    ofstream fileOut;
    fileOut.open("./final.txt");

    string linea,linea2;
    int contador = 0;
    int lenght1 =0;
    int lenght2=0;
    
    
    // se hace un match entre los datos que entrega el DBScan con la lectura de los pixeles de la imagen
    for(string line1; getline(file1, line1); ){
        istringstream in(line1); 
        float numFila,id;
        in>>numFila>>id;
        for(string line2; getline(file2, line2);){
            if(numFila!=0){              
                contador++;
                if(numFila==contador){
                    istringstream in2(line2);
                    float x,y;
                    in2>> x >> y ;
                    fileOut<<x<<" "<<y<<" "<<id<<endl;
                    break;
                }
            }
            else{
                break;
                }           
        }
    }

    
    file1.close();
    file2.close();
    fileOut.close();
    return EXIT_SUCCESS;
}