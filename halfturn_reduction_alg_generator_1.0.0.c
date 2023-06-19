#include <stdio.h>
#include <string.h>

//personal note: This is DRHTRv4 (from 1. November 2022)

/*
Moves:

R2 = R
L2 = L
F2 = F
B2 = B

U' = T
U  = U
U2 = V

D' = C
D =  D
D2 = E

Solved: 1
1c auf c1: 2 
11... : 3
flipped: 4
101... : 5
flipped :6

*/
char MOVE[10] = {'R','L','F','B','T','U','V','C','D','E'}; 
char tabelle[39][39][8];
int state[16] = {};

int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0;
int e1 = 0, e2 = 0, e3 = 0, e4 = 0, e5 = 0, e6 = 0, e7 = 0, e8 = 0;

void setzero(){
    c1 = 0; c2 = 0; c3 = 0; c4 = 0; c5 = 0; c6 = 0; c7 = 0; c8 = 0; 
    e1 = 0; e2 = 0; e3 = 0; e4 = 0; e5 = 0; e6 = 0; e7 = 0; e8 = 0;
}

void n(){
    printf("\n");
}


int zweimovesplausibel(previousmove, nextmove){
    int a_previousmove = previousmove;
    int a_nextmove = nextmove;
    // T und U: 
    if(((a_previousmove == 4)&&(a_nextmove == 5)) || ((a_previousmove == 5)&&(a_nextmove == 4))){return 0;}
    // T und V:
    if(((a_previousmove == 4)&&(a_nextmove == 6)) || ((a_previousmove == 6)&&(a_nextmove == 4))){return 0;}
    //V und U:
    if(((a_previousmove == 5)&&(a_nextmove == 6)) || ((a_previousmove == 6)&&(a_nextmove == 5))){return 0;}
    //für C,D,E:
    if(((a_previousmove == 7)&&(a_nextmove == 8)) || ((a_previousmove == 8)&&(a_nextmove == 7))){return 0;}
    if(((a_previousmove == 8)&&(a_nextmove == 9)) || ((a_previousmove == 9)&&(a_nextmove == 8))){return 0;}
    if(((a_previousmove == 7)&&(a_nextmove == 9)) || ((a_previousmove == 9)&&(a_nextmove == 7))){return 0;}

    else{return 1;}
}



void R(){
    //e2 swap e6
    //c2 swap c7
    //c3 swap c6
    int zwischen = e2;
    if (e6 == 0){e2 = 0;} else {e2 = 1;}
    if (zwischen == 0){e6 = 0;} else {e6 = 1;}

    int zwischen2 = c2;
    if (c7 == 0){c2 = 0;} else {c2 = 1;}
    if (zwischen2 == 0){c7 = 0;} else {c7 = 1;}

    int zwischen3 = c3;
    if (c6 == 0){c3 = 0;} else {c3 = 1;}
    if (zwischen3 == 0){c6 = 0;} else {c6 = 1;}
}

void L(){
    int zwischen = e4;
    if (e8 == 0){e4 = 0;} else {e4 = 1;}
    if (zwischen == 0){e8 = 0;} else {e8 = 1;}

    int zwischen2 = c1;
    if (c8 == 0){c1 = 0;} else {c1 = 1;}
    if (zwischen2 == 0){c8 = 0;} else {c8 = 1;}

    int zwischen3 = c4;
    if (c5 == 0){c4 = 0;} else {c4 = 1;}
    if (zwischen3 == 0){c5 = 0;} else {c5 = 1;}
}

void F(){
    int zwischen = e3;
    if (e7 == 0){e3 = 0;} else {e3 = 1;}
    if (zwischen == 0){e7 = 0;} else {e7 = 1;}

    int zwischen2 = c4;
    if (c7 == 0){c4 = 0;} else {c4 = 1;}
    if (zwischen2 == 0){c7 = 0;} else {c7 = 1;}

    int zwischen3 = c3;
    if (c8 == 0){c3 = 0;} else {c3 = 1;}
    if (zwischen3 == 0){c8 = 0;} else {c8 = 1;}
}

void B(){
    int zwischen = e5;
    if (e1 == 0){e5 = 0;} else {e5 = 1;}
    if (zwischen == 0){e1 = 0;} else {e1 = 1;}

    int zwischen2 = c1;
    if (c6 == 0){c1 = 0;} else {c1 = 1;}
    if (zwischen2 == 0){c6 = 0;} else {c6 = 1;}

    int zwischen3 = c5;
    if (c2 == 0){c5 = 0;} else {c5 = 1;}
    if (zwischen3 == 0){c2 = 0;} else {c2 = 1;}
}

