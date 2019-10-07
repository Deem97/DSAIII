
#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
	
	string text,wildCard,fName,pName;
	ofstream file;
	cout<<"Enter text fil name : ";                      
	getline(cin,fName);

	cout<<"Enter pattern file name : ";
	getline(cin,pName);
	
	fstream txt(fName.c_str());
    fstream patt(pName.c_str());
    
    file.open("output.txt", fstream::app);
    
   if (!txt || !patt){

        cout << "File not Open\n";
        return 1;

    }else{
    	getline(txt, text, '\0');
        getline(patt, wildCard, '\0');
        
        
        int Tleng=text.length();
	int Pleng=wildCard.length();
	
	
	
	
	
	/* int count=0;
	for(int i=0;i<Pleng;i++){
		if(wildCard[i]=='_')
			count=count+1;
	}*/
	int count1;
	
	int i=0;
	int j;
	while(i<Tleng-Pleng+1){
		j=0;
		while(j<Pleng){
			if((text[i+j]==wildCard[j])||(wildCard[j]=='_')){
				j=j+1;
			}else{
				break;
			}
			
			
		}
		if(j==Pleng){
				
				file<<"Pattern found at index: "<<i<<endl;
		}
				
		
		i=i+1;
	}
	}
	
	file.close();
	
	
	
} 
	
	
	

