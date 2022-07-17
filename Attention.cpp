Codeblock設定
-std=c++14 -Wall -Wshadow -O2
Linux可加找更多錯誤-Wextra

標頭檔
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <utility>
#include <vector>

vim .vimrc
cd -> vim .vimrc -> cd Desktop -> mkdir -> AC印出來
syntax on
set clipboard=unnamed
set nu
set bs=2
set cin si
set cf
set sta sw=4 sts=4 ts=4
set mouse=a
set bg=dark
set cul
imap {<CR> {<CR>}<esc>ko
imap [ []<esc>i
imap ( ()<esc>i

vim指令
yy 複製當行
dd 剪下當行
d^ 從游標到最頂剪下
p 貼上
u undo
ctrl+r unundo

常犯的錯
g++ -O2
取餘數、浮點數會有誤差(可以轉整數處理)、注意溢位、別吃太飽
