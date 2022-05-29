const void* f_memchr(const void* buf,int val,size_t num)
{
    size_t i;
    for(i=0; i<num; i++)
        if(*((char*)buf+i)==val) return (char*)buf+i;
    return NULL;
}
int main(int argc,char* argv[])
{   
    char s[]="qwerty";
    size_t i;
    for(i=0; i<strlen(s); i++)
        printf("%d\n",(char*)f_memchr(s,s[i],strlen(s))-s);