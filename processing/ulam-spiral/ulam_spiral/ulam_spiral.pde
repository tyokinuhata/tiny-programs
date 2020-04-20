void setup () {
  size(700, 700);
  background(255);
  spiral();
}

void spiral () {
  // 1の描画
  print("C");
  fill(255, 255, 255);
  rect(350, 350, 10, 10);
  
  // 角までの距離
  int corner = 1;

  // 方向
  int direction = 1;

  // 現在の数字
  int i = 2;

  // ループ回数
  int k = 0;
  
  // 座標
  int x = 350;
  int y = 350;
  
  while (i < 20) {
    for (int j = 0; j < corner; j++) {
      int mod = direction % 4;
      
      // 素数なら赤, 合成数なら白
      if (isPrime(i + j)) {
          fill(255, 0, 0);
      } else {
        fill(255, 255, 255);
      }
      
      switch (mod) {
        case 0:
          display("D", x, y += 10);
          break;
        case 1:
          display("R", x += 10, y);
          break;
        case 2:
          display("U", x, y -= 10);
          break;
        case 3:
          display("L", x -= 10, y);
      }
    }
    i += corner;
    if (k % 2 != 0)  corner++;
    k++;
    direction++;
  }
}

void display (String d, int x, int y) {
  print(d);
  rect(x, y, 10, 10);
}

boolean isPrime (int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}