void U(){
    int zwischen = e1;
    if (e4 == 0){e1 = 1;} else {e1 = 0;}
    if (e3 == 0){e4 = 1;} else {e4 = 0;}
    if (e2 == 0){e3 = 1;} else {e3 = 0;}
    if (zwischen == 0){e2 = 1;} else {e2 = 0;}

    int zwischen2 = c1;
    if (c4 == 0){c1 = 1;} else {c1 = 0;}
    if (c3 == 0){c4 = 1;} else {c4 = 0;}
    if (c2 == 0){c3 = 1;} else {c3 = 0;}
    if (zwischen2 == 0){c2 = 1;} else {c2 = 0;}
}


void D(){
    int zwischen = e5;
    if (e8 == 0){e5 = 1;} else {e5 = 0;}
    if (e7 == 0){e8 = 1;} else {e8 = 0;}
    if (e6 == 0){e7 = 1;} else {e7 = 0;}
    if (zwischen == 0){e6 = 1;} else {e6 = 0;}

    int zwischen2 = c5;
    if (c8 == 0){c5 = 1;} else {c5 = 0;}
    if (c7 == 0){c8 = 1;} else {c8 = 0;}
    if (c6 == 0){c7 = 1;} else {c7 = 0;}
    if (zwischen2 == 0){c6 = 1;} else {c6 = 0;}
}
void E(){D();D();}

void C(){D();D();D();}

void V(){U();U();}

void T(){U();U();U();}

int move(x){
    if(x == 0 ){R();}
    if(x == 1 ){L();}
    if(x == 2 ){F();}
    if(x == 3 ){B();}
    if(x == 4 ){T();}
    if(x == 5 ){U();}
    if(x == 6 ){V();}
    if(x == 7 ){C();}
    if(x == 8 ){D();}
    if(x == 9 ){E();}
    return 0;
}

void printcube(){
    printf("%d%d%d      %d%d%d\n%d %d      %d %d\n%d%d%d      %d%d%d\n\n",c1,e1,c2,c5,e5,c6,   e4,e2,e8,e6,   c4,e3,c3,c8,e7,c7);
}


void S(){
    printf("%d%d%d%d_%d%d%d%d__",c1,c2,c3,c4,c5,c6,c7,c8);
    printf("%d%d%d%d_%d%d%d%d",e1,e2,e3,e4,e5,e6,e7,e8);
}



int casefinder(int a,int b,int c,int d,int e,int f,int g,int h){

if((a == 0)&&(b == 0)&&(c == 0)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 1;}
if((a == 1)&&(b == 0)&&(c == 0)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 2;}
if((a == 1)&&(b == 1)&&(c == 0)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 3;}
if((a == 1)&&(b == 0)&&(c == 0)&&
   (d == 1)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 4;}
if((a == 1)&&(b == 0)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 5;}
if((a == 1)&&(b == 0)&&(c == 0)&&
   (d == 0)&&          (e == 1)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 6;}
if((a == 1)&&(b == 0)&&(c == 0)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 1)&&(h == 0))
   {return 7;}
if((a == 1)&&(b == 0)&&(c == 0)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 1))
   {return 8;}
   
if((a == 1)&&(b == 1)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 9;}

if((a == 1)&&(b == 1)&&(c == 0)&&
   (d == 1)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 10;}
if((a == 1)&&(b == 1)&&(c == 0)&&
   (d == 0)&&          (e == 1)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 11;}
if((a == 1)&&(b == 0)&&(c == 0)&&
   (d == 1)&&          (e == 0)&&
   (f == 0)&&(g == 1)&&(h == 0))
   {return 12;}
//R-Perm
if((a == 1)&&(b == 0)&&(c == 1)&&
   (d == 1)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 13;}
if((a == 1)&&(b == 0)&&(c == 1)&&
   (d == 0)&&          (e == 1)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 14;}
if((a == 1)&&(b == 0)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 15;}
if((a == 0)&&(b == 0)&&(c == 1)&&
   (d == 1)&&          (e == 1)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 16;}

if((a == 1)&&(b == 1)&&(c == 0)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 1))
   {return 17;}
if((a == 0)&&(b == 1)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 1)&&(g == 0)&&(h == 0))
   {return 18;}

if((a == 1)&&(b == 0)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 1)&&(g == 0)&&(h == 0))
   {return 19;}
if((a == 1)&&(b == 0)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 1)&&(h == 0))
   {return 20;}
if((a == 1)&&(b == 0)&&(c == 0)&&
   (d == 0)&&          (e == 1)&&
   (f == 0)&&(g == 1)&&(h == 0))
   {return 21;}
if((a == 0)&&(b == 1)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 22;}

if((a == 1)&&(b == 1)&&(c == 1)&&
   (d == 1)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 23;}
   if((a == 1)&&(b == 1)&&(c == 1)&&
   (d == 0)&&          (e == 1)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 24;}
if((a == 1)&&(b == 1)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 1)&&(g == 0)&&(h == 0))
   {return 25;}
if((a == 1)&&(b == 1)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 1))
   {return 26;}


if((a == 1)&&(b == 1)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 1)&&(h == 0))
   {return 27;}
if((a == 1)&&(b == 1)&&(c == 0)&&
   (d == 1)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 1))
   {return 28;}
