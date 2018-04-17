#include <iostream>
#include <fstream>  
#include <stdlib.h>

using namespace std;


const int N=16354;
float cota(float z);
int k=0,i=0, c=0, m=0,M=0;


 main()
{
	
	float x,y,z,Pitch,Row,Yall, max=0, min=1000, soma=0;
	double Amptot, ampC, alt, FR;
	float freq[10][4]={0};
    int a, R,G,B;
	
	char nome[]="c:\\temp\\sparse.txt"; 
	char nomeF[]="c:\\temp\\sparseCotas.txt"; 
	char nomeR[]="c:\\temp\\sparsefrequencia.txt"; 
	
	ifstream ler; 
	ofstream gerar;
	
	ler.open(nome,ios::in);
	gerar.open(nomeF,ios::out);
	        
	while  (!ler.eof()) {
		ler>>x>>y>>z>>R>>G>>B>>Pitch>>Row>>Yall;
		gerar<<z<<endl;
          	
		if (z>max)
      max=z;
      
    if (z<min)
    	min=z;
     					   	    			
   	}
   	

	ler.close();
  gerar.close();
 
 	Amptot=(max-min);
 	ampC=Amptot/10;
	
	for(c=0;c<=9;c++){
	freq[c][0]= min + c*ampC;
	freq[c][1]= min + (c+1)*ampC;

	} 
		
	ler.open(nomeF,ios::in);
	gerar.open(nomeR,ios::out);
		
   	gerar<<"Classes"<<"         "<<"Min"<<"          "<<"Max"<<"        "<<"Pixels"<<"        "<<"FR(%)"<<endl;

   	for(i=0;i<N;i++){
   		ler>>z;
   			
		a = (z-min)/ampC;
		freq[a][2]++;
	}
						
	for(c=0;c<=9;c++)
					{
					 freq[c][3]=(freq[c][2]/N)*100;
				    
					  gerar<<"Classe "<<c+1<<":     "<<freq[c][0]<<"  |--  "<<freq[c][1]<<"       "<<freq[c][2]<<"       "<<freq[c][3]<<endl;	
				    }
	gerar<<"Maior cota: "<<max<<endl;
    gerar<<"Menor cota: "<<min<<endl;
    
	cout<<endl;
	cout<<" O novo Arquivo foi salvo com sucesso! "<<endl;
	
	ler.close();
	gerar.close();
}

