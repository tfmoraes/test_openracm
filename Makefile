CC = g++

taubin_occ:
	g++ -I../opencram/inc/ taubin_ooc.cpp -o taubin_ooc  -L../opencram/Lib -lOpenRACM -g -pedantic -fpermissive

clean:
	rm taubin_ooc
