#include<stdio.h>
#include<string.h>
#define MAX 100
void createEmail(char *name,char *email);
int main()
{
    char name[]="Do   Dinh   nguyen    Nhat";
    char email[MAX];
    createEmail(name,email);
    puts(email);
    return 0;
}
void createEmail(char *name,char *email) //khốn nạn cái email có con trỏ
{
    char word[MAX][MAX],clone[MAX];
	char mail[]="@gmail.com";
	int i=0,j=0;
	strlwr(name); // đầu tiên là chuẩn hóa nó về chữ thường
	char *p=strtok(name," "); // lấy từ đầu tiên ( họ )
	while(p!='\0') //sau đó lần lượt lấy các từ còn lại
	{
		strcpy(word[i],p);
		p=strtok(NULL," ");
		i++;
	}
	strcpy(clone,word[i-1]); // lấy tên chuyển vào clone
	for(j=0;j<i-1;j++)
	{
		clone[strlen(clone)]=word[j][0]; //lấy các chữ cái đầu của các từ còn lại ( họ, tên đệm)
	}
	strcpy(clone+strlen(clone),mail);//gắn thêm cái đuôi mail
	strcpy(email,clone);//chuyển có vào biến chính
    return ;
}
