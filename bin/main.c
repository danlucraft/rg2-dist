/*
 * main.c
 * Ruby launcher
*/
#include <stdio.h>
#include <ruby.h>


int main(argc, argv)
int argc;
char *argv[];
{
  char *path = NULL;
  path = argv[0];
    char bootup[1000] = "begin; p :foo; loop do; sleep 1; p :bar; end; rescue Object => e; puts(e.message); end";
    // int len = shoes_snprintf(bootup,
    //   1000,
    //   "begin;"
    //   "DIR = File.expand_path(File.dirname(%%q<%s>));"
    //   "$:.replace([DIR+'/ruby/lib/'+PLATFORM, DIR+'/ruby/lib', DIR+'/lib', '.']);"
    //   "require 'shoes/cache';"
    //   "DIR;"
    //   "rescue Object => e;"
    //   "puts(e.message);"
    //   "end",
    //   path);
          // 
    // if (len < 0 || len >= 1000)
    //   return 0;
      
    argc--;
    argv[1] = argv[0];
    argv = &argv[1];
    {
      VALUE variable_in_this_stack_frame;
      ruby_init_stack(&variable_in_this_stack_frame);
      ruby_init();
      printf("eval_string: \n");
      rb_eval_string(bootup);
      ruby_options(argc, argv);
      ruby_run();
      return 0;
    }
  // 
//   code = shoes_init();
//   if (code != SHOES_OK)
//   goto done;
//   
//   shoes_set_argv(argc - 1, &argv[1]);
//   code = shoes_start(path, "/");
//   if (code != SHOES_OK)
//     goto done;
//   
// done:
// 
//   shoes_final();
  return 0;
}

  
  
