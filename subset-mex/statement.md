## 問題文

$N$ 枚のカードが一列に並べられており、左から $i$ 番目のカードには非負整数 $A_i$ が書かれています。

$N$ 枚のカードから $1$ 枚以上選ぶ方法は $2^N - 1$ 通りありますが、そのすべてについて以下の値を求め、
総和を $998244353$ で割った余りを求めてください。

- 左から $B_1, B_2, \ldots, B_K$ 番目のカードを選んだとする。$\mathrm{mex}(A_{B_1}, A_{B_2}, \ldots, A_{B_K})$ を求める値とする。


ここで、ある数列 $X$ に対して、 $\mathrm{mex}(X)$ は以下の条件を満たす唯一の非負整数 $m$ として定義します。
- $0 \leq i < m$ を満たすすべての整数 $i$ が $X$ に含まれる
- $m$ が $X$ に含まれない 


## 制約
- $1 \leq N \leq 2 \times 10^5$
- $0 \leq A_i \leq 2 \times 10^5~~(1 \leq i \leq N)$
- 入力はすべて整数

### 部分点

以下の条件を満たすテストケースにすべて正解したとき、記載された点数が与えられる。
1. (20点) $N \leq 17,~ A_i \leq 1000~~(1 \leq i \leq N)$
1. (40点) $A_i \leq 1000~~(1 \leq i \leq N)$
1. (40点) 追加の制約なし

## 入力

入力は、以下の形式で標準入力から与えられる。

<div class="code-math">

$N$
$A_1$ $A_2$ $\ldots$ $A_N$
</div>

## 出力

$1$ 行で、カードを $1$ 枚以上選ぶようなすべての選び方について、求める値を足し合わせた値を $998244353$ で割った余りを出力せよ。

### サンプル1

#### 入力
```
4
0 1 1 2
```

#### 出力
```
17
```
カードを $1$ 枚以上選ぶ選び方と、その時の求める値は以下のようになります。
- $1$ 番目 のカードを選んだ時: $\mathrm{mex}(0) = 1$ です。
- $2$ 番目 のカードを選んだ時: $\mathrm{mex}(1) = 0$ です。
- $3$ 番目 のカードを選んだ時: $\mathrm{mex}(1) = 0$ です。
- $4$ 番目 のカードを選んだ時: $\mathrm{mex}(2) = 0$ です。
- $1, 2$ 番目のカードを選んだ時: $\mathrm{mex}(0, 1) = 2$ です。
- $1, 3$ 番目のカードを選んだ時: $\mathrm{mex}(0, 1) = 2$ です。
- $1, 4$ 番目のカードを選んだ時: $\mathrm{mex}(0, 2) = 1$ です。
- $2, 3$ 番目のカードを選んだ時: $\mathrm{mex}(1, 1) = 0$ です。
- $2, 4$ 番目のカードを選んだ時: $\mathrm{mex}(1, 2) = 0$ です。
- $3, 4$ 番目のカードを選んだ時: $\mathrm{mex}(1, 2) = 0$ です。
- $1, 2, 3$ 番目のカードを選んだ時: $\mathrm{mex}(0, 1, 1) = 2$ です。
- $1, 2, 4$ 番目のカードを選んだ時: $\mathrm{mex}(0, 1, 2) = 3$ です。
- $1, 3, 4$ 番目のカードを選んだ時: $\mathrm{mex}(0, 1, 2) = 3$ です。
- $2, 3, 4$ 番目のカードを選んだ時: $\mathrm{mex}(1, 1, 2) = 0$ です。
- $1, 2, 3, 4$ 番目のカードを選んだ時: $\mathrm{mex}(0, 1, 1, 2) = 3$ です。

よって、答えはこれらをすべて足し合わせた $17$ が答えとなります。


### サンプル2

#### 入力
```
12
2 0 2 4 0 3 3 0 1 4 0 0
```
#### 出力
```
9393
```

本コンテストは2024年3月30日 14:00 から開始されます。

### サンプル3

#### 入力
```
25
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4 3
```
#### 出力
```
0
```

どのようにカードを選んでも、求める値は $0$ となります。
