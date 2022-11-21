package JavaAlgorithms;

import JavaAlgorithms.Matrix;

/** ／(^ㅅ^)＼
 * @filename Perceptron
 * @author Kali Hale
 * @version 1.0
 */

public class perceptron {
    public static double[] w;
    public static double[][] vectors;
    public static int vectorSize = 3;

    public static double m;
    public static double b;
    public static double[] f;

    public static int[] ys;

    public static int iterations;

    public static void runPerceptron(int vectorNum) {
        vectors = new double[vectorNum][3];

        for(double[] v:
            vectors) {
            v[0] = 1;
            for(int i = 1; i < 3; i++) {
                v[i] = Math.random() * 100;
            }
        }

        m = Math.random() * 2 - 1;
        b = Math.random() * 100;
        f = new double[100];
        ys = new int[vectorNum];

        for(int i = 0; i < 100; i++) {
            f[i] = (m * i) + b;
        }

        for(int i = 0; i < vectorNum; i++) {
            if(vectors[i][2] > (m * vectors[i][1] + b)) {
                ys[i] = 1;
            }
            else {
                ys[i] = -1;
            }
        }

        iterations = 0;
        boolean misclassified = true;


        while(misclassified) {
            misclassified = false;
            for(int i = 0; i < vectorNum; i++) {
                /*if(Math.signum(Matrix.Winograd()))
                {

                }*/
            }
        }

    }

    public static void main(String[] args) {

    }
}
