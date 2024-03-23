set -e
g++ gen.cpp -o gen
g++ ac.cpp -o ac
g++ wa.cpp -o wa
for((i=0;i<1000;i++))do
        echo "case $i"
        ./gen > input$i
        ./ac < input$i > ac.ans
        ./wa < input$i > wa.ans
        diff ac.ans wa.ans || break
        rm input$i
done