// j+1 I
if((a == 1)&&(b == 1)&&(c == 0)&&
   (d == 0)&&          (e == 1)&&
   (f == 1)&&(g == 0)&&(h == 0))
   {return 29;}
// j+1 II
if((a == 1)&&(b == 0)&&(c == 1)&&
   (d == 1)&&          (e == 0)&&
   (f == 0)&&(g == 1)&&(h == 0))
   {return 30;}
if((a == 1)&&(b == 1)&&(c == 0)&&
   (d == 0)&&          (e == 1)&&
   (f == 0)&&(g == 1)&&(h == 0))
   {return 31;}
if((a == 1)&&(b == 0)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 0)&&(g == 1)&&(h == 0))
   {return 32;}
if((a == 1)&&(b == 1)&&(c == 0)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 1)&&(h == 1))
   {return 33;}
if((a == 1)&&(b == 0)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 0)&&(g == 0)&&(h == 1))
   {return 34;}

if((a == 0)&&(b == 1)&&(c == 0)&&
   (d == 0)&&          (e == 0)&&
   (f == 0)&&(g == 1)&&(h == 0))
   {return 35;}
if((a == 0)&&(b == 1)&&(c == 0)&&
   (d == 1)&&          (e == 0)&&
   (f == 0)&&(g == 0)&&(h == 0))
   {return 36;}
if((a == 0)&&(b == 1)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 0)&&(g == 1)&&(h == 0))
   {return 37;}
//-----------flipped--------------
if((a == 1)&&(b == 1)&&(c == 1)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 1;}
if((a == 0)&&(b == 1)&&(c == 1)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 2;}
if((a == 0)&&(b == 0)&&(c == 1)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 3;}
if((a == 0)&&(b == 1)&&(c == 1)&&
   (d == 0)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 4;}
if((a == 0)&&(b == 1)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 5;}
if((a == 0)&&(b == 1)&&(c == 1)&&
   (d == 1)&&          (e == 0)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 6;}
if((a == 0)&&(b == 1)&&(c == 1)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 0)&&(h == 1))
   {return 7;}
if((a == 0)&&(b == 1)&&(c == 1)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 0))
   {return 8;}
   
if((a == 0)&&(b == 0)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 9;}

if((a == 0)&&(b == 0)&&(c == 1)&&
   (d == 0)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 10;}
if((a == 0)&&(b == 0)&&(c == 1)&&
   (d == 1)&&          (e == 0)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 11;}
if((a == 0)&&(b == 1)&&(c == 1)&&
   (d == 0)&&          (e == 1)&&
   (f == 1)&&(g == 0)&&(h == 1))
   {return 12;}
//R-Perm
if((a == 0)&&(b == 1)&&(c == 0)&&
   (d == 0)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 13;}
if((a == 0)&&(b == 1)&&(c == 0)&&
   (d == 1)&&          (e == 0)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 14;}
if((a == 0)&&(b == 1)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 15;}
if((a == 1)&&(b == 1)&&(c == 0)&&
   (d == 0)&&          (e == 0)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 16;}

if((a == 0)&&(b == 0)&&(c == 1)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 0))
   {return 17;}
if((a == 1)&&(b == 0)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 0)&&(g == 1)&&(h == 1))
   {return 18;}

if((a == 0)&&(b == 1)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 0)&&(g == 1)&&(h == 1))
   {return 19;}
if((a == 0)&&(b == 1)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 0)&&(h == 1))
   {return 20;}
if((a == 0)&&(b == 1)&&(c == 1)&&
   (d == 1)&&          (e == 0)&&
   (f == 1)&&(g == 0)&&(h == 1))
   {return 21;}
if((a == 1)&&(b == 0)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 22;}

if((a == 0)&&(b == 0)&&(c == 0)&&
   (d == 0)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 23;}
   if((a == 0)&&(b == 0)&&(c == 0)&&
   (d == 1)&&          (e == 0)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 24;}
if((a == 0)&&(b == 0)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 0)&&(g == 1)&&(h == 1))
   {return 25;}
if((a == 0)&&(b == 0)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 0))
   {return 26;}

if((a == 0)&&(b == 0)&&(c == 0)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 0)&&(h == 1))
   {return 27;}
if((a == 0)&&(b == 0)&&(c == 1)&&
   (d == 0)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 0))
   {return 28;}
// j+0 I
if((a == 0)&&(b == 0)&&(c == 1)&&
   (d == 1)&&          (e == 0)&&
   (f == 0)&&(g == 1)&&(h == 1))
   {return 29;}
// j+0 II
if((a == 0)&&(b == 1)&&(c == 0)&&
   (d == 0)&&          (e == 1)&&
   (f == 1)&&(g == 0)&&(h == 1))
   {return 30;}
if((a == 0)&&(b == 0)&&(c == 1)&&
   (d == 1)&&          (e == 0)&&
   (f == 1)&&(g == 0)&&(h == 1))
   {return 31;}
