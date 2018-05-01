# ATRobots
ATRobots relives project

## History of ATRobots

[ATRobots](http://necrobones.com/atrobots/) was created by Ed T. Toton III (AKA: Necrobones).
It is now mostly living as a school project in William "Amos" Confer's computer science classes at [SUNY Polytechnic Institute](http://sunypoly.edu).

## Installing

### Ubuntu Linux
 Install required packages
`sudo apt install libsdl2-dev libsdl2-gfx-dev libsdl2-ttf-dev libsdl2-mixer-dev gcc make -y`

Move into proper directory
`cd atrobots/robotic-codes/src/graphic_tests/`

Compile program
`make`

Run
`./rcode`


### Mac OS X

Download SDL2 requirements
`wget https://www.libsdl.org/release/SDL2-2.0.8.tar.gz
wget http://www.ferzkopp.net/Software/SDL2_gfx/SDL2_gfx-1.0.4.tar.gz
wget https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.tar.gz
wget https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.2.tar.gz`

Decompress SDL2
`tar -xf SDL2-2.0.8.tar.gz
tar -xf SDL2_mixer-2.0.2.tar.gz
tar -xf SDL2_ttf-2.0.14.tar.gz
tar -xf SDL2_gfx-1.0.4.tar.gz`

Compile and install SDL2
`cd SDL2-2.0.8
./configure
make
sudo make install
cd ../SDL2_gfx-1.0.4
./configure
make
sudo make install
cd ../SDL2_ttf-2.0.14
./configure
make
sudo make install
cd ../SDL2_mixer-2.0.2
./configure
make
sudo make install
cd ..
rm -rf SDL2-2.0.8 SDL2_gfx-1.0.4 SDL2_ttf-2.0.14 SDL2_mixer-2.0.2`

Move to proper directory
`cd atrobots/robotic-codes/src/graphic_tests/`

Compile
`make`

Run
`./rcode`


## Resources

* [SDL2](https://www.libsdl.org/release/SDL2-2.0.8.tar.gz)
* [SDL2_gfx](http://www.ferzkopp.net/Software/SDL2_gfx/SDL2_gfx-1.0.4.tar.gz)
* [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.tar.gz)
* [SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.2.tar.gz)
* [Cantina 8-Bit](https://soundcloud.com/crig-1/star-wars-cantina-8bit)
