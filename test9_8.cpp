#include<iostream>
#include<cstring>
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
int main(){
	WORD word[100];
	int n = 0;
    char str[] = "with with whatever klj wo Texs fixes Sublime Text 3";
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
    return 1;
}
