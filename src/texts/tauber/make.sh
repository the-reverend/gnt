#!/bin/bash
#010101 ! n- ----nsf- n-nf-s ! *bi/blos biblos bi/blos ! bi/blos
#010101 ! n- ----gsf- n-gf-s ! gene/sews genesews gene/sews ! ge/nesis
#book/chapter/verse 
#! 
#part-of-speech 
#Derived-MorphGNT-tag 
#Friberg-tag 
#! 
#UBS3-text 
#Friberg-text 
#MorphGNT-text 
#! 
#Lemma
echo 'CREATE TABLE versewords ( verseword_ integer primary key, book_ integer, chapter integer, verse integer, word integer, pos text, mtag text, ftag text, ubs3 text, friberg text, morphgnt text, llema text );' > $1.sql
echo 'begin;' >> $1.sql
cat $1 | sed "s/'/''/g" |  sed "s/\([0-9]\{2\}\)\([0-9]\{2\}\)\([0-9x]\{2\}\) ! \([^ ]*\) \([^ ]*\) \([^ ]*\) ! \([^ ]*\) \([^ ]*\) \([^ ]*\)/insert into versewords (book_,chapter,verse,word,pos,mtag,ftag,ubs3,friberg,morphgnt,llema) values (\1,\2,\3,(select count(*) from versewords where book_=\1 and chapter=\2 and verse=\3)+1,'\4','\5','\6','\7','\8','\9',/" | sed "s/\([^!]*\) ! \(.*\)/\1'\2');/" >> $1.sql
echo 'commit;' >> $1.sql
