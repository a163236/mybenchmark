extern int _pallc(int tid, int func); 
extern int _publk(int tid); 
extern int _pblk(int tid); 
extern int _pdall(int tid);

#define LOOP_NUMBER 50

int a;  // 結果格納
int b;

int success_publk;
int success_pblk;
int success_pdall;

int i0;
void loop0(){
    a = 0;
    for (i0 = 0; i0 < LOOP_NUMBER/2; i0++)
    {
        a++;
    }

}

int i1;
void loop1(){
    b = 0;
    for (i1 = 0; i1 < LOOP_NUMBER/2; i1++)
    {
        b++;
    }

    // スレッド0の再開
    success_publk = 0;
    while (!success_publk)
    {
        success_publk = _publk(0);
    }
    // スレッド1の終了
    success_pdall = 0;
    while (!success_pdall)
    {
        success_pdall = _pdall(1);
    }

}

int main(){
    _pallc(1, loop1);

    _publk(1);

    loop0();

    _pblk(0);
    
    return 77000+a+b;
}