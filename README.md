# KWIC

This repository contains an implementation of the classical **Keyword in Context** program. The project was proposed as a work of the Programming Techniques 2 discipline.

## Requirements

The implemented KWIC was based on the following article:

> "On the Criteria To Be Used in Decomposing Systems into Modules", **D. L. Parnas**

The article explores the problem as a modularization exercise, so the main requirement of the project is the use of advanced modularization techniques of the chosen language (**C++**). 

## How to compile

The project does not have a makefile yet. Therefore, in order to compile, you must provide the following command in terminal:

> **$ g++ parser.cpp  processor.cpp circularShifter.cpp main.cpp ext_Alphabetizer.cpp ext_ReverseAlphabetizer.cpp output.cpp**

Suggested version of GCC: > **7.4.0**

