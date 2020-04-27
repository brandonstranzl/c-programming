
void rotate(char matrix[10][10]) {
  char rotated[10][10];
  for (int i = 0; i < 10; i ++) {
    for (int j = 0; j < 10; j++) {
      rotated[i][j] = matrix[10-1-j][i];
    }
  }
  for (int i = 0; i < 10; i ++) {
    for (int j = 0; j < 10; j++) {
      matrix[i][j] = rotated[i][j];
    }
  }
}
