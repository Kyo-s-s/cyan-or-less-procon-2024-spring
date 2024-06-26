## 問題文

ある数列が増加と減少を交互に繰り返しているとき、その数列はジグザグ数列であると呼びます。
例えば、$(3, 1, 4, 1)$ は減少→増加→減少の順になっているのでジグザグ数列です。
また、$(1, 4, 1, 4, 2)$ は増加→減少→増加→減少の順なのでジグザグ数列です。
一方、$(2, 3, 5, 7)$ や$(1, 3, 3, 1)$ や$(7, 6, 5)$ や$(7, 7)$ はジグザグ数列ではありません。
なお、1つの項からなる数列はジグザグ数列であるとします。

$1$ 以上 $K$ 以下の要素からなる、長さ $N$ のジグザグ数列の個数を 
$998244353$ で割った余りを求めてください。

より厳密には、以下の条件を満たす数列 $\{A_i\}$ をジグザグ数列と呼びます。

- 各$i~(1 \leq i \leq N)$ に対して、 $1 \le A_i \le K$
- 連続する2項は異なる
- 各$i~(1 \leq i \leq N-2)$ に対して、 $(A_i - A_{i+1})(A_{i+1} - A_{i+2}) < 0$ を満たす

## 制約

- $1 \leq N \leq 5000$
- $1 \leq K \leq 5000$
- 入力はすべて整数である

### 部分点

以下の条件を満たすテストケースにすべて正解したとき、記載された点数が与えられる。
1. (20点) $N \leq 5,~~ K \leq 5$
1. (30点) $N \leq 5000,~~K \leq 50$
1. (50点) 追加の制約なし

## 入力

入力は以下の形式で標準入力から与えられる。
<div class="code-math">

$N$ $K$

</div>

## 出力

条件を満たす数列の数を998244353で割った余りを1行に出力してください。

### サンプル1
#### 入力
```
4 3
```

#### 出力

$(1, 2, 1, 2), (1, 2, 1, 3), (1, 3, 1, 2), (1, 3, 1, 3), (1, 3, 2, 3),$
$(2, 1, 2, 1), (2, 1, 3, 1), (2, 1, 3, 2), (2, 3, 1, 2), (2, 3, 1, 3), (2, 3, 2, 3),$
$(3, 1, 2, 1), (3, 1, 3, 1), (3, 1, 3, 2), (3, 2, 3, 1), (3, 2, 3, 2)$
の16個が条件を満たします。

この入力は部分点1の制約を満たします。

```
16
```

### サンプル2
#### 入力
```
2 2
```
#### 出力

$(1, 2), (2, 1)$
の2個が条件を満たします。

この入力は部分点1の制約を満たします。

```
2
```

### サンプル3
#### 入力
```
5 1
```
#### 出力

条件を満たす数列は存在しません。

この入力は部分点1の制約を満たします。

```
0
```

### サンプル4
#### 入力
```
1000 1000
```

#### 出力
```
228139627
```
