#!/bin/bash

useValgrind=0   ## 1:= use valgrind.     0:= don't use valgrind.
runWValgrind="valgrind --leak-check=full" ## no need to change
exeName="scriptRunner" ## write your executable's name here

## HOW TO USE:
## Put Tester.sh in the same folder as your source files
## Write a makefile for your program and name it "makefile".
## Open the terminal in the folder and enter "chmod +x Tester.sh"
## Enter "./Tester.sh" every time you want to run a test.
## You can change the code in this tester if you want to, but I don't recommend changing anything beyond this point.
## Good luck!

if [ "$useValgrind" -eq "0" ] 
then runWValgrind="";fi;
clear;
make
i=1


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - simple declarations, simple print ~~~~~~~~~~~~~~~~~
"
echo "a=5
b=\"a string\"
c=false
print(a)
print(b)
print(c)" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

5
a string
false

    ~YOUR OUTPUT:~\n\n"


$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - complex declarations, array declaration, array print ~~~~~~~~~~~~~~~~~
"
echo "a=5
b=\"word\"
c=false
d=a
e=b
f=c
print(d)
print(e)
print(f)
arr=[1,2,3]
print(arr)
arrr=[\"strings\",\"are\",\"fun\"]
print(arrr)
arrrr=[true,false]
print(arrrr)" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

5
word
false
1, 2, 3
strings, are, fun
true, false

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - array members assignment ~~~~~~~~~~~~~~~~~
"
echo "a=2
arr=[1,2,3]
arr[0]=0
arr[1]=1
arr[a]=a
print(arr)
b=\"not\"
arrr=[\"strings\",\"are\",\"fun\"]
arrr[1]=b
arrr[2]=\"cool\"
print(arrr)
c=true
arrrr=[true,false]
arrrr[0]=c
arrrr[1]=false
print(arrrr)" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

0, 1, 2
strings, not, cool
true, false

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - operands, complex print ~~~~~~~~~~~~~~~~~
"
echo "a=5
b=\"word\"
c=true
print(a+6)
print(a+=7)
print(13)
print(a=14)
print(a==14)
print(a==15)
print(a==15==c==true)
print(\"string\")
print(b=\"otherWord\")
print(b)
print(b==\"word\"==false)
print(c)" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

11
12
13
14
true
false
false
string
otherWord
otherWord
true
true

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - if ~~~~~~~~~~~~~~~~~
"
echo "if(true){x=5}
if(true){print(x)}else{x=6}
n=\"\"
y=\" \"
if(false){print(n=\"nope\")}else{print(y=\"yup\")}
arr=[0,1,2,3,4]
if(arr[0]+=arr[1]+=arr[1]+=arr[1]==arr[3]){print(y)}else{print(n)}
if(arr[0]+=arr[1]+=arr[1]+=arr[1]==arr[3]){print(n)}else{print(y)}" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

5
yup
yup
yup


    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - ‫‪‫‪all together ~~~~~~~~~~~~~~~~~
"
echo "arr=[\"!\",\"o\",\"J\",\"G\",\"b\",\"d\"]
brr=[\"G\",\"G\",\"G\",\"G\",\"G\",\"G\",\"G\",\"G\"]
brr[0]=arr[3]
brr[1]=arr[1]
brr[2]=arr[1]
brr[3]=arr[5]
brr[4]=arr[2]
brr[5]=arr[1]
brr[6]=arr[4]
brr[7]=arr[0]
x=50
y=25
x=y+=y+=40
z=0
a=\"string\"
if(x==90==true){print(brr)}else{print(\"nope\")}
if(a==\"string\"==false){print(\"nope\")}else{print(z+10)}" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

surprise

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - BadVariableTypeException 1 ~~~~~~~~~~~~~~~~~
"
echo "a=5
a=true" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

BadVariableTypeException (line 2)

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - BadVariableTypeException 2 ~~~~~~~~~~~~~~~~~
"
echo "arr=[\"string\",false]" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

BadVariableTypeException (line 1)

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - BadVariableTypeException 3 ~~~~~~~~~~~~~~~~~
"
echo "a=5
b=false
a+b" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

BadVariableTypeException (line 3)

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - BadVariableTypeException 4 ~~~~~~~~~~~~~~~~~
***I'm not sure if we are really expected to detect this
"
echo "a=5
b=false
b+a" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

BadVariableTypeException (line 3)

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - BadVariableTypeException 5 ~~~~~~~~~~~~~~~~~
"
echo "a=true
b=\"string\"
a==b" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

BadVariableTypeException (line 3)

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - BadVariableTypeException 6 ~~~~~~~~~~~~~~~~~
"
echo "if(5){}else{}" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

BadVariableTypeException (line 1)

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - BadVariableTypeException 7 ~~~~~~~~~~~~~~~~~
"
echo "arr=[1,2,3]
arr[\"1\"]=0" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

BadVariableTypeException (line 2)

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - ‫‪VariableNotFoundException‬‬ 1 ~~~~~~~~~~~~~~~~~
"
echo "ab=10
print(a)" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

VariableNotFoundException‬‬ (line 2)

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - ‫‪‫‪ArrayOutOfBoundException‬‬ 1 ~~~~~~~~~~~~~~~~~
"
echo "arr=[true,true,false]
print(arr[3])" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

ArrayOutOfBoundException‬‬ (line 2)

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - ‫‪‫‪fib5 ~~~~~~~~~~~~~~~~~
"
echo "last=1
beforelast=0
print(last)
temp=last
last+=beforelast
beforelast=temp
print(last)
temp=last
last+=beforelast
beforelast=temp
print(last)
temp=last
last+=beforelast
beforelast=temp
print(last)
temp=last
last+=beforelast
print(last)" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

1
1
2
3
5

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++


printf "\n\n~~~~~~~~~~~~~~~~~ Test $i - ‫‪‫‪arrTest ~~~~~~~~~~~~~~~~~
"
echo "arr=[6,6]
arr[0]=5
arr[1]+=1
if(arr[0]+2==arr[1]==false==true){print(“one”)}else{print(arr)}" > Tester.txt
cat Tester.txt
printf "
    ~EXPECTED OUTPUT:~

5, 7

    ~YOUR OUTPUT:~\n\n"
$runWValgrind ./$exeName Tester.txt
let i++





echo "This is intentionally empty." > Tester.txt
