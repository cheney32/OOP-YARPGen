#include <memory>
char *a;
short b[1][8][8];
void c(int d[][0][20], int e[][0], char f[][0][20], unsigned short g[][8][8],
       int h[][8][8]) {
  for (int i;;)
    for (int m;;)
      for (int j;;)
        for (char k;;)
          for (int l; l < (h[i][j][i] ?: 1); l = 1) {
            *a = (unsigned short)f[m][m][m] %
                 std::max(unsigned(!e[j][j]),
                          std::max(1073741824U, (unsigned)g[i][m][j]));
            b[m][k][m] = d[i][m][j] + 13738;
          }
}
int main() {}
