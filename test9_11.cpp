#include <iostream>
#include <cstring>
struct WORD{
	char *w;
	int c1,c2;
};
int search(WORD word[],int n,char *s){
	for(int i=0;i<n;i++){
		if(strcmp(word[i].w,s)==0)
			return i;
	}
	return n;
}
int main(){
	WORD word[100];
	int n=0;
	char str_1[]="AB AC AD AE AF AG";
	char str_2[]="AB AC AD AG AH AK";
	char *p = strtok(str_1," ");
	while(p!=NULL){
		int pos = search(word,n,p);
		if(pos < n){
			word[pos].c1++;
		}
		else{
			n++;
			word[pos].w = p;
			word[pos].c1 = 1;
		}
		p = strtok(NULL," ");
	}
	p = strtok(str_2," ");
	while(p!=NULL){
		int pos = search(word,n,p);
		if(pos < n){
			word[pos].c2++;
		}
		else{
			n++;
			word[pos].w = p;
			word[pos].c2 = 1;
		}
		p = strtok(NULL," ");
	}
	for(int i=0;i<n;i++){
		if(word[i].c1>0 && word[i].c2<1){
			std::cout<<word[i].w<<' '<<word[i].c1 + word[i].c2<<std::endl;
		}
	}
	return 1;
}