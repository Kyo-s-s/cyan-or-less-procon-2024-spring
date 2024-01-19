# 水以下コンテスト 作問リポジトリ

## 進捗

完了したら ✔ を書く

|問題名|Writer|問題文|テストケース|想定解実装|Tester AC|(Python AC)|解説|
|:--|:--|:--:|:--:|:--:|:--:|:--:|:--:|
|X-word database|Kyo_s_s|✔|✔|✔||||
||||||||

- 問題文: `statement.md` に記述、そのままMofeCoderに登録できるようにする
- テストケース: validatorを書き、通ることを確認する
- 想定解実装: subtaskの実装については制約validateを行う
- Tester AC: Writer以外の誰かの解法を追加し、ACを確認する
- Python AC: Pythonでの想定解を実装する
- 解説: Kyo_s_sが書きます そのうちこのリポジトリに当日用スライドを追加します

## 環境構築

1. このリポジトリをクローンする

1. rime を導入する
  ```
  $ pip install rime
  ```

## rime の操作

### 問題の新規作成

```
$ rime add . problem (問題名)
```

### 解法の新規作成

問題のディレクトリで、
```
$ rime add . solution (解法の名前)
```

`cpp-correct` など

C++なら `cxx_solution(src='main.cc', flags=["-std=c++20", "-O2", "-Wall", "-Wextra"])` とする

その中で `main.cc` を作成し、解法コードを書く

`challenge_cases=[]` を足すとその解法では落ちることをテストしてくれる

### テストケースの新規作成

問題のディレクトリで、
```
$ rime add . testset tests
```

generator/validatorは後で弄ることにする、そのまま抜けてOK

入力は `xxx.in`、出力は `xxx.diff` にする

### 実際に走らす

問題のディレクトリで、
```
$ rime test .
```


## TODO

- validatorの設定(Pythonで書くのが楽なのかも)
- generator？ これは別に各自で書けばよいかも

