extern int _pallc(int tid, int func); 
extern int _publk(int tid); 
extern int _pblk(int tid); 
extern int _pdall(int tid);

#define LOOP_NUMBER 1000

int i;
int sum;
int loop(){
    int a[100];
    int b[100];
    int c[100];
    sum = 0;
    for (i = 0; i < LOOP_NUMBER; i++)
    {
        c[i] = a[i] + b[i];
    }
    return sum;

}

int a;
int main(){

    a = loop();
    return a;
}