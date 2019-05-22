#pragma once
#ifndef READ_HPP
#define READ_HPP
#include "DBUG.CPP"
#include "HEAD.CPP"
#include<stdio.h>
class READ
{
public:
    int LENS;
    int DATA[1024][6];
    READ(string ,string ,string ,int );
};

#endif // READ_HPP
