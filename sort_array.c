#include <stdio.h>
#include <stdlib.h>

void scan_array(int *a, int b);
void sort_array(int *a, int b);
void print_array(int *a, int b);
 
int main (void)
{
    int n; 
    printf("Array size : ");
    scanf("%d", &n);
    int * a = (int*)malloc(n*sizeof(int));
        
    scan_array(a, n);                    
    sort_array(a, n);           
    print_array(a, n);          
 
    free(a);
    return 0;
}

void scan_array(int *a, int n)
{
    int i = 0;
    while(i<n) {
    scanf("%d", &a[i]);
    i++;
    }
    
}

void sort_array(int *a, int b) {
int j=0;
while(j<b){
int i=0 ; 
while(i<b-1){
    if(a[i]> a[i+1]) {
        int q = a[i+1];
        a[i+1] = a[i];
        a[i] = q;
    }
i++;  
}
    j++; 
    }
}

void print_array(int *a, int n)
{
    int i;
    for (i=0; i<n; i++)
        printf("%d ", a[i]);
        printf("\n");
}