if((a == 0)&&(b == 1)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 1)&&(g == 0)&&(h == 1))
   {return 32;}
if((a == 0)&&(b == 0)&&(c == 1)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 0)&&(h == 0))
   {return 33;}
if((a == 0)&&(b == 1)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 1)&&(g == 1)&&(h == 0))
   {return 34;}

if((a == 1)&&(b == 0)&&(c == 1)&&
   (d == 1)&&          (e == 1)&&
   (f == 1)&&(g == 0)&&(h == 1))
   {return 35;}
if((a == 1)&&(b == 0)&&(c == 1)&&
   (d == 0)&&          (e == 1)&&
   (f == 1)&&(g == 1)&&(h == 1))
   {return 36;}
if((a == 1)&&(b == 0)&&(c == 1)&&
   (d == 0)&&          (e == 0)&&
   (f == 1)&&(g == 0)&&(h == 1))
   {return 37;}



else return 0;
}


int fail = 0;

void caseprinter(int layer){
    if(layer == 0){
    switch(casefinder(c1, e1, c2, e4, e2, c4, e3, c3)){
        fail = 0;
        case 1: printf(" solved"); break;
        case 2: printf(" 1c"); break;
        case 3: printf(" icase1"); break;
        case 4: printf(" icase2"); break;
        case 5: printf(" 2c-adj"); break;
        case 6: printf(" half-diag1"); break;
        case 7: printf(" half-diag2"); break;
        case 8: printf(" 2c-diag"); break;
        case 9: printf(" bar"); break;
        case 10: printf(" fullcorner"); break;
        case 11: printf(" j1"); break;
        case 12: printf(" j2"); break;
        case 13: printf(" r1"); break;
        case 14: printf(" r2"); break;
        case 15: printf(" r-inv1"); break;
        case 16: printf(" r-inv2"); break;
        case 17: printf(" fall1"); break;
        case 18: printf(" fall2"); break;
        case 19: printf(" 3c"); break;
        case 20: printf(" v"); break;
        case 21: printf(" 132"); break;
        case 22: printf(" u"); break;
        case 23: printf(" l1"); break;
        case 24: printf(" l2"); break;
        case 25: printf(" umbrella1"); break;
        case 26: printf(" umbrella2"); break;
        case 27: printf(" t"); break;
        case 28: printf(" y"); break;
        case 29: printf(" j+1 I"); break;
        case 30: printf(" j+1 II"); break;
        case 31: printf(" Kelle1"); break;
        case 32: printf(" Kelle2"); break;
        case 33: printf(" n1"); break;
        case 34: printf(" n2"); break;
        case 35: printf(" 2e-opp"); break;
        case 36: printf(" 2e-adj"); break;
        case 37: printf(" o"); break;
        default: printf(" unknown"); fail = 1; break;
       //8:diag2c, bar, fullcorner, j1, j2 (12), r1, r2, r-inv1, r-inv2, 

   //3c (19), v, 132, u, l1, l2 umbrella1, umbrella2, t, y
   
    }
    }

        if(layer == 1){
        
    switch(casefinder(c5, e5, c6, e8, e6, c8, e7, c7)){
        fail = 0;
        case 1: printf(" solved"); break;
        case 2: printf(" 1c"); break;
        case 3: printf(" icase1"); break;
        case 4: printf(" icase2"); break;
        case 5: printf(" 2c-adj"); break;
        case 6: printf(" half-diag1"); break;
        case 7: printf(" half-diag2"); break;
        case 8: printf(" 2c-diag"); break;
        case 9: printf(" bar"); break;
        case 10: printf(" fullcorner"); break;
        case 11: printf(" j1"); break;
        case 12: printf(" j2"); break;
        case 13: printf(" r1"); break;
        case 14: printf(" r2"); break;
        case 15: printf(" r-inv1"); break;
        case 16: printf(" r-inv2"); break;
        case 17: printf(" fall1"); break;
        case 18: printf(" fall2"); break;
        case 19: printf(" 3c"); break;
        case 20: printf(" v"); break;
        case 21: printf(" 132"); break;
        case 22: printf(" u"); break;
        case 23: printf(" l1"); break;
        case 24: printf(" l2"); break;
        case 25: printf(" umbrella1"); break;
        case 26: printf(" umbrella2"); break;
        case 27: printf(" t"); break;
        case 28: printf(" y"); break;
        case 29: printf(" j+1 I"); break;
        case 30: printf(" j+1 II"); break;
        case 31: printf(" Kelle1"); break;
        case 32: printf(" Kelle2"); break;
        case 33: printf(" n1"); break;
        case 34: printf(" n2"); break;
        case 35: printf(" 2e-opp"); break;
        case 36: printf(" 2e-adj"); break;
        case 37: printf(" o"); break;
        default: printf(" unknown"); fail = 1; break;
    }
    }

}

