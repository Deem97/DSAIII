#include <iostream>
#include <fstream>
#include <string>
#include <map>

#define CHARS 256
using namespace std;

void readQuery(string);
void readDatab(string);
void badChar(string,int,int[]);
void search(string,string,string);

ofstream file;

map<string, string> query;
map<string, string> data;

int main(){
    string fName,pName,txt,ptn;
    cout<<"Enter the Database File Name: ";
    getline(cin, fName);

    cout<<"Enter the Query File Name: ";
    getline(cin, pName);

    readQuery(pName);
    readDatab(fName);
    
    map<string, string>::iterator itr,itr2;  //itr for query and itr2 for database

    for(itr=query.begin();itr!=query.end();++itr){
        file.open("output.txt",fstream::app);
        file<<itr->first<<endl;
        file.close();
        for(itr2=data.begin();itr2!=data.end();++itr2){
            search(itr2->second,itr->second,itr2->first);
        }
    }
}

void badChar(string str,int size,int badchar[CHARS]){
    int i;  
  
    for (i = 0; i < CHARS; i++)  
        badchar[i] = -1;  

    for (i = 0; i < size; i++)  
        badchar[(int) str[i]] = i;  
}

void search(string txt, string pat, string des1){

    int m = pat.length();  
    int n = txt.length();  
    
    int badchar[CHARS]; 
    
    badChar(pat, m, badchar);  

    int s = 0,flag; 
    while(s <= (n - m))  {  
        int j = m - 1; 
        while(j >= 0 && pat[j] == txt[s + j])  
            j--;  

        if (j < 0)  {  
            flag=1;
            file.open("output.txt",fstream::app);
            file <<"["<<des1<<"] at offset "<<s<<endl;
            file.close();
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;  
        }else
            s += max(1, j - badchar[txt[s + j]]);
    }  

    if(flag!=1){
        file.open("output.txt",fstream::app);
        file <<"N"<<endl;
        file.close();
    }

}

void readQuery(string name){

    string pStr,des1,pat="";

    fstream que(name.c_str());
    while(getline(que,pStr)){
        if(pStr[0]=='>'){
            
            if(pat!=""){
                query[des1] = pat;
                pat="";
            }
            des1 = pStr;
            continue;
        }else{
            pat = pat + pStr;
        }
    }
}

void readDatab(string name){

    string tStr,des2,txt="";

    fstream dat(name.c_str());
    while(getline(dat,tStr)){
        if(tStr[0]=='>'){
            
            if(txt!=""){
                data[des2] = txt;
                txt="";
            }
            des2 = tStr;
            continue;
        }else{
            txt = txt + tStr;
        }
    }
}
