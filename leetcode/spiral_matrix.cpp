#include <bits/stdc++.h>

using namespace std;

/*
Problem: https://leetcode.com/problems/spiral-matrix/
Given an m x n matrix, return all elements of the matrix in spiral order.

*/

/*
Solution:

The idea here is to keep track of direction and visited cells.

Approach:

We are at current position (i, j), with an initial direction as right
We move in that direction as much as possible, and we assign each cell on the way as -101, to mark as visited
If we cross the matrix border or we reach an already visited cell, we stop moving in that direction.
We come one step back, as we have moved to an invalid cell.
We go in the next direction in this fashion right -> down -> left -> up.
Then we start moving this new direction, following the step one.
If we cannot move even once in a direction, which means we've come to the center of the matrix and all the cells are visited. Then terminate the loop and return spiral.
Example:
[1 2 3]
[4 5 6]
[7 8 9]

In the first iteration, we start with i, j = 0, 0 and we move in the right direction, till 0, 3. Now as (0, 3) is invalid, we go back to (0, 2) and then to (1, 2) (down). Spiral = [1, 2, 3]
Then from (1, 2) we go down till (3, 2), which is invalid so we move to (2, 2) and then (2, 1) (left). Spiral [1, 2, 3, 6, 9]
Then from (2, 1) we go left till (2, -1), which is invalid so we move to (2, 0) and then (1, 0) (up). Spiral [1, 2, 3, 6, 9, 8, 7]
From (1, 0) we go up and see (0, 0), but it is visited, so we chance direction and reach (1, 1) (right) Spiral [1, 2, 3, 6, 9, 8, 7, 4]
After visiting (1, 1) we reach (1, 2). But (1, 2) is itself and we cannot move anywhere from there as well, so we terminate. Spiral [1, 2, 3, 6, 9, 8, 7, 4, 5]

*/

vector<int> spiralOrder(vector<vector<int>> matrix) {
    /*
        variables: 
        - spiral: answer vector
        - dir: directions vector
        - i: initial row position
        - j: initial column position
        - possible: flag whether next direction is possible or not
        - curr: current direction
    */
    vector<int> spiral;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int i=0, j=0, possible=1, curr = 0;
    
    // while we can try moving in a valid direction
    while(possible){
        possible = 0;
        while(i>-1 and i<matrix.size() and j>-1 and j<matrix[0].size() and matrix[i][j]!=-101){
            spiral.push_back(matrix[i][j]);
            matrix[i][j]=-101;
            i+=dir[curr].first;
            j+=dir[curr].second;
            possible=1;
        }
        if (possible) {
            i-=dir[curr].first;
            j-=dir[curr].second;
        }
        curr = (curr+1)%4;
        if (possible) {
            i+=dir[curr].first;
            j+=dir[curr].second;
        }
    }
    return spiral;
}
    
int main() {
    vector<int> ans = spiralOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