void casename(int a){
        switch(a){
        case 1: printf(" solved    "); break;
        case 2: printf(" 1c        "); break;
        case 3: printf(" icase1    "); break;
        case 4: printf(" icase2    "); break;
        case 5: printf(" 2c-adj    "); break;
        case 6: printf(" half-diag1"); break;
        case 7: printf(" half-diag2"); break;
        case 8: printf(" 2c-diag   "); break;
        case 9: printf(" bar       "); break;
        case 10: printf(" fullcorner"); break;
        case 11: printf(" j1        "); break;
        case 12: printf(" j2        "); break;
        case 13: printf(" r1        "); break;
        case 14: printf(" r2        "); break;
        case 15: printf(" r-inv1    "); break;
        case 16: printf(" r-inv2    "); break;
        case 17: printf(" fall1     "); break;
        case 18: printf(" fall2     "); break;
        case 19: printf(" 3c        "); break;
        case 20: printf(" v         "); break;
        case 21: printf(" 132       "); break;
        case 22: printf(" u         "); break;
        case 23: printf(" l1        "); break;
        case 24: printf(" l2        "); break;
        case 25: printf(" umbrella1 "); break;
        case 26: printf(" umbrella2 "); break;
        case 27: printf(" t         "); break;
        case 28: printf(" y         "); break;
        case 29: printf(" j+1 I     "); break;
        case 30: printf(" j+1 II    "); break;
        case 31: printf(" Kelle1    "); break;
        case 32: printf(" Kelle2    "); break;
        case 33: printf(" n1        "); break;
        case 34: printf(" n2        "); break;
        case 35: printf(" 2e-opp    "); break;
        case 36: printf(" 2e-adj    "); break;
        case 37: printf(" o         "); break;
        default: printf(" unknown   "); break;}
}

void tabellenullen(){
    for(int a = 0; a<39; a++){
        for(int b = 0; b<39; b++){
            for(int c = 0; c<8; c++){
                tabelle[a][b][c]= '0';
            }
        }
    }
}

void eightmover()
{
   int counter = 0;
   for (int a = 0; a < 10; a++)
   {
      for (int b = 0; b < 10; b++)
      {
         for (int c = 0; c < 10; c++)
         {
            for (int d = 0; d < 10; d++)
            {
               for (int e = 0; e < 10; e++)
               {
                  for (int f = 0; f < 10; f++)
                  {
                     for (int g = 0; g < 10; g++)
                     {
                        for (int h = 0; h < 10; h++)
                        {
                           if (
                               (MOVE[a] != MOVE[b]) &&
                               (MOVE[b] != MOVE[c]) &&
                               (MOVE[c] != MOVE[d]) &&
                               (MOVE[d] != MOVE[e]) &&
                               (MOVE[e] != MOVE[f]) &&
                               (MOVE[f] != MOVE[g]) &&
                               (MOVE[g] != MOVE[h]) &&
                               zweimovesplausibel(a, b) &&
                               zweimovesplausibel(b, c) &&
                               zweimovesplausibel(c, d) &&
                               zweimovesplausibel(d, e) &&
                               zweimovesplausibel(e, f) &&
                               zweimovesplausibel(f, g) &&
                               zweimovesplausibel(g, h)

                               
                                        &&
                                        (MOVE[a] = 'D')&&
                                        (MOVE[b] = 'B')&&
                                        (MOVE[c] = 'D')&&
                                        (MOVE[d] = 'B')&&
                                        (MOVE[e] = 'U')&&
                                        (MOVE[f] = 'L')&&
                                        (MOVE[g] = 'D')&&
                                        (MOVE[h] = 'L')
                           )
                           {
                              /*setzero();
                              move(a);
                              move(b);
                              move(c);
                              move(d);
                              move(e);
                              move(f);
                              move(g);
                              move(h);*/
                              printf("marker");

                              setzero();
                                            move(a);
                                            n();printcube();n();
                                            move(b);
                                            n();printcube();n();
                                            move(c);
                                            n();printcube();n();
                                            move(d);
                                            n();printcube();n();
                                            move(e);
                                            n();printcube();n();
                                            move(f);
                                            n();printcube();n();
                                            move(g);
                                            n();printcube();n();
                                            move(h);

                              if (

                                  (casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 0) && (casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 0) && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 1) && (casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 1)) && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 9) && (casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 9)))
                              {

                                 //printf("#8er# ");

                                 tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)][casefinder(c5, e5, c6, e8, e6, c8, e7, c7)][0] = MOVE[a];
                                 tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)][casefinder(c5, e5, c6, e8, e6, c8, e7, c7)][1] = MOVE[b];
                                 tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)][casefinder(c5, e5, c6, e8, e6, c8, e7, c7)][2] = MOVE[c];
                                 tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)][casefinder(c5, e5, c6, e8, e6, c8, e7, c7)][3] = MOVE[d];
                                 tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)][casefinder(c5, e5, c6, e8, e6, c8, e7, c7)][4] = MOVE[e];
                                 tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)][casefinder(c5, e5, c6, e8, e6, c8, e7, c7)][5] = MOVE[f];
                                 tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)][casefinder(c5, e5, c6, e8, e6, c8, e7, c7)][6] = MOVE[g];
                                 tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)][casefinder(c5, e5, c6, e8, e6, c8, e7, c7)][7] = MOVE[h];
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
}

