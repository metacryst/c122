#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    char last[50];
    char first[50];
    char email[100];
    int classStanding;
}Student;