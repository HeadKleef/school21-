#include<stdio.h>
#include<stdlib.h>

int new_line(char c){return (c == '\n');}
int is_empty_line(FILE *file){
            char d;
            int empty;

            empty = 0;

            d = getc(file);
            if (new_line(d)) empty = 1;
            ungetc(d, file);
            return empty;
}
int option(char *filename){
      char opt[2]; 
      opt[1] = filename[1];
    int l = 0;
        if(opt[1] == 'e'){
                l = 1;
        }else if(opt[1] == 'n'){
                l =  2;
         }else if(opt[1] == 'b'){
                 l =  3;
        }else if(opt[1] == 's'){
                 l =  4;
            }
         return l;
        
         }
  
void open(char *filename[]){
   
    int p = option(filename[1]); 
    char *c = (filename[1]);
    FILE* file = fopen(filename[2], "r");
    char ch;
    int i = 1;
    while ((ch = fgetc(file)) != EOF)
        if(p == 1){
            if(ch == '\n' || ch == 4) printf("$\n");
            else putchar(ch);
         }else if(p == 2){
                if(i == 1){printf(" %d ", i); i++;}
            else if(ch == '\n') { 
            printf("\n %d ", i);
            i++;
            }                                                   
            else putchar(ch);
        }else if(p == 3 ){
                if(i == 1){printf(" %d ", i); i++;}
            else if(ch == '\n' && !is_empty_line(file) ) { 
            printf("\n %d ", i);
            i++;
            }
            else putchar(ch);
        }else if(p == 4){
            if (is_empty_line(file) && new_line(ch)){
                if(ch == EOF){
                ungetc(ch, file);
                } 
                }else putchar(ch);
                }
        
            

        fclose(file);
}
int main(int argc, char *argv[]){
    
    open(argv);
    return 0;
}