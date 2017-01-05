mkn clean
mkn clean -p jsonvalid

mkn build -dtSa "-O2 -fPIC -std=c++14" && ln -sf mip/miptknzr/build/bin/libmiptknzr.so build/bin || exit 1
mkn build -p jsonvalid -dtSa "-O2 -fPIC -std=c++14" 