void sevenmover(){
    int counter = 0;
        for(int a = 0; a<10; a++){
            for(int b = 0; b<10; b++){    
                for(int c = 0; c<10; c++){
                  for(int d = 0; d<10; d++){
                      for(int e = 0; e<10; e++){
                           for(int f = 0; f<10; f++){
                               for(int g = 0; g<10; g++){
                                    if(
                                        (MOVE[a]!= MOVE[b])&&
                                        (MOVE[b]!= MOVE[c])&&
                                        (MOVE[c]!= MOVE[d])&&
                                        (MOVE[d]!= MOVE[e])&&
                                        (MOVE[e]!= MOVE[f])&&
                                        (MOVE[f]!= MOVE[g])&&
                                        zweimovesplausibel(a,b)&&
                                        zweimovesplausibel(b,c)&&
                                        zweimovesplausibel(c,d)&&
                                        zweimovesplausibel(d,e)&&
                                        zweimovesplausibel(e,f)&&
                                        zweimovesplausibel(f,g)                           
                                        /* 
                                        &&(MOVE[a] = 'F')&&
                                        (MOVE[b] = 'U')&&
                                        (MOVE[c] = 'R')&&
                                        (MOVE[d] = 'U')&&
                                        (MOVE[e] = 'R')&&
                                        (MOVE[f] = 'C')*/
              
                                    ){  
                                        setzero();
                                        move(a);
                                        move(b);
                                        move(c);
                                        move(d);
                                        move(e);
                                        move(f);
                                        move(g);
              
                                            /*setzero();
                                            move(a);
                                            n();printcube();n();
                                            move(b);
                                            n();printcube();n();
                                            move(c);
                                            n();printcube();n();
                                            move(d);
                                            n();printcube();n();
                                            move(e);
                                            n();printcube();n();
                                            move(f);
                                            n();printcube();n();
                                            move(g);*/
                
                
                
                                        // Diese if-Schleife führt zu einem Sechsteln der Laufzeit (0,5s statt 3s)
                                        
                                        if(
                                        
                                            (casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 0)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 0)
                                            && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 1)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 1))
                                            && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 9)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 9))){
                                                
                                                
                                            
                                        /*n();n();
                                        printf("------------------");
                                        n();
                                        printf("%c, %c, %c, %c, %c, %c, %c", MOVE[a], MOVE[b], MOVE[c], MOVE[d], MOVE[e], MOVE[f], MOVE[g]);
                                        n();n();
                                        printcube();
                                        caseprinter(0);
                                        printf(" and ");
                                        caseprinter(1);
                                        n();
                                        printf("---------%d---------",counter);
                                        counter++;*/
                                        
                                        //saving in tabelle:
                                        //if erster eintrag des scrambles is free
                                        //if(tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [0] == '0'){
                                            //printf("   #####saved new case#####\n");
                                            //for(int i = 0; i<5; i++){
                                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [0] = MOVE[a];
                                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [1] = MOVE[b];
                                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [2] = MOVE[c];
                                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [3] = MOVE[d];
                                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [4] = MOVE[e];
                                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [5] = MOVE[f];
                                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [6] = MOVE[g];
                                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [7] = '0';
                                            
                        
                            }
                            }
                            }
                        }
                    }
                }
            }
        }  
    }
}


