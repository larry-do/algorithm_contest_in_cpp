#include <iostream>
int main(int argc, char const *argv[])
{
	char *s;
	std::cin>>*s;
	std::cout<<s;
	return 0;
}
class STRING {
private:
	char *s;
public:
	void initString();
	int stringLength();
	char *toLowerString();
	char *toUpperString();
	char codeChar();
	char decodeChar();
	void showAndCountWord();
	int searchWord();
	int searchChar();
	void showAndCountChar();
	char *codeString();
	char *decodeString();
};
///////////////////////////////////////////////////////
/// Các hàm sẽ ko viết vào class. Và mình dùng string
//đếm từ.
struct WORD{
	char w[20];
	int c;
};
int searchInStr(WORD word[],int n,char *str){
	for(int i=0;i<n;i++){
		if(strcmp(str,word[i].w) == 0)
			return i;
	}
	return n;
}
void showAndCountWord(char str[]){
	WORD word[100];
	int n = 0;
    char *p = strtok(str," ");
    while(p!=NULL){
    	int pos = searchInStr(word,n,p);
    	if(pos < n){
    		word[pos].c++;
    	}
    	else{
    		++n;
    		strcpy(word[pos].w,p);
    		word[pos].c = 1;
    	}
        p = strtok(NULL," ");
    }
    for(int i=0;i<n;i++){
    	std::cout<<word[i].w<<' '<<word[i].c<<std::endl;
    }
}
// đếm kí tự
void showAndCountChar(char a[]){
    int Count[256] = {0};
    for(int i=0;i<strlen(a);i++){
        Count[a[i]]++;
    }
    for(int i=0;i<256;i++){
        if(Count[i]>0){
            std::cout<<char(i);
        }
    }
}
//