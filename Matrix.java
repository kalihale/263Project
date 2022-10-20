/** ／(^ㅅ^)＼
 * @file Matrix.java
 * @author Kali Hale
 * @version 1.0
 *
 * Code used from my undergraduate Algorithms class
 * in Spring of 2021.
 */

public class Matrix {
    public static double[][] Winograd(double[][] mat1, double[][] mat2) throws IllegalArgumentException,
            ArithmeticException
    {
        if(mat1[0].length != mat2.length)
        {
            throw new IllegalArgumentException("Matrices cannot be multiplied");
        }
        int a = mat1.length;
        int b = mat1[0].length;
        int c = mat2[0].length;
        double[][] result = new double[a][c];
        double[] rowFactors = new double[a];
        double[] columnFactors = new double[c];
        int d = b/2;
        //  <@  Calculate row factors
        for(int i = 0; i < a; i++)
        {
            rowFactors[i] = mat1[i][0] * mat1[i][1];
            for(int j = 1; j < d; j++)
            {
                rowFactors[i] += mat1[i][2*j] * mat1[i][2*j+1];
            }
        }
//		System.out.println(Arrays.toString(rowFactors));
        //  <@  Calculate column factors
        for(int i = 0; i < c; i++)
        {
            columnFactors[i] = mat2[0][i] * mat2[1][i];
            for(int j = 1; j < d; j++)
            {
                columnFactors[i] += mat2[2*j][i] * mat2[2*j+1][i];
            }
        }
//		System.out.println(Arrays.toString(columnFactors));
        //  <@  Calculate results
        for(int i = 0; i < rowFactors.length; i++)
        {
            for(int j = 0; j < columnFactors.length; j++)
            {
                result[i][j] = -rowFactors[i] - columnFactors[j];
                for(int k = 0; k < d; k++)
                {
                    result[i][j] += (mat1[i][2*k] + mat2[2*k+1][j]) * (mat1[i][2*k+1] + mat2[2*k][j]);
                }
            }
        }
        //  <@  Deal with odd numbered row-column
        if(2 * (b / 2) != b)
        {
            for(int i = 0; i < a; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    result[i][j] += mat1[i][b-1] * mat2[b-1][j];
                }
            }
        }
        return result;
    }

}
