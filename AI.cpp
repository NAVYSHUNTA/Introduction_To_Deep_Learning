/*
パーセプトロンのプログラムです。
Shunta Nakamura
*/

#include <iostream>

using namespace std;

// 関数のプロトタイプ宣言
int XOR(int x1, int x2);
int OR(int x1, int x2);
int NAND(int x1, int x2);
int AND(int x1, int x2);

// メイン関数
int main(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "XOR(" << i << ", " << j << ") = " << XOR(i, j) << endl;
        }
    }
    cout << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "OR(" << i << ", " << j << ") = " << OR(i, j) << endl;
        }
    }
    cout << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "NAND(" << i << ", " << j << ") = " << NAND(i, j) << endl;
        }
    }
    cout << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "AND(" << i << ", " << j << ") = " << AND(i, j) << endl;
        }
    }
    cout << endl;

    return 0;
}

// XOR回路のパーセプトロン
int XOR(int x1, int x2){
    int s1 = NAND(x1, x2);
    int s2 = OR(x1, x2);
    int y = AND(s1, s2);
    return y;
}


// OR回路のパーセプトロン
int OR(int x1, int x2){
    int x[] = {x1, x2}; // 入力層 x1, x2
    double w[] = {1.0, 1.0}; // 重み w1, w2
    double b = 0.5; // バイアス b
    double score = w[0] * x[0] + w[1] * x[1];
    if(score <= b){
        return 0;  // ニューロンは発火しない
    } else {
        return 1; // ニューロンは発火する
    }
}

// NAND回路のパーセプトロン
int NAND(int x1, int x2){
    int x[] = {x1, x2}; // 入力層 x1, x2
    double w[] = {-1.0, -1.0}; // 重み w1, w2
    double b = -1.5; // バイアス b
    double score = w[0] * x[0] + w[1] * x[1];
    if(score <= b){
        return 0;  // ニューロンは発火しない
    } else {
        return 1; // ニューロンは発火する
    }
}

// AND回路のパーセプトロン
int AND(int x1, int x2){
    int x[] = {x1, x2}; // 入力層 x1, x2
    double w[] = {1.0, 1.0}; // 重み w1, w2
    double b = 1.5; // バイアス b
    double score = w[0] * x[0] + w[1] * x[1];
    if(score <= b){
        return 0;  // ニューロンは発火しない
    } else {
        return 1; // ニューロンは発火する
    }
}
