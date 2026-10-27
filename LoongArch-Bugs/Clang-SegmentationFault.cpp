int a, b;
static unsigned char c();
void d() {
  c();
  for (; a;)
    b = 0;
}
unsigned char c() {
  for (;;)
    ;
}
int main() { d(); }
