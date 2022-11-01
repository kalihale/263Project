

def Winograd(mat1, mat2):
    if len(mat1[0]) != len(mat2):
        raise ArithmeticError("Matrices cannot be multipled")
    
    a = len(mat1)
    b = len(mat1[0])
    c = len(mat2[0])
    result = [[None * c] * a]
    rowFactors = [None * a]
    columnFactors = [None * c]
    d = b // 2

    # Calc row factors
    for i in range(a):
        rowFactors[i] = mat1[i][0] * mat1[i][1]
        for j in range(1, d):
            rowFactors[i] += mat1[i][2*j] * mat1[i][2*j+1]
   
   # Calc col factors
    for i in range(c):
        columnFactors[i] = mat2[0][i] * mat2[1][i]
        for j in range(1, d):
            columnFactors[i] += mat2[2*j][i] * mat2[2*j+1][i]
    
    # Calc results
    for i in range(len(rowFactors)):
        for j in range(len(columnFactors)):
            result[i][j] = -rowFactors[i] - columnFactors[j]
            for k in range(d):
                result[i][j] += (mat1[i][2*k] + mat2[2*k+1][j]) * (mat1[i][2*k+1] + mat2[2*k][j])
    
    # Deal with odd numbered row-column
    if (2 * (b//2)) != b:
        for i in range(a):
            for j in range(c):
                result[i][j] += mat1[i][b-1] * mat2[b-1][j]
    
    return result