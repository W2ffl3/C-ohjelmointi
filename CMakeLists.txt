cmake_minimum_required(VERSION 3.30)
project(C_kurssi C)

set(CMAKE_C_STANDARD 11)

add_executable(C_kurssi main.c
        week1/teht1.c
        week1/teht2.c
        week1/teht3.c
        week2/teht4.c
        "VILLE tehtävät/introduction.c"
        "VILLE tehtävät/programming1_1.c"
        week2/teht5.c
        week2/teht6.c
        week3/teht7.c
        week3/teht8.c
        week3/teht9.c
        week4/teht10.c
        week4/teht11.c
        week4/teht12.c
        week5/teht13.c
        week5/teht14.c
        week5/teht15.c
        week6/teht16.c
        week6/teht17.c
        week6/teht18.c
        week7/teht19.c
        week7/teht20.c
        week7/teht21.c
        Projekti_grade_calculator/gradecalculator.c
)
