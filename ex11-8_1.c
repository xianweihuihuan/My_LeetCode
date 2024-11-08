void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    int t = 0;
    int tmp[matrixSize][matrixSize];
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            tmp[i][j] = matrix[matrixSize - 1 - j][i];
        }
    }
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            matrix[i][j] = tmp[i][j];
        }
    }
}