# Templates
## 1.(Lang)_temp /템플릿 폴더 
(언어 이름)_temp으로 되어 있는 폴더는 그대로 복사하여서, 아래의 형태에 맞추어서 각 문제를 풀어 넣으면 된다.

~~~
(cpp) number_tags
├── README.md   # 문제 풀이 정리 기록
├── answer.cpp  # 문제 풀이 파일 (.cpp, .js, .py ...)
└── data        # input & output 정리
    ├── data.txt    # test cases (input & output)
    └── input.txt   # input
~~~

## 2. Basecode / Basecode
문제를 푸는데 유용한 code의 틀을 저장하고 있다.

## 3. txt 파일을 input으로 넣는 법
1. Redirect
OS에서 제공하는 redirect 기능을 이용할 수 있음. 프로그램을 실행할 때 
~~~
./program <data/input.txt> output.txt
~~~
와 같이 실행하면, stdin에 읽을 것을 input.txt 파일에서 읽어오고, stdout에 출력하면 모니터가 아니라 output.txt 파일에 출력함

https://www.acmicpc.net/board/view/51324
https://losskatsu.github.io/os-kernel/linux-redirection/#1-%ED%91%9C%EC%A4%80-%EC%8A%A4%ED%8A%B8%EB%A6%BCstandard-stream

2. freopen
아래의 코드를 이용해서 파일을 stdin과 stdout의 stream으로 받아올 수 있다.
```cpp
    #include <iostream>
    freopen("data/data.txt", "r", stdin);
    freopen("data/output.txt", "w", stdout);
```
https://jaimemin.tistory.com/1439
