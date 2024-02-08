## 問題文について
クエリの内容説明で、「より形式的には〜」を書くかどうか悩み  
「先頭に追加」などで一般的には十分な気がする一方で、厳密さに欠ける印象もある  
記述がけっこう長くなるので、あってもなくてもどっちでもいいなら消す  

## 制約について
N,Qの上限は想定解法コードを書いたあとにまた調整する

## 想定解法と簡単な解説
### 10点 O(Q * N^2)
配列でクエリを実行し、すべての(i,j)を確認して転倒数を求める

### 30点 O(Q * N^2)
配列でクエリを実行し、すべての(i,j)を確認して転倒数を求める  
配列の先頭への追加/削除は O(N) であるが、転倒数の計算に O(N^2) かかるので全体のオーダーは悪化しない（重要ポイント）  
dequeを使ってもよいが、ランダムアクセスが平均O(N)な言語では、転倒数の計算が O(N^3) になってしまうことに注意（罠ポイント）

### 50点 O(Q * NlogN)
配列やdequeでクエリを実行し、fenwick_treeなどで転倒数を求める  
負数をfenwick_treeのインデックスに乗せるために、10^6程度の数を足すような工夫が必要である  
クエリ先読み+座標圧縮でもよいが、やや実装が重くなるのが欠点であろう  
配列の先頭への(以下略)  
転倒数の計算にランダムアクセスを要しないのでdequeを使ってもよい  
Python勢で、「30点狙いのdeque解法が落ちたのに NlogN 転倒数を調べて実装がんばったらなぜか50点まで通った」みたいなモヤっとが発生するかも？

### 100点 O(NlogN + QlogN) これWAじゃないよね？
dequeでクエリを実行し転倒数を差分更新する  
fenwick_treeで初期状態のAの転倒数を計算 (NlogN) 、仮に I とする  
push_front X: `I += ft.sum(0, X), ft.add(X, 1), A.push_front(X)`  
push_back X: `I += ft.sum(X+1, inf), ft.add(X, 1), A.push_back(X)`  
pop_front: `I -= ft.sum(0, A[0]), ft.add(A[0], -1), A.pop_front()`  
pop_back: `I -= ft.sum(A[-1]+1, inf), ft.add(A[-1], -1), A.pop_back()`  
クエリの実行は O(1) 、差分更新に O(logN) なので、全体で NlogN + QlogN