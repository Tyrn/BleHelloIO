#/usr/bin/env bash

pio project init --ide=vim
pio run -t compiledb
python piopt.py
#curl -s https://anurag3301.com/files/GrDSa.py | python
