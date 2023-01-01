def hannoi(n, qidian, zhongjian, jieshu):
    if n == 2:
        print(f"{qidian}>{zhongjian}")
        print(f"{qidian}>{jieshu}")
        print(f"{zhongjian}>{jieshu}")
    else:
        hannoi(n-1,qidian,jieshu,zhongjian)
        print(f"{qidian}>{jieshu}")
        hannoi(n-1,zhongjian,qidian,jieshu)
hannoi(64,'a','b','c')

