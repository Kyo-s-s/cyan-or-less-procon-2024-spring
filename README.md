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

### 作問時の注意

- ファイル構成は以下のようにする 解答コードやvalidatorの言語はなんでもよい
  ```
  └─problem title
    ├─PROBLEM
    ├─statement.md
    ├─cpp-correct-all
    │  ├─main.cc
    │  └─SOLUTION    // expected_score(100) とする
    ├─cpp-correct-task1
    │  ├─main.cc     // 部分点想定解法では最初に入力validateをすること！
    │  └─SOLUTION    // 部分点を設定
    ├─cpp-correct-task2 ...
    └─tests
      ├─TESTSET
      ├─task1_hogehoge.in
      ├─task1_hogehoge.diff
      ├─ ...
      └─validator.py
  ```
- `TESTSET` で以下のように部分点を設定 得点は各問題に準拠する
  ```
  subtask_testset(name='task1', score=20, input_patterns=['task1_*.in'])
  subtask_testset(name='task2', score=30, input_patterns=['task2_*.in'])
  subtask_testset(name='all', score=50, input_patterns=['*.in'])
  ```

### TODO

- generator？ これは別に各自で書けばよいかも

