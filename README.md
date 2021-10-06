# so_long

2D 게임 만들기

### 과제 수행 전 공부해야 하는 것

Makefile에서 라이브러리 연결하는 법

- make -C 연결할 파일경로 `예) make -C ./mlx`
- -L파일경로 `예) -L./mlx`

비트연산(프엡, 넷왓)

mlx 라이브러리 공부하기

- tealee42 : mlx_example [https://github.com/taelee42/mlx_example.git](https://github.com/taelee42/mlx_example.git)

### flowchart
파일참조

### 예외처리

1. 맵의 요소
    
    1, 0, P, C, E 다섯개 문자로만 구성되어 있는가?
    
    플레이어 스타팅포인터, 탈출구, 수집아이템이 각 한개씩 존재 하는가?
    
    - 나는 플레이어 스타팅 포지션은 1개만 존재해야 하도록 처리하고, 탈출구는 여러개여도 게임성에 지장을 주지않는다고 판단하여  탈출구가 여러개여도 에러처리 하지 않았음.
    
    벽(1)으로 둘러 쌓여 있는가?
    
    사각형 형태인가?
    
    - gnl이 저장하는 모든 문자열의 길이가 같아야한다(0같은걸로 채워져있거나 스페이스바로 채워져 있으면 맵에 다른문자가 들어있다고 걸러진다, 여기서는 문자열의 길이가 달라서 사각형이 아닌경우)
2. 파일 오픈 fd 에러
3. 인자로 맵 파일이 제대로 들어왔는지 체크
4. 맵파일 중간에 개행이 껴있는지 체크
('\n')으로 스플릿을 하기때문에, 스플릿 전에 체크해야한다.
5. mlx_init() 에러

---
### 참고자료

MiniLibx 파헤치기 : [https://42kchoi.tistory.com/229](https://42kchoi.tistory.com/229)

MiniLibx 참고 : [https://github.com/qst0/ft_libgfx](https://github.com/qst0/ft_libgfx)

mlx.h : [https://bigpel66.oopy.io/library/c/etc/3](https://bigpel66.oopy.io/library/c/etc/3)

mlx 함수 매뉴얼 : [https://gwpaeng.tistory.com/248](https://gwpaeng.tistory.com/248)

창에 이미지 띄우기 : [https://velog.io/@sayi/42cursursftminiRTmlx-튜토리얼1](https://velog.io/@sayi/42cursursftminiRTmlx-%ED%8A%9C%ED%86%A0%EB%A6%AC%EC%96%BC1)

키 입력 이벤트 : [https://velog.io/@parksj3205/2.-키보드-입력으로-도형-움직이기](https://velog.io/@parksj3205/2.-%ED%82%A4%EB%B3%B4%EB%93%9C-%EC%9E%85%EB%A0%A5%EC%9C%BC%EB%A1%9C-%EB%8F%84%ED%98%95-%EC%9B%80%EC%A7%81%EC%9D%B4%EA%B8%B0)

```c
mlx_loop(void *mlx_ptr)
- 이벤트를 기다리는 무한루프 함수
```

```c
mlx_hook(void *win_ptr, [event], [eventmask], int (funct_ptr)(), void *param);
- 이벤트를 생성하는 함수
- 함수 포인터로 받은 함수를 호출한다.
```

```c
mlx_loop_hook(void *mlx_ptr, int(funct_ptr)(), void *param);
- mlx_loop가 진행되는동안 함수포인터로 들어온 파라미터 함수를 계속 실행한다.
/* 이미지를 뿌려주는 함수를 인자로 넣게된다면,
	mlx_hook에서 키프레스 이벤트를 통해 변경된 사항을 화면에 뿌려주기 위해서 사용함. (프레임업데이트)*/
```

- keycode 알아내기, keypress 와 keyrelease 차이, esc 키 눌러서 창닫기 : [https://velog.io/@hekang/miniRT-mlx.h-사용해보기](https://velog.io/@hekang/miniRT-mlx.h-%EC%82%AC%EC%9A%A9%ED%95%B4%EB%B3%B4%EA%B8%B0)
- 입력 이벤트 hooking, key event 번호 : [https://velog.io/@sayi/42cursursmlx-튜토리얼-입력-이벤트-hooking](https://velog.io/@sayi/42cursursmlx-%ED%8A%9C%ED%86%A0%EB%A6%AC%EC%96%BC-%EC%9E%85%EB%A0%A5-%EC%9D%B4%EB%B2%A4%ED%8A%B8-hooking)

```c
mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
- (x,y)좌표에 string을 출력한다.
- int자료형 인자는 4바이트(32비트)로 8비트씩 각각 투명도, R,G,B를 담당한다.
```

- mlx_string_put() 함수에서 int자료형 컬러의 이해 : [https://42kchoi.tistory.com/229](https://42kchoi.tistory.com/229)
- int 자료형의 크기 : [https://dojang.io/mod/page/view.php?id=30](https://dojang.io/mod/page/view.php?id=30)
- 원하는 색상의 rgb코드 값 알아내기 : [https://search.naver.com/search.naver?where=nexearch&sm=top_sug.pre&fbm=1&acr=2&acq=ㄱgb&qdt=0&ie=utf8&query=rgb+색상표](https://search.naver.com/search.naver?where=nexearch&sm=top_sug.pre&fbm=1&acr=2&acq=%E3%84%B1gb&qdt=0&ie=utf8&query=rgb+%EC%83%89%EC%83%81%ED%91%9C)
- rgb코드값으로 hex,int형 값 계산하기 : [https://www.shodor.org/stella2java/rgbint.html](https://www.shodor.org/stella2java/rgbint.html)

### 사용한 이미지

[https://o-lobster.itch.io/simple-dungeon-crawler-16x16-pixel-pack](https://o-lobster.itch.io/simple-dungeon-crawler-16x16-pixel-pack)

- 문을 제외한 이미지의 크기가 16x16사이즈라 크기변환사이트에서 32로 늘려서 사용했다.
