# build the sprite

the original source contains a bunch of gif files.  some of these files appear to be malformed.  todo: figure that out.  we need to compile these gifs into a sprite.

## dependencies

* sudo apt-get install imagemagick pip
* build spritemapper
	* git clone git://github.com/yostudios/Spritemapper.git
	* cd Spritemapper
	* modify Spritemapper/spritecss/packing/__init__.py

		import sys
		sys.setrecursionlimit(2000)
	
	* sudo python setup.py install

## approach

1. use imagemagick to convert the gif files into png files and compute the height and width of the images.
1. generate input css assuming each png is a background image to a css class.
1. use spritemapper (http://yostudios.github.io/Spritemapper/) to generate the sprite and corresponding css.

## make.sh

make.sh does it all.
