// UVa11988 Broken Keyboard
// Rujia Liu
#include<cstdio>
#include<cstring>
#include <iostream>
const int maxn = 100000 + 5;
int last, cur, next1[maxn]; // 光标位于cur号字符之后面
char s[maxn];
using namespace std;

int main() {
  cout << "111" << endl;
  cout << "222" << endl;
  while(scanf("%s", s+1) == 1) {
    int n = strlen(s+1); // 输入保存在s[1], s[2]...中
    last = cur = 0;
    next1[0] = 0;

    for(int i = 1; i <= n; i++) {
      char ch = s[i];
      if(ch == '[') cur = 0;
      else if(ch == ']') cur = last;
      else {
        next1[i] = next1[cur];
        next1[cur] = i;
        if(cur == last) last = i; // 更新“最后一个字符”编号
        cur = i; // 移动光标
      }
    }
    for(int i = next1[0]; i != 0; i = next1[i])
      printf("%c", s[i]);
    printf("\n");
  }
  return 0;
}
