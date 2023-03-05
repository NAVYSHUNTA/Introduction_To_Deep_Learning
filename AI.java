/*
パーセプトロンのプログラムです。
コードを実行するときは、ファイル名をAI.javaにしてください。
Shunta Nakamura
*/
public class AI {
    public static void main(String[] args){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                System.out.println("AND(" + i + ", " + j + ") = " + AND(i, j));
            }
        }
        System.out.println();

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                System.out.println("NAND(" + i + ", " + j + ") = " + NAND(i, j));
            }
        }
        System.out.println();

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                System.out.println("OR(" + i + ", " + j + ") = " + OR(i, j));
            }
        }
        System.out.println();

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                System.out.println("XOR(" + i + ", " + j + ") = " + XOR(i, j));
            }
        }
        System.out.println();
    }

    // AND回路のパーセプトロン
    static int AND(int x1, int x2){
        int[] x = {x1, x2}; // 入力層 x1, x2
        double[] w = {1.0, 1.0}; // 重み w1, w2
        double b = 1.5; // バイアス b
        double score = w[0] * x[0] + w[1] * x[1];
        if(score <= b){
            return 0;  // ニューロンは発火しない
        } else {
            return 1; // ニューロンは発火する
        }
    }

    // NAND回路のパーセプトロン
    static int NAND(int x1, int x2){
        int[] x = {x1, x2}; // 入力層 x1, x2
        double[] w = {-1.0, -1.0}; // 重み w1, w2
        double b = -1.5; // バイアス b
        double score = w[0] * x[0] + w[1] * x[1];
        if(score <= b){
            return 0;  // ニューロンは発火しない
        } else {
            return 1; // ニューロンは発火する
        }
    }

    // OR回路のパーセプトロン
    static int OR(int x1, int x2){
        int[] x = {x1, x2}; // 入力層 x1, x2
        double[] w = {1.0, 1.0}; // 重み w1, w2
        double b = 0.5; // バイアス b
        double score = w[0] * x[0] + w[1] * x[1];
        if(score <= b){
            return 0;  // ニューロンは発火しない
        } else {
            return 1; // ニューロンは発火する
        }
    }

    // XOR回路のパーセプトロン
    static int XOR(int x1, int x2){
        int s1 = NAND(x1, x2);
        int s2 = OR(x1, x2);
        int y = AND(s1, s2);
        return y;
    }
}