void sixmover(){
    int counter = 0;
       for(int a = 0; a<10; a++){
        for(int b = 0; b<10; b++){    
            for(int c = 0; c<10; c++){
                for(int d = 0; d<10; d++){
                    for(int e = 0; e<10; e++){
                        for(int f = 0; f<10; f++){

                        if(
                            (MOVE[a]!= MOVE[b])&&
                            (MOVE[b]!= MOVE[c])&&
                            (MOVE[c]!= MOVE[d])&&
                            (MOVE[d]!= MOVE[e])&&
                            (MOVE[e]!= MOVE[f])&&
                            zweimovesplausibel(a,b)&&
                            zweimovesplausibel(b,c)&&
                            zweimovesplausibel(c,d)&&
                            zweimovesplausibel(d,e)&&
                            zweimovesplausibel(e,f)
                            
                           /* 
                           &&(MOVE[a] = 'F')&&
                           (MOVE[b] = 'U')&&
                           (MOVE[c] = 'R')&&
                           (MOVE[d] = 'U')&&
                           (MOVE[e] = 'R')&&
                           (MOVE[f] = 'C')*/

                        ){  
                            setzero();
                            move(a);
                            move(b);
                            move(c);
                            move(d);
                            move(e);
                            move(f);

                            /*setzero();
                            move(a);
                            n();printcube();n();
                            move(b);
                            n();printcube();n();
                            move(c);
                            n();printcube();n();
                            move(d);
                            n();printcube();n();
                            move(e);
                            n();printcube();n();
                            move(f);*/



                        // Diese if-Schleife führt zu einem Sechsteln der Laufzeit (0,5s statt 3s)
                        
                        if(

                            (casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 0)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 0)
                            && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 1)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 1))
                            && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 9)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 9))){
                                
                                

                        /*n();n();
                        printf("------------------");
                        n();
                        printf("%c, %c, %c, %c, %c, %c", MOVE[a], MOVE[b], MOVE[c], MOVE[d], MOVE[e], MOVE[f]);
                        n();n();
                        printcube();
                        caseprinter(0);
                        printf(" and ");
                        caseprinter(1);
                        n();
                        printf("---------%d---------",counter);
                        counter++;*/
                        
                        //saving in tabelle:
                        //if erster eintrag des scrambles is free
                        //if(tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [0] == '0'){
                            //printf("   #####saved new case#####\n");
                            //for(int i = 0; i<5; i++){
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [0] = MOVE[a];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [1] = MOVE[b];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [2] = MOVE[c];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [3] = MOVE[d];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [4] = MOVE[e];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [5] = MOVE[f];

                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [6] = '0';
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [7] = '0';
                            
                            
                            }
                            }
                        }
                    }
                }
            }
        }  
    }
}

void fivemover(){
    int counter = 0;
       for(int a = 0; a<10; a++){
        for(int b = 0; b<10; b++){    
            for(int c = 0; c<10; c++){
                for(int d = 0; d<10; d++){
                    for(int e = 0; e<10; e++){
                        

                        if(
                            (MOVE[a]!= MOVE[b])&&
                            (MOVE[b]!= MOVE[c])&&
                            (MOVE[c]!= MOVE[d])&&
                            (MOVE[d]!= MOVE[e])&&
                            zweimovesplausibel(a,b)&&
                            zweimovesplausibel(b,c)&&
                            zweimovesplausibel(c,d)&&
                            zweimovesplausibel(d,e)
                            
                           /* 
                           &&(MOVE[a] = 'F')&&
                           (MOVE[b] = 'U')&&
                           (MOVE[c] = 'R')&&
                           (MOVE[d] = 'U')&&
                           (MOVE[e] = 'R')*/

                        ){  
                            setzero(); 
                            move(a);
                            move(b);
                            move(c);
                            move(d);
                            move(e);

                            /*setzero();
                            move(a);
                            n();printcube();n();
                            move(b);
                            n();printcube();n();
                            move(c);
                            n();printcube();n();
                            move(d);
                            n();printcube();n();
                            move(e);*/



                        /* Diese if-Schleife führt zu einem Sechsteln der Laufzeit (0,5s statt 3s)
                        
                        if(

                            (casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 0)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 0)
                            && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 1)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 1))
                            && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 9)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 9))){
                                
                                */

                        /*n();n();
                        printf("------------------");
                        n();
                        printf("%c, %c, %c, %c, %c", MOVE[a], MOVE[b], MOVE[c], MOVE[d], MOVE[e]);
                        n();n();
                        printcube();
                        caseprinter(0);
                        printf(" and ");
                        caseprinter(1);
                        n();
                        printf("---------%d---------",counter);
                        counter++;*/
                        
                        //saving in tabelle:
                        //if erster eintrag des scrambles is free
                        //if(tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [0] == '0'){
                            //printf("   #####saved new case#####\n");
                            
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [0] = MOVE[a];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [1] = MOVE[b];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [2] = MOVE[c];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [3] = MOVE[d];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [4] = MOVE[e];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [5] = '0';
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [6] = '0';
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [7] = '0';
                            

                        
                            }
                        
                    }
                }
            }
        }  
    } 
}

