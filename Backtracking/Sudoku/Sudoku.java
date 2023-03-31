package Backtracking.Sudoku;

import java.util.Arrays;


class Solution {
    public static void Solve(int i, int j, int[][] sudoku, boolean[][][] Matrix, boolean[][] Row, boolean[][] Col) {
        if (i < 9 && j < 9) {
            if (sudoku[i][j] == 0) {
                for (int z = 1; z <= 9; z++) {
                    if (!Matrix[i/3][j/3][z-1] && !Row[i][z-1] && !Col[j][z-1]) {
                        Matrix[i/3][j/3][z-1] = true;
                        Row[i][z-1] = true;
                        Col[j][z-1] = true;
                        sudoku[i][j] = z;

                        Solve(i, j + 1, sudoku, Matrix, Row, Col);
                        Matrix[i/3][j/3][z-1] = false;
                        Row[i][z-1] = false;
                        Col[j][z-1] = false;
                        sudoku[i][j] = 0;
                    }
                }
            } else {
                Solve(i, j + 1, sudoku, Matrix, Row, Col); // dịch chuyển tới ô tiếp theo trong ma trận
            }
        } else if (i < 9 && j >= 9) // trường hơp i < 9 và j >= 9
            Solve(i + 1, 0, sudoku, Matrix, Row, Col);
        else {
            printResult(sudoku);
        }
    }

    private static void printResult(int[][] sudoku) {
        for (int i = 0; i < sudoku.length; i++) {
            System.out.println(Arrays.toString(sudoku[i]));
        }
    }

}

class Sudoku {
    public static void main(String[] args) {
        boolean[][][] Matrix = new boolean[9/3][9/3][9];
        boolean[][] Row = new boolean[9][9];
        boolean[][] Col = new boolean[9][9];

        int[][] sudoku = new int[][] {
                { 3, 7, 8, 9, 2, 6, 4, 1, 5 },
                { 4, 2, 9, 1, 5, 0, 0, 6, 0 },
                { 5, 6, 1, 3, 4, 0, 9, 2, 0 },
                { 1, 9, 6, 7, 0, 5, 2, 8, 4 },
                { 7, 4, 5, 2, 8, 1, 0, 9, 0 },
                { 0, 0, 2, 4, 6, 9, 0, 5, 7 },
                { 9, 8, 4, 5, 1, 3, 6, 7, 2 },
                { 2, 5, 7, 6, 9, 4, 0, 3, 1 },
                { 6, 1, 3, 8, 7, 2, 5, 4, 0 }
        };

        for (int i = 0; i < sudoku.length; i++) {
            for (int j = 0; j < sudoku[i].length; j++) {
                int currentNumber = sudoku[i][j];
                if (sudoku[i][j] != 0) {
                    Row[i][currentNumber - 1] = true;
                    Col[j][currentNumber - 1] = true;
                    Matrix[i/3][j/3][currentNumber - 1] = true;
                }
            }
        }

        Solution.Solve(0, 0, sudoku, Matrix, Row, Col);
    }
}