unsigned int tribonacci(unsigned int n) {
return (n<=2 ? (n<=0?0:1) : tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3));
}

int main(){
    return tribonacci(10);
}