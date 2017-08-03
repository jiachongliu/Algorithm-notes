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
bign sub(bign a, bign b);
void print(bign a);


int main(int argc, char* argv[])
{
    char str1[N], str2[N];
    scanf("%s%s", str1, str2);

    bign a = change(str1);
    bign b = change(str2);

    print(sub(a, b));

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

bign sub(bign a, bign b){
    bign c;
    for(int i = 0; i < a.len || i < b.len; i++){
        if(a.d[i] < b.d[i]){
            a.d[i + 1]--;
            a.d[i] += 10;
        }

        c.d[c.len++] = a.d[i] - b.d[i];
    }

    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){
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