void fourmover(){
    int counter = 0;
       for(int a = 0; a<10; a++){
          for(int b = 0; b<10; b++){    
            for(int c = 0; c<10; c++){
                for(int d = 0; d<10; d++){
                    
                        

                        if(
                            (MOVE[a]!= MOVE[b])&&
                            (MOVE[b]!= MOVE[c])&&
                            (MOVE[c]!= MOVE[d])&&
                            zweimovesplausibel(a,b)&&
                            zweimovesplausibel(b,c)&&
                            zweimovesplausibel(c,d)
                            
                           /* 
                           &&(MOVE[a] = 'F')&&
                           (MOVE[b] = 'U')&&
                           (MOVE[c] = 'R')&&
                           (MOVE[d] = 'U')*/

                        ){   
                            setzero();
                            move(a);
                            move(b);
                            move(c);
                            move(d);

                            /*setzero();
                            move(a);
                            n();printcube();n();
                            move(b);
                            n();printcube();n();
                            move(c);
                            n();printcube();n();
                            move(d);*/



                        // Diese if-Schleife führt zu einem Sechsteln der Laufzeit (0,5s statt 3s)
                        
                        if(

                            (casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 0)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 0)
                            && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 1)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 1))
                            && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 9)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 9))){
                                
                                

                        /*n();n();
                        printf("------------------");
                        n();
                        printf("%c, %c, %c, %c", MOVE[a], MOVE[b], MOVE[c], MOVE[d]);
                        n();n();
                        printcube();
                        caseprinter(0);
                        printf(" and ");
                        caseprinter(1);
                        n();
                        printf("---------%d---------",counter);
                        counter++;*/
                        
                        //saving in tabelle:
                        //if erster eintrag des scrambles is free
                        //if(tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [0] == '0'){
                            //printf("   #####saved new case#####\n");
                            //for(int i = 0; i<5; i++){
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [0] = MOVE[a];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [1] = MOVE[b];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [2] = MOVE[c];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [3] = MOVE[d];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [4] = '0';
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [5] = '0';
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [6] = '0';
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [7] = '0';
                            

                            /*}*/
                            
                        
                    
                }
            }
        }  
    } 
}
}
}


void threemover(){
    int counter = 0;
       for(int a = 0; a<10; a++){
          for(int b = 0; b<10; b++){    
            for(int c = 0; c<10; c++){
                    
                        

                        if(
                            (MOVE[a]!= MOVE[b])&&
                            (MOVE[b]!= MOVE[c])&&
                            zweimovesplausibel(a,b)&&
                            zweimovesplausibel(b,c)
                            
                           /* 
                           &&(MOVE[a] = 'F')&&
                           (MOVE[b] = 'U')&&
                           (MOVE[c] = 'R')*/

                        ){   
                            setzero();
                            move(a);
                            move(b);
                            move(c);

                            /*setzero();
                            move(a);
                            n();printcube();n();
                            move(b);
                            n();printcube();n();
                            move(c);*/



                        // Diese if-Schleife führt zu einem Sechsteln der Laufzeit (0,5s statt 3s)
                        
                        if(

                            (casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 0)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 0)
                            && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 1)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 1))
                            && ((casefinder(c1, e1, c2, e4, e2, c4, e3, c3) != 9)&&(casefinder(c5, e5, c6, e8, e6, c8, e7, c7) != 9))){
                                
                                

                        /*n();n();
                        printf("------------------");
                        n();
                        printf("%c, %c, %c", MOVE[a], MOVE[b], MOVE[c]);
                        n();n();
                        printcube();
                        caseprinter(0);
                        printf(" and ");
                        caseprinter(1);
                        n();
                        printf("---------%d---------",counter);
                        counter++;*/
                        
                        //saving in tabelle:
                        //if erster eintrag des scrambles is free
                        //if(tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [0] == '0'){
                            //printf("   #####saved new case#####\n");
                            //for(int i = 0; i<5; i++){
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [0] = MOVE[a];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [1] = MOVE[b];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [2] = MOVE[c];
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [3] = '0';
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [4] = '0';
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [5] = '0';
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [6] = '0';
                                tabelle[casefinder(c1, e1, c2, e4, e2, c4, e3, c3)] [casefinder(c5, e5, c6, e8, e6, c8, e7, c7)] [7] = '0';
                            

                            
                            }
                        
                    
                
            }
        }  
    } 
}
}



void printtable(){
    for(int a = 0; a<37; a++){
        for(int b = 0; b<37; b++){
            if(tabelle[a] [b] [0] != '0'){
                n();
                for(int c = 0; c<8; c++){
                    printf("%c", tabelle[a][b][c]);
                }
                printf(" ");
                casename(a);
                printf(" ");
                casename(b);
                printf(" ");
                printf("Tabellenstelle: %d - %d", a, b);
            }
        } 
    }
}

void printtable2(){
    n();
    for(int a = 0; a<37; a++){
        for(int b = 0; b<37; b++){

               printf("    | ");
                for(int c = 0; c<8; c++){
                    printf("%c", tabelle[a][b][c]);
                }
                printf(" ");
                casename(a);
                printf(" ");
                casename(b);
                printf(" ");
                printf("TS: %02d - %d", a, b);
                printf(" |    ");
            
        } 
        n();
    }
}

int main(){
    tabellenullen();
    
    eightmover();
    sevenmover();
    sixmover();
    fivemover();
    fourmover();
    threemover();
    printtable();
    printtable2();


return 0;
}
//F, U, R, U, R, C fullcorner 1c

// F U L U R F    Kelle, I



/*
void scanstate(){ 
    state[0 ]= c1; state[1 ]= c2; state[2 ]= c3; state[3 ]= c4; 
    state[4 ]= c5; state[5 ]= c6; state[6 ]= c7; state[7 ]= c8; 
    state[8 ]= e1; state[9 ]= e2; state[10]= e3; state[11]= e4; 
    state[12]= e5; state[13]= e6; state[14]= e7; state[15]= e8; 
}
*/


