import random
flag = "y"
while (flag=="y"):
    num=random.randint(1,100)
    count=0
    tmp=0
    while(tmp!=num):
        tmp=int(input("please input your answer"))
        count+=1
        if(tmp>num):
            print("your answer is bigger than the right answer")
        elif(tmp<num):
            print("your answer is smaller than the right answer")
    print(f"congratulations!right answer!\nyou have guessed {count} times")
    flag=input("once again?('y'or'n')")
