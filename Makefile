kwic : main.o parser.o processor.o circularShifter.o ext_Alphabetizer.o ext_ReverseAlphabetizer.o output.o
	
	g++ main.o parser.o processor.o circularShifter.o ext_Alphabetizer.o ext_ReverseAlphabetizer.o output.o -o kwic

main.o : main.cpp parser.hpp processor.hpp circularShifter.hpp ext_Alphabetizer.hpp ext_ReverseAlphabetizer.hpp output.hpp
	g++ -c main.cpp

parser.o : parser.cpp parser.hpp
	g++ -c parser.cpp

processor.o : processor.cpp processor.hpp
	g++ -c processor.cpp

circularShifter.o : circularShifter.cpp circularShifter.hpp
	g++ -c circularShifter.cpp

ext_Alphabetizer.o : ext_Alphabetizer.cpp ext_Alphabetizer.hpp
	g++ -c ext_Alphabetizer.cpp

ext_ReverseAlphabetizer.o : ext_ReverseAlphabetizer.cpp ext_ReverseAlphabetizer.hpp
	g++ -c ext_ReverseAlphabetizer.cpp

output.o : output.cpp output.hpp
	g++ -c output.cpp
