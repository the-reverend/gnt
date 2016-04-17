#!/bin/bash
# dependencies :
#  imagemagick - apt-get install imagemagick
#  spritemapper - http://yostudios.github.io/Spritemapper/
rm -rf *.png
for f in ./*.gif; do convert $f $f.png; done

echo "/* spritemapper.anneal_steps=500 */" > gnt.css
echo ".letter { display: inline-block; overflow: hidden; text-indent: -999px; }" >> gnt.css
echo ".letter.space { width: 18px; height: 30px; }" >> gnt.css
for f in ./*.png; do
	identify $f | sed 's/\(\.\/\([^ ]\+\)\.gif\.png\) PNG \([0-9]\+\)x\([0-9]\+\) .*/.letter.\2 { background: url(\1); width:\3; height:\4; }/' >> gnt.css;
done

echo "[spritemapper]" > sm.ini
echo "anneal_steps=5000" >> sm.ini
echo "output_image=gnt_sprite.png" >> sm.ini
echo "output_css=gnt_sprite.css" >> sm.ini

spritemapper -c sm.ini gnt.css
