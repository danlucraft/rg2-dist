require 'fileutils'
include FileUtils

task :default => :build

task :build do
  sh "rm -rf dist"
  mkdir "dist"
  mkdir "dist/ruby"
  sh "gcc -I. -c -obin/main.o -Wall -I/usr/include -I/usr/local/lib/ruby/1.8/i686-linux -O bin/main.c"
  rm_f "dist/shoes"
  sh "gcc -Ldist -o dist/redcar-bin bin/main.o -lruby -L/usr/local/lib -L.  -rdynamic -Wl,-export-dynamic"
  cp_r "/usr/local/lib/ruby/1.8", "dist/ruby/lib"
  cp "/usr/local/lib/libruby.so", "dist/libruby.so"
  ln_s "libruby.so",  "dist/libruby.so.1.8"
  sh "strip -x dist/*.so*"
  sh "strip -x dist/*.so"
  sh "echo 'LD_LIBRARY_PATH=dist/ dist/redcar-bin \"$@\"' >> dist/redcar"
  sh "chmod 755 dist/redcar"
end
