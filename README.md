# 水以下コンテスト 作問リポジトリ

### 環境構築

1. このリポジトリをクローンする

1. rime を導入する
  ```
  $ pip install rime
  ```

### rime の操作

##### 問題の新規作成

```
$ rime add . problem (問題名)
```

##### 解法の新規作成

問題のディレクトリで、
```
$ rime add . solution (解法の名前)
```

`cpp-correct` など

C++なら `cxx_solution(src='main.cc', flags=["-std=c++20", "-O2", "-Wall", "-Wextra"])` とする

その中で `main.cc` を作成し、解法コードを書く

`challenge_cases=[]` を足すとその解法では落ちることをテストしてくれる

##### テストケースの新規作成

問題のディレクトリで、
```
$ rime add . testset tests
```

generator/validatorは後で弄ることにする、そのまま抜けてOK

入力は `xxx.in`、出力は `xxx.diff` にする

##### 実際に走らす

問題のディレクトリで、
```
$ rime test .
```


### TODO

- validatorの設定(Pythonで書くのが楽なのかも)
- generator？ これは別に各自で書けばよいかも

