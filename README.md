# 水以下コンテスト 作問リポジトリ

## 進捗

完了したら ✔ を書く

| 問題名             | Writer   | 問題文 | テストケース | 想定解実装 | Tester AC | (Python AC) | 解説 |
| :----------------- | :------- | :----: | :----------: | :--------: | :-------: | :---------: | :--: |
| Straight Conditons | Ackvy    |   ✔    |              |            |           |             |      |
| f(f(f(f(f(x)))))   | Kyo_s_s  |   ✔    |      ✔       |     ✔      |           |             |  ✔   |
| Unions             | yasunori |   ✔    |      ✔       |     ✔      |           |             |
| X-word Database    | Kyo_s_s  |   ✔    |      ✔       |     ✔      |           |             |  ✔   |
| Long Chess Board   | yasunori |        |              |            |           |             |      |
| LCM and GCD        | yasunori |   ✔    |      △       |     △      |           |             |      |
| Range Rotate Query | loop0919 |   ✔    |       ✔      |      ✔     |           |             |      |
| Deque Inversion    | Nichi10p |   ✔    |              |            |           |             |      |
| counting-zig-zag-sequence | Ackvy    |   △    |              |            |           |             |      |
|                    |          |        |              |            |           |             |      |

- 問題文: `statement.md` に記述、そのまま MofeCoder に登録できるようにする
- テストケース: validator を書き、通ることを確認する
- 想定解実装: subtask の実装については制約 validate を行う
- Tester AC: Writer 以外の誰かの解法を追加し、AC を確認する
- Python AC: Python での想定解を実装する
- 解説: Kyo_s_s が書きます そのうちこのリポジトリに当日用スライドを追加します

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

generator/validator は後で弄ることにする、そのまま抜けて OK

入力は `xxx.in`、出力は `xxx.diff` にする

### 実際にテストを実行する

問題のディレクトリで、

```
$ rime test . -k
```

### 作問時の注意

- ファイル構成は以下のようにする 解答コードや validator の言語はなんでもよい
  ```
  └─problem title
    ├─PROBLEM
    ├─statement.md
    ├─cpp-correct-all
    │  ├─main.cc
    │  └─SOLUTION    // expected_score(100) とする
    ├─cpp-correct-task1
    │  ├─main.cc     // 部分点想定解法では最初に入力validateをすること！
    │  └─SOLUTION    // 部分点を設定し、challenge_cases=[] を書く
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

### MofeCoder へのアップロード

```
$ python3 export.py
```

をすると、`export-testcases`というフォルダが作成されて、その中の `.zip` がそのまま MofeCoder にアップロードできる

サンプルとそれに対する説明の付与は自分でやらないとダメ
問題文によって subtask2 に subtask1 が含まれている/いないがあるので、それぞれちゃんとしないとダメ
