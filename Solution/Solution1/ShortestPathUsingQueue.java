package Solution.Solution1;

import java.util.*;

public class ShortestPathUsingQueue {
    public static int shortestPath(int[][] grid, int startX, int startY) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] distance = new int[rows][cols];
        boolean[][] visited = new boolean[rows][cols];

        // Initialize all cells with infinity distance except the starting cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                distance[i][j] = Integer.MAX_VALUE;
            }
        }
        distance[startX][startY] = 0;

        // Create a queue
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{startX, startY});
        visited[startX][startY] = true;

        // Loop until the queue is empty
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int x = current[0];
            int y = current[1];

            // Check if the current cell is the exit cell
            if (grid[x][y] == 3) {
                return distance[x][y];
            }

            // Explore the neighboring cells
            int[][] neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int[] neighbor : neighbors) {
                int newX = x + neighbor[0];
                int newY = y + neighbor[1];
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] != 1 && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    queue.offer(new int[]{newX, newY});
                    distance[newX][newY] = distance[x][y] + 1;
                }
            }
        }

        return -1; // Path not found
    }

    public static void main(String[] args) {
        int[][] grid = {
                {3, 0, 0, 0, 0},
                {0, 1, 1, 1, 0},
                {0, 1, 2, 1, 0},
                {0, 1, 0, 0, 0},
                {0, 0, 0, 0, 0}
        };
        int startX = 0;
        int startY = 1;
        int shortestPath = shortestPath(grid, startX, startY);
        System.out.println("Shortest path from (" + startX + ", " + startY + ") to the exit: " + shortestPath);
    }
}
