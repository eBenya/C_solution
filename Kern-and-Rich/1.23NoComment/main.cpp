#include <cstdlib>
#include <iostream>

#define TextMaxSize 1000

void noComm(char s[TextMaxSize], char c);

int main(int argc, char *argv[]){
    char c, line[TextMaxSize];
    int a=0;
    while( (c=getchar())!=EOF ){
           //noComm(line, c);
           if(c!='/') line[a]=c;                              
            else if( ((c=getchar())!='/') && (c != '*') ){
                          line[a]='/';
                          a+=1; 
                          line[a]=c;
                          }                        
                        else if(c=='/'){ 
                                while( (c=getchar())!='\n' );
                                line[a]='\n';
                                }
                               else {
                                    bool ex=true;
                                    while( ex==true ){
                                           if ( (c=getchar())=='*' ) if( (c=getchar())=='/' ) ex=false;                    
                                           }
                                    if (c!='\n') line[a]='\n';
                                    }
           a++;           
           }
    printf("%s \n", line);
    system("PAUSE");
    return EXIT_SUCCESS;
    }
/*
//Не работает...:(

void noComm(char s[], char c){
     int a=0;
     if(c!='/') s[a]=c;                              
            else if( ((c=getchar())!='/') && (c != '*') ){
                          s[a]='/';
                          a+=1; 
                          s[a]=c;
                          }                        
                        else if(c=='/'){ 
                                while( (c=getchar())!='\n' );
                                s[a]='\n';
                                }
                               else {
                                    bool ex=true;
                                    while( ex==true ){
                                           if ( (c=getchar())=='*' ) if( (c=getchar())=='/' ) ex=false;                    
                                           }
                                    if (c!='\n') s[a]='\n';
                                    }
           a++;               
     }*/
