# Test OpenRACM

## Taubin Out-of-core

I'm trying to implement a out-of-core version of taubin using OpenRACM.

## Compiling

You'll need [OpenRACM](http://sglab.kaist.ac.kr/~sungeui/OpenRACM/). Then:

g++ taubin_ooc.cpp -o taubin_ooc -I openracm_inc_dir -L openracm_lib_dir -lOpenRACM
