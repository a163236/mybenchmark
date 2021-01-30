# Text segment
  .text	
  .globl _start

_start:
  li sp, 30000  # スタックポインタ 変数格納できる場所確保
  li ra, 10000  # 最終的なreturn addres
  j main

