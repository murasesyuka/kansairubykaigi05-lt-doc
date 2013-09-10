#/bin/sh

cc -g -I ~/git/mruby/include $1 -L ~/git/mruby/build/host/lib -lmruby -lm

