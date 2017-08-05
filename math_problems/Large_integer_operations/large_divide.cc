#include <cstdio>
#include <cstring>

const int N = 1000;

struct bign{
    int d[N];
    int len;

    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
};


bign change(char str[]);
bign divide(bign a, int b, int& r);
void print(bign a);


int main(int argc, char* argv[])
{
    char str1[N];
    int b;
    int r;
    scanf("%s%d%d", str1, &b, &r);

    bign a = change(str1);

    print(divide(a, b, r));

    return 0;
}

bign change(char str[]){
    bign a;
    a.len = strlen(str);

    for(int i = 0; i < a.len; i++){
        a.d[i] = str[a.len - i - 1] - '0';
    }

    return a;
}

bign divide(bign a, int b, int& r){
    bign c;
    c.len = a.len;

    for(int i = a.len - 1; i >= 0; i--){
        r = r * 10 + a.d[i];
        if(r < b) c.d[i] = 0;
        else{
            c.d[i] = r / b;
            r = r % b;
        }
    }

    while(c.len - 1 >= 0 && c.d[c.len - 1] == 0){
        c.len--;
    }

    return c;
}

void print(bign a){
    for(int i = a.len - 1; i >= 0; i--){
        printf("%d", a.d[i]);
    }
    printf("\n");

}
