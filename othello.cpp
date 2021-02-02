#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

char matrix[ 8 ][ 8 ];
int x,y,rr,dd1,dd2,cc;
string s,p;
bool foo;
char O,B;

void print(){

    cout << "\n\n\t  0 1 2 3 4 5 6 7\n";

    for(int i = 0; i < 8; i++){

        cout << "\t"<< i << " ";

        for(int j = 0; j < 8; j++)

        cout << matrix[ i ][ j ] << " ";

        cout << endl;
    }
    cout << endl;
}

void matrix_build(){

     for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {

            if(i == 3 and j == 3 or i == 4 and j == 4) matrix[ i ][ j ] = 'W';
            else if((i == 3 and j == 4) or (i == 4 and j == 3)) matrix[ i ][ j ] = 'B';

            else  matrix[ i ][ j ] = '*';
        }

    print();
}
bool check(){

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++) {

            if(matrix[ i ][ j ] == '*') return true;
        }
    }
    return false;
}
bool row(bool flag,int x,int y){

    int y1 = 0;
    int c1 = 0,c2 = 0;

    if( flag ){

        y1 = y;

        while(y1 < 7){

            y1++;

            if(matrix[ x ][ y1 ] == 'B' and matrix[ x ][ y1 ] != '*' and matrix[ x ][ y1 ] != 'W') c1++;
            else if(matrix[ x ][ y1 ] == '*' or matrix[ x ][ y1 ] == 'W'){

                if(matrix[ x ][ y1 ] == '*') c1 = 0;
                break;
            }
            if(y1 == 7 and matrix[ x ][ y1 ] == 'B')c1 = 0;
        }

        y1 = y;

        while(y1 > 0){

            y1--;

            if(matrix[ x ][ y1 ] == 'B' and matrix[ x ][ y1 ] != '*' and matrix[ x ][ y1 ] != 'W') c2++;
            else if(matrix[ x ][ y1 ] == '*' or matrix[ x ][ y1 ] == 'W'){

                if(matrix[ x ][ y1 ] == '*') c2 = 0;
                break;
            }
            if(y1 == 0 and matrix[ x ][ y1 ] == 'B')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        if(foo) {

            rr = c1 + c2;
            return true;
        }
        y1 = y;

        matrix[ x ][ y1 ] = 'W';

        for(int i = 0; i < c1; i++) {

            y1++;
            matrix[ x ][ y1 ] = 'W';
        }

        y1 = y;

        for(int i = 0; i < c2; i++) {

            y1--;
            matrix[ x ][ y1 ] = 'W';
        }
        return true;
    }
    else{

        c1 = 0,c2 = 0;

        y1 = y;

        while(y1 < 7){

            y1++;

            if(matrix[ x ][ y1 ] == 'W' and matrix[ x ][ y1 ] != '*' and matrix[ x ][ y1 ] != 'B') c1++;
            else if(matrix[ x ][ y1 ] == '*' or matrix[ x ][ y1 ] == 'B'){

                if(matrix[ x ][ y1 ] == '*') c1 = 0;
                break;
            }
            if(y1 == 7 and matrix[ x ][ y1 ] == 'W') c1 = 0;
        }

        y1 = y;

        while(y1 > 0){

            y1--;

            if(matrix[ x ][ y1 ] == 'W' and matrix[ x ][ y1 ] != '*' and matrix[ x ][ y1 ] != 'B') c2++;
            else if(matrix[ x ][ y1 ] == '*' or matrix[ x ][ y1 ] == 'B'){

                if(matrix[ x ][ y1 ] == '*') c2 = 0;
                break;
            }
            if(y1 == 0 and matrix[ x ][ y1 ] == 'W')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        if(foo) {

            rr = c1 + c2;
            return true;
        }

        y1 = y;

        matrix[ x ][ y1 ] = 'B';

        for(int i = 0; i < c1; i++) {

            y1++;
            matrix[ x ][ y1 ] = 'B';
        }

        y1 = y;

        for(int i = 0; i < c2; i++) {

            y1--;
            matrix[ x ][ y1 ] = 'B';
        }
        return true;
    }
}

bool cullume(bool flag,int x,int y){

    int x1 = 0;
    int c1 = 0,c2 = 0;

    if( flag ){

        x1 = x;

        while(x1 < 7){

            x1++;

            if(matrix[ x1 ][ y ] == 'B' and matrix[ x1 ][ y ] != '*' and matrix[ x1 ][ y ] != 'W') c1++;
            else if(matrix[ x1 ][ y ] == '*' or matrix[ x1 ][ y ] == 'W'){

                if(matrix[ x1 ][ y ] == '*') c1 = 0;
                break;
            }
            if(x1 == 7 and matrix[ x1 ][ y ] == 'B')c1 = 0;
        }

        x1 = x;

        while(x1 > 0){

            x1--;

            if(matrix[ x1 ][ y ] == 'B' and matrix[ x1 ][ y ] != '*' and matrix[ x1 ][ y ] != 'W') c2++;
            else if(matrix[ x1 ][ y ] == '*' or matrix[ x1 ][ y ] == 'W'){

                if(matrix[ x1 ][ y ] == '*') c2 = 0;
                break;
            }
            if(x1 == 0 and matrix[ x1 ][ y ] == 'B')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        if(foo) {

            cc = c1 + c2;
            return true;
        }

        x1 = x;

        matrix[ x1 ][ y ] = 'W';

        for(int i = 0; i < c1; i++) {

            x1++;
            matrix[ x1 ][ y ] = 'W';
        }

        x1 = x;

        for(int i = 0; i < c2; i++) {

            x1--;
            matrix[ x1 ][ y ] = 'W';
        }
        return true;
    }
    else{

        c1 = 0,c2 = 0;

        x1 = x;

        while(x1 < 7){

            x1++;

            if(matrix[ x1 ][ y ] == 'W' and matrix[ x1 ][ y ] != '*' and matrix[ x1 ][ y ] != 'B') c1++;
            else if(matrix[ x1 ][ y ] == '*' or matrix[ x1 ][ y ] == 'B'){

                if(matrix[ x1 ][ y ] == '*') c1 = 0;
                break;
            }
            if(x1 == 7 and matrix[ x1 ][ y ] == 'W') c1 = 0;
        }

        x1 = x;

        while(x1 > 0){

            x1--;

            if(matrix[ x1 ][ y ] == 'W' and matrix[ x1 ][ y ] != '*' and matrix[ x1 ][ y ] != 'B') c2++;
            else if(matrix[ x1 ][ y ] == '*' or matrix[ x1 ][ y ] == 'B'){

                if(matrix[ x1 ][ y ] == '*') c2 = 0;
                break;
            }
            if(x1 == 0 and matrix[ x1 ][ y ] == 'W')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        if(foo) {

            cc = c1 + c2;
            return true;
        }

        x1 = x;

        matrix[ x1 ][ y ] = 'B';

        for(int i = 0; i < c1; i++) {

            x1++;
            matrix[ x1 ][ y ] = 'B';
        }

        x1 = x;

        for(int i = 0; i < c2; i++) {

            x1--;
            matrix[ x1 ][ y ] = 'B';
        }
        return true;
    }
}
bool diagonal1(bool flag,int x,int y){

    int c1 = 0,c2 = 0,x1 = 0,y1 = 0;

    if(flag){

        x1 = x,y1 = y;

        while(x1 < 7 and y1 < 7){

            x1++;
            y1++;

            if(matrix[ x1 ][ y1 ] == 'B' and matrix[ x1 ][ y1 ] != '*' and matrix[ x1 ][ y1 ] != 'W') c1++;
            else if(matrix[ x1 ][ y1 ] == '*' or matrix[ x1 ][ y1 ] == 'W') {

                if(matrix[ x1 ][ y1 ] == '*') c1 = 0;
                break;
            }
            if(x1 == 7 or y1 == 7 and matrix[ x1 ][ y1 ] == 'B')c1 = 0;
        }

        x1 = x,y1 = y;

        while(x1 > 0 and y1 > 0){

            x1--;
            y1--;

            if(matrix[ x1 ][ y1 ] == 'B' and matrix[ x1 ][ y1 ] != '*' and matrix[ x1 ][ y1 ] != 'W') c2++;
            else if(matrix[ x1 ][ y1 ] == '*' or matrix[ x1 ][ y1 ] == 'W') {

                if(matrix[ x1 ][ y1 ] == '*') c2 = 0;
                break;
            }
            if(x1 == 0 or y1 == 0 and matrix[ x1 ][ y1 ] == 'B')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        if(foo) {

            dd1 = c1 + c2;
            return true;
        }

        x1 = x,y1 = y;

        matrix[ x ][ y ] = 'W';

        for(int i = 0; i < c1; i++){

            x1++;
            y1++;

            matrix[ x1 ][ y1 ] = 'W';
        }

        x1 = x,y1 = y;

        for(int i = 0; i < c2; i++){

            x1--;
            y1--;

            matrix[ x1 ][ y1 ] = 'W';
        }
        return true;
    }
    else {

        x1 = x,y1 = y;
        c1 = 0,c2 = 0;

        while( x1 < 7 and y1 < 7){

            x1++;
            y1++;

            if(matrix[ x1 ][ y1 ] == 'W' and matrix[ x1 ][ y1 ] != '*' and matrix[ x1 ][ y1 ] != 'B') c1++;
            else if(matrix[ x1 ][ y1 ] == '*' or matrix[ x1 ][ y1 ] == 'B') {

                if(matrix[ x1 ][ y1 ] == '*') c1 = 0;
                break;
            }
            if(x1 == 7 or y1 == 7 and matrix[ x1 ][ y1 ] == 'W') c1 = 0;
        }

        x1 = x,y1 = y;

        while(x1 > 0 and y1 > 0){

            x1--;
            y1--;

            if(matrix[ x1 ][ y1 ] == 'W' and matrix[ x1 ][ y1 ] != '*' and matrix[ x1 ][ y1 ] != 'B') c2++;
            else if(matrix[ x1 ][ y1 ] == '*' or matrix[ x1 ][ y1 ] == 'B') {

                if(matrix[ x1 ][ y1 ] == '*') c2 = 0;
                break;
            }
            if(x1 == 0 or y1 == 0 and matrix[ x1 ][ y1 ] == 'W')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        if(foo) {

            dd1 = c1 + c2;
            return true;
        }

        x1 = x,y1 = y;

        matrix[ x ][ y ] = 'B';

        for(int i = 0; i < c1; i++){

            x1++;
            y1++;

            matrix[ x1 ][ y1 ] = 'B';
        }
        x1 = x,y1 = y;

        for(int i = 0; i < c2; i++){

            x1--;
            y1--;

            matrix[ x1 ][ y1 ] = 'B';
        }
        return true;
    }
}
bool diagonal2(bool flag,int x,int y){

    int c1 = 0,c2 = 0,x1 = 0,y1 = 0;

    if(flag){

        x1 = x,y1 = y;

        while(x1 < 7 and y1 > 0){

            x1++;
            y1--;

            if(matrix[ x1 ][ y1 ] == 'B' and matrix[ x1 ][ y1 ] != '*' and matrix[ x1 ][ y1 ] != 'W') c1++;
            else if(matrix[ x1 ][ y1 ] == '*' or matrix[ x1 ][ y1 ] == 'W') {

                if(matrix[ x1 ][ y1 ] == '*') c1 = 0;
                break;
            }
            if(x1 == 7 or y1 == 0 and matrix[ x1 ][ y1 ] == 'B')c1 = 0;
        }

        x1 = x,y1 = y;

        while(x1 > 0 and y1 < 7){

            x1--;
            y1++;

            if(matrix[ x1 ][ y1 ] == 'B' and matrix[ x1 ][ y1 ] != '*' and matrix[ x1 ][ y1 ] != 'W') c2++;
            else if(matrix[ x1 ][ y1 ] == '*' or matrix[ x1 ][ y1 ] == 'W') {

                if(matrix[ x1 ][ y1 ] == '*') c2 = 0;
                break;
            }
            if(x1 == 0 or y1 == 7 and matrix[ x1 ][ y1 ] == 'B')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        if(foo) {

            dd2 = c1 + c2;
            return true;
        }
        x1 = x,y1 = y;

        matrix[ x ][ y ] = 'W';

        for(int i = 0; i < c1; i++){

            x1++;
            y1--;

            matrix[ x1 ][ y1 ] = 'W';
        }

        x1 = x,y1 = y;

        for(int i = 0; i < c2; i++){

            x1--;
            y1++;

            matrix[ x1 ][ y1 ] = 'W';
        }
        return true;
    }
    else {

        x1 = x,y1 = y;
        c1 = 0,c2 = 0;

        while( x1 < 7 and y1 > 0){

            x1++;
            y1--;

            if(matrix[ x1 ][ y1 ] == 'W' and matrix[ x1 ][ y1 ] != '*' and matrix[ x1 ][ y1 ] != 'B') c1++;
            else if(matrix[ x1 ][ y1 ] == '*' or matrix[ x1 ][ y1 ] == 'B') {

                if(matrix[ x1 ][ y1 ] == '*') c1 = 0;
                break;
            }
            if(x1 == 7 or y1 == 0 and matrix[ x1 ][ y1 ] == 'W')c1 = 0;
        }

        x1 = x,y1 = y;

        while(x1 > 0 and y1 < 7){

            x1--;
            y1++;

            if(matrix[ x1 ][ y1 ] == 'W' and matrix[ x1 ][ y1 ] != '*' and matrix[ x1 ][ y1 ] != 'B') c2++;
            else if(matrix[ x1 ][ y1 ] == '*' or matrix[ x1 ][ y1 ] == 'B') {

                if(matrix[ x1 ][ y1 ] == '*') c2 = 0;
                break;
            }
            if(x1 == 0 or y1 == 7 and matrix[ x1 ][ y1 ] == 'W')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        if(foo) {

            dd2 = c1 + c2;
            return true;
        }
        x1 = x,y1 = y;

        matrix[ x ][ y ] = 'B';

        for(int i = 0; i < c1; i++){

            x1++;
            y1--;
            matrix[ x1 ][ y1 ] = 'B';
        }

        x1 = x,y1 = y;

        for(int i = 0; i < c2; i++){

            x1--;
            y1++;

            matrix[ x1 ][ y1 ] = 'B';
        }
        return true;
    }
}


void invalid(){

    cout << "\n\t\tEnter The Valid Point Please.\n\n";
}
bool white(int x,int y){

    if(matrix[ x ][ y ] != '*'){

        if(foo) return true;

        invalid();

        return true;
    }
    bool d1 = diagonal1(true,x,y);
    bool d2 = diagonal2(true,x,y);
    bool rw = row(true,x,y);
    bool clm = cullume(true,x,y);

    if(d1 or d2 or rw or clm){

        if(foo) return true;

        return false;
    }

    if(foo) return true;

    invalid();

    return true;
}

bool black(int x,int y){

    if(matrix[ x ][ y ] != '*'){

        invalid();

        return false;
    }
    bool d1 = diagonal1(false,x,y);
    bool d2 = diagonal2(false,x,y);
    bool rw = row(false,x,y);
    bool clm = cullume(false,x,y);

    if(d1 or d2 or rw or clm){

        return true;
    }

    invalid();

    return false;
}

bool Validation(bool flag){

    if(flag){

        for(int i = 0; i < 8; i++){

            for(int j = 0; j < 8; j++){

                if(matrix[ i ][ j ] == '*'){

                    foo = true;

                    bool d1 = diagonal1(true,i,j);
                    bool d2 = diagonal2(true,i,j);
                    bool rw = row(true,i,j);
                    bool clm = cullume(true,i,j);

                    if(d1 or d2 or rw or clm) {

                        foo = false;

                        return true;
                    }
                }
            }
        }
    }
    else {

        for(int i = 0; i < 8; i++){

            for(int j = 0; j < 8; j++){

                if(matrix[ i ][ j ] == '*'){

                    foo = true;

                    bool d1 = diagonal1(false,i,j);
                    bool d2 = diagonal2(false,i,j);
                    bool rw = row(false,i,j);
                    bool clm = cullume(false,i,j);

                    if(d1 or d2 or rw or clm) {

                        foo = false;
                        return true;
                    }
                }
            }
        }
    }

    foo = false;

    return false;
}

void Othelo_game(){

    bool ck = true,flag = false;

    while( ck and check() ){

        while( flag and check() ){

            cout << "\n\n\t" << p << " For 'White' Enter The Valid Point =  ";
            cin >> x >> y;
            cout << endl;

            ck = Validation(flag);

            bool f = white(x,y);

            print();

            flag = f;
        }
        while(!flag and check()){

            cout << "\n\n\t" << s << " For 'Black' Enter The Valid Point =  ";
            cin >> x >> y;
            cout << endl;

            ck = Validation(flag);

            bool f = black(x,y);

            print();

            flag = f;
        }
    }
}

int main(){

    foo = false;

    matrix_build();
    int play,b = 0,w = 0;

    cout << "\n\n\tEnter Your Name Please =   ";
    cin >> s;
    cout << "\n\n\tEnter Your Friend Name Please =   ";
    cin >> p;

    Othelo_game();

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            if(matrix[ i ][ j ] == 'W') w++;
            else if(matrix[ i ][ j ] == 'B')b++;
        }
    }

    cout << "\n\n\t" << s << " "<< b << " " << p << " " << w << endl << endl;

    if(b == w) cout << "\t\tDraw\n\n";
    else if(b > w) cout <<"\t\t"<< s << "\t\tWIN" << endl;
    else cout <<"\t\t"<< p << "\t\tWIN" << endl;

    return 0;